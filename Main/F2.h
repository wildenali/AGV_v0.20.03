void F2A_LogicSet();
void F2B_LogicSet();

// ========== Mode ==========
// 1, 2, 3 dan seterusnya

// ========== type ==========
// 1 > RFID
// 2 > DI (Digital Input)
// 3 > DO (Digital Output)

// ========== Action ==========
// 1 > Berhenti
// 2 > Maju
// 3 > Belok Kiri
// 4 > Belok Kanan
// 5 > Balik Kiri
// 6 > Balik Kanan
// 7 > Lift On
// 8 > Lift Off
// 9 > DOut

void NoF2A(int noA, int noB, int noC, int noD, int noE);
void ModeF2A(int modeA, int modeB, int modeC, int modeD, int modeE);
void TypeF2A(int typeA, int typeB, int typeC, int typeD, int typeE);
void TriggerF2A(int triggerA, int triggerB, int triggerC, int triggerD, int triggerE);
void ActionF2A(int actionA, int actionB, int actionC, int actionD, int actionE);

void NoF2B(String no);
void ModeF2B(String mode);
void TypeF2B(String type);
void TriggerF2B(String trigger);
void ActionF2B(String action);

void pilihTriggerDown();
void pilihTriggerUp();
void pilihChangeTriggerDIDO();
void pilihChangeActionDIDO();

  bool LtexNo = false;
  bool LtexMode = false;
  bool LtexType = false;
  bool LtexTrigger = false;
  bool LtexAction = false;  
  void pilihTeks();

  int pinBerapa = 1;
  bool pinBerapaStatus = HIGH;

  int no;
  int mode;
  int type;
  int trigger;
  int action;

  int noKe[11];
  int modeKe[11];
  int typeKe[11];
  int triggerKe[11];
  int actionKe[11];

        
