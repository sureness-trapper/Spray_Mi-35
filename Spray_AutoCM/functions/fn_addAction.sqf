params ["_veh", "_add"];
_veh removeAction (_veh getVariable ["Spray_AutoCMID", -1]);
private _AutoCMID = nil;
if _add then {
    _AutoCMID = _veh addAction ["Automatic Countermeasures", {[_this select 0] call Spray_AutoCM_fnc_Dialog}, nil, 1.5, false, true, "", "_this in (fullcrew _target select {_x select 1 in ['driver','commander','gunner']} apply {_x select 0})", -1];
} else {
    [_veh, false] call Spray_AutoCM_fnc_init;
    _veh removeAction (_veh getVariable ["Spray_AutoCMID", -1]);
};
_veh setVariable ["Spray_AutoCMID", _AutoCMID, true];
//Locality change handler
_veh addEventHandler ["Local", {
	params ["_entity", "_isLocal"];
    private _AutoCMEH = _entity getVariable ["Spray_AutoCMEH", -1];
    if (_AutoCMEH != -1) then {
        if (!_isLocal) then {
            _entity removeEventHandler ["IncomingMissile", _AutoCMEH];
        } else {
            _entity setVariable ["Spray_AutoCMEH", nil, true];
            [_entity, _AutoCMEH != -1] call Spray_AutoCM_fnc_init;
        };
    };
}];