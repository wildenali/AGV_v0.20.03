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
enum tombol{tIDLE, tBACK, tNEXT, tGO, tCANCEL, tPLUS, tMINUS, tUP, tDOWN, tSAVE, tDELETE, tYES, tNO, tBACKSPACE, tPAUSE, tLOW, tHIGH, tPASSWORD, tCLEAR, tOK, tCHANGE}Tombol;
enum number{numIDLE, numF4ASpeed, numF4AAccel, numF4BGainP, numF4BGainI, numF4BGainD}Number;
enum teks{teksIDLE, teksNo, teksMode, teksType, teksTrigger, teksAction}Teks;

#define typeIDLE  0
#define typeRFID  1
#define typeDI    2
#define typeDO    3

uint32_t addressGspeed = 1;
uint32_t addressGaccel = 2;
uint32_t addressGgainP = 3;
uint32_t addressGgainI = 4;
uint32_t addressGgainD = 5;
uint32_t addressGnoRefDist = 6;
uint32_t addressGminDistSens[20] = { 7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};    // maksimal nilai yang bisa dimasukan ke eeprom adalah 255, sedangkan untuk nilai address, bisa lebih dari 255, di coba di 2003 pun bisa

//uint32_t addressCOBA[10] = {41,  51,  61, 71, 81, 91, 101, 111, 121, 13}; // kenapa dilewatin sepuluh, karena itu untuk menyimpan data string si rfid nya
int noID;
String dummyIdRFID[11];
uint32_t addressGdummyIdRFID[11] = {27,  37,  47, 57, 67, 77, 87, 97, 107, 117, 127};



uint32_t addressGnoKe[11]     = {137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147};
uint32_t addressGmodeKe[11]     = {148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158};
uint32_t addressGtypeKe[11]     = {159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169};
uint32_t addressGtriggerKe[11]  = {170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180};
uint32_t addressGactionKe[11]   = {181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191};



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