void F2A_LogicSet(){
  pageF2A.show();
  Serial.println("F2A_LogicSet");
  
  
  int noA = 1;
  int noB = 2;
  int noC = 3;
  int noD = 4;
  int noE = 5;
  
  int modeA = 1;
  int modeB = 1;
  int modeC = 1;
  int modeD = 1;
  int modeE = 1;
  
  int typeA = 1;
  int typeB = 1;
  int typeC = 1;
  int typeD = 1;
  int typeE = 1;

  int triggerA = 1;
  int triggerB = 2;
  int triggerC = 3;
  int triggerD = 10;
  int triggerE = 21;

  int actionA = 1;
  int actionB = 2;
  int actionC = 3;
  int actionD = 4;
  int actionE = 5;
  
//  NoF2A(noA, noB, noC, noD, noE);
//  ModeF2A(modeA, modeB, modeC, modeD, modeE);
//  TypeF2A(typeA, typeB, typeC, typeD, typeE);
//  TriggerF2A(triggerA, triggerB, triggerC, triggerD, triggerE);
//  ActionF2A(actionA, actionB, actionC, actionD, actionE);

//  noKe[i]
//  modeKe[i]
//  typeKe[i]
//  triggerKe[i]
//  actionKe[i]
  NoF2A(noKe[1], noKe[2], noKe[3], noKe[4], noKe[5]);
  ModeF2A(modeKe[1], modeKe[2], modeKe[3], modeKe[4], modeKe[5]);
  TypeF2A(typeKe[1], typeKe[2], typeKe[3], typeKe[4], typeKe[5]);
  TriggerF2A(triggerKe[1], triggerKe[2], triggerKe[3], triggerKe[4], triggerKe[5]);
  ActionF2A(actionKe[1], actionKe[2], actionKe[3], actionKe[4], actionKe[5]);
  
  
  while(true){
    nexLoop(nex_listen_list_F2A_LogicSet);
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF2ABack");
        Menu = F0;
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF2ANext");
        F2B_LogicSet();
        pageF2A.show();
        Serial.println("F2A_LogicSet");
        
        NoF2A(noA, noB, noC, noD, noE);
        ModeF2A(modeA, modeB, modeC, modeD, modeE);
        TypeF2A(typeA, typeB, typeC, typeD, typeE);
        TriggerF2A(triggerA, triggerB, triggerC, triggerD, triggerE);
        ActionF2A(actionA, actionB, actionC, actionD, actionE);
        
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2ADown");

        noA++;        if(noA >= 16)       noA = 16;
        noB++;        if(noB >= 17)       noB = 17;
        noC++;        if(noC >= 18)       noC = 18;
        noD++;        if(noD >= 19)       noD = 19;
        noE++;        if(noE >= 20)       noE = 20;
        modeA++;      if(modeA >= 16)     modeA = 16;
        modeB++;      if(modeB >= 17)     modeB = 17;
        modeC++;      if(modeC >= 18)     modeC = 18;
        modeD++;      if(modeD >= 19)     modeD = 19;
        modeE++;      if(modeE >= 20)     modeE = 20;
        typeA++;      if(typeA >= 16)     typeA = 16;
        typeB++;      if(typeB >= 17)     typeB = 17;
        typeC++;      if(typeC >= 18)     typeC = 18;
        typeD++;      if(typeD >= 19)     typeD = 19;
        typeE++;      if(typeE >= 20)     typeE = 20;
        triggerA++;   if(triggerA >= 116) triggerA = 116;
        triggerB++;   if(triggerB >= 117) triggerB = 117;
        triggerC++;   if(triggerC >= 118) triggerC = 118;
        triggerD++;   if(triggerD >= 119) triggerD = 119;
        triggerE++;   if(triggerE >= 120) triggerE = 120;
        actionA++;    if(actionA >= 16)   actionA = 16;
        actionB++;    if(actionB >= 17)   actionB = 17;
        actionC++;    if(actionC >= 18)   actionC = 18;
        actionD++;    if(actionD >= 19)   actionD = 19;
        actionE++;    if(actionE >= 20)   actionE = 20;
        NoF2A(noA, noB, noC, noD, noE);
        ModeF2A(modeA, modeB, modeC, modeD, modeE);
        TypeF2A(typeA, typeB, typeC, typeD, typeE);
        TriggerF2A(triggerA, triggerB, triggerC, triggerD, triggerE);
        ActionF2A(actionA, actionB, actionC, actionD, actionE);
        
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2AUp");
        
        noA--;        if(noA <= 1) noA = 1;
        noB--;        if(noB <= 2) noB = 2;
        noC--;        if(noC <= 3) noC = 3;
        noD--;        if(noD <= 4) noD = 4;
        noE--;        if(noE <= 5) noE = 5;
        modeA--;      if(modeA <= 1) modeA = 1;
        modeB--;      if(modeB <= 2) modeB = 2;
        modeC--;      if(modeC <= 3) modeC = 3;
        modeD--;      if(modeD <= 4) modeD = 4;
        modeE--;      if(modeE <= 5) modeE = 5;
        typeA--;      if(typeA <= 1) typeA = 1;
        typeB--;      if(typeB <= 2) typeB = 2;
        typeC--;      if(typeC <= 3) typeC = 3;
        typeD--;      if(typeD <= 4) typeD = 4;
        typeE--;      if(typeE <= 5) typeE = 5;
        triggerA--;   if(triggerA <= 101) triggerA = 101;
        triggerB--;   if(triggerB <= 102) triggerB = 102;
        triggerC--;   if(triggerC <= 103) triggerC = 103;
        triggerD--;   if(triggerD <= 104) triggerD = 104;
        triggerE--;   if(triggerE <= 105) triggerE = 105;
        actionA--;    if(actionA <= 1) actionA = 1;
        actionB--;    if(actionB <= 2) actionB = 2;
        actionC--;    if(actionC <= 3) actionC = 3;
        actionD--;    if(actionD <= 4) actionD = 4;
        actionE--;    if(actionE <= 5) actionE = 5;
        NoF2A(noA, noB, noC, noD, noE);
        ModeF2A(modeA, modeB, modeC, modeD, modeE);
        TypeF2A(typeA, typeB, typeC, typeD, typeE);
        TriggerF2A(triggerA, triggerB, triggerC, triggerD, triggerE);
        ActionF2A(actionA, actionB, actionC, actionD, actionE);
        break;
      default:
        break;
    }
  }
}

  String pinBerapaStatusString;
  String typeString;
  String triggerString;
  String actionString;
  
