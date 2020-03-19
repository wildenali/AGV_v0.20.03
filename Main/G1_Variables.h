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

enum menu{F0=0, F1=1, F2=2, F3=3, F4=4, MENUIDLE=5, E=99} Menu;
enum tombol{tIDLE, tBACK, tNEXT, tGO, tCANCEL, tPLUS, tMINUS, tUP, tDOWN, tSAVE, tDELETE, tYES, tNO, tBACKSPACE, tPAUSE, tLOW, tHIGH, tPASSWORD, tCLEAR, tOK}Tombol;
enum number{numIDLE, numF4ASpeed, numF4AAccel, numF4BGainP, numF4BGainI, numF4BGainD}Number;

uint32_t addressGspeed = 1;
uint32_t addressGaccel = 2;
uint32_t Gspeed;               // G for Global variable
uint32_t Gaccel;               // G for Global variable

uint32_t addressGgainP = 3;
uint32_t addressGgainI = 4;
uint32_t addressGgainD = 5;
uint32_t GgainP;
uint32_t GgainI;
uint32_t GgainD;

uint32_t addressGnoRefDist = 26;
uint32_t addressGrefDist = 27;
uint32_t GnoRefDist;
uint32_t GrefDist;

char bufferSensorLine[100] = {0};
int32_t GsensorLine;
