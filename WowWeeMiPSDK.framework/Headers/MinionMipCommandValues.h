//
//  MinionMipCommandValues.h
//  minionmip-cocos2d
//
//  Created by Alex Lam on 15/2/2017.
//
//

#import "MipRobot.h"

typedef NS_OPTIONS(uint8_t, kMinionCommand) {
    kMinionPlayBodycon = 0x76, //Byte1:Bodycon numbers(0~106) with MinionMipBodycon_2017_02_09_16_56_58.c
    
    kMinionGet570LdromApromStatus = 0x90, /* return
                                           BYTE 1 : 0x01:570 in LDROM
                                           0x02:570 in APROM
                                           BYTE 2 : 0x01:570 Aprom Code Correct
                                           0x02:570 Aprom Flag Error
                                           0x03:570 Aprom Crc Error
                                           BYTE 3 : 0x00:Voice is reliable in SPI flash
                                           0x01:Voice is unreliable in SPI flash
                                           (BYTE 4,BYTE5): Voice file Version 0xNNNN(First one is 0x0000)
                                           BYTE 6 : voice chip LDROM version
                                           BYTE 7 : voice chip APROM version*/
    
    kMinionGetIMUDevice = 0x92, /* return
                                 BYTE 1 : 0x01: MPU-6880
                                 0x02: ICM-20618
                                 0x00: IMU error
                                 */
    
    kMinionGetVoiceFileCRCValue = 0x93, // (BYTE 1,BYTE2): Voice file CRC value
    
    kMinionSetLowPowerWarningLevel = 0x94, /*
                                            BYTE 1: 0x47(3.7V),0x49(3.8V),0x4B(3.9V),0x4D(4.0V),0x4F(4.1V),0x51(4.2V),0x53(4.3V),0x55(4.4V),0x57(4.5V),0x59(4.6V),0x5B(4.7V),0x5D(4.8V),0x5F(4.9V),0x60(5.0V),0x62(5.1V),0x64(5.2V),0x66(5.3V),0x68(5.4V),0x6A(5.5V),0x6C(5.6V),0x6E(5.7V),0x70(5.8V),0x72(5.9V),0x74(6.0V),0x76(6.1V),0x78(6.2V),0x7A(6.3V),0x7C(6.4V)
                                            Default value is "0x55(4.4V)" and 0x47(3.7V)~0x64(5.2V) is valid
                                            */
    kMinionGetLowPowerWarningLevel = 0x95,
    
    kMinionSetM051Reset = 0x96, /*
                                 Byte1:
                                 0x01--reset to LDROM
                                 0x02--reset to APROM
                                 */
    
//    kGetMinionMipVersion = 0x97, /*
//                                  BYTE 1: Hardware Version
//                                  BYTE 2: Year (software ver) of Balance IC Aprom
//                                  BYTE 3: Month (software ver) of Balance IC Aprom
//                                  BYTE 4: Day (software ver) of Balance IC Aprom
//                                  BYTE 5: Unique Version # of Balance IC Aprom
//                                  BYTE 6 : 0x00:Voice is reliable in SPI flash
//                                  0x01:Voice is unreliable in SPI flash
//                                  BYTE 7 : 0x01:570 in LDROM
//                                  0x02:570 in APROM
//                                  BYTE 8 : 0x01:570 Aprom Code Correct
//                                  0x02:570 Aprom Flag Error
//                                  0x03:570 Aprom Crc Error
//                                  BYTE 9 : voice chip LDROM version
//                                  BYTE 10 : voice chip APROM version
//                                  BYTE 11,BYTE12: Voice file CRC value
//                                  */
};

typedef NS_OPTIONS(uint8_t, kMinionIMUDeviceValue) {
    kMinionIMUDevice_MPU6880 = 0x01,
    kMinionIMUDevice_ICM20618 = 0x02,
    kMinionIMUDevice_IMU_ERROR = 0x00
};

typedef NS_OPTIONS(uint8_t, kMinionM051ResetValue) {
    kMinionM051Reset_LDROM = 0x01,
    kMinionM051Reset_APROM = 0x02
};

typedef NS_OPTIONS(uint8_t, kMinion570StatusValue) {
    kMinion570StatusInLdrom = 0x01,
    kMinion570StatusInAprom = 0x02
};

typedef NS_OPTIONS(uint8_t, kMinion570ApromStatusValue) {
    kMinion570ApromStatus_CodeCorrect = 0x01,
    kMinion570ApromStatus_FlagError = 0x02,
    kMinion570ApromStatus_CrcError = 0x03
};