void F2B_LogicSet(){
  pageF2B.show();
  Serial.println("F2B_LogicSet");
  
  no = 0;
  mode = 0;
  type = 0;
  trigger = 0;
  action = 0;

  NoF2B("");
  ModeF2B("");
  TypeF2B("");
  TriggerF2B("");
  ActionF2B("");
  //NoF2B(String(no));
  //ModeF2B(String(mode));
  //TypeF2B(String(type));
  //TriggerF2B(dummyIdRFID[trigger]); 
  //ActionF2B(String(action));
  
  Teks = teksNo;   // kondisi awal yg aktfi si numF4ASpeed
  LtexNo = true;
  LtexMode = true;
  LtexType = true;
  LtexTrigger = true;
  LtexAction = true;

  type = typeRFID;
  
  while(true){
    nexLoop(nex_listen_list_F2B_LogicSet);
    pilihTeks();
    
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF2BBack");
        return false;
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2BDown");
        if(LtexNo)
        {
          no++;     if(no >= 20)     no = 20;   // untuk sample batasin dulu sampai 20 dlu aja
          NoF2B(String(no));
        }
        if(LtexMode)
        {
          mode++;     if(mode >= 20)     mode = 20;
          ModeF2B(String(mode));
        }
        if(LtexType)
        {
          type++;      if(type >= 3)     type = 3;    // edit disini dulu
          TypeF2B(String(type));
          TriggerF2B("");
          trigger = 0;
          dummyIdRFID[trigger];
          pinBerapa = 0;
        }
        if(LtexTrigger)
        {
          pilihTriggerDown();
        }
        if(LtexAction)
        {
          action++;    if(action >= 13) action = 13;    // kenapa ada 13, karena action nya ada 13 tipe, see on top
          ActionF2B(String(action));
        }
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2BUp");
        if(LtexNo)
        {
          no--;      if(no <= 1)     no = 1;
          NoF2B(String(no));
        }
        if(LtexMode)
        {
          mode--;      if(mode <= 1)     mode = 1;
          ModeF2B(String(mode));
        }
        if(LtexType)
        {
          type--;      if(type <= 1)     type = 1;
          TypeF2B(String(type));
          TriggerF2B("");
          trigger = 0;
          dummyIdRFID[trigger];
          pinBerapa = 0;
        }
        if(LtexTrigger)
        {
          pilihTriggerUp();
        }
        if(LtexAction)
        {
          action--;    if(action <= 1) action = 1;
          ActionF2B(String(action));
        }
        break;
      case tCHANGE:
        Tombol = tIDLE;
        Serial.println("bF2BChange");

        pilihChangeTriggerDIDO();
        pilihChangeActionDIDO();
        
        break;
      case tSAVE:
        Tombol = tIDLE;
        Serial.println("bF2BSave");         Serial.print("\n\n");
        Serial.print(no);                   Serial.print(" ");
        Serial.print(mode);                 Serial.print(" ");
        Serial.print(type);                 Serial.print(" ");
        Serial.print(trigger);              Serial.print(" ");
        Serial.print(action);               Serial.print("\n\n");

//        EEPROM.write(addressGnoKe[no], no);
//        EEPROM.write(addressGmodeKe[no], mode);
//        EEPROM.write(addressGtypeKe[no], type);
//        EEPROM.write(addressGtriggerKe[no], trigger);
//        EEPROM.write(addressGactionKe[no], action);
        pageF2B.show();

        // Sementara paksa di kosongkan dulu
        no = 0;
        mode = 0;
        type = 0;
        trigger = 0;
        action = 0;
        NoF2B("");
        ModeF2B("");
        TypeF2B("");
        TriggerF2B("");
        ActionF2B("");
//        NoF2B(String(no));
//        ModeF2B(String(mode));
//        TypeF2B(String(type));
//        if(type == typeRFID)
//        {
//          TriggerF2B(dummyIdRFID[1]);
//        }
//        else 
//        {
//          TriggerF2B(triggerString);
//        }
//        ActionF2B(String(action));
        
        break;
      default:
        break;
    }
  }
}

