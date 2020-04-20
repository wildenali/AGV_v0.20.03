#include <EEPROM.h>
#include "Nextion.h"
#include "G_EEPROM_String.h"
#include "G1_Variables.h"
#include "G2_NextionParameters.h"
#include "SensorLine.h"
#include "RFID_Data.h"
#include "E.h"
#include "F0.h"
#include "F2.h"
#include "F3.h"
#include "F4.h"
#include "F1.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  nexInit();
  G2_NextionParameters();
  setupRFID_Data();
  
  pinMode(13, OUTPUT);

  Serial.println("Menu Utama");

  pinMode(22, INPUT_PULLUP);

  for(int i = 1; i < (sizeof(digitalInput) / sizeof(digitalInput[0])); i++)
  {
    pinMode(digitalInput[i], INPUT_PULLUP);
    stateDigitalInput[i] = 0;
    lastStateDigitalInput[i] = 0;
  }

  for(int i = 0; i < (sizeof(digitalOutput) / sizeof(digitalOutput[0])); i++)
  {
    pinMode(digitalOutput[i], OUTPUT);
    digitalWrite(digitalOutput[i], LOW);
  }

  resetData(false);
  dummyDataRFID(false);
  readDataRFID();
  readDataLogicSetting();
  contohData(false);

  Menu = E;


  for(int i = 0; i <= 10; i++){
    Serial.println(stringDI(i));
  }

//  int len_ID, len_DT;
//  String message = "";
//  String id, Data;
  
//  while(true){
//    Serial.print(stringDI(0));   Serial.print(" ");
//    Serial.print(stringDI(1));   Serial.print(" ");
//    Serial.print(stringDI(2));   Serial.print(" ");
//    Serial.print(stringDI(3));   Serial.print(" ");
//    Serial.print(stringDI(4));   Serial.print(" ");
//    Serial.print(stringDI(5));   Serial.print(" ");
//    Serial.print(stringDI(6));   Serial.print(" ");
//    Serial.print(stringDI(7));   Serial.print(" ");
//    Serial.print(stringDI(8));   Serial.print(" ");
//    Serial.print(stringDI(9));   Serial.print(" ");
//    Serial.print(stringDI(10));   Serial.print(" ");
////    len_ID = stringDI(1).indexOf(",");
////    len_DT = message.indexOf("#");
////    id = stringDI(1).substring(3,4); // parsing id
////    Data = message.substring(len_ID+1, len_DT); // parsing data
//
////    Serial.print(stringDI(1).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(2).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(3).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(4).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(5).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(6).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(7).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(8).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(9).substring(3,4));   Serial.print(" ");
////    Serial.print(stringDI(10).substring(3,4));  Serial.print(" ");
//
//    Serial.print(stringDI(1).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(2).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(3).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(4).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(5).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(6).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(7).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(8).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(9).substring(5,6));   Serial.print(" ");
//    Serial.print(stringDI(10).substring(5,6));  Serial.print(" ");
//
//    int coba = 2;
//    if(stringDI(1).substring(5,6) == "H"){
//      Serial.print("high NIH");
//    }
//    Serial.println();
//    
//    
//  }
//  while(true){
//    Serial.print(digitalRead(digitalInput[0]));   Serial.print(" ");
//    Serial.print(digitalRead(digitalInput[1]));   Serial.print(" ");
//    Serial.print(digitalRead(digitalInput[2]));   Serial.print(" ");
//    Serial.print(digitalRead(digitalInput[3]));   Serial.print(" ");
//    Serial.print(digitalRead(digitalInput[4]));   Serial.print("n");
//  }

}

void loop() {
  nexLoop(nex_listen_list_F0_MainMenu);
  Usb.Task();
//  if(scanFinished == true){
//    Serial.print("Panjang Data: ");   Serial.println(scanResult.length());
//    
//    scanResult = scanResult.substring(scanResult.length() - 10, scanResult.length());
//    Serial.print("Hasil       : ");   Serial.println(scanResult);
//    scanFinished = false;
//    scanResult = "";
//  }
//  if(scanRFID() == "85192051e4"){
//    Serial.println("YES");
//  }
//  Serial.println("Menu Utama");
  
  switch(Menu){
    case E:
      E_Password();
      break;
    case F0:
      F0_MainMenu();
      Menu = MENUIDLE;
      break;
    case F1:
      F1A_PlayMenu();
      break;
    case F2:
      F2A_LogicSet();
      break;
    case F3:
      F3A_RFID_Data();
      break;
    case F4:
      F4A_MachineSet();
      break;
    default:
      break;
  }
}
