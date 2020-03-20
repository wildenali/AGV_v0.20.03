#include "Nextion.h"
#include "G1_Variables.h"

#define pinDigitalInput22 22
#define pinDigitalInput01 23  // DI01
#define pinDigitalInput02 24
#define pinDigitalInput03 25
#define pinDigitalInput04 26
#define pinDigitalInput05 27
unsigned int digitalInput[5] = {pinDigitalInput01, pinDigitalInput02, pinDigitalInput03, pinDigitalInput04, pinDigitalInput05};   // DI[5]
bool stateDigitalInput[5];                         // buttonStateDI[5];
bool lastStateDigitalInput[5];                     // lastButtonStateDI[5];

#define pinDigitalOutput01 28
#define pinDigitalOutput02 29
#define pinDigitalOutput03 30
#define pinDigitalOutput04 31
#define pinDigitalOutput05 32
unsigned int digitalOutput[5] = {pinDigitalOutput01, pinDigitalOutput02, pinDigitalOutput03, pinDigitalOutput04, pinDigitalOutput05};   // DI[5]


uint32_t distSens[20];
uint32_t minDistSens[20];
uint32_t addressMinDistSens[20] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                                   40, 41, 42, 43, 44, 45, 46, 47, 48, 49
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

  for(int i = 0; i < (sizeof(digitalInput) / sizeof(digitalInput[0])); i++){
    pinMode(digitalInput[i], INPUT_PULLUP);
    stateDigitalInput[i] = 0;
    lastStateDigitalInput[i] = 0;
  }

  for(int i = 0; i < (sizeof(digitalOutput) / sizeof(digitalOutput[0])); i++){
    pinMode(digitalOutput[i], OUTPUT);
    digitalWrite(digitalOutput[i], LOW);
  }

  
  // ini masih dummy pembatasan minimal sensor jarak
  for(int i = 0; i < (sizeof(distSens) / sizeof(distSens[0])); i++){
    minDistSens[i] = 200;
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
