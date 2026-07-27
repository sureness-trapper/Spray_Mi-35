params ["_target"];
private _turrets = [[-1]] + allturrets _target;

createDialog "Spray_AutoCM_Dialog";
//idd 12000
{
	private _cms = _target weaponsTurret _x select {getText (configFile >> "CfgWeapons" >> _x >> 'simulation') == 'cmlauncher'};
	lbAdd [1502, str _x];
	lbSetData [1502, (lbSize 1502) - 1, str _cms];
} forEach _turrets;
// 1502 turret
(displayCtrl 1502) ctrlAddEventHandler ["LBSelChanged", {
	params ["_control", "_lbCurSel", "_lbSelection"];
	private _cms = call compile lbData [1502, _lbCurSel];
	// 1500 launcher
	lbClear 1500;
	{
		private _y = _x;
		private _modes = getArray (configFile >> "CfgWeapons" >> _x >> "modes") select {getNumber (configFile >> "CfgWeapons" >> _y >> _x >> "showToPlayer") == 1};
		lbAdd [1500, _x];
		lbSetData [1500, (lbSize 1500) - 1, str _modes];
	} forEach _cms;
	(displayCtrl 1500) ctrlAddEventHandler ["LBSelChanged", {
		params ["_control", "_lbCurSel", "_lbSelection"];
		private _modes = call compile lbData [1500, _lbCurSel];
		if (count _modes == 0) then {_modes pushBack lbText [1500, lbCurSel 1500]};
		//1501 mode
		lbClear 1501;
		{
			lbAdd [1501, _x];
		} forEach _modes;
		private _preferCM = vehicle player getVariable ["Spray_AutoCM_preferCM", []];
		private _mode = "";
		if (_preferCM isNotEqualTo []) then {
			_mode = _preferCM select 1;
		};
		if (_mode in _modes) then {
			lbSetCurSel [1501, [1501, _mode] call Spray_AutoCM_fnc_findlbItem];
		} else {
			lbSetCurSel [1501, 0];
		};
	}];
	private _preferCM = vehicle player getVariable ["Spray_AutoCM_preferCM", []];
	private _cm = "";
	if (_preferCM isNotEqualTo []) then {
		_cm = _preferCM select 0;
	}; 
	if (_cm in _cms) then {
		lbSetCurSel [1500, [1500, _cm] call Spray_AutoCM_fnc_findlbItem];
	} else {
		lbSetCurSel [1500, 0];
	};
}];
(displayCtrl 2600) ctrlAddEventHandler ["ButtonClick", {
	params ["_control"];
	//1401 Burst 1400 timer 
	if ((lbText [1500, lbCurSel 1500] != "") && (parseNumber ctrlText 1401 >= 1) && (parseNumber ctrlText 1401 <= 5) && (parseNumber ctrlText 1400 >= 0.2) && (parseNumber ctrlText 1400 <= 5)) then {
		private _turret = call compile lbText [1502, lbCurSel 1502];
		private _mode = lbText [1501, lbCurSel 1501];
		private _burst = parseNumber ctrlText 1401;
		private _timer = round (parseNumber ctrlText 1400 * 10) / 10;
		private _weap = lbText [1500, lbCurSel 1500];
		private _preferCM = [_weap, _mode, _burst, _timer];
		[vehicle player, cbChecked ((findDisplay 12000) displayCtrl 2800), _turret, _preferCM] call Spray_AutoCM_fnc_init;
		Hint "Applied";
	} else {
		Hint "Incorrect input";
	};
	
}];
(displayCtrl 2700) ctrlAddEventHandler ["ButtonClick", {
	params ["_control"];
	closeDialog 2;
}];

private _preferCM = _target getVariable ["Spray_AutoCM_preferCM", []];
if (_preferCM isNotEqualTo []) then {
	ctrlSetText [1401, str (_preferCM select 2)];
	ctrlSetText [1400, str (_preferCM select 3)];
} else {
	ctrlSetText [1401, "2"];
	ctrlSetText [1400, "0.5"];
};
private _on = _target getVariable ["Spray_AutoCMEH", -1];
if (_on != -1) then {
	(findDisplay 12000) displayCtrl 2800 cbSetChecked true;
} else {
	(findDisplay 12000) displayCtrl 2800 cbSetChecked false;
};
private _turret = _target getVariable ["Spray_AutoCM_turret", []];
if (_turret in _turrets) then {
	lbSetCurSel [1502, [1502, str _turret] call Spray_AutoCM_fnc_findlbItem];
} else {
	lbSetCurSel [1502, 0];
};
