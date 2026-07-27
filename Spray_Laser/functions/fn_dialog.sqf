params ["_veh"];

createDialog "Spray_Laser_Dialog";
private _targets = _veh getVariable ["Spray_LaserTargets", []];

// Populate listbox with current targets
{
	private _target = _x select 0;
	private _time = [_x select 3, "HH:MM:SS"] call BIS_fnc_timeToString;
	lbAdd [1500, netId _target + ", Grid:" + mapGridPosition  _target + ", Created:" + _time];
} forEach _targets;

// Add button
(displayCtrl 2400) ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    closeDialog 2;
    hint "Select Target Location";
    openMap true;
    [vehicle player] onMapSingleClick {
        params ["_veh"];
        onMapSingleClick "";
        // Should it run locally?
        [_veh, _pos] remoteExec ["Spray_Laser_fnc_add", 2];
        [_veh] spawn {
            params ["_veh"];
            Hint "";
            sleep 0.5;
            openMap false;
            [_veh] call Spray_Laser_fnc_dialog;
        };
    };
}];

// Remove button
(displayCtrl 2401) ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _sel = lbCurSel 1500;
    if (_sel != -1) then {
        [vehicle player, _sel] remoteExec ["Spray_Laser_fnc_remove", 2];
        lbDelete [1500, _sel];
    };
}];

// Cancel button
(displayCtrl 2402) ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    closeDialog 2;
}];
