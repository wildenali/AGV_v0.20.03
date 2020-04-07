#include "Nextion.h"
#include "G1_Variables.h"
#include "G2_NextionParameters.h"
#include <EEPROM.h>
#include "G_EEPROM_String.h"
#include "SensorLine.h"
#include "RFID_Data.h"
#include "E.h"
#include "F0.h"
//#include "F1.h"
#include "F2.h"
#include "F3.h"
#include "F4.h"
#include "F1.h"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  nexInit();
  G2_NextionParameters();
 
  pinMode(13, OUTPUT);

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

/*  // ====================== RESET DATA ======================
  for(int i = 0; i <= jumlahData ; i++){
    mode = 0;
    type = 0;
    trigger = 0;
    action = 0;
    EEPROM.write(addressGmodeKe[i], mode);
    EEPROM.write(addressGtypeKe[i], type);
    EEPROM.write(addressGtriggerKe[i], trigger);
    EEPROM.write(addressGactionKe[i], action);
    
//    EEPROM_writeString(addressGidRFID[i], "");
  }
*/  // ====================== RESET DATA ======================

/*  // =========== dummy id RFID untuk testing ===========
    idRFID[1]  = "2000000001";  idRFID[11] = "2000000011";  idRFID[21] = "2000000021";
    idRFID[2]  = "2000000002";  idRFID[12] = "2000000012";  idRFID[22] = "2000000022";
    idRFID[3]  = "2000000003";  idRFID[13] = "2000000013";  idRFID[23] = "2000000023";
    idRFID[4]  = "2000000004";  idRFID[14] = "2000000014";  idRFID[24] = "2000000024";
    idRFID[5]  = "2000000005";  idRFID[15] = "2000000015";  idRFID[25] = "2000000025";
    idRFID[6]  = "2000000006";  idRFID[16] = "2000000016";  idRFID[26] = "2000000026";
    idRFID[7]  = "2000000007";  idRFID[17] = "2000000017";  idRFID[27] = "2000000027";
    idRFID[8]  = "2000000008";  idRFID[18] = "2000000018";  idRFID[28] = "2000000028";
    idRFID[9]  = "2000000009";  idRFID[19] = "2000000019";  idRFID[29] = "2000000029";
    idRFID[10] = "2000000010";  idRFID[20] = "2000000020";  idRFID[30] = "2000000030";
    EEPROM_writeString(addressGidRFID[0], "0"); 
    for(int i = 1; i <= jumlahData; i++){
      EEPROM_writeString(addressGidRFID[i], idRFID[i]); 
    }
*/  // =========== dummy id RFID untuk testing ===========

  for(int i = 1; i < (sizeof(idRFID) / sizeof(idRFID[0])); i++)
  {
    idRFID[i] = EEPROM_readString(addressGidRFID[i]);
    Serial.println(idRFID[i]);
  }

// ====================== READ DATA ======================
  for(int i = 1; i <= jumlahData ; i++)
  {
    modeKe[i]     = EEPROM.read(addressGmodeKe[i]);
    typeKe[i]     = EEPROM.read(addressGtypeKe[i]);
    triggerKe[i]  = EEPROM.read(addressGtriggerKe[i]);
    actionKe[i]   = EEPROM.read(addressGactionKe[i]);

    Serial.print(i);                Serial.print("_");
    Serial.print(modeKe[i]);        Serial.print("_");
    Serial.print(typeKe[i]);        Serial.print("_");
    Serial.print(triggerKe[i]);     Serial.print("_");
    Serial.print(actionKe[i]);      Serial.print("\n");
  }
// ====================== READ DATA ======================

/*  // Contoh sampe data  
  for(int i = 1; i < (sizeof(addressGmodeKe) / sizeof(addressGmodeKe[0])); i++)//  for(int i = 1; i < (sizeof(addressGnoKe) / sizeof(addressGnoKe[0])); i++)
  {
    modeKe[i]     = 0;
    typeKe[i]     = 0;
    triggerKe[i]  = 0;
    actionKe[i]   = 0;
    
    Serial.print(i);                Serial.print("_");
    Serial.print(modeKe[i]);        Serial.print("_");
    Serial.print(typeKe[i]);        Serial.print("_");
    Serial.print(triggerKe[i]);     Serial.print("_");
    Serial.print(actionKe[i]);      Serial.print("\n");
  }
  // ============= CONTOH SAMPLE AJA ======================
  modeKe[1] = 1;
  modeKe[2] = 1;
  modeKe[3] = 1;
  modeKe[4] = 1;
  modeKe[5] = 1;
  modeKe[6] = 2;
  modeKe[7] = 2;
  modeKe[8] = 2;
  modeKe[9] = 0;
  modeKe[10] = 0;
  for(int i = 11; i <= jumlahData; i++){
    modeKe[i] = 0;
  }

  typeKe[1] = 1;
  typeKe[2] = 1;
  typeKe[3] = 2;
  typeKe[4] = 2;
  typeKe[5] = 3;
  typeKe[6] = 1;
  typeKe[7] = 1;
  typeKe[8] = 2;
  typeKe[9] = 0;
  typeKe[10] = 0;
  for(int i = 11; i <= jumlahData; i++){
    typeKe[i] = 0;
  }

  triggerKe[1] = 1;
  triggerKe[2] = 2;
  triggerKe[3] = 1;
  triggerKe[4] = 5;
  triggerKe[5] = 10;
  triggerKe[6] = 4;
  triggerKe[7] = 7;
  triggerKe[8] = 3;
  triggerKe[9] = 0;
  triggerKe[10] = 0;
  for(int i = 11; i <= jumlahData; i++){
    triggerKe[i] = 0;
  }

  actionKe[1] = 1;
  actionKe[2] = 2;
  actionKe[3] = 10;
  actionKe[4] = 15;
  actionKe[5] = 18;
  actionKe[6] = 5;
  actionKe[7] = 3;
  actionKe[8] = 7;
  actionKe[9] = 0;
  actionKe[10] = 0;
  for(int i = 11; i <= jumlahData; i++){
    actionKe[i] = 0;
  }
  // ============= CONTOH SAMPLE AJA ======================
*/

  Menu = E;

//  delay(3000);

}

void loop() {
  nexLoop(nex_listen_list_F0_MainMenu);  
  Serial.println("Menu Utama");
  
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


