class CfgPatches {
    class Spray_Laser_Hind {
        addonRootClass = "patch";
        units[] = {};
        magazines[] = {};
        weapons[] = {};
        requiredVersion = 0.100000;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {"Spray_Hind"};
    };
};

class CfgVehicles {
	class Helicopter;
    class Helicopter_Base_F;
    class Heli_Attack_02_base_F : Helicopter_Base_F {
        class EventHandlers;
    };
    class Aegis_Heli_Attack_04_base_F : Heli_Attack_02_base_F {
        class EventHandlers : EventHandlers {
            class Laser {
                init = "[_this select 0, true] call Spray_Laser_fnc_addAction";
            };
        };
    };
};