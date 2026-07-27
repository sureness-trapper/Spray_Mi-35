params [ "_target", "_turret", "_cm", "_mode", "_burst", "_timer"];
private _allcms = _target weaponsTurret _turret;
_allcms = _allcms select {getText (configFile >> "CfgWeapons" >> _x >> 'simulation') == 'cmlauncher'};
// selectWeapon doesn't work for cmlauncher !!! Need to remove all other cmlauncher to select _cm
_allcms deleteAt (_allcms find _cm);
{
	_target removeWeaponTurret [_x, _turret];
} forEach _allcms;
{
	_target addWeaponTurret [_x, _turret];
} forEach _allcms;
// delay burst until current burst is finished
private _delay = 0;
if (_cm == _mode) then {
	_delay = getNumber (configFile >> "CfgWeapons" >> _cm >> "burst") * getNumber (configFile >> "CfgWeapons" >> _cm >> "reloadTime");
} else {
	_delay = getNumber (configFile >> "CfgWeapons" >> _cm >> _mode >> "burst") * getNumber (configFile >> "CfgWeapons" >> _cm >> _mode >> "reloadTime");
};
for "_i" from 0 to (((_burst max 1) min 5) - 1) do {
	// [_target, _cm, _turret] call BIS_fnc_fire;
	(_target turretUnit _turret) forceWeaponFire [_cm, _mode];
	sleep (_delay + ((_timer max 0.2) min 5));
};
