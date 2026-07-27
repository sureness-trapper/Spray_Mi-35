class CfgPatches {
    class Spray_Hind_Opf {
        addonRootClass = "Spray_Hind";
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.100000;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {"A3_Opf_Air_F_Opf_Heli_Attack_04"};
    };
};

class CfgVehicles {
    class Helicopter_Base_F;
    class Heli_Attack_02_base_F: Helicopter_Base_F {
        class Turrets;
        class Components;
    };
    class Aegis_Heli_Attack_04_base_F : Heli_Attack_02_base_F {
        class Turrets : Turrets {
			class CargoTurret_01;
			class CargoTurret_02;
			class CargoTurret_03;
			class CargoTurret_04;
        };
        class Components : Components {
            class TransportPylonsComponent {
                class Pylons {
                    class PylonLeft1;
                    class PylonLeft2;
                    class PylonLeft3;
                    class PylonRight1;
                    class PylonRight2;
                    class PylonRight3;
                    class PylonLeft4;
                    class PylonRight4;
                    class PylonRadar;
                };
                class Presets {
                    class Default;
                    class AT;
                    class CAS;
                    class HAT;
                };
            };
        };
   };
    class Opf_O_S_Heli_Attack_04_F : Aegis_Heli_Attack_04_base_F {
        cargoProxyIndexes[] = {1,2,3,4,9,10,11};
        transportsoldier = 7;
        cargoAction[] = {"Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "Passenger_Heli_Attack_04", "passenger_flatground_generic02", "passenger_flatground_generic05", "passenger_flatground_leanleft"};
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {

            };
            class CargoTurret_02: CargoTurret_02 {

            };
            class CargoTurret_03: CargoTurret_03 {

            };
            class CargoTurret_04: CargoTurret_04 {

            };
        };
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class Pylons : pylons {
                    class PylonLeft1 : PylonLeft1 {
                    };
                    class PylonLeft2 : PylonLeft2 {
                    };
                    class PylonLeft3 : PylonLeft3 {
                    };
                    class PylonRight1 : PylonRight1 {
                    };
                    class PylonRight2 : PylonRight2 {
                    };
                    class PylonRight3 : PylonRight3 {
                    };
                    class PylonLeft4: PylonLeft4 {
                    };
                    class PylonRight4 : PylonRight4 {
                    };
                    class PylonRadar: PylonRadar {
                        attachment = "";
                    };
                };
                class Presets : Presets {
                    class Default : Default {
                        attachment[] = {"PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonWeapon_250Rnd_20mm_shells","PylonRack_20Rnd_Rocket_80mm","PylonRack_20Rnd_Rocket_80mm","PylonWeapon_250Rnd_20mm_shells", "", "", ""};
                    };
                };
            };
        };
    };
};