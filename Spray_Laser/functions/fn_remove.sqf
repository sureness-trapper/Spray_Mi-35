params ["_veh", "_targetID"];
private _targets = _veh getVariable ["Spray_LaserTargets", []];
private _target = _targets select _targetID;

deleteVehicle (_target select 0);
deleteMarker (_target select 1);
terminate (_target select 2);
_targets deleteAt _targetID;

_veh setVariable ["Spray_LaserTargets", _targets, true];
