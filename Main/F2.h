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
// 9 > Buzzer On
// 10 > Buzzer Off
// 11 > DO 01,LOW
// 12 > DO 01,HIGH
// 13 > DO 02,LOW
// 14 > DO 02,HIGH
// 15 > DO 03,LOW
// 16 > DO 03,HIGH
// 17 > DO 04,LOW
// 18 > DO 04,HIGH
// 19 > DO 05,LOW
// 20 > DO 05,HIGH


void NoF2A(int noA, int noB, int noC, int noD, int noE);
void ModeF2A(int modeA, int modeB, int modeC, int modeD, int modeE);
void TypeF2A(int typeA, int typeB, int typeC, int typeD, int typeE);
void TriggerF2A(int triggerA, int triggerB, int triggerC, int triggerD, int triggerE);
void ActionF2A(int actionA, int actionB, int actionC, int actionD, int actionE);

void NoF2B(int noInt);
void ModeF2B(int modeInt);
void TypeF2B(int typeInt);
void TriggerF2B(int triggerInt);
void ActionF2B(int actionInt);

  bool LtexNo = false;
  bool LtexMode = false;
  bool LtexType = false;
  bool LtexTrigger = false;
  bool LtexAction = false;  
  void pilihTeks();

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
    
  // ============= CONTOH SAMPLE AJA ======================
  noKe[1] = 1;
  noKe[2] = 2;
  noKe[3] = 3;
  noKe[4] = 4;
  noKe[5] = 5;
  noKe[6] = 6;
  noKe[7] = 7;
  noKe[8] = 8;
  noKe[9] = 9;
  noKe[10] = 10;

  modeKe[noKe[1]] = 1;
  modeKe[noKe[2]] = 1;
  modeKe[noKe[3]] = 1;
  modeKe[noKe[4]] = 1;
  modeKe[noKe[5]] = 1;
  modeKe[noKe[6]] = 0;
  modeKe[noKe[7]] = 0;
  modeKe[noKe[8]] = 0;
  modeKe[noKe[9]] = 0;
  modeKe[noKe[10]] = 0;

  typeKe[noKe[1]] = 1;
  typeKe[noKe[2]] = 1;
  typeKe[noKe[3]] = 0;
  typeKe[noKe[4]] = 2;
  typeKe[noKe[5]] = 3;
  typeKe[noKe[6]] = 0;
  typeKe[noKe[7]] = 0;
  typeKe[noKe[8]] = 0;
  typeKe[noKe[9]] = 0;
  typeKe[noKe[10]] = 0;

  triggerKe[noKe[1]] = 1;
  triggerKe[noKe[2]] = 2;
  triggerKe[noKe[3]] = 0;
  triggerKe[noKe[4]] = 5;
  triggerKe[noKe[5]] = 10;
  triggerKe[noKe[6]] = 0;
  triggerKe[noKe[7]] = 0;
  triggerKe[noKe[8]] = 0;
  triggerKe[noKe[9]] = 0;
  triggerKe[noKe[10]] = 0;

  actionKe[noKe[1]] = 1;
  actionKe[noKe[2]] = 2;
  actionKe[noKe[3]] = 0;
  actionKe[noKe[4]] = 15;
  actionKe[noKe[5]] = 18;
  actionKe[noKe[6]] = 0;
  actionKe[noKe[7]] = 0;
  actionKe[noKe[8]] = 0;
  actionKe[noKe[9]] = 0;
  actionKe[noKe[10]] = 0;
  // ============= CONTOH SAMPLE AJA ======================

  NoF2A(noKe[1],                  noKe[2],              noKe[3],              noKe[4],              noKe[5]);
  ModeF2A(modeKe[noKe[1]],        modeKe[noKe[2]],      modeKe[noKe[3]],      modeKe[noKe[4]],      modeKe[noKe[5]]);
  TypeF2A(typeKe[noKe[1]],        typeKe[noKe[2]],      typeKe[noKe[3]],      typeKe[noKe[4]],      typeKe[noKe[5]]);
  TriggerF2A(triggerKe[noKe[1]],  triggerKe[noKe[2]],   triggerKe[noKe[3]],   triggerKe[noKe[4]],   triggerKe[noKe[5]]);
  ActionF2A(actionKe[noKe[1]],    actionKe[noKe[2]],    actionKe[noKe[3]],    actionKe[noKe[4]],    actionKe[noKe[5]]);
  
  
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
        
        NoF2A(noKe[1],                  noKe[2],              noKe[3],              noKe[4],              noKe[5]);
        ModeF2A(modeKe[noKe[1]],        modeKe[noKe[2]],      modeKe[noKe[3]],      modeKe[noKe[4]],      modeKe[noKe[5]]);
        TypeF2A(typeKe[noKe[1]],        typeKe[noKe[2]],      typeKe[noKe[3]],      typeKe[noKe[4]],      typeKe[noKe[5]]);
        TriggerF2A(triggerKe[noKe[1]],  triggerKe[noKe[2]],   triggerKe[noKe[3]],   triggerKe[noKe[4]],   triggerKe[noKe[5]]);
        ActionF2A(actionKe[noKe[1]],    actionKe[noKe[2]],    actionKe[noKe[3]],    actionKe[noKe[4]],    actionKe[noKe[5]]);
        
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2ADown");

        noKe[1]++;        if(noKe[1] >= 6)       noKe[1] = 6;
        noKe[2]++;        if(noKe[2] >= 7)       noKe[2] = 7;
        noKe[3]++;        if(noKe[3] >= 8)       noKe[3] = 8;
        noKe[4]++;        if(noKe[4] >= 9)       noKe[4] = 9;
        noKe[5]++;        if(noKe[5] >= 10)      noKe[5] = 10;
        
        NoF2A(noKe[1],                  noKe[2],              noKe[3],              noKe[4],              noKe[5]);
        ModeF2A(modeKe[noKe[1]],        modeKe[noKe[2]],      modeKe[noKe[3]],      modeKe[noKe[4]],      modeKe[noKe[5]]);
        TypeF2A(typeKe[noKe[1]],        typeKe[noKe[2]],      typeKe[noKe[3]],      typeKe[noKe[4]],      typeKe[noKe[5]]);
        TriggerF2A(triggerKe[noKe[1]],  triggerKe[noKe[2]],   triggerKe[noKe[3]],   triggerKe[noKe[4]],   triggerKe[noKe[5]]);
        ActionF2A(actionKe[noKe[1]],    actionKe[noKe[2]],    actionKe[noKe[3]],    actionKe[noKe[4]],    actionKe[noKe[5]]);
        
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2AUp");
        
        noKe[1]--;        if(noKe[1] <= 1)       noKe[1] = 1;
        noKe[2]--;        if(noKe[2] <= 2)       noKe[2] = 2;
        noKe[3]--;        if(noKe[3] <= 3)       noKe[3] = 3;
        noKe[4]--;        if(noKe[4] <= 4)       noKe[4] = 4;
        noKe[5]--;        if(noKe[5] <= 5)       noKe[5] = 5;
        
        NoF2A(noKe[1],                  noKe[2],              noKe[3],              noKe[4],              noKe[5]);
        ModeF2A(modeKe[noKe[1]],        modeKe[noKe[2]],      modeKe[noKe[3]],      modeKe[noKe[4]],      modeKe[noKe[5]]);
        TypeF2A(typeKe[noKe[1]],        typeKe[noKe[2]],      typeKe[noKe[3]],      typeKe[noKe[4]],      typeKe[noKe[5]]);
        TriggerF2A(triggerKe[noKe[1]],  triggerKe[noKe[2]],   triggerKe[noKe[3]],   triggerKe[noKe[4]],   triggerKe[noKe[5]]);
        ActionF2A(actionKe[noKe[1]],    actionKe[noKe[2]],    actionKe[noKe[3]],    actionKe[noKe[4]],    actionKe[noKe[5]]);
        break;
      default:
        break;
    }
  }
}

  String pinBerapaStatusString;
  
