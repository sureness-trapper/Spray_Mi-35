params ["_veh", "_add"];
_veh removeAction (_veh getVariable ["Spray_LaserDialogID", -1]);
private _LaserDialogID = nil;
if _add then {
    _LaserDialogID = _veh addAction ["Laser Target", {[_this select 0] call Spray_Laser_fnc_dialog}, nil, 1.5, false, true, "", "_this in (fullcrew _target select {_x select 1 in ['driver','commander','gunner']} apply {_x select 0})", -1];

} else {
    for "_i" from 0 to (count (_veh getVariable ["Spray_LaserTargets", []])) do {
        [_veh, 0] call Spray_Laser_fnc_remove;
    };
};
_veh setVariable ["Spray_LaserDialogID", _LaserDialogID, true];