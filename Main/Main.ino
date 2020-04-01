#include "Nextion.h"
#include "G1_Variables.h"
#include "G2_NextionParameters.h"
#include <EEPROM.h>
#include "G_EEPROM_String.h"
#include "SensorLine.h"
#include "RFID_Data.h"
#include "E.h"
#include "F0.h"
#include "F1.h"
#include "F2.h"
#include "F3.h"
#include "F4.h"




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  nexInit();
  G2_NextionParameters();
 
  pinMode(13, OUTPUT);

  Menu = E;
  Serial.println("Menu Utama");

  pinMode(22, INPUT_PULLUP);

  for(int i = 0; i < (sizeof(digitalInput) / sizeof(digitalInput[0])); i++)
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
  
  for(int i = 1; i < (sizeof(dummyIdRFID) / sizeof(dummyIdRFID[0])); i++)
  {
    dummyIdRFID[i] = EEPROM_readString(addressGdummyIdRFID[i]);
  }


//EEPROM.write(addressGnoKe[1],  1); EEPROM.write(addressGmodeKe[1],  1); EEPROM.write(addressGtypeKe[1],  1); EEPROM.write(addressGtriggerKe[1],  1);  EEPROM.write(addressGactionKe[1],  1);
//EEPROM.write(addressGnoKe[2],  2); EEPROM.write(addressGmodeKe[2],  2); EEPROM.write(addressGtypeKe[2],  1); EEPROM.write(addressGtriggerKe[2],  2);  EEPROM.write(addressGactionKe[2],  2);
//EEPROM.write(addressGnoKe[3],  3); EEPROM.write(addressGmodeKe[3],  3); EEPROM.write(addressGtypeKe[3],  2); EEPROM.write(addressGtriggerKe[3], 11);  EEPROM.write(addressGactionKe[3],  3);
//EEPROM.write(addressGnoKe[4],  4); EEPROM.write(addressGmodeKe[4],  4); EEPROM.write(addressGtypeKe[4],  2); EEPROM.write(addressGtriggerKe[4], 10);  EEPROM.write(addressGactionKe[4],  4);
//EEPROM.write(addressGnoKe[5],  5); EEPROM.write(addressGmodeKe[5],  5); EEPROM.write(addressGtypeKe[5],  3); EEPROM.write(addressGtriggerKe[5], 21);  EEPROM.write(addressGactionKe[5],  5);
//EEPROM.write(addressGnoKe[6],  6); EEPROM.write(addressGmodeKe[6],  1); EEPROM.write(addressGtypeKe[6],  1); EEPROM.write(addressGtriggerKe[6],  4);  EEPROM.write(addressGactionKe[6],  6);
//EEPROM.write(addressGnoKe[7],  7); EEPROM.write(addressGmodeKe[7],  2); EEPROM.write(addressGtypeKe[7],  1); EEPROM.write(addressGtriggerKe[7],  5);  EEPROM.write(addressGactionKe[7],  7);
//EEPROM.write(addressGnoKe[8],  8); EEPROM.write(addressGmodeKe[8],  3); EEPROM.write(addressGtypeKe[8],  2); EEPROM.write(addressGtriggerKe[8], 20);  EEPROM.write(addressGactionKe[8],  8);
//EEPROM.write(addressGnoKe[9],  9); EEPROM.write(addressGmodeKe[9],  4); EEPROM.write(addressGtypeKe[9],  3); EEPROM.write(addressGtriggerKe[9], 30);  EEPROM.write(addressGactionKe[9],  9);
//EEPROM.write(addressGnoKe[10], 10); EEPROM.write(addressGmodeKe[10], 5); EEPROM.write(addressGtypeKe[10], 3); EEPROM.write(addressGtriggerKe[10],41);  EEPROM.write(addressGactionKe[10], 1);
  
//  for(int i = 1; i < (sizeof(addressGnoKe) / sizeof(addressGnoKe[0])); i++)
//  {
//    noKe[i]     = EEPROM.read(addressGnoKe[i]);
//    modeKe[i]     = EEPROM.read(addressGmodeKe[i]);
//    typeKe[i]     = EEPROM.read(addressGtypeKe[i]);
//    triggerKe[i]  = EEPROM.read(addressGtriggerKe[i]);
//    actionKe[i]   = EEPROM.read(addressGactionKe[i]);
//
//    Serial.print(noKe[i]);        Serial.print("_");
//    Serial.print(modeKe[i]);        Serial.print("_");
//    Serial.print(typeKe[i]);        Serial.print("_");
//    Serial.print(triggerKe[i]);     Serial.print("_");
//    Serial.print(actionKe[i]);      Serial.print("\n");
//  }

  
  for(int i = 1; i < (sizeof(addressGnoKe) / sizeof(addressGnoKe[0])); i++)
  {
    noKe[i]       = 0;
    modeKe[i]     = 0;
    typeKe[i]     = 0;
    triggerKe[i]  = 0;
    actionKe[i]   = 0;

    Serial.print(noKe[i]);          Serial.print("_");
    Serial.print(modeKe[i]);        Serial.print("_");
    Serial.print(typeKe[i]);        Serial.print("_");
    Serial.print(triggerKe[i]);     Serial.print("_");
    Serial.print(actionKe[i]);      Serial.print("\n");
  }
  
  
}

void loop() {
  
  nexLoop(nex_listen_list_F0_MainMenu);  
//  Serial.println("Menu Utama");
//  Serial.println(Menu);

  
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