void F2B_LogicSet(){
  pageF2B.show();
  Serial.println("F2B_LogicSet");
  
  no = 0;
  mode = 0;
  type = 0;
  trigger = 0;
  action = 0;

  NoF2B(no);
  ModeF2B(mode);
  TypeF2B(type);
  TriggerF2B(trigger);
  ActionF2B(action);
  
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
          no++;     if(no >= (sizeof(addressGnoKe) / sizeof(addressGnoKe[0])) - 1)     no = (sizeof(addressGnoKe) / sizeof(addressGnoKe[0])) - 1;   // untuk sample batasin dulu sampai 10 dlu aja
          NoF2B(no);
          ModeF2B(modeKe[no]);
          TypeF2B(typeKe[no]);        //disini kali masalah nya yg dari F2A ke F2B, tampilan di DI sama DO bermasalah
          TriggerF2B(triggerKe[no]); 
          ActionF2B(actionKe[no]);
        }
        if(LtexMode)
        {
          mode++;   if(mode >= (sizeof(addressGmodeKe) / sizeof(addressGmodeKe[0])) - 1)     mode = (sizeof(addressGmodeKe) / sizeof(addressGmodeKe[0])) - 1;   // untuk sample batasin dulu sampai 10 dlu aja
          modeKe[no] = mode;
          ModeF2B(modeKe[no]);
        }
        if(LtexType)
        {
          type++;      if(type >= 3)      type = 3;    // edit disini dulu
          typeKe[no] = type;
          TypeF2B(typeKe[no]);
          
          triggerKe[no] = 1;
          TriggerF2B(triggerKe[no]);
        }
        if(LtexTrigger)
        {
          trigger++;
          if(type == 1)
          {
            if(trigger >= (sizeof(dummyIdRFID) / sizeof(dummyIdRFID[0])) - 1)     trigger = (sizeof(dummyIdRFID) / sizeof(dummyIdRFID[0])) - 1;
          }
          else if(type == 2 || type == 3)
          {
            if(trigger >= 8)     trigger = 8;
          }
          triggerKe[no] = trigger;
          TriggerF2B(triggerKe[no]);
        }
        if(LtexAction)
        {
          action++;    if(action >= 20) action = 20;    // kenapa ada 13, karena action nya ada 13 tipe, see on top
          actionKe[no] = action;
          ActionF2B(actionKe[no]);
        }
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2BUp");
        if(LtexNo)
        {
          no--;      if(no <= 1)     no = 1;
          NoF2B(no);
          ModeF2B(modeKe[no]);
          TypeF2B(typeKe[no]);
          TriggerF2B(triggerKe[no]); 
          ActionF2B(actionKe[no]);
        }
        if(LtexMode)
        {
          mode--;      if(mode <= 1)     mode = 1;
          modeKe[no] = mode;
          ModeF2B(modeKe[no]);
        }
        if(LtexType)
        {
          type--;      if(type <= 1)     type = 1;
          typeKe[no] = type;
          TypeF2B(typeKe[no]);

          triggerKe[no] = 1;
          TriggerF2B(triggerKe[no]);
        }
        if(LtexTrigger)
        {
          trigger--;  if(trigger <= 1)     trigger = 1;
          triggerKe[no] = trigger;
          TriggerF2B(triggerKe[no]);
        }
        if(LtexAction)
        {
          action--;    if(action <= 1) action = 1;
          actionKe[no] = action;
          ActionF2B(actionKe[no]);
        }
        break;
