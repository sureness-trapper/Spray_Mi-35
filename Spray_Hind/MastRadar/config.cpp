class CfgPatches {
    class Spray_Hind_MastRadar {
        units[] = {};
        weapons[] = {};
        magazines[] = {"MastRadar", "MastRadarMkii"};
        addonRootClass = "Spray_Hind";
        requiredVersion = 0.100000;
        requiredAddons[] = {"A3_Weapons_F"};
    };
};
class SensorTemplateActiveRadar;
class SensorTemplateDataLink;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateAntiRadiation;
class CfgMagazines {
    class VehicleMagazine;
    class MastRadar: VehicleMagazine {
        mass = 200;
        weight = 200;
        displayName = "Mast Sensor";
        descriptionShort = "Mast Sensor";
        hardpoints[] = { "MastRadar_Pylon" };
        hiddenSelections[] = {"camo2"};
        simulation = "components";
        hiddenSelectionsTextures[] = {"\A3_Aegis\air_f_Aegis\Heli_Attack_04\Data\Skins\Heli_Attack_04_ext_01_Grey_CO.paa"};
        model = "Spray_Hind\MastRadar\MastRadar.p3d";
        class Components {            
            class AdditionalSensorsComponent {
                class Components {
                    class ActiveRadarSensorComponent : SensorTemplateActiveRadar {
                        aimDown = 30;
                        angleRangeVertical = 90;
                        groundNoiseDistanceCoef = -1;
                        maxGroundNoiseDistance = -1;
                        maxSpeedThreshold = 0;
                        maxTrackableSpeed = 125;
                        minSpeedThreshold = 0;
                        class GroundTarget {
                            maxRange = 4000;
                            minRange = 4000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class AirTarget {
                            maxRange = 5000;
                            minRange = 5000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                    };					
                };
            };
        };
    };
    class MastRadarMkii: MastRadar {
        displayName = "Mast Sensor MKII";
        descriptionShort = "Mast Sensor MKII, enhanced range, anti-radiation and datalink support";
        class Components: Components {
            class AdditionalSensorsComponent: AdditionalSensorsComponent {
                class Components: Components {
                    class ActiveRadarSensorComponent: ActiveRadarSensorComponent {
                        typeRecognitionDistance = 6000;
                        class GroundTarget: GroundTarget {
                            maxRange = 8000;
                            minRange = 8000;
                        };
                        class AirTarget: AirTarget {
                            maxRange = 8000;
                            minRange = 8000;
                        };
                    };
                    class DataLinkSensorComponent : SensorTemplateDataLink {
                        typeRecognitionDistance = 32000;
                        class AirTarget {
                            minRange = 32000;
                            maxRange = 32000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            minRange = 32000;
                            maxRange = 32000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                    };
                    class AntiRadiationSensorComponent : SensorTemplateAntiRadiation {
                    };
                    class LaserSensorComponent : SensorTemplateLaser {
                        class GroundTarget {
                            maxRange = 8000;
                            minRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class AirTarget {
                            maxRange = 8000;
                            minRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                    };
                    class NVSensorComponent : SensorTemplateNV {
                        class GroundTarget {
                            maxRange = 8000;
                            minRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class AirTarget {
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
