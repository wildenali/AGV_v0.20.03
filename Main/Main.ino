#include "Nextion.h"
#include "G1_Variables.h"

#define DI01 23
#define DI02 24
#define DI03 25
#define DI04 26
#define DI05 27
int DI[5] = {23, 24, 25, 26, 27};
int buttonStateDI[5];         // current state of the button
int lastButtonStateDI[5];     // previous state of the button

uint32_t distSens[20];
uint32_t minDistSens[20];
uint32_t addressMinDistSens[20] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                                   40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50
                                  };




#include "G2_NextionParameters.h"
#include <EEPROM.h>
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
  Serial.println("Menu UtamaAA");

  pinMode(22, INPUT_PULLUP);

  for(int i = 0; i < (sizeof(DI) / sizeof(DI[0])); i++){
    pinMode(DI[i], INPUT_PULLUP);
    buttonStateDI[i] = 0;
    lastButtonStateDI[i] = 0;
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
