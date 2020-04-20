//#include <SoftwareSerial.h>
/*
 * File yg di edit di nextion
 * NexConfig.h
 */
//SoftwareSerial LayarSerial(2, 3);// Nextion TX to pin 2 and RX to pin 3 of Arduino
//SoftwareSerial LayarSerial(10, 11); // Not all pins on the Mega and Mega 2560 support change interrupts, 
                                      // so only the following can be used for RX: 10, 11, 12, 13, 14, 15, 50, 51, 52, 53,
                                      // A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69).
                                      // Akhirnya pakai Serial2 saja, karena itu yg terbaik

#define pinDigitalInput22 22

#define pinDigitalInput01 23  // Coklat // DI01
#define pinDigitalInput02 24
#define pinDigitalInput03 25  // Merah
#define pinDigitalInput04 26
#define pinDigitalInput05 27  //Orange
#define pinDigitalOutput01 28
#define pinDigitalOutput02 29 // Kuning
#define pinDigitalOutput03 30
#define pinDigitalOutput04 31 // Hijau
#define pinDigitalOutput05 32

                              // A1 Ungu
                              // A2 Biru

enum menu{F0=0, F1=1, F2=2, F3=3, F4=4, MENUIDLE=5, E=99} Menu;
enum tombol{tIDLE, tBACK, tNEXT, tGO, tCANCEL, tPLUS, tMINUS, tUP, tDOWN, tSAVE, tDELETE, tYES, tNO, tBACKSPACE, tSTOP, tLOW, tHIGH, tPASSWORD, tCLEAR, tOK}Tombol;
enum number{numIDLE, numF4ASpeed, numF4AAccel, numF4BGainP, numF4BGainI, numF4BGainD}Number;
enum teks{teksIDLE, teksNo, teksMode, teksType, teksTrigger, teksAction}Teks;

#define typeIDLE  0
#define typeRFID  1
#define typeDI    2
#define typeDO    3

#define addressGspeed       1
#define addressGaccel       2
#define addressGgainP       3
#define addressGgainI       4
#define addressGgainD       5
#define addressGnoRefDist   6

int addressGminDistSens[20] = { 7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};    // maksimal nilai yang bisa dimasukan ke eeprom adalah 255, sedangkan untuk nilai address, bisa lebih dari 255, di coba di 2003 pun bisa

#define jumlahData   20   // dianjurkan di bawah 50 aja
//#define jumlahData   60   // di 60, mulai berasa lemot
//#define jumlahData   90   // maksimal 90, di 100, nge hang

int addressGidRFID[1+jumlahData]      = {60,
                                         61, 71, 81, 91, 101, 111, 121, 131, 141, 151,
                                         161, 171, 181, 191, 201, 211, 221, 231, 241, 251,
//                                         261, 271, 281, 291, 301, 311, 321, 331, 341, 351,
//                                         6301, 6311, 6321, 6331, 6341, 6351, 6361, 6371, 6381, 6391,
//                                         6401, 6411, 6421, 6431, 6441, 6451, 6461, 6471, 6481, 6491,
//                                         6501, 6511, 6521, 6531, 6541, 6551, 6561, 6571, 6581, 6591,
//                                         6601, 6611, 6621, 6631, 6641, 6651, 6661, 6671, 6681, 6691,
//                                         6701, 6711, 6721, 6731, 6741, 6751, 6761, 6771, 6781, 6791,
//                                         6801, 6811, 6821, 6831, 6841, 6851, 6861, 6871, 6881, 6891,
//                                         6901, 6911, 6921, 6931, 6941, 6951, 6961, 6971, 6981, 6991,
                                        };

int addressGmodeKe[1+jumlahData]      = {2000,
                                         2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
                                         2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020,
//                                         2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028, 2029, 2030,
//                                         2031, 2032, 2033, 2034, 2035, 2036, 2037, 2038, 2039, 2040,
//                                         2041, 2042, 2043, 2044, 2045, 2046, 2047, 2048, 2049, 2050,
//                                         2051, 2052, 2053, 2054, 2055, 2056, 2057, 2058, 2059, 2060,
//                                         2061, 2062, 2063, 2064, 2065, 2066, 2067, 2068, 2069, 2070,
//                                         2071, 2072, 2073, 2074, 2075, 2076, 2077, 2078, 2079, 2080,
//                                         2081, 2082, 2083, 2084, 2085, 2086, 2087, 2088, 2089, 2090,
//                                         2091, 2092, 2093, 2094, 2095, 2096, 2097, 2098, 2099, 2100,
                                        };

int addressGtypeKe[1+jumlahData]      = {3000,
                                         3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010,
                                         3011, 3012, 3013, 3014, 3015, 3016, 3017, 3018, 3019, 3020,
//                                         3021, 3022, 3023, 3024, 3025, 3026, 3027, 3028, 3029, 3030,
//                                         3031, 3032, 3033, 3034, 3035, 3036, 3037, 3038, 3039, 3040,
//                                         3041, 3042, 3043, 3044, 3045, 3046, 3047, 3048, 3049, 3050,
//                                         3051, 3052, 3053, 3054, 3055, 3056, 3057, 3058, 3059, 3060,
//                                         3061, 3062, 3063, 3064, 3065, 3066, 3067, 3068, 3069, 3070,
//                                         3071, 3072, 3073, 3074, 3075, 3076, 3077, 3078, 3079, 3080,
//                                         3081, 3082, 3083, 3084, 3085, 3086, 3087, 3088, 3089, 3090,
//                                         3091, 3092, 3093, 3094, 3095, 3096, 3097, 3098, 3099, 3100,
                                        };

