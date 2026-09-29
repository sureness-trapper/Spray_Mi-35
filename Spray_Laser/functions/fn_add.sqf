params ["_veh", "_pos"];
private _side = switch (side _veh) do {
	case WEST : {"W"};
	case EAST : {"E"};
	default {"C"};
};
private _targets = _veh getVariable ["Spray_LaserTargets", []];

// Check for clear view of the sky
_pos = ATLToASL _pos;
private _pos_5000 = +_pos;
_pos_5000 set [2, _pos_5000 # 2 + 5000];
private _intersect = lineIntersectsSurfaces [_pos_5000, _pos, objNull, objNull, true, -1, "VIEW", "FIRE", true];
if (count _intersect > 0) then {
	_pos = (_intersect select 0) select 0;
};
_pos = ASLToATL _pos;
private _target = createVehicle [("LaserTarget" + _side), _pos, [], 0, "CAN_COLLIDE"];
private _t = dayTime;

// Isn't it supposed to work without remoteExec?
[[_target],  {
	params ["_target"];
	if (alive _target) then {
		_marker = createMarker [("Spray_Laser_" + netId _target), _target, 1];
		_marker setMarkerType "waypoint";
		_marker setMarkerText ("Laser Target " + netId _target);
	};
}] remoteExec ["call", 0, true];
private _keepAlive = [_veh, _target] spawn {
	params ["_veh", "_target"];	
	private _netID = "Spray_Laser_" + netId _target;
	while {alive _target && alive _veh} do {
		_target setPosATL getPosATL _target;
		sleep 5;
	};
	if (alive _veh) then {
		private _targets = _veh getVariable ["Spray_LaserTargets", []];
		private _sel = _targets findIf {(_x # 1) == _netID};
		[_veh, _sel] remoteExec ["Spray_Laser_fnc_remove", 2];
	} else {
		deleteMarker _netID;
	};
};
[[side _veh, _target],  {
	params ["_side", "_target"];
	if (alive _target) then {
		// The biggest time allow seems to be ≈ 2.14733e+06, which is ≈ 24.85 days
		_side reportRemoteTarget [_target, 1e9];
	};
}] remoteExec ["call", 0, true];
_targets pushBack [_target, ("Spray_Laser_" + netId _target), _keepAlive, _t];
_veh setVariable ["Spray_LaserTargets", _targets, true];
