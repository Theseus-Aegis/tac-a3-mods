class CfgPatches
{
    class bnae_rk95_compat_ace
    {
        requiredaddons[]=
        {
            "bnae_RK95",
            "bnae_core",
            "bnae_suppressor",
            "bnae_suppressor_v2",
            "cba_jr"
        };
        requiredversion=0.1;
        magazines[]=
        {
            "6Rnd_B_357_Mag",
            "8Rnd_9x19_B",
            "30Rnd_762x39_Magazine",
            "2Rnd_B_00_buckshot",
            "6Rnd_B_00_buckshot",
            "7Rnd_B_338_lapua",
            "9Rnd_B_45ACP"
        };
    };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class asdg_OpticRail;
class asdg_OpticRail1913: asdg_OpticRail
{
};
class CfgWeapons
{
    class Rifle;
    class Rifle_Base_F: Rifle
    {
        class WeaponSlotsInfo;
    };
    class bnae_rk95_base: Rifle_Base_F // http://guns.connect.fi/gow/M95.html
    {
        ACE_barrelTwist=240.0;
        ACE_barrelLength=420.0;
        class Single: Mode_SemiAuto
        {
            dispersion=0.00044; // 1.5 MOA; default: 0.00058=2 MOA
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.00044; // 1.5 MOA; default: 0.00058=2 MOA
        };
    };
    class bnae_rk95_virtual: bnae_rk95_base
    {
    };
    class bnae_rk95r_virtual: bnae_rk95_virtual
    {
        ACE_RailHeightAboveBore=14.0;
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            class asdg_OpticRail_bnae: asdg_OpticRail1913
            {
            };
        };
    };
    class ItemCore;
    class InventoryMuzzleItem_Base_F;
    class bnae_suppressor_v2_base: ItemCore // ACE3 values: https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgWeapons.hpp#L643
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
            class MagazineCoef
            {
                initSpeed=1.0;
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.1;
                audibleFire=0.5;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef="0.95f";
                artilleryDispersionCoef="1.0f";
                fireLightCoef="0.5f";
                recoilCoef="0.95f";
                recoilProneCoef="0.95f";
                minRangeCoef="1.0f";
                minRangeProbabCoef="1.0f";
                midRangeCoef="1.0f";
                midRangeProbabCoef="1.0f";
                maxRangeCoef="1.0f";
                maxRangeProbabCoef="1.0f";
            };
        };
    };
    class bnae_suppressor_base: ItemCore // ACE3 values: https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgWeapons.hpp#L643
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
            class MagazineCoef
            {
                initSpeed=1.0;
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.1;
                audibleFire=0.5;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef="0.95f";
                artilleryDispersionCoef="1.0f";
                fireLightCoef="0.5f";
                recoilCoef="0.95f";
                recoilProneCoef="0.95f";
                minRangeCoef="1.0f";
                minRangeProbabCoef="1.0f";
                midRangeCoef="1.0f";
                midRangeProbabCoef="1.0f";
                maxRangeCoef="1.0f";
                maxRangeProbabCoef="1.0f";
            };
        };
    };
};
class CfgMagazines
{
    class CA_Magazine;
    class 30Rnd_762x39_Mag_F: CA_Magazine
    {
        initSpeed=719; // muzzle velocity according with the barrel length, default 730
    };
    class 30Rnd_762x39_Magazine: 30Rnd_762x39_Mag_F
    {
        ammo="B_762x39_Ball_F"; // AtragMx GunList "7.62x39mm", default ammo "B_762x51_Ball"
        initSpeed=719; // muzzle velocity according with the barrel length, default 730
    };
    class 30Rnd_762x39_Mag_Green_F: 30Rnd_762x39_Mag_F
    {
        initSpeed=719; // muzzle velocity according with the barrel length, default 730
    };
    class 30Rnd_762x39_Mag_Tracer_F: 30Rnd_762x39_Mag_F
    {
        initSpeed=719; // muzzle velocity according with the barrel length, default 730
    };
    class 30Rnd_762x39_Mag_Tracer_Green_F: 30Rnd_762x39_Mag_F
    {
        initSpeed=719; // muzzle velocity according with the barrel length, default 730
    };
};
class CfgAmmo
{
    class BulletBase;
    class B_762x39_Ball_F : BulletBase // https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L340
    {
        airFriction=-0.00154815;
        typicalSpeed=719; // muzzle velocity according with the barrel length
        ACE_caliber=7.823;
        ACE_bulletLength=28.956;
        ACE_bulletMass=7.9704;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.275}; // AtragMx G1 BC
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={719}; // muzzle velocity according with the barrel length
        ACE_barrelLengths[]={420};
    };
};
