void F2A_LogicSet();
void F2B_LogicSet();

// ========== Mode ==========
// 1, 2, 3 dan seterusnya

// ========== type ==========
// 1 > RFID
// 2 > DI (Digital Input)
// 3 > DO (Digital Output)
// 4 > LORA

// ========== Action ==========
// 0 > (kosong)
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
// 21 > Tx_1
// 22 > Tx_2
// 23 > Tx_3
// 24 > Tx_4
// 25 > Tx_5


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

void pilihTeks();
void sample();
  
//bool LtexNo = false;
//bool LtexMode = false;
//bool LtexType = false;
//bool LtexTrigger = false;
//bool LtexAction = false;
//
//
//
//
//int no;
//int mode;
//int type;
//int trigger;
//int action;
//
//int modeKe[jumlahData+1];   // kenapa ada 10, karena maksimal data nya ada 10, 1 untuk buffer aja, biar dimulainya tidak dari 0 si array nya   
//int typeKe[jumlahData+1];
//int triggerKe[jumlahData+1];
//int actionKe[jumlahData+1];

        
void F2A_LogicSet(){
  pageF2A.show();
  Serial.println("F2A_LogicSet");
  int numA = 1;
  int numB = 2;
  int numC = 3;
  int numD = 4;
  int numE = 5;
  

  NoF2A(numA,                  numB,              numC,              numD,              numE);
  ModeF2A(modeKe[numA],        modeKe[numB],      modeKe[numC],      modeKe[numD],      modeKe[numE]);
  TypeF2A(typeKe[numA],        typeKe[numB],      typeKe[numC],      typeKe[numD],      typeKe[numE]);
  TriggerF2A(triggerKe[numA],  triggerKe[numB],   triggerKe[numC],   triggerKe[numD],   triggerKe[numE]);
  ActionF2A(actionKe[numA],    actionKe[numB],    actionKe[numC],    actionKe[numD],    actionKe[numE]);
  
  
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

        readDataLogicSetting();
        
        NoF2A(numA,                  numB,              numC,              numD,              numE);
        ModeF2A(modeKe[numA],        modeKe[numB],      modeKe[numC],      modeKe[numD],      modeKe[numE]);
        TypeF2A(typeKe[numA],        typeKe[numB],      typeKe[numC],      typeKe[numD],      typeKe[numE]);
        TriggerF2A(triggerKe[numA],  triggerKe[numB],   triggerKe[numC],   triggerKe[numD],   triggerKe[numE]);
        ActionF2A(actionKe[numA],    actionKe[numB],    actionKe[numC],    actionKe[numD],    actionKe[numE]);
        
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2ADown");

        numA++;        if(numA >= jumlahData - 4)       numA = jumlahData - 4;
        numB++;        if(numB >= jumlahData - 3)       numB = jumlahData - 3;
        numC++;        if(numC >= jumlahData - 2)       numC = jumlahData - 2;
        numD++;        if(numD >= jumlahData - 1)       numD = jumlahData - 1;
        numE++;        if(numE >= jumlahData)           numE = jumlahData;
        
        NoF2A(numA,                  numB,              numC,              numD,              numE);
        ModeF2A(modeKe[numA],        modeKe[numB],      modeKe[numC],      modeKe[numD],      modeKe[numE]);
        TypeF2A(typeKe[numA],        typeKe[numB],      typeKe[numC],      typeKe[numD],      typeKe[numE]);
        TriggerF2A(triggerKe[numA],  triggerKe[numB],   triggerKe[numC],   triggerKe[numD],   triggerKe[numE]);
        ActionF2A(actionKe[numA],    actionKe[numB],    actionKe[numC],    actionKe[numD],    actionKe[numE]);
        
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2AUp");
        
        numA--;        if(numA <= 1)       numA = 1;
        numB--;        if(numB <= 2)       numB = 2;
        numC--;        if(numC <= 3)       numC = 3;
        numD--;        if(numD <= 4)       numD = 4;
        numE--;        if(numE <= 5)       numE = 5;
        
        NoF2A(numA,                  numB,              numC,              numD,              numE);
        ModeF2A(modeKe[numA],        modeKe[numB],      modeKe[numC],      modeKe[numD],      modeKe[numE]);
        TypeF2A(typeKe[numA],        typeKe[numB],      typeKe[numC],      typeKe[numD],      typeKe[numE]);
        TriggerF2A(triggerKe[numA],  triggerKe[numB],   triggerKe[numC],   triggerKe[numD],   triggerKe[numE]);
        ActionF2A(actionKe[numA],    actionKe[numB],    actionKe[numC],    actionKe[numD],    actionKe[numE]);
        break;
      default:
        break;
    }
  }
}

  
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

  
  Teks = teksNo;
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
          no++;     if(no >= jumlahData)     no = jumlahData;   // untuk sample batasin dulu sampai 10 dlu aja
          NoF2B(no);
          ModeF2B(modeKe[no]);
          TypeF2B(typeKe[no]);
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
          type++;     if(type >= 3)      type = 3;
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
            if(trigger >= (sizeof(idRFID) / sizeof(idRFID[0])) - 1)     trigger = (sizeof(idRFID) / sizeof(idRFID[0])) - 1;
          }
          else if(type == 2)
          {
            if(trigger >= 10)     trigger = 10;   // ini jumlah triger, kenapa ada 10 triger pada typeDI, yaitu
                                                  // DO 01,LOW        DO 02,LOW       DO 03,LOW       DO 04,LOW       DO 05,LOW
                                                  // DO 01,HIGH       DO 02,HIGH      DO 03,HIGH      DO 04,HIGH      DO 05,HIGH
          }
          else if(type == 3)
          {
            if(trigger >= 5)     trigger = 5;   // ini jumlah triger, kenapa ada 5 triger pada typeLORA, yaitu
                                                  // Rx_1        Rx_2       Rx_3       Rx_4       Rx_5
          }
          triggerKe[no] = trigger;
          TriggerF2B(triggerKe[no]);
        }
        if(LtexAction)
        {
          action++;    if(action >= 25) action = 25;    // kenapa ada 25, karena action nya ada 25 jenis, see on top
          actionKe[no] = action;
          ActionF2B(actionKe[no]);
        }
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2BUp");
        if(LtexNo)
        {
          no--;      if(no <= 0)     no = 0;
          NoF2B(no);
          ModeF2B(modeKe[no]);
          TypeF2B(typeKe[no]);
          TriggerF2B(triggerKe[no]); 
          ActionF2B(actionKe[no]);
        }
        if(LtexMode)
        {
          mode--;      if(mode <= 0)     mode = 0;
          modeKe[no] = mode;
          ModeF2B(modeKe[no]);
        }
        if(LtexType)
        {
          type--;      if(type <= 0)     type = 0;
          typeKe[no] = type;
          TypeF2B(typeKe[no]);
          
          triggerKe[no] = 1;
          TriggerF2B(triggerKe[no]);
        }
        if(LtexTrigger)
        {
          trigger--;  if(trigger <= 0)  trigger = 0;
          triggerKe[no] = trigger;
          TriggerF2B(triggerKe[no]);
        }
        if(LtexAction)
        {
          action--;    if(action <= 0) action = 0;
          actionKe[no] = action;
          ActionF2B(actionKe[no]);
        }
        break;
      case tSAVE:
        Tombol = tIDLE;
        Serial.println("bF2BSave");         Serial.print("\n\n");
        Serial.print(no);                   Serial.print(" ");
        Serial.print(mode);                 Serial.print(" ");
        Serial.print(type);                 Serial.print(" ");
        Serial.print(trigger);              Serial.print(" ");
        Serial.print(action);               Serial.print("\n\n");

        
        EEPROM.write(addressGmodeKe[no], modeKe[no]);
        EEPROM.write(addressGtypeKe[no], typeKe[no]);
        EEPROM.write(addressGtriggerKe[no], triggerKe[no]);
        EEPROM.write(addressGactionKe[no], actionKe[no]);
        pageF2B.show();

        Teks = teksNo;
        LtexNo = true;
        LtexMode = true;
        LtexType = true;
        LtexTrigger = true;
        LtexAction = true;
        type = typeRFID;
        
        // Refresh the screen
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

  if     (typeA == typeIDLE)      {typeAstring = "";}
  else if(typeA == typeRFID)      {typeAstring = "RFID";}
  else if(typeA == typeDI)        {typeAstring = "DI";}
  else if(typeA == typeLORA)      {typeAstring = "LORA";}
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
  else if(typeB == typeLORA)      {typeBstring = "LORA";}
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
  else if(typeC == typeLORA)      {typeCstring = "LORA";}
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
  else if(typeD == typeLORA)      {typeDstring = "LORA";}
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
  else if(typeE == typeLORA)      {typeEstring = "LORA";}
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
  if     (typeAstring == "RFID")    Serial2.print(idRFID[triggerA]);
  else if(typeAstring == "DI")      Serial2.print(stringDI(triggerA));
  else if(typeAstring == "LORA")    Serial2.print(stringLORA(triggerA));
  else                              Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerB.txt=");
  Serial2.print("\"");
  if     (typeBstring == "RFID")    Serial2.print(idRFID[triggerB]);
  else if(typeBstring == "DI")      Serial2.print(stringDI(triggerB));
  else if(typeBstring == "LORA")    Serial2.print(stringLORA(triggerB));
  else                              Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerC.txt=");
  Serial2.print("\"");
  if     (typeCstring == "RFID")    Serial2.print(idRFID[triggerC]);
  else if(typeCstring == "DI")      Serial2.print(stringDI(triggerC));
  else if(typeCstring == "LORA")    Serial2.print(stringLORA(triggerC));
  else                              Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerD.txt=");
  Serial2.print("\"");
  if     (typeDstring == "RFID")    Serial2.print(idRFID[triggerD]);
  else if(typeDstring == "DI")      Serial2.print(stringDI(triggerD));
  else if(typeDstring == "LORA")    Serial2.print(stringLORA(triggerD));
  else                              Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial.println(typeKe[5]);
  Serial2.print("tF2ATriggerE.txt=");
  Serial2.print("\"");
  if     (typeEstring == "RFID")    Serial2.print(idRFID[triggerE]);
  else if(typeEstring == "DI")      Serial2.print(stringDI(triggerE));
  else if(typeEstring == "LORA")    Serial2.print(stringLORA(triggerE));
  else                              Serial2.print("");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2A(int actionA, int actionB, int actionC, int actionD, int actionE){
  Serial2.print("tF2AActionA.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionA));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionB.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionB));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionC.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionC));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionD.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionD));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionE.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionE));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}


void NoF2B(int noInt){
  Serial2.print("tF2BNo.txt=");
  Serial2.print("\"");
  if(noInt == 0)            Serial2.print("");
  else                      Serial2.print(String(noInt));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ModeF2B(int modeInt){
  Serial2.print("tF2BMode.txt=");
  Serial2.print("\"");
  if(modeInt == 0)          Serial2.print(String(""));
  else                      Serial2.print(String(modeInt));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TypeF2B(int typeInt){
  Serial2.print("tF2BType.txt=");
  Serial2.print("\"");
  if     (typeInt == 0)     Serial2.print("");
  else if(typeInt == 1)     Serial2.print("RFID");
  else if(typeInt == 2)     Serial2.print("DI");
  else if(typeInt == 3)     Serial2.print("LORA");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TriggerF2B(int triggerInt){
  String baper;
  char buffer[10] = {0};
  tF2BType.getText(buffer, sizeof(buffer));    
  baper = buffer;
  
  Serial2.print("tF2BTrigger.txt=");
  Serial2.print("\"");
  if     (baper == "")        Serial2.print("");
  else if(baper == "RFID")    Serial2.print(idRFID[triggerInt]);
  else if(baper == "DI")      Serial2.print(stringDI(triggerInt));
  else if(baper == "LORA")    Serial2.print(stringLORA(triggerInt));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2B(int actionInt){
  Serial2.print("tF2BAction.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionInt));
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

    mode = modeKe[no];
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
    
    type = typeKe[no];
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

    type = typeKe[no];
    trigger = triggerKe[no];
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

    action = actionKe[no];
  }
}
