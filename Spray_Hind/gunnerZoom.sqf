params ["_unit"];

_unit addEventHandler ["GetIn", {
	params ["_vehicle", "_role", "_unit", "_turret"];
    if (_turret isEqualTo [0] && !(isplayer _unit)) then {
        _vehicle setTurretOpticsMode [[0], 2];
    };
}];