int addressGtriggerKe[1+jumlahData]   = {4000,
                                         4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010,
                                         4011, 4012, 4013, 4014, 4015, 4016, 4017, 4018, 4019, 4020,
//                                         4021, 4022, 4023, 4024, 4025, 4026, 4027, 4028, 4029, 4030,
//                                         4031, 4032, 4033, 4034, 4035, 4036, 4037, 4038, 4039, 4040,
//                                         4041, 4042, 4043, 4044, 4045, 4046, 4047, 4048, 4049, 4050,
//                                         4051, 4052, 4053, 4054, 4055, 4056, 4057, 4058, 4059, 4060,
//                                         4061, 4062, 4063, 4064, 4065, 4066, 4067, 4068, 4069, 4070,
//                                         4071, 4072, 4073, 4074, 4075, 4076, 4077, 4078, 4079, 4080,
//                                         4081, 4082, 4083, 4084, 4085, 4086, 4087, 4088, 4089, 4090,
//                                         4091, 4092, 4093, 4094, 4095, 4096, 4097, 4098, 4099, 4100,
                                        };

int addressGactionKe[1+jumlahData]    = {5000,
                                         5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010,
                                         5011, 5012, 5013, 5014, 5015, 5016, 5017, 5018, 5019, 5020,
//                                         5021, 5022, 5023, 5024, 5025, 5026, 5027, 5028, 5029, 5030,
//                                         5031, 5032, 5033, 5034, 5035, 5036, 5037, 5038, 5039, 5040,
//                                         5041, 5042, 5043, 5044, 5045, 5046, 5047, 5048, 5049, 5050,
//                                         5051, 5052, 5053, 5054, 5055, 5056, 5057, 5058, 5059, 5060,
//                                         5061, 5062, 5063, 5064, 5065, 5066, 5067, 5068, 5069, 5070,
//                                         5071, 5072, 5073, 5074, 5075, 5076, 5077, 5078, 5079, 5080,
//                                         5081, 5082, 5083, 5084, 5085, 5086, 5087, 5088, 5089, 5090,
//                                         5091, 5092, 5093, 5094, 5095, 5096, 5097, 5098, 5099, 5100,
                                        };

//int addressGidRFID[1+jumlahData]      = {6000,
//                                         6001, 6011, 6021, 6031, 6041, 6051, 6061, 6071, 6081, 6091,
//                                         6101, 6111, 6121, 6131, 6141, 6151, 6161, 6171, 6181, 6191,
//                                         6201, 6211, 6221, 6231, 6241, 6251, 6261, 6271, 6281, 6291,
////                                         6301, 6311, 6321, 6331, 6341, 6351, 6361, 6371, 6381, 6391,
////                                         6401, 6411, 6421, 6431, 6441, 6451, 6461, 6471, 6481, 6491,
////                                         6501, 6511, 6521, 6531, 6541, 6551, 6561, 6571, 6581, 6591,
////                                         6601, 6611, 6621, 6631, 6641, 6651, 6661, 6671, 6681, 6691,
////                                         6701, 6711, 6721, 6731, 6741, 6751, 6761, 6771, 6781, 6791,
////                                         6801, 6811, 6821, 6831, 6841, 6851, 6861, 6871, 6881, 6891,
////                                         6901, 6911, 6921, 6931, 6941, 6951, 6961, 6971, 6981, 6991,
//                                        };


String idRFID[1+jumlahData];

int noID;

// kenapa pakai uint32_t karena untuk kebutuhan Nextion, dia butuh tipe data tersebut supaya bisa dikirim ke nextion
uint32_t Gspeed;               // G for Global variable
uint32_t Gaccel;               // G for Global variable
uint32_t GgainP;
uint32_t GgainI;
uint32_t GgainD;

int32_t  GnoRefDist;
bool stateDigitalInput[5];
bool lastStateDigitalInput[5];
unsigned int digitalInput[5+1] = {99, pinDigitalInput01, pinDigitalInput02, pinDigitalInput03, pinDigitalInput04, pinDigitalInput05};   // DI[5]      // 99 untuk buangaan, biar di awali dari 1 nanti pas di panggil klo butuh
unsigned int digitalOutput[5+1] = {99, pinDigitalOutput01, pinDigitalOutput02, pinDigitalOutput03, pinDigitalOutput04, pinDigitalOutput05};   // DI[5]
uint32_t GdistSens[20];
uint32_t GminDistSens[20];

uint32_t addressGmode = 0;
uint32_t Gmode;               // G for Global variable

bool LtexNo = false;
bool LtexMode = false;
bool LtexType = false;
bool LtexTrigger = false;
bool LtexAction = false;

int no;
int mode;
int type;
int trigger;
int action;

int modeKe[jumlahData+1];   // kenapa ada 10, karena maksimal data nya ada 10, 1 untuk buffer aja, biar dimulainya tidak dari 0 si array nya   
int typeKe[jumlahData+1];
int triggerKe[jumlahData+1];
int actionKe[jumlahData+1];

