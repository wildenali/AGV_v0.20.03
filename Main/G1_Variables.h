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

#define pinDigitalInput01 23  // DI01
#define pinDigitalInput02 24
#define pinDigitalInput03 25
#define pinDigitalInput04 26
#define pinDigitalInput05 27
#define pinDigitalOutput01 28
#define pinDigitalOutput02 29
#define pinDigitalOutput03 30
#define pinDigitalOutput04 31
#define pinDigitalOutput05 32


enum menu{F0=0, F1=1, F2=2, F3=3, F4=4, MENUIDLE=5, E=99} Menu;
enum tombol{tIDLE, tBACK, tNEXT, tGO, tCANCEL, tPLUS, tMINUS, tUP, tDOWN, tSAVE, tDELETE, tYES, tNO, tBACKSPACE, tPAUSE, tLOW, tHIGH, tPASSWORD, tCLEAR, tOK}Tombol;
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

//#define jumlahData   10
#define jumlahData   11
//int addressGnoKe[10+1]        = {137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147};
//int addressGnoKe[1+jumlahData]        = {1000,
//                                         1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010,
//                                         1011
//                                        };

//int addressGmodeKe[1+10]      = {148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158};
int addressGmodeKe[1+jumlahData]      = {2000,
                                         2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
                                         2011
                                        };

//int addressGtypeKe[1+10]      = {159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169};
int addressGtypeKe[1+jumlahData]      = {3000,
                                         3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010,
                                         3011
                                        };

//int addressGtriggerKe[1+10]   = {170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180};
int addressGtriggerKe[1+jumlahData]   = {4000,
                                         4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010,
                                         4011
                                        };

//int addressGactionKe[1+10]    = {181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191};
int addressGactionKe[1+jumlahData]    = {5000,
                                         5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010,
                                         5011
                                        };

//int addressGdummyIdRFID[11] = {27,  37,  47, 57, 67, 77, 87, 97, 107, 117, 127};
int addressGidRFID[1+jumlahData]      = {6000,
                                         6010, 6020, 6030, 6040, 6050, 6060, 6070, 6080, 6090, 6100,
                                         6011
                                        };

String dummyIdRFID[1+jumlahData];

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
unsigned int digitalInput[5] = {pinDigitalInput01, pinDigitalInput02, pinDigitalInput03, pinDigitalInput04, pinDigitalInput05};   // DI[5]
unsigned int digitalOutput[5] = {pinDigitalOutput01, pinDigitalOutput02, pinDigitalOutput03, pinDigitalOutput04, pinDigitalOutput05};   // DI[5]
uint32_t GdistSens[20];
uint32_t GminDistSens[20];







