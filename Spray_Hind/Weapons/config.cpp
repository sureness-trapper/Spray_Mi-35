class CfgPatches {
    class Spray_Hind_Weapons {
        addonRootClass = "Spray_Hind";
        units[] = {};
        weapons[] = {"Aegis_Autocannon_Heli_Attack_04_F", "missiles_Scalpel_NLOS"};
        magazines[] = {"PylonMissile_1Rnd_Scalpel_NLOS", "PylonRack_1Rnd_Scalpel_NLOS", "PylonRack_2Rnd_Scalpel_NLOS", "PylonRack_3Rnd_Scalpel_NLOS", "PylonRack_4Rnd_Scalpel_NLOS"};
        requiredVersion = 0.100000;
        requiredAddons[] = {"A3_Weapons_F_Tank","A3_Aegis_Weapons_F_Aegis", "A3_Weapons_F"};
    };
};
class SensorTemplateDataLink;
class CfgAmmo {
	class B_20mm_AP;
	class B_20mm_APDS: B_20mm_AP {
        caliber = 3.8;
        hit = 70;
        indirectHit = 0;
        indirectHitRange = 0;
        airFriction = -0.00036;
    };
	class B_20mm_APDS_Tracer_Red: B_20mm_AP {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
	class B_20mm_APDS_Tracer_Green: B_20mm_AP {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
	class B_20mm_APDS_Tracer_Yellow: B_20mm_AP {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class B_20mm;
	class B_20mm_Tracer_Yellow: B_20mm {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class MissileCore;
    class MissileBase: MissileCore {
        class Components;
    };
    class M_Scalpel_AT: MissileBase {
        class Components {
            class SensorsManagerComponent {
                class Components;
            };
        };
    };
    class M_Scalpel_NLOS : M_Scalpel_AT {
        aiAmmoUsageFlags = "128 + 256 + 512";
        weaponType = "missileAT";
        timeToLive = 60;
        airLock = 1;
        flightProfiles[] = {"Direct", "TopDown", "Cruise"};
        missileLockMaxDistance = 8000;
        class Direct {};
        class Cruise {
            lockDistanceToTarget = 800;
            preferredFlightAltitude = 400;
        };
        class Components : Components {
            class SensorsManagerComponent : SensorsManagerComponent {
                class Components : Components {
                    class DataLinkSensorComponent : SensorTemplateDataLink {
                        maxTrackableSpeed = 55;
                        class AirTarget {
                            maxRange = 8000;
                            minRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            maxRange = 8000;
                            minRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                    };
                };
            };
        };
    };
};
class CfgMagazines {
	class VehicleMagazine;
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_F: VehicleMagazine {
        count = 420;
        ammo = "B_20mm";
        weight = 126;
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_Green_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_F {
        ammo = "B_20mm_Tracer_Green";
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_Red_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_F {
        ammo = "B_20mm_Tracer_Red";
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_White_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_F {
        ammo = "B_20mm";
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_Yellow_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_F {
        ammo = "B_20mm_Tracer_Yellow";
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_F: VehicleMagazine {
        count = 420;
        ammo = "B_20mm_APDS";
        weight = 126;
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_Green_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_F {
        ammo = "B_20mm_APDS_Tracer_Green";
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_Red_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_F {
        ammo = "B_20mm_APDS_Tracer_Red";
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_White_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_F {
        ammo = "B_20mm_APDS";
    };
	class Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_Yellow_F: Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_F {
        ammo = "B_20mm_APDS_Tracer_Yellow";
    };
    class PylonMissile_1Rnd_LG_scalpel;
    class PylonMissile_1Rnd_Scalpel_NLOS : PylonMissile_1Rnd_LG_scalpel {
        ammo = "M_Scalpel_NLOS";
        pylonWeapon = "missiles_Scalpel_NLOS";
        displayName = "Scalpel NLOS";
        weight = 49;
        displayNameMFDFormat = "MISL";
    };
    class PylonRack_1Rnd_Scalpel_NLOS : PylonMissile_1Rnd_Scalpel_NLOS {
        hardpoints[] = {"B_MISSILE_PYLON", "SCALPEL_1RND_EJECTOR", "UNI_SCALPEL"};
        model = "\A3\Weapons_F\DynamicLoadout\PylonPod_1x_Missile_LG_scalpel_F.p3d";
        mass = 110;
        weight = 110;
    };
    class 2Rnd_LG_scalpel;
    class PylonRack_1Rnd_LG_scalpel : 2Rnd_LG_scalpel {
        class mfdElements;
    };
    class PylonRack_4Rnd_LG_scalpel : PylonRack_1Rnd_LG_scalpel {
        class mfdElements : mfdElements {
            class Heli_Attack_01 {
                class Draw {
                    class Default {
                        class PylonText1;
                        class PylonText2;
                        class Shape;
                    };
                    class Empty {
                        class PylonText1;
                        class PylonText2;
                        class Shape;
                    };
                    class Selected {
                        class PylonText1;
                        class PylonText2;
                        class Shape;
                    };
                };
            };
        };
    };
    class PylonRack_4Rnd_Scalpel_NLOS : PylonRack_4Rnd_LG_scalpel {
        weight = 370;
        ammo = "M_Scalpel_NLOS";
        pylonWeapon = "missiles_Scalpel_NLOS";
        displayName = "Scalpel NLOS 4x";
        hardpoints[] += {"B_MISSILE_PYLON"};
        displayNameMFDFormat = "MISL";
    };
    class PylonRack_3Rnd_Scalpel_NLOS : PylonRack_4Rnd_Scalpel_NLOS {
        count = 3;
        mass = 300;
        weight = 300;
        displayName = "Scalpel NLOS 3x";
        mirrorMissilesIndexes[] = {2,1,3};
        model = "\A3\Weapons_F\DynamicLoadout\PylonPod_3x_Missile_LG_scalpel_F.p3d";
    };
    class PylonRack_2Rnd_Scalpel_NLOS : PylonRack_3Rnd_Scalpel_NLOS {
        mass = 251;
        count = 2;
        weight = 251;
        displayName = "Scalpel NLOS 2x";
    };
};

class CfgWeapons {
    class autocannon_Base_F;
    class cannon_20mm: autocannon_Base_F {
        class HE: autocannon_Base_F {
            class player;
            class close;
            class short;
            class medium;
            class far;
        };
        class AP: autocannon_Base_F {
            class player;
            class close;
            class short;
            class medium;
            class far;
        };
    };
    class Aegis_Autocannon_Heli_Attack_04_F: cannon_20mm {
        class GunParticles {
            class Effect {
                directionName = "z_gun_chamber";
                effectName = "AutoCannonFired";
                positionName = "z_gun_muzzle";
            };
            class Shell {
                directionName = "pos gunner dir";
                effectName = "HeavyGunCartridge1";
                positionName = "z_gun_gunnerview";
            };
        };
        class HE : HE {
            FCSZeroingDelay = 0.5;
            ballisticsComputer = "1 + 2 + 16";
            magazineReloadTime = 0;
            magazines[] = {"Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_Yellow_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_Green_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_Red_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_HE_White_F"};
            class player : player {
                reloadTime = 0.066667;
                displayName = "Gun HE";
            };
            class close : close {
                reloadTime = 0.066667;
                displayName = "Gun HE";
            };
            class short : short {
                reloadTime = 0.066667;
                displayName = "Gun HE";
            };
            class medium : medium {
                reloadTime = 0.066667;
                displayName = "Gun HE";
            };
            class far : far {
                reloadTime = 0.066667;
                displayName = "Gun HE";
            };
        };
        class AP : AP {
            FCSZeroingDelay = 0.5;
            ballisticsComputer = "1 + 2 + 16";
            magazineReloadTime = 0;
            magazines[] = {"Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_Yellow_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_Green_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_Red_F","Aegis_150Rnd_Autocannon_Heli_Attack_04_AP_White_F"};
            class player : player {
                reloadTime = 0.066667;
                displayName = "Gun AP";
            };
            class close : close {
                reloadTime = 0.066667;
                displayName = "Gun AP";
            };
            class short : short {
                reloadTime = 0.066667;
                displayName = "Gun AP";
            };
            class medium : medium {
                reloadTime = 0.066667;
                displayName = "Gun AP";
            };
            class far : far {
                reloadTime = 0.066667;
                displayName = "Gun AP";
            };
        };
    };
    class RocketPods;
    class missiles_SCALPEL : RocketPods {
        class TopDown;
    };
    class missiles_Scalpel_NLOS : missiles_SCALPEL {
        magazines[] = {"PylonMissile_1Rnd_Scalpel_NLOS", "PylonRack_1Rnd_Scalpel_NLOS", "PylonRack_3Rnd_Scalpel_NLOS", "PylonRack_4Rnd_Scalpel_NLOS", "PylonRack_2Rnd_Scalpel_NLOS"};
        modes[] = {"TopDown", "Cruise", "Direct"};
        displayName = "Skalpel NLOS";
        weaponLockSystem = 2 + 8;
        class TopDown : TopDown {
            maxRange = 8000;
            midRange = 1000;
            displayName = "Skpl Top";
        };
        class Direct : TopDown {
            displayName = "Skpl Dir";
            textureType = "semi";
        };
        class Cruise : TopDown {
            displayName = "Skpl Crs";
            textureType = "terrain";
        };
    };
};