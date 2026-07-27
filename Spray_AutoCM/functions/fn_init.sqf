/*
	_turret: Turret Path,  e.g. [-1], [0], [0, 0]
	_preferCM: ["CMFlareLauncher", "Burst", 3, 0.5]
	If both _turret and _preferCM is empty, the first available CM is chosen. _turret is 'prefered', if _preferCM isn't available in _turret, some other turret with _preferCM is chosen. But if _preferCM is not empty, then only _preferCM would be selected, if none is found, it would not work.
*/
params ["_veh", "_on", ["_turret", []], ["_preferCM", []]];
if (_turret isNotEqualTo []) then {
	_veh setVariable ["Spray_AutoCM_turret", _turret, true];
};
if (_preferCM isNotEqualTo []) then {
	_veh setVariable ["Spray_AutoCM_preferCM", _preferCM, true];
};
_veh removeEventHandler ["IncomingMissile", _veh getVariable ["Spray_AutoCMEH", -1]];
if (_on) then {
	private _AutoCMEH = _veh addEventHandler ["IncomingMissile", {
		params ["_target", "_ammo", "_vehicle", "_instigator", "_missile"];
		private _preferCM = _target getVariable ["Spray_AutoCM_preferCM", []];
		private _preferturret = _target getVariable ["Spray_AutoCM_turret", []];
		private _turrets = (fullcrew _target apply {_x select 3});
		private _turret = [];
		private _cm = [];
		
		if ([] in _turrets) then {
			_turrets set [_turrets find [], [-1]];
		};
		if (_preferturret isNotEqualTo [] && _preferturret in _turrets) then {	
			_turrets deleteAt (_turrets find _preferturret);
			_turrets = [_preferturret] + _turrets;
		};
		
		{
			private _cms = _target weaponsTurret _x select {getText (configFile >> "CfgWeapons" >> _x >> 'simulation') == 'cmlauncher'};
			private _mags = _target magazinesTurret [_x, false];
			_cms = _cms select {_mags arrayIntersect (compatibleMagazines _x) isNotEqualTo []};
			if (count _cms > 0) then {
				if (_preferCM isEqualTo []) then {
					_cm = [_cms select 0, getArray (configFile >> "CfgWeapons" >> _cms select 0 >> "modes") select {getNumber (configFile >> "CfgWeapons" >> _cms select 0 >> _x >> "showToPlayer") == 1} select 0, 2, 0.5];	
					_turret = _x;
					break;
				} else {
					if (_preferCM select 0 in _cms) then {
						_cm = _preferCM;
						_turret = _x;
						break;
					};
				};
			};
		} forEach _turrets;
		if (_turret isNotEqualTo [] && _cm isNotEqualTo []) then {
			[_target, _turret] + _cm spawn Spray_AutoCM_fnc_FireCM;
		} else {
			// Chat repeated several times?
			["Automatic countermeasures unavailable"] remoteExec ["Hint", (fullcrew _target select {_x select 1 in ['driver','commander','gunner']} apply {_x select 0}) select {isPlayer _x}];
		};
	}];
	_veh setVariable ["Spray_AutoCMEH", _AutoCMEH, true];
} else {
	_veh setVariable ["Spray_AutoCMEH", nil, true];
};
