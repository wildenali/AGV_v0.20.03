#include "Nextion.h"
#include "G1_Variables.h"
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