typedef NS_OPTIONS(uint8_t, kMinionLowPowerWarningLevelValue) {
    kMinionLowPowerWarningLevel_3_7V = 0x47,
    kMinionLowPowerWarningLevel_3_8V = 0x49,
    kMinionLowPowerWarningLevel_3_9V = 0x4B,
    kMinionLowPowerWarningLevel_4_0V = 0x4D,
    kMinionLowPowerWarningLevel_4_1V = 0x4F,
    kMinionLowPowerWarningLevel_4_2V = 0x51,
    kMinionLowPowerWarningLevel_4_3V = 0x53,
    kMinionLowPowerWarningLevel_4_4V = 0x55,
    kMinionLowPowerWarningLevel_4_5V = 0x57,
    kMinionLowPowerWarningLevel_4_6V = 0x59,
    kMinionLowPowerWarningLevel_4_7V = 0x5B,
    kMinionLowPowerWarningLevel_4_8V = 0x5D,
    kMinionLowPowerWarningLevel_4_9V = 0x5F,
    kMinionLowPowerWarningLevel_5_0V = 0x60,
    kMinionLowPowerWarningLevel_5_1V = 0x62,
    kMinionLowPowerWarningLevel_5_2V = 0x64,
    kMinionLowPowerWarningLevel_5_3V = 0x66,
    kMinionLowPowerWarningLevel_5_4V = 0x68,
    kMinionLowPowerWarningLevel_5_5V = 0x6A,
    kMinionLowPowerWarningLevel_5_6V = 0x6C,
    kMinionLowPowerWarningLevel_5_7V = 0x6E,
    kMinionLowPowerWarningLevel_5_8V = 0x70,
    kMinionLowPowerWarningLevel_5_9V = 0x72,
    kMinionLowPowerWarningLevel_6_0V = 0x74,
    kMinionLowPowerWarningLevel_6_1V = 0x76,
    kMinionLowPowerWarningLevel_6_2V = 0x78,
    kMinionLowPowerWarningLevel_6_3V = 0x7A,
    kMinionLowPowerWarningLevel_6_4V = 0x7C
};