//      case tCHANGE:
//        Tombol = tIDLE;
//        Serial.println("bF2BChange");        
//        break;
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
        
        NoF2B(no);
        ModeF2B(modeKe[no]);
        TypeF2B(typeKe[no]);
        TriggerF2B(triggerKe[no]); 
        ActionF2B(actionKe[no]);
        
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
  if(modeA == 0)    Serial2.print("");
  else              Serial2.print(modeA);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeB.txt=");
  Serial2.print("\"");
  if(modeB == 0)    Serial2.print("");
  else              Serial2.print(modeB);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeC.txt=");
  Serial2.print("\"");
  if(modeC == 0)    Serial2.print("");
  else              Serial2.print(modeC);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeD.txt=");
  Serial2.print("\"");
  if(modeD == 0)    Serial2.print("");
  else              Serial2.print(modeD);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AModeE.txt=");
  Serial2.print("\"");
  if(modeE == 0)    Serial2.print("");
  else              Serial2.print(modeE);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

String typeAstring, typeBstring, typeCstring, typeDstring, typeEstring;
void TypeF2A(int typeA, int typeB, int typeC, int typeD, int typeE){
//  String typeAstring, typeBstring, typeCstring, typeDstring, typeEstring;
  if     (typeA == typeIDLE)      {typeAstring = "";}
  else if(typeA == typeRFID)      {typeAstring = "RFID";}
  else if(typeA == typeDI)        {typeAstring = "DI";}
  else if(typeA == typeDO)        {typeAstring = "DO";}
  Serial2.print("tF2ATypeA.txt=");
  Serial2.print("\"");
  Serial2.print(typeAstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (typeB == typeIDLE)      {typeBstring = "";}
  else if(typeB == typeRFID)      {typeBstring = "RFID";}
  else if(typeB == typeDI)        {typeBstring = "DI";}
  else if(typeB == typeDO)        {typeBstring = "DO";}
  Serial2.print("tF2ATypeB.txt=");
  Serial2.print("\"");
  Serial2.print(typeBstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (typeC == typeIDLE)      {typeCstring = "";}
  else if(typeC == typeRFID)      {typeCstring = "RFID";}
  else if(typeC == typeDI)        {typeCstring = "DI";}
  else if(typeC == typeDO)        {typeCstring = "DO";}
  Serial2.print("tF2ATypeC.txt=");
  Serial2.print("\"");
  Serial2.print(typeCstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (typeD == typeIDLE)      {typeDstring = "";}
  else if(typeD == typeRFID)      {typeDstring = "RFID";}
  else if(typeD == typeDI)        {typeDstring = "DI";}
  else if(typeD == typeDO)        {typeDstring = "DO";}
  Serial2.print("tF2ATypeD.txt=");
  Serial2.print("\"");
  Serial2.print(typeDstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  if     (typeE == typeIDLE)      {typeEstring = "";}
  else if(typeE == typeRFID)      {typeEstring = "RFID";}
  else if(typeE == typeDI)        {typeEstring = "DI";}
  else if(typeE == typeDO)        {typeEstring = "DO";}
  Serial2.print("tF2ATypeE.txt=");
  Serial2.print("\"");
  Serial2.print(typeEstring);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TriggerF2A(int triggerA, int triggerB, int triggerC, int triggerD, int triggerE){
  Serial2.print("tF2ATriggerA.txt=");
  Serial2.print("\"");
  if     (typeAstring == "RFID")                     Serial2.print(dummyIdRFID[triggerA]);
  else if(typeAstring == "DI" && triggerA == 1)      Serial2.print("1,HIGH");
  else if(typeAstring == "DI" && triggerA == 2)      Serial2.print("1,LOW");
  else if(typeAstring == "DI" && triggerA == 3)      Serial2.print("2,HIGH");
  else if(typeAstring == "DI" && triggerA == 4)      Serial2.print("2,LOW");
  else if(typeAstring == "DI" && triggerA == 5)      Serial2.print("3,HIGH");
  else if(typeAstring == "DI" && triggerA == 6)      Serial2.print("3,LOW");
  else if(typeAstring == "DI" && triggerA == 7)      Serial2.print("4,HIGH");
  else if(typeAstring == "DI" && triggerA == 8)      Serial2.print("4,LOW");
  else if(typeAstring == "DI" && triggerA == 9)      Serial2.print("5,HIGH");
  else if(typeAstring == "DI" && triggerA == 10)     Serial2.print("5,LOW");
  else if(typeAstring == "DO" && triggerA == 1)      Serial2.print("1,HIGH");
  else if(typeAstring == "DO" && triggerA == 2)      Serial2.print("1,LOW");
  else if(typeAstring == "DO" && triggerA == 3)      Serial2.print("2,HIGH");
  else if(typeAstring == "DO" && triggerA == 4)      Serial2.print("2,LOW");
  else if(typeAstring == "DO" && triggerA == 5)      Serial2.print("3,HIGH");
  else if(typeAstring == "DO" && triggerA == 6)      Serial2.print("3,LOW");
  else if(typeAstring == "DO" && triggerA == 7)      Serial2.print("4,HIGH");
  else if(typeAstring == "DO" && triggerA == 8)      Serial2.print("4,LOW");
  else if(typeAstring == "DO" && triggerA == 9)      Serial2.print("5,HIGH");
  else if(typeAstring == "DO" && triggerA == 10)     Serial2.print("5,LOW");
  else                                               Serial2.print("");
//  Serial2.print(dummyIdRFID[triggerA]);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerB.txt=");
  Serial2.print("\"");
  if     (typeBstring == "RFID")                     Serial2.print(dummyIdRFID[triggerB]);
  else if(typeBstring == "DI" && triggerB == 1)      Serial2.print("1,HIGH");
  else if(typeBstring == "DI" && triggerB == 2)      Serial2.print("1,LOW");
  else if(typeBstring == "DI" && triggerB == 3)      Serial2.print("2,HIGH");
  else if(typeBstring == "DI" && triggerB == 4)      Serial2.print("2,LOW");
  else if(typeBstring == "DI" && triggerB == 5)      Serial2.print("3,HIGH");
  else if(typeBstring == "DI" && triggerB == 6)      Serial2.print("3,LOW");
  else if(typeBstring == "DI" && triggerB == 7)      Serial2.print("4,HIGH");
  else if(typeBstring == "DI" && triggerB == 8)      Serial2.print("4,LOW");
  else if(typeBstring == "DI" && triggerB == 9)      Serial2.print("5,HIGH");
  else if(typeBstring == "DI" && triggerB == 10)     Serial2.print("5,LOW");
  else if(typeBstring == "DO" && triggerB == 1)      Serial2.print("1,HIGH");
  else if(typeBstring == "DO" && triggerB == 2)      Serial2.print("1,LOW");
  else if(typeBstring == "DO" && triggerB == 3)      Serial2.print("2,HIGH");
  else if(typeBstring == "DO" && triggerB == 4)      Serial2.print("2,LOW");
  else if(typeBstring == "DO" && triggerB == 5)      Serial2.print("3,HIGH");
  else if(typeBstring == "DO" && triggerB == 6)      Serial2.print("3,LOW");
  else if(typeBstring == "DO" && triggerB == 7)      Serial2.print("4,HIGH");
  else if(typeBstring == "DO" && triggerB == 8)      Serial2.print("4,LOW");
  else if(typeBstring == "DO" && triggerB == 9)      Serial2.print("5,HIGH");
  else if(typeBstring == "DO" && triggerB == 10)     Serial2.print("5,LOW");
  else                                               Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerC.txt=");
  Serial2.print("\"");
  if     (typeCstring == "RFID")                     Serial2.print(dummyIdRFID[triggerC]);
  else if(typeCstring == "DI" && triggerC == 1)      Serial2.print("1,HIGH");
  else if(typeCstring == "DI" && triggerC == 2)      Serial2.print("1,LOW");
  else if(typeCstring == "DI" && triggerC == 3)      Serial2.print("2,HIGH");
  else if(typeCstring == "DI" && triggerC == 4)      Serial2.print("2,LOW");
  else if(typeCstring == "DI" && triggerC == 5)      Serial2.print("3,HIGH");
  else if(typeCstring == "DI" && triggerC == 6)      Serial2.print("3,LOW");
  else if(typeCstring == "DI" && triggerC == 7)      Serial2.print("4,HIGH");
  else if(typeCstring == "DI" && triggerC == 8)      Serial2.print("4,LOW");
  else if(typeCstring == "DI" && triggerC == 9)      Serial2.print("5,HIGH");
  else if(typeCstring == "DI" && triggerC == 10)     Serial2.print("5,LOW");
  else if(typeCstring == "DO" && triggerC == 1)      Serial2.print("1,HIGH");
  else if(typeCstring == "DO" && triggerC == 2)      Serial2.print("1,LOW");
  else if(typeCstring == "DO" && triggerC == 3)      Serial2.print("2,HIGH");
  else if(typeCstring == "DO" && triggerC == 4)      Serial2.print("2,LOW");
  else if(typeCstring == "DO" && triggerC == 5)      Serial2.print("3,HIGH");
  else if(typeCstring == "DO" && triggerC == 6)      Serial2.print("3,LOW");
  else if(typeCstring == "DO" && triggerC == 7)      Serial2.print("4,HIGH");
  else if(typeCstring == "DO" && triggerC == 8)      Serial2.print("4,LOW");
  else if(typeCstring == "DO" && triggerC == 9)      Serial2.print("5,HIGH");
  else if(typeCstring == "DO" && triggerC == 10)     Serial2.print("5,LOW");
  else                                               Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerD.txt=");
  Serial2.print("\"");
  if     (typeDstring == "RFID")                     Serial2.print(dummyIdRFID[triggerD]);
  else if(typeDstring == "DI" && triggerD == 1)      Serial2.print("1,HIGH");
  else if(typeDstring == "DI" && triggerD == 2)      Serial2.print("1,LOW");
  else if(typeDstring == "DI" && triggerD == 3)      Serial2.print("2,HIGH");
  else if(typeDstring == "DI" && triggerD == 4)      Serial2.print("2,LOW");
  else if(typeDstring == "DI" && triggerD == 5)      Serial2.print("3,HIGH");
  else if(typeDstring == "DI" && triggerD == 6)      Serial2.print("3,LOW");
  else if(typeDstring == "DI" && triggerD == 7)      Serial2.print("4,HIGH");
  else if(typeDstring == "DI" && triggerD == 8)      Serial2.print("4,LOW");
  else if(typeDstring == "DI" && triggerD == 9)      Serial2.print("5,HIGH");
  else if(typeDstring == "DI" && triggerD == 10)     Serial2.print("5,LOW");
  else if(typeDstring == "DO" && triggerD == 1)      Serial2.print("1,HIGH");
  else if(typeDstring == "DO" && triggerD == 2)      Serial2.print("1,LOW");
  else if(typeDstring == "DO" && triggerD == 3)      Serial2.print("2,HIGH");
  else if(typeDstring == "DO" && triggerD == 4)      Serial2.print("2,LOW");
  else if(typeDstring == "DO" && triggerD == 5)      Serial2.print("3,HIGH");
  else if(typeDstring == "DO" && triggerD == 6)      Serial2.print("3,LOW");
  else if(typeDstring == "DO" && triggerD == 7)      Serial2.print("4,HIGH");
  else if(typeDstring == "DO" && triggerD == 8)      Serial2.print("4,LOW");
  else if(typeDstring == "DO" && triggerD == 9)      Serial2.print("5,HIGH");
  else if(typeDstring == "DO" && triggerD == 10)     Serial2.print("5,LOW");
  else                                               Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial.println(typeKe[noKe[5]]);
  Serial2.print("tF2ATriggerE.txt=");
  Serial2.print("\"");
  if     (typeEstring == "RFID")                     Serial2.print(dummyIdRFID[triggerE]);
  else if(typeEstring == "DI" && triggerE == 1)      Serial2.print("1,HIGH");
  else if(typeEstring == "DI" && triggerE == 2)      Serial2.print("1,LOW");
  else if(typeEstring == "DI" && triggerE == 3)      Serial2.print("2,HIGH");
  else if(typeEstring == "DI" && triggerE == 4)      Serial2.print("2,LOW");
  else if(typeEstring == "DI" && triggerE == 5)      Serial2.print("3,HIGH");
  else if(typeEstring == "DI" && triggerE == 6)      Serial2.print("3,LOW");
  else if(typeEstring == "DI" && triggerE == 7)      Serial2.print("4,HIGH");
  else if(typeEstring == "DI" && triggerE == 8)      Serial2.print("4,LOW");
  else if(typeEstring == "DI" && triggerE == 9)      Serial2.print("5,HIGH");
  else if(typeEstring == "DI" && triggerE == 10)     Serial2.print("5,LOW");
  else if(typeEstring == "DO" && triggerE == 1)      Serial2.print("1,HIGH");
  else if(typeEstring == "DO" && triggerE == 2)      Serial2.print("1,LOW");
  else if(typeEstring == "DO" && triggerE == 3)      Serial2.print("2,HIGH");
  else if(typeEstring == "DO" && triggerE == 4)      Serial2.print("2,LOW");
  else if(typeEstring == "DO" && triggerE == 5)      Serial2.print("3,HIGH");
  else if(typeEstring == "DO" && triggerE == 6)      Serial2.print("3,LOW");
  else if(typeEstring == "DO" && triggerE == 7)      Serial2.print("4,HIGH");
  else if(typeEstring == "DO" && triggerE == 8)      Serial2.print("4,LOW");
  else if(typeEstring == "DO" && triggerE == 9)      Serial2.print("5,HIGH");
  else if(typeEstring == "DO" && triggerE == 10)     Serial2.print("5,LOW");
  else                                               Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2A(int actionA, int actionB, int actionC, int actionD, int actionE){
  Serial2.print("tF2AActionA.txt=");
  Serial2.print("\"");
//  Serial2.print(actionA);
  if     (actionA == 0)     Serial2.print("");
  else if(actionA == 1)     Serial2.print("Berhenti");
  else if(actionA == 2)     Serial2.print("Maju");
  else if(actionA == 3)     Serial2.print("Belok Kiri");
  else if(actionA == 4)     Serial2.print("Belok Kanan");
  else if(actionA == 5)     Serial2.print("Balik Kiri");
  else if(actionA == 6)     Serial2.print("Balik Kanan");
  else if(actionA == 7)     Serial2.print("Lift On");
  else if(actionA == 8)     Serial2.print("Lift Off");
  else if(actionA == 9)     Serial2.print("Buzzer On");
  else if(actionA == 10)    Serial2.print("Buzzer Off");
  else if(actionA == 11)    Serial2.print("DO 01,HIGH");
  else if(actionA == 12)    Serial2.print("DO 01,LOW");
  else if(actionA == 13)    Serial2.print("DO 02,HIGH");
  else if(actionA == 14)    Serial2.print("DO 02,LOW");
  else if(actionA == 15)    Serial2.print("DO 03,HIGH");
  else if(actionA == 16)    Serial2.print("DO 03,LOW");
  else if(actionA == 17)    Serial2.print("DO 04,HIGH");
  else if(actionA == 18)    Serial2.print("DO 04,LOW");
  else if(actionA == 19)    Serial2.print("DO 05,HIGH");
  else if(actionA == 20)    Serial2.print("DO 05,LOW");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionB.txt=");
  Serial2.print("\"");
//  Serial2.print(actionB);
  if     (actionB == 0)     Serial2.print("");
  else if(actionB == 1)     Serial2.print("Berhenti");
  else if(actionB == 2)     Serial2.print("Maju");
  else if(actionB == 3)     Serial2.print("Belok Kiri");
  else if(actionB == 4)     Serial2.print("Belok Kanan");
  else if(actionB == 5)     Serial2.print("Balik Kiri");
  else if(actionB == 6)     Serial2.print("Balik Kanan");
  else if(actionB == 7)     Serial2.print("Lift On");
  else if(actionB == 8)     Serial2.print("Lift Off");
  else if(actionB == 9)     Serial2.print("Buzzer On");
  else if(actionB == 10)    Serial2.print("Buzzer Off");
  else if(actionB == 11)    Serial2.print("DO 01,HIGH");
  else if(actionB == 12)    Serial2.print("DO 01,LOW");
  else if(actionB == 13)    Serial2.print("DO 02,HIGH");
  else if(actionB == 14)    Serial2.print("DO 02,LOW");
  else if(actionB == 15)    Serial2.print("DO 03,HIGH");
  else if(actionB == 16)    Serial2.print("DO 03,LOW");
  else if(actionB == 17)    Serial2.print("DO 04,HIGH");
  else if(actionB == 18)    Serial2.print("DO 04,LOW");
  else if(actionB == 19)    Serial2.print("DO 05,HIGH");
  else if(actionB == 20)    Serial2.print("DO 05,LOW");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionC.txt=");
  Serial2.print("\"");
//  Serial2.print(actionC);
  if     (actionC == 0)     Serial2.print("");
  else if(actionC == 1)     Serial2.print("Berhenti");
  else if(actionC == 2)     Serial2.print("Maju");
  else if(actionC == 3)     Serial2.print("Belok Kiri");
  else if(actionC == 4)     Serial2.print("Belok Kanan");
  else if(actionC == 5)     Serial2.print("Balik Kiri");
  else if(actionC == 6)     Serial2.print("Balik Kanan");
  else if(actionC == 7)     Serial2.print("Lift On");
  else if(actionC == 8)     Serial2.print("Lift Off");
  else if(actionC == 9)     Serial2.print("Buzzer On");
  else if(actionC == 10)    Serial2.print("Buzzer Off");
  else if(actionC == 11)    Serial2.print("DO 01,HIGH");
  else if(actionC == 12)    Serial2.print("DO 01,LOW");
  else if(actionC == 13)    Serial2.print("DO 02,HIGH");
  else if(actionC == 14)    Serial2.print("DO 02,LOW");
  else if(actionC == 15)    Serial2.print("DO 03,HIGH");
  else if(actionC == 16)    Serial2.print("DO 03,LOW");
  else if(actionC == 17)    Serial2.print("DO 04,HIGH");
  else if(actionC == 18)    Serial2.print("DO 04,LOW");
  else if(actionC == 19)    Serial2.print("DO 05,HIGH");
  else if(actionC == 20)    Serial2.print("DO 05,LOW");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionD.txt=");
  Serial2.print("\"");
//  Serial2.print(actionD);
  if     (actionD == 0)     Serial2.print("");
  else if(actionD == 1)     Serial2.print("Berhenti");
  else if(actionD == 2)     Serial2.print("Maju");
  else if(actionD == 3)     Serial2.print("Belok Kiri");
  else if(actionD == 4)     Serial2.print("Belok Kanan");
  else if(actionD == 5)     Serial2.print("Balik Kiri");
  else if(actionD == 6)     Serial2.print("Balik Kanan");
  else if(actionD == 7)     Serial2.print("Lift On");
  else if(actionD == 8)     Serial2.print("Lift Off");
  else if(actionD == 9)     Serial2.print("Buzzer On");
  else if(actionD == 10)    Serial2.print("Buzzer Off");
  else if(actionD == 11)    Serial2.print("DO 01,HIGH");
  else if(actionD == 12)    Serial2.print("DO 01,LOW");
  else if(actionD == 13)    Serial2.print("DO 02,HIGH");
  else if(actionD == 14)    Serial2.print("DO 02,LOW");
  else if(actionD == 15)    Serial2.print("DO 03,HIGH");
  else if(actionD == 16)    Serial2.print("DO 03,LOW");
  else if(actionD == 17)    Serial2.print("DO 04,HIGH");
  else if(actionD == 18)    Serial2.print("DO 04,LOW");
  else if(actionD == 19)    Serial2.print("DO 05,HIGH");
  else if(actionD == 20)    Serial2.print("DO 05,LOW");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionE.txt=");
  Serial2.print("\"");
//  Serial2.print(actionE);
  if     (actionE == 0)     Serial2.print("");
  else if(actionE == 1)     Serial2.print("Berhenti");
  else if(actionE == 2)     Serial2.print("Maju");
  else if(actionE == 3)     Serial2.print("Belok Kiri");
  else if(actionE == 4)     Serial2.print("Belok Kanan");
  else if(actionE == 5)     Serial2.print("Balik Kiri");
  else if(actionE == 6)     Serial2.print("Balik Kanan");
  else if(actionE == 7)     Serial2.print("Lift On");
  else if(actionE == 8)     Serial2.print("Lift Off");
  else if(actionE == 9)     Serial2.print("Buzzer On");
  else if(actionE == 10)    Serial2.print("Buzzer Off");
  else if(actionE == 11)    Serial2.print("DO 01,HIGH");
  else if(actionE == 12)    Serial2.print("DO 01,LOW");
  else if(actionE == 13)    Serial2.print("DO 02,HIGH");
  else if(actionE == 14)    Serial2.print("DO 02,LOW");
  else if(actionE == 15)    Serial2.print("DO 03,HIGH");
  else if(actionE == 16)    Serial2.print("DO 03,LOW");
  else if(actionE == 17)    Serial2.print("DO 04,HIGH");
  else if(actionE == 18)    Serial2.print("DO 04,LOW");
  else if(actionE == 19)    Serial2.print("DO 05,HIGH");
  else if(actionE == 20)    Serial2.print("DO 05,LOW");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}


void NoF2B(int noInt){
  Serial2.print("tF2BNo.txt=");
  Serial2.print("\"");
  Serial2.print(String(noInt));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ModeF2B(int modeInt){
  Serial2.print("tF2BMode.txt=");
  Serial2.print("\"");
  
  if(modeInt == 0)      Serial2.print(String(""));
  else                  Serial2.print(String(modeInt));
  
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TypeF2B(int typeInt){
  Serial2.print("tF2BType.txt=");
  Serial2.print("\"");
  
  if     (typeInt == 0)  Serial2.print("");
  else if(typeInt == 1)  Serial2.print("RFID");
  else if(typeInt == 2)  Serial2.print("DI");
  else if(typeInt == 3)  Serial2.print("DO");
  
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TriggerF2B(int triggerInt){
  Serial2.print("tF2BTrigger.txt=");
  Serial2.print("\"");

  if     (type == 0)                         Serial2.print("");
  else if(type == 1)                         Serial2.print(dummyIdRFID[triggerInt]);
  else if(type == 2 && triggerInt == 1)      Serial2.print("1,HIGH");
  else if(type == 2 && triggerInt == 2)      Serial2.print("1,LOW");
  else if(type == 2 && triggerInt == 3)      Serial2.print("2,HIGH");
  else if(type == 2 && triggerInt == 4)      Serial2.print("2,LOW");
  else if(type == 2 && triggerInt == 5)      Serial2.print("3,HIGH");
  else if(type == 2 && triggerInt == 6)      Serial2.print("3,LOW");
  else if(type == 2 && triggerInt == 7)      Serial2.print("4,HIGH");
  else if(type == 2 && triggerInt == 8)      Serial2.print("4,LOW");
  else if(type == 2 && triggerInt == 9)      Serial2.print("5,HIGH");
  else if(type == 2 && triggerInt == 10)     Serial2.print("5,LOW");
  else if(type == 3 && triggerInt == 1)      Serial2.print("1,HIGH");
  else if(type == 3 && triggerInt == 2)      Serial2.print("1,LOW");
  else if(type == 3 && triggerInt == 3)      Serial2.print("2,HIGH");
  else if(type == 3 && triggerInt == 4)      Serial2.print("2,LOW");
  else if(type == 3 && triggerInt == 5)      Serial2.print("3,HIGH");
  else if(type == 3 && triggerInt == 6)      Serial2.print("3,LOW");
  else if(type == 3 && triggerInt == 7)      Serial2.print("4,HIGH");
  else if(type == 3 && triggerInt == 8)      Serial2.print("4,LOW");
  else if(type == 3 && triggerInt == 9)      Serial2.print("5,HIGH");
  else if(type == 3 && triggerInt == 10)     Serial2.print("5,LOW");
  
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2B(int actionInt){
  Serial2.print("tF2BAction.txt=");
  Serial2.print("\"");

  if     (actionInt == 0)     Serial2.print("");
  else if(actionInt == 1)     Serial2.print("Berhenti");
  else if(actionInt == 2)     Serial2.print("Maju");
  else if(actionInt == 3)     Serial2.print("Belok Kiri");
  else if(actionInt == 4)     Serial2.print("Belok Kanan");
  else if(actionInt == 5)     Serial2.print("Balik Kiri");
  else if(actionInt == 6)     Serial2.print("Balik Kanan");
  else if(actionInt == 7)     Serial2.print("Lift On");
  else if(actionInt == 8)     Serial2.print("Lift Off");
  else if(actionInt == 9)     Serial2.print("Buzzer On");
  else if(actionInt == 10)    Serial2.print("Buzzer Off");
  else if(actionInt == 11)    Serial2.print("DO 01,HIGH");
  else if(actionInt == 12)    Serial2.print("DO 01,LOW");
  else if(actionInt == 13)    Serial2.print("DO 02,HIGH");
  else if(actionInt == 14)    Serial2.print("DO 02,LOW");
  else if(actionInt == 15)    Serial2.print("DO 03,HIGH");
  else if(actionInt == 16)    Serial2.print("DO 03,LOW");
  else if(actionInt == 17)    Serial2.print("DO 04,HIGH");
  else if(actionInt == 18)    Serial2.print("DO 04,LOW");
  else if(actionInt == 19)    Serial2.print("DO 05,HIGH");
  else if(actionInt == 20)    Serial2.print("DO 05,LOW");

  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void pilihTeks(){
  String baper;
  char buffer[10] = {0};
  memset(buffer, 0, sizeof(buffer));
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

    tF2BMode.getText(buffer, sizeof(buffer));
    mode = atoi(buffer);
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
    
    tF2BType.getText(buffer, sizeof(buffer));    
    baper = buffer;
    if     (baper == "")        type = 0;
    else if(baper == "RFID")    type = 1;
    else if(baper == "DI")      type = 2;
    else if(baper == "DO")      type = 3;
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

    tF2BType.getText(buffer, sizeof(buffer));    
    baper = buffer;
    if     (baper == "")        type = 0;
    else if(baper == "RFID")    type = 1;
    else if(baper == "DI")      type = 2;
    else if(baper == "DO")      type = 3;
    
    trigger = 1;
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

    tF2BAction.getText(buffer, sizeof(buffer)); //    action = atoi(buffer);
    baper = buffer;
    if     (baper == "")              action = 0;
    else if(baper == "Berhenti")      action = 1;
    else if(baper == "Maju")          action = 2;
    else if(baper == "Belok Kiri")    action = 3;
    else if(baper == "Belok Kanan")   action = 4;
    else if(baper == "Balik Kiri")    action = 5;
    else if(baper == "Balik Kanan")   action = 6;
    else if(baper == "Lift On")       action = 7;
    else if(baper == "Lift Off")      action = 8;
    else if(baper == "Buzzer On")     action = 9;
    else if(baper == "Buzzer Off")    action = 10;
    else if(baper == "DO 01,HIGH")    action = 11;
    else if(baper == "DO 01,LOW")     action = 12;
    else if(baper == "DO 02,HIGH")    action = 13;
    else if(baper == "DO 02,LOW")     action = 14;
    else if(baper == "DO 03,HIGH")    action = 15;
    else if(baper == "DO 03,LOW")     action = 16;
    else if(baper == "DO 04,HIGH")    action = 17;
    else if(baper == "DO 04,LOW")     action = 18;
    else if(baper == "DO 05,HIGH")    action = 19;
    else if(baper == "DO 05,LOW")     action = 20;
  }
}