void NoF2A(int noA, int noB, int noC, int noD, int noE){
  Serial2.print("tF2ANoA.txt=");
  Serial2.print("\"");
  Serial2.print(noA);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ANoB.txt=");
  Serial2.print("\"");
  Serial2.print(noB);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ANoC.txt=");
  Serial2.print("\"");
  Serial2.print(noC);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ANoD.txt=");
  Serial2.print("\"");
  Serial2.print(noD);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ANoE.txt=");
  Serial2.print("\"");
  Serial2.print(noE);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ModeF2A(int modeA, int modeB, int modeC, int modeD, int modeE){
  Serial2.print("tF2AModeA.txt=");
  Serial2.print("\"");
  Serial2.print(modeA);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeB.txt=");
  Serial2.print("\"");
  Serial2.print(modeB);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeC.txt=");
  Serial2.print("\"");
  Serial2.print(modeC);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeD.txt=");
  Serial2.print("\"");
  Serial2.print(modeD);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeE.txt=");
  Serial2.print("\"");
  Serial2.print(modeE);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TypeF2A(int typeA, int typeB, int typeC, int typeD, int typeE){
  String typeAstring, typeBstring, typeCstring, typeDstring, typeEstring;
  if(typeA == typeRFID)     {typeAstring = "RFID";}
  else if(typeA == typeDI)  {typeAstring = "DI";}
  else if(typeA == typeDO)  {typeAstring = "DO";}
  Serial2.print("tF2ATypeA.txt=");
  Serial2.print("\"");
  Serial2.print(typeAstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeB == typeRFID)     {typeBstring = "RFID";}
  else if(typeB == typeDI)  {typeBstring = "DI";}
  else if(typeB == typeDO)  {typeBstring = "DO";}
  Serial2.print("tF2ATypeB.txt=");
  Serial2.print("\"");
  Serial2.print(typeBstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeC == typeRFID)     {typeCstring = "RFID";}
  else if(typeC == typeDI)  {typeCstring = "DI";}
  else if(typeC == typeDO)  {typeCstring = "DO";}
  Serial2.print("tF2ATypeC.txt=");
  Serial2.print("\"");
  Serial2.print(typeCstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeD == typeRFID)     {typeDstring = "RFID";}
  else if(typeD == typeDI)  {typeDstring = "DI";}
  else if(typeD == typeDO)  {typeDstring = "DO";}
  Serial2.print("tF2ATypeD.txt=");
  Serial2.print("\"");
  Serial2.print(typeDstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeE == typeRFID)     {typeEstring = "RFID";}
  else if(typeE == typeDI)  {typeEstring = "DI";}
  else if(typeE == typeDO)  {typeEstring = "DO";}
  Serial2.print("tF2ATypeE.txt=");
  Serial2.print("\"");
  Serial2.print(typeEstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TriggerF2A(int triggerA, int triggerB, int triggerC, int triggerD, int triggerE){
  String triggerAstring, triggerBstring, triggerCstring, triggerDstring, triggerEstring;
  int pin, statusPin;
  
  if(typeKe[1] == typeRFID)     {triggerAstring = dummyIdRFID[triggerA];}
  else if(typeKe[1] == typeDI)
  {
    pin = triggerA/10;
    statusPin = triggerA % 2;
    triggerAstring = pin;
    if(statusPin == 1)  triggerAstring += ",HIGH";
    else                triggerAstring += ",LOW";
  }
  else if(typeKe[1] == typeDO)
  {
    pin = triggerA/10;
    statusPin = triggerA % 2;
    triggerAstring = pin;
    if(statusPin == 1)  triggerAstring += ",HIGH";
    else                triggerAstring += ",LOW";
  }
  Serial2.print("tF2ATriggerA.txt=");
  Serial2.print("\"");
  Serial2.print(triggerAstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeKe[2] == typeRFID)     {triggerBstring = dummyIdRFID[triggerB];}
  else if(typeKe[2] == typeDI)
  {
    pin = triggerB/10;
    statusPin = triggerB % 2;
    triggerBstring = pin;
    if(statusPin == 1)  triggerBstring += ",HIGH";
    else                triggerBstring += ",LOW";
  }
  else if(typeKe[2] == typeDO)
  {
    pin = triggerB/10;
    statusPin = triggerB % 2;
    triggerBstring = pin;
    if(statusPin == 1)  triggerBstring += ",HIGH";
    else                triggerBstring += ",LOW";
  }
  Serial2.print("tF2ATriggerB.txt=");
  Serial2.print("\"");
  Serial2.print(triggerBstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeKe[3] == typeRFID)
  {
    triggerCstring = dummyIdRFID[triggerC];
  }
  else if(typeKe[3] == typeDI)
  {
    pin = triggerC/10;
    statusPin = triggerC % 2;
    triggerCstring = pin;
    if(statusPin == 1)  triggerCstring += ",HIGH";
    else                triggerCstring += ",LOW";
  }
  else if(typeKe[3] == typeDO)
  {
    pin = triggerC/10;
    statusPin = triggerC % 2;
    triggerCstring = pin;
    if(statusPin == 1)  triggerCstring += ",HIGH";
    else                triggerCstring += ",LOW";
  }
  Serial2.print("tF2ATriggerC.txt=");
  Serial2.print("\"");
  Serial2.print(triggerCstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeKe[4] == typeRFID)     {triggerDstring = dummyIdRFID[triggerD];}
  else if(typeKe[4] == typeDI)
  {
    pin = triggerD/10;
    statusPin = triggerD % 2;
    triggerDstring = pin;
    if(statusPin == 1)  triggerDstring += ",HIGH";
    else                triggerDstring += ",LOW";
  }
  else if(typeKe[4] == typeDO)
  {
    pin = triggerD/10;
    statusPin = triggerD % 2;
    triggerDstring = pin;
    if(statusPin == 1)  triggerDstring += ",HIGH";
    else                triggerDstring += ",LOW";
  }
  Serial2.print("tF2ATriggerD.txt=");
  Serial2.print("\"");
  Serial2.print(triggerDstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if(typeKe[5] == typeRFID)     {triggerEstring = dummyIdRFID[triggerE];}
  else if(typeKe[5] == typeDI)
  {
    pin = triggerE/10;
    statusPin = triggerE % 2;
    triggerEstring = pin;
    if(statusPin == 1)  triggerEstring += ",HIGH";
    else                triggerEstring += ",LOW";
  }
  else if(typeKe[5] == typeDO)
  {
    pin = triggerE/10;
    statusPin = triggerE % 2;
    triggerEstring = pin;
    if(statusPin == 1)  triggerEstring += ",HIGH";
    else                triggerEstring += ",LOW";
  }
  Serial2.print("tF2ATriggerE.txt=");
  Serial2.print("\"");
  Serial2.print(triggerEstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2A(int actionA, int actionB, int actionC, int actionD, int actionE){
  String actionAstring, actionBstring, actionCstring, actionDstring, actionEstring;
  if     (actionA == 1)    actionAstring = "Berhenti";
  else if(actionA == 2)    actionAstring = "Maju";
  else if(actionA == 3)    actionAstring = "Belok Kiri";
  else if(actionA == 4)    actionAstring = "Belok Kanan";
  else if(actionA == 5)    actionAstring = "Balik Kiri";
  else if(actionA == 6)    actionAstring = "Balik Kanan";
  else if(actionA == 7)    actionAstring = "Lift On";
  else if(actionA == 8)    actionAstring = "Lift Off";
  else if(actionA == 9)    actionAstring = "DO 1,LOW";
  else if(actionA == 10)   actionAstring = "DO 2,LOW";
  else if(actionA == 11)   actionAstring = "DO 3,LOW";
  else if(actionA == 12)   actionAstring = "DO 4,LOW";
  else if(actionA == 13)   actionAstring = "DO 5,LOW";
  Serial2.print("tF2AActionA.txt=");
  Serial2.print("\"");
  Serial2.print(actionAstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (actionB == 1)    actionBstring = "Berhenti";
  else if(actionB == 2)    actionBstring = "Maju";
  else if(actionB == 3)    actionBstring = "Belok Kiri";
  else if(actionB == 4)    actionBstring = "Belok Kanan";
  else if(actionB == 5)    actionBstring = "Balik Kiri";
  else if(actionB == 6)    actionBstring = "Balik Kanan";
  else if(actionB == 7)    actionBstring = "Lift On";
  else if(actionB == 8)    actionBstring = "Lift Off";
  else if(actionB == 9)    actionBstring = "DO 1,LOW";
  else if(actionB == 10)   actionBstring = "DO 2,LOW";
  else if(actionB == 11)   actionBstring = "DO 3,LOW";
  else if(actionB == 12)   actionBstring = "DO 4,LOW";
  else if(actionB == 13)   actionBstring = "DO 5,LOW";
  Serial2.print("tF2AActionB.txt=");
  Serial2.print("\"");
  Serial2.print(actionBstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (actionC == 1)    actionCstring = "Berhenti";
  else if(actionC == 2)    actionCstring = "Maju";
  else if(actionC == 3)    actionCstring = "Belok Kiri";
  else if(actionC == 4)    actionCstring = "Belok Kanan";
  else if(actionC == 5)    actionCstring = "Balik Kiri";
  else if(actionC == 6)    actionCstring = "Balik Kanan";
  else if(actionC == 7)    actionCstring = "Lift On";
  else if(actionC == 8)    actionCstring = "Lift Off";
  else if(actionC == 9)    actionCstring = "DO 1,LOW";
  else if(actionC == 10)   actionCstring = "DO 2,LOW";
  else if(actionC == 11)   actionCstring = "DO 3,LOW";
  else if(actionC == 12)   actionCstring = "DO 4,LOW";
  else if(actionC == 13)   actionCstring = "DO 5,LOW";
  Serial2.print("tF2AActionC.txt=");
  Serial2.print("\"");
  Serial2.print(actionCstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (actionD == 1)    actionDstring = "Berhenti";
  else if(actionD == 2)    actionDstring = "Maju";
  else if(actionD == 3)    actionDstring = "Belok Kiri";
  else if(actionD == 4)    actionDstring = "Belok Kanan";
  else if(actionD == 5)    actionDstring = "Balik Kiri";
  else if(actionD == 6)    actionDstring = "Balik Kanan";
  else if(actionD == 7)    actionDstring = "Lift On";
  else if(actionD == 8)    actionDstring = "Lift Off";
  else if(actionD == 9)    actionDstring = "DO 1,LOW";
  else if(actionD == 10)   actionDstring = "DO 2,LOW";
  else if(actionD == 11)   actionDstring = "DO 3,LOW";
  else if(actionD == 12)   actionDstring = "DO 4,LOW";
  else if(actionD == 13)   actionDstring = "DO 5,LOW";
  Serial2.print("tF2AActionD.txt=");
  Serial2.print("\"");
  Serial2.print(actionDstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (actionE == 1)    actionEstring = "Berhenti";
  else if(actionE == 2)    actionEstring = "Maju";
  else if(actionE == 3)    actionEstring = "Belok Kiri";
  else if(actionE == 4)    actionEstring = "Belok Kanan";
  else if(actionE == 5)    actionEstring = "Balik Kiri";
  else if(actionE == 6)    actionEstring = "Balik Kanan";
  else if(actionE == 7)    actionEstring = "Lift On";
  else if(actionE == 8)    actionEstring = "Lift Off";
  else if(actionE == 9)    actionEstring = "DO 1,LOW";
  else if(actionE == 10)   actionEstring = "DO 2,LOW";
  else if(actionE == 11)   actionEstring = "DO 3,LOW";
  else if(actionE == 12)   actionEstring = "DO 4,LOW";
  else if(actionE == 13)   actionEstring = "DO 5,LOW";
  Serial2.print("tF2AActionE.txt=");
  Serial2.print("\"");
  Serial2.print(actionEstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void noF2B(String no){
  Serial2.print("tF2BNo.txt=");
  Serial2.print("\"");
  Serial2.print(no);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ModeF2B(String mode){
  Serial2.print("tF2BMode.txt=");
  Serial2.print("\"");
  Serial2.print(mode);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TypeF2B(String type){
  if(type == "0")       type = "";
  else if(type == "1")  type = "RFID";
  else if(type == "2")  type = "DI";
  else if(type == "3")  type = "DO";
  Serial2.print("tF2BType.txt=");
  Serial2.print("\"");
  Serial2.print(type);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TriggerF2B(String trigger){
  Serial2.print("tF2BTrigger.txt=");
  Serial2.print("\"");
  Serial2.print(trigger);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2B(String action){
  String actionString;
  if     (action == "1")    actionString = "Berhenti";
  else if(action == "2")    actionString = "Maju";
  else if(action == "3")    actionString = "Belok Kiri";
  else if(action == "4")    actionString = "Belok Kanan";
  else if(action == "5")    actionString = "Balik Kiri";
  else if(action == "6")    actionString = "Balik Kanan";
  else if(action == "7")    actionString = "Lift On";
  else if(action == "8")    actionString = "Lift Off";
  else if(action == "9")    actionString = "DO 1,LOW";
  else if(action == "10")   actionString = "DO 2,LOW";
  else if(action == "11")   actionString = "DO 3,LOW";
  else if(action == "12")   actionString = "DO 4,LOW";
  else if(action == "13")   actionString = "DO 5,LOW";
  else                      actionString = action;
  Serial2.print("tF2BAction.txt=");
  Serial2.print("\"");
  Serial2.print(actionString);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void pilihTeks(){
  if(Teks == teksNo){
    Teks = teksIDLE;
    Serial.println("F2B teksNo");
    tF2BNo.Set_background_color_bco(1500);
    tF2BMode.Set_background_color_bco(65535);
    tF2BType.Set_background_color_bco(65535);
    tF2BTrigger.Set_background_color_bco(65535);
    tF2BAction.Set_background_color_bco(65535);
    LtexNo = true;
    LtexMode = false;
    LtexType = false;
    LtexTrigger = false;
    LtexAction = false;
  }
  if(Teks == teksMode){
    Teks = teksIDLE;
    Serial.println("F2B teksMode");
    tF2BNo.Set_background_color_bco(65535);   // 1500 warna biru
    tF2BMode.Set_background_color_bco(1500);   // 1500 warna biru
    tF2BType.Set_background_color_bco(65535);   // 1500 warna biru
    tF2BTrigger.Set_background_color_bco(65535);
    tF2BAction.Set_background_color_bco(65535);
    LtexNo = false;
    LtexMode = true;
    LtexType = false;
    LtexTrigger = false;
    LtexAction = false;
  }
  if(Teks == teksType){
    Teks = teksIDLE;
    Serial.println("F2B teksType");
    tF2BNo.Set_background_color_bco(65535);
    tF2BMode.Set_background_color_bco(65535);
    tF2BType.Set_background_color_bco(1500);
    tF2BTrigger.Set_background_color_bco(65535);
    tF2BAction.Set_background_color_bco(65535);
    LtexNo = false;
    LtexMode = false;
    LtexType = true;
    LtexTrigger = false;
    LtexAction = false;
  }
  if(Teks == teksTrigger){
    Teks = teksIDLE;
    Serial.println("F2B teksTrigger");
    tF2BNo.Set_background_color_bco(65535);
    tF2BMode.Set_background_color_bco(65535);
    tF2BType.Set_background_color_bco(65535);
    tF2BTrigger.Set_background_color_bco(1500);
    tF2BAction.Set_background_color_bco(65535);
    LtexNo = false;
    LtexMode = false;
    LtexType = false;
    LtexTrigger = true;
    LtexAction = false;
  }
  if(Teks == teksAction){
    Teks = teksIDLE;
    Serial.println("F2B teksAction");
    tF2BNo.Set_background_color_bco(65535);
    tF2BMode.Set_background_color_bco(65535);
    tF2BType.Set_background_color_bco(65535);
    tF2BTrigger.Set_background_color_bco(65535);
    tF2BAction.Set_background_color_bco(1500);
    LtexNo = false;
    LtexMode = false;
    LtexType = false;
    LtexTrigger = false;
    LtexAction = true;
  }
}

void pilihTriggerDown(){
  if(type == typeRFID)
  {
    trigger++;  if(trigger >= 10) trigger = 10;
    dummyIdRFID[trigger];
    TriggerF2B(dummyIdRFID[trigger]); 
  }
  else if(type == typeDI)
  {
    pinBerapa++;
    if(pinBerapa >= 5) pinBerapa = 5;
    pinBerapaStatus = HIGH;
    if(pinBerapaStatus == HIGH)
      pinBerapaStatusString = "HIGH";
    else
      pinBerapaStatusString = "LOW";
    triggerString = String(pinBerapa);
    triggerString += ",";
    triggerString += pinBerapaStatusString;
    TriggerF2B(triggerString);

    triggerString = String(pinBerapa) + String(pinBerapaStatus);
    trigger = triggerString.toInt();
  }
  else if(type == typeDO)
  {
    pinBerapa++;
    if(pinBerapa >= 5) pinBerapa = 5;
    pinBerapaStatus = HIGH;            
    if(pinBerapaStatus == HIGH)
      pinBerapaStatusString = "HIGH";
    else
      pinBerapaStatusString = "LOW";
    triggerString = String(pinBerapa);
    triggerString += ",";
    triggerString += pinBerapaStatusString;
    TriggerF2B(triggerString);

    triggerString = String(pinBerapa) + String(pinBerapaStatus);
    trigger = triggerString.toInt();
  }
}

void pilihTriggerUp(){
  if(type == typeRFID)
  {
    trigger--;   if(trigger <= 1) trigger = 1;
    dummyIdRFID[trigger];
    TriggerF2B(dummyIdRFID[trigger]); 
  }
  else if(type == typeDI)
  {
    pinBerapa--;
    if(pinBerapa <= 1) pinBerapa = 1;
    pinBerapaStatus = HIGH;
    if(pinBerapaStatus == HIGH)
      pinBerapaStatusString = "HIGH";
    else
      pinBerapaStatusString = "LOW";
    triggerString = String(pinBerapa);
    triggerString += ",";
    triggerString += pinBerapaStatusString;
    TriggerF2B(triggerString);

    triggerString = String(pinBerapa) + String(pinBerapaStatus);
    trigger = triggerString.toInt();
  }
  else if(type == typeDO)
  {
    pinBerapa--;
    if(pinBerapa <= 1) pinBerapa = 1;
    pinBerapaStatus = HIGH;            
    if(pinBerapaStatus == HIGH)
      pinBerapaStatusString = "HIGH";
    else
      pinBerapaStatusString = "LOW";
    triggerString = String(pinBerapa);
    triggerString += ",";
    triggerString += pinBerapaStatusString;
    TriggerF2B(triggerString);

    triggerString = String(pinBerapa) + String(pinBerapaStatus);
    trigger = triggerString.toInt();
  }
}

void pilihChangeTriggerDIDO(){
  if(LtexTrigger)
  {
    if(type == typeDI)
    {
      if(pinBerapaStatus == LOW)
      {
        pinBerapaStatus = HIGH;
        pinBerapaStatusString = "HIGH";
      }
      else
      {
        pinBerapaStatus = LOW;
        pinBerapaStatusString = "LOW";
      }
      triggerString = String(pinBerapa);
      triggerString += ",";
      triggerString += pinBerapaStatusString;
      TriggerF2B(triggerString);

      triggerString = String(pinBerapa) + String(pinBerapaStatus);
      trigger = triggerString.toInt();
    }
    else if(type == typeDO)
    {
      if(pinBerapaStatus == LOW)
      {
        pinBerapaStatus = HIGH;
        pinBerapaStatusString = "HIGH";
      }
      else
      {
        pinBerapaStatus = LOW;
        pinBerapaStatusString = "LOW";
      }
      triggerString = String(pinBerapa);
      triggerString += ",";
      triggerString += pinBerapaStatusString;
      TriggerF2B(triggerString);

      triggerString = String(pinBerapa) + String(pinBerapaStatus);
      trigger = triggerString.toInt();
    }
  }
}

void pilihChangeActionDIDO(){
  if(LtexAction)
  {
    if(action == 9)//    actionString = "DO";
    {
      if(pinBerapaStatus == LOW)
      {
        pinBerapaStatus = HIGH;
        pinBerapaStatusString = "HIGH";
      }
      else
      {
        pinBerapaStatus = LOW;
        pinBerapaStatusString = "LOW";
      }
      actionString = "DO 1";
      actionString += ",";
      actionString += pinBerapaStatusString;
      ActionF2B(actionString);
    }
    if(action == 10)
    {
      if(pinBerapaStatus == LOW)
      {
        pinBerapaStatus = HIGH;
        pinBerapaStatusString = "HIGH";
      }
      else
      {
        pinBerapaStatus = LOW;
        pinBerapaStatusString = "LOW";
      }
      actionString = "DO 2";
      actionString += ",";
      actionString += pinBerapaStatusString;
      ActionF2B(actionString);
    }
    if(action == 11)
    {
      if(pinBerapaStatus == LOW)
      {
        pinBerapaStatus = HIGH;
        pinBerapaStatusString = "HIGH";
      }
      else
      {
        pinBerapaStatus = LOW;
        pinBerapaStatusString = "LOW";
      }
      actionString = "DO 3";
      actionString += ",";
      actionString += pinBerapaStatusString;
      ActionF2B(actionString);
    }
    if(action == 12)
    {
      if(pinBerapaStatus == LOW)
      {
        pinBerapaStatus = HIGH;
        pinBerapaStatusString = "HIGH";
      }
      else
      {
        pinBerapaStatus = LOW;
        pinBerapaStatusString = "LOW";
      }
      actionString = "DO 4";
      actionString += ",";
      actionString += pinBerapaStatusString;
      ActionF2B(actionString);
    }
    if(action == 13)
    {
      if(pinBerapaStatus == LOW)
      {
        pinBerapaStatus = HIGH;
        pinBerapaStatusString = "HIGH";
      }
      else
      {
        pinBerapaStatus = LOW;
        pinBerapaStatusString = "LOW";
      }
      actionString = "DO 5";
      actionString += ",";
      actionString += pinBerapaStatusString;
      ActionF2B(actionString);
    }
  }
}