typedef NS_OPTIONS(uint8_t, kMinionMipSoundFileValue) {
    kMinionMipSoundFile_ONEKHZ_500MS_8K16BIT                                         = 0,
    kMinionMipSoundFile_NO0ZERO                                                      = 1,
    kMinionMipSoundFile_NO1ONE                                                       = 2,
    kMinionMipSoundFile_NO2TWO                                                       = 3,
    kMinionMipSoundFile_NO3THREE                                                     = 4,
    kMinionMipSoundFile_NO4FOUR                                                      = 5,
    kMinionMipSoundFile_NO5FIVE                                                      = 6,
    kMinionMipSoundFile_NO6SIX                                                       = 7,
    kMinionMipSoundFile_NO7SEVEN                                                     = 8,
    kMinionMipSoundFile_NO8EIGHT                                                     = 9,
    kMinionMipSoundFile_NO9NIGHT                                                     = 10,
    kMinionMipSoundFile_NOTEN                                                        = 11,
    kMinionMipSoundFile_ANGRY_STUART_DIAL_042_GROWL_LO_SI_POLATA                     = 12,
    kMinionMipSoundFile_ANGRY_STUART_DIAL_043_GROWLING_THEN_LAUGHING                 = 13,
    kMinionMipSoundFile_ANGRY_STUART_DIAL_075_MACURISTO_BAAH_CUSSING                 = 14,
    kMinionMipSoundFile_ANGRY_STUART_SCREAMS_016_WHAAA_BLUMOCK                       = 15,
    kMinionMipSoundFile_HAPPY_DMF_GIGGLES                                            = 16,
    kMinionMipSoundFile_HAPPY_DMF_MINION_HEH_HEH_BELLO                               = 17,
    kMinionMipSoundFile_HAPPY_DMF_MINION_LAUGHING_HYSTERICALLY_DM2                   = 18,
    kMinionMipSoundFile_HAPPY_DMF_MINION_LAUGHS_DM2                                  = 19,
    kMinionMipSoundFile_HAPPY_DMF_MINION_REACTS_TO_GOLF_BALL_BABBLE_DM2              = 20,
    kMinionMipSoundFile_HAPPY_DMF_MINION_RELAXES_DM2                                 = 21,
    kMinionMipSoundFile_HAPPY_DMF_MINION_WOO_HOO_DM1                                 = 22,
    kMinionMipSoundFile_HAPPY_KEVIN_DIAL_048_CUMBAYA                                 = 23,
    kMinionMipSoundFile_HAPPY_KEVIN_DIAL_095_LAUGH_EN_CHE_LE_UN_LA_BOSS              = 24,
    kMinionMipSoundFile_HAPPY_KEVIN_DIAL_096_LAUGH_TOCARINA_BOCALOO                  = 25,
    kMinionMipSoundFile_HAPPY_KEVIN_DIAL_097_LAUGH_HEY_BUDDIES                       = 26,
    kMinionMipSoundFile_HAPPY_KEVIN_DIAL_116_OH_NO_ME_LE_DO_IT                       = 27,
    kMinionMipSoundFile_HAPPY_KEVIN_LAUGHING_003_HA_HA_HA_HA_HA_HA                   = 28,
    kMinionMipSoundFile_HAPPY_KEVIN_LAUGHING_008_LA_BUGEE                            = 29,
    kMinionMipSoundFile_HAPPY_KEVIN_LAUGHING_013_STIFLED_AT_FIRST                    = 30,
    kMinionMipSoundFile_HAPPY_KEVIN_REACTION_042_WOOO_HO_HO                          = 31,
    kMinionMipSoundFile_HAPPY_KEVIN_REACTION_045_YES_HA_HA                           = 32,
    kMinionMipSoundFile_HAPPY_STUART_DIAL_007_AH_HA_HA_PATEL                         = 33,
    kMinionMipSoundFile_HAPPY_STUART_DIAL_027_BRAVO_BRAVO                            = 34,
    kMinionMipSoundFile_HAPPY_STUART_DIAL_046_HE_HA_HA_WOO_HOO                       = 35,
    kMinionMipSoundFile_HAPPY_STUART_DIAL_120_WOO_HOO_LA_FRITA_PA_TA_KEYS            = 36,
    kMinionMipSoundFile_HAPPY_STUART_LAUGHING_003_MOCKING                            = 37,
    kMinionMipSoundFile_HAPPY_STUART_LAUGHING_006_AH_HA_HA                           = 38,
    kMinionMipSoundFile_HAPPY_STUART_LAUGHING_013_HA_HA_HA_DIALGOUE                  = 39,
    kMinionMipSoundFile_HAPPY_STUART_LAUGHING_015_LONG                               = 40,
    kMinionMipSoundFile_HAPPY_STUART_LAUGHING_019_THEN_TRAILS_OFF                    = 41,
    kMinionMipSoundFile_HAPPY_STUART_REACTION_002_OH_HA_HA_HA                        = 42,
    kMinionMipSoundFile_HAPPY_STUART_REACTION_012_HA_HA_HA_HA_YEAA                   = 43,
    kMinionMipSoundFile_HAPPY_STUART_REACTION_043_YEAHHHH_WOO_HOO_HOO                = 44,
    kMinionMipSoundFile_JOKES_DMF_MINION_IDIOT_LAUGHS_DM1                            = 45,
    kMinionMipSoundFile_JOKES_DMF_MINION_MAKING_KISSING_SOUNDS_DM1_SHORT             = 46,
    kMinionMipSoundFile_JOKES_DMF_PAPADUM_EH                                         = 47,
    kMinionMipSoundFile_JOKES_DMF_UH_HAH_HAH_BLOWS_AIR                               = 48,
    kMinionMipSoundFile_JOKES_STUART_EFFORTS_008_DIAL_LE_BUTT                        = 49,
    kMinionMipSoundFile_SAD_DMF_MINION_INJECTED_DM2                                  = 50,
    kMinionMipSoundFile_SAD_DMF_MINION_RELAXED_SIGH_DM2                              = 51,
    kMinionMipSoundFile_SAD_STUART_DIAL_022_BLUMMOCK                                 = 52,
    kMinionMipSoundFile_SAD_STUART_DIAL_033_DEPRESSED_RAMBLING                       = 53,
    kMinionMipSoundFile_SAD_STUART_DIAL_078_MOCALE                                   = 54,
    kMinionMipSoundFile_SAD_STUART_DIAL_104_PROFITORAL_MUMBLING                      = 55,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_ALMOST_FALLS_DM1                          = 56,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_CRUSHED_DM1                               = 57,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_CRYING_DM2                                = 58,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_FALLING_DM2                               = 59,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_FIGHTING_SOUNDS_DM2                       = 60,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_IN_VIBRATING_CHAIR_DM1                    = 61,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_LONG_SCREAM_WHEN_WHIPED_DM2               = 62,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_SCREAMS_DM2                               = 63,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_SCREAMS_INTO_TRASH_CAN_DM2                = 64,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_SCREAMS_SEING_GRU_CAPTURED_DM2            = 65,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_SCREAMS_SHORT_DM2_POS_TEMP                = 66,
    kMinionMipSoundFile_SCREAMS_DMF_MINION_STUGGLES_WITH_DUCK_DM2                    = 67,
    kMinionMipSoundFile_SCREAMS_DMF_STOP_STOP_HEY_HO                                 = 68,
    kMinionMipSoundFile_SCREAMS_DMF_SUCKED_INTO_OCEAN                                = 69,
    kMinionMipSoundFile_SCREAMS_STUART_EFFORTS_EH_OH_AHHHH                           = 70,
    kMinionMipSoundFile_SING_DMF_BEE_DO_CLEAN                                        = 71,
    kMinionMipSoundFile_SING_DMF_MINION_HUMMING_1_DM1                                = 72,
    kMinionMipSoundFile_SING_DMF_MINION_HUMMING_2_DM1                                = 73,
    kMinionMipSoundFile_SING_DMF_MINION_SINGING_2_MAID                               = 74,
    kMinionMipSoundFile_SING_DMF_MINION_SINGING_FRUIT                                = 75,
    kMinionMipSoundFile_SING_DMF_MINION_SINGS_GO_TO_SLEEP_TEMP_DM2                   = 76,
    kMinionMipSoundFile_SING_DMF_MINION_SINIGING_BELLA                               = 77,
    kMinionMipSoundFile_SING_DMF_MINION_TRIBAL_DANCE_SONG_DM2                        = 78,
    kMinionMipSoundFile_SING_KEVIN_SINGING_INDIAN_CHANT                              = 79,
    kMinionMipSoundFile_SING_KEVIN_SINGING_KUKA_CHOW_KUKA_CHOW                       = 80,
    kMinionMipSoundFile_SING_KEVIN_SINGING_OPERATIC                                  = 81,
    kMinionMipSoundFile_SING_STUART_SINGING_LA_LA_LA_LA                              = 82,
    kMinionMipSoundFile_SPEECH_L_DMF_MINION_EXERCISING_DM1                           = 83,
    kMinionMipSoundFile_SPEECH_L_DMF_MINION_GETTING_SOMEONES_ATTENTION_DM1           = 84,
    kMinionMipSoundFile_SPEECH_L_DMF_MINION_JABBER_DM2                               = 85,
    kMinionMipSoundFile_SPEECH_L_DMF_MINION_MAKING_SHADOW_PUPPET_IAMGRU_DM1          = 86,
    kMinionMipSoundFile_SPEECH_L_DMF_MINION_MAKING_TOAST_DM2                         = 87,
    kMinionMipSoundFile_SPEECH_L_DMF_MINION_SWINGING_CLUB_DM2                        = 88,
    kMinionMipSoundFile_SPEECH_L_DMF_PUPOI_1_TOY                                     = 89,
    kMinionMipSoundFile_SPEECH_L_STUART_DIAL_041_FLIRTING_WITH_FIRE_HYDRANT          = 90,
    kMinionMipSoundFile_SPEECH_S_DIAL_021_BELLO                                      = 91,
    kMinionMipSoundFile_SPEECH_S_DIAL_048_HELLO                                      = 92,
    kMinionMipSoundFile_SPEECH_S_DIAL_063_HUH                                        = 93,
    kMinionMipSoundFile_SPEECH_S_DIAL_073_LAUGH_THANK_YOU                            = 94,
    kMinionMipSoundFile_SPEECH_S_DIAL_091_OK_OK                                      = 95,
    kMinionMipSoundFile_SPEECH_S_DIAL_092_OK_POLATACA                                = 96,
    kMinionMipSoundFile_SPEECH_S_DIAL_094_OKAY                                       = 97,
    kMinionMipSoundFile_SPEECH_S_DIAL_112_SI_SI_LA_MATACO                            = 98,
    kMinionMipSoundFile_SPEECH_S_DIAL_115_THANK_YOU_LAPORTA_THANK_YOU                = 99,
    kMinionMipSoundFile_SPEECH_S_DMF_AHH_GOOQUAH                                     = 100,
    kMinionMipSoundFile_SPEECH_S_DMF_BACAFOOT                                        = 101,
    kMinionMipSoundFile_SPEECH_S_DMF_BAPPLE                                          = 102,
    kMinionMipSoundFile_SPEECH_S_DMF_GEKO                                            = 103,
    kMinionMipSoundFile_SPEECH_S_DMF_GROWL_FOR_LUCY                                  = 104,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_21_GUN_SALUTE_DM2                        = 105,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_AHHH_NO_DM2                              = 106,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_AWWW_DM2                                 = 107,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_BABBLE_READY_DM2                         = 108,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_EHHH_PPPPP_DM1                           = 109,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_GOLF_KARATE_SOUND_DM2                    = 110,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_HELLO                                    = 111,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_MAKES_DUCK_SOUND_DM2                     = 112,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_MM_HMM_YES_DM2                           = 113,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_OKAY_OKAY_DM1                            = 114,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_RELAXES_AND_WAVES_DM2                    = 115,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_TALKING_OFFERING_PAPOY_DM1               = 116,
    kMinionMipSoundFile_SPEECH_S_DMF_MINION_VOILA_DM2_TEMP_DM2                       = 117,
    kMinionMipSoundFile_SPEECH_S_DMF_MOCA                                            = 118,
    kMinionMipSoundFile_SPEECH_S_DMF_PUTT_PUTT                                       = 119,
    kMinionMipSoundFile_SPEECH_S_DMF_UH                                              = 120,
    kMinionMipSoundFile_SPEECH_S_DMF_UHH                                             = 121,
    kMinionMipSoundFile_SPEECH_S_KEVIN_DIAL_018_BANANA                               = 122,
    kMinionMipSoundFile_SPEECH_S_KEVIN_DIAL_063_HA_BELLO                             = 123,
    kMinionMipSoundFile_SPEECH_S_KEVIN_DIAL_125_OOH_BATA_ME_HA_HA                    = 124,
    kMinionMipSoundFile_SPEECH_S_KEVIN_DIAL_181_YOU_GO_THAT_WAY_I_GO_THIS_WAY        = 125,
    kMinionMipSoundFile_SPEECH_S_KEVIN_SINGING_001_BIG_BOSS_BIG_BOSS                 = 126,
    kMinionMipSoundFile_SPEECH_S_REACTION_018_HUH                                    = 127,
    kMinionMipSoundFile_SPEECH_S_REACTION_042_YEAH_YEAH_OOH_OOH                      = 128,
    kMinionMipSoundFile_SPEECH_S_STUART_DIAL_005_AH_MANATONITO_PORA_MUR              = 129,
    kMinionMipSoundFile_SPEECH_S_STUART_DIAL_008_AH_MI_MALA_TIKA_A_TU_NI             = 130,
    kMinionMipSoundFile_SPEECH_S_STUART_DIAL_011_AH_SI                               = 131,
    kMinionMipSoundFile_SPEECH_S_STUART_DIAL_083_NO_LE_ME_DO_IT_SPETA                = 132,
    kMinionMipSoundFile_SPEECH_S_STUART_DIAL_101_PONYA_BURRITO_MACARA_DOH            = 133,
    kMinionMipSoundFile_NEW_FART_2                                                   = 134,
    kMinionMipSoundFile_NEW_FART_9                                                   = 135,
    kMinionMipSoundFile_NEW_FART_10                                                  = 136,
    kMinionMipSoundFile_NEW_FART_11                                                  = 137,
    kMinionMipSoundFile_NEW_FART_19                                                  = 138,
    kMinionMipSoundFile_NEW_FART_21                                                  = 139,
    kMinionMipSoundFile_NEW_FART_SQUEAK_4                                            = 140,
    kMinionMipSoundFile_NEW_FART_WET                                                 = 141,
    kMinionMipSoundFile_NEW_SING_DM3_MAJOR_GENERAL_SHORT                             = 142,
    kMinionMipSoundFile_NEW_CHARACTER_FART_01                                        = 143,
    kMinionMipSoundFile_NEW_CREAKY_FART_02                                           = 144
};

static const uint8_t BroadcastDataKey_MinionAvatarValue = 0x01;
static const uint8_t BroadcastDataKey_MinionHPValue = 0x02;


@interface MinionMipCommandValues : NSObject

@end
