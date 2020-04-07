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

void pilihTeks();
void sample();
  
bool LtexNo = false;
bool LtexMode = false;
bool LtexType = false;
bool LtexTrigger = false;
bool LtexAction = false;




int no;
int mode;
int type;
int trigger;
int action;

int modeKe[jumlahData+1];   // kenapa ada 10, karena maksimal data nya ada 10, 1 untuk buffer aja, biar dimulainya tidak dari 0 si array nya   
int typeKe[jumlahData+1];
int triggerKe[jumlahData+1];
int actionKe[jumlahData+1];

        
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
          
//          Serial.print(no);                Serial.print("_");
//          Serial.print(modeKe[no]);        Serial.print("_");
//          Serial.print(typeKe[no]);        Serial.print("_");
//          Serial.print(triggerKe[no]);     Serial.print("_");
//          Serial.print(actionKe[no]);      Serial.print("\n");
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

//          trigger = 0;
//          triggerKe[no] = trigger;
//          trigger = 0;
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
          else if(type == 2 || type == 3)
          {
            if(trigger >= 10)     trigger = 10;   // ini jumlah triger
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
  if     (typeAstring == "RFID")                     Serial2.print(idRFID[triggerA]);
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
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerB.txt=");
  Serial2.print("\"");
  if     (typeBstring == "RFID")                     Serial2.print(idRFID[triggerB]);
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
  if     (typeCstring == "RFID")                     Serial2.print(idRFID[triggerC]);
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
  if     (typeDstring == "RFID")                     Serial2.print(idRFID[triggerD]);
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

  Serial.println(typeKe[5]);    //Serial.println(typeKe[noKe[5]]);
  Serial2.print("tF2ATriggerE.txt=");
  Serial2.print("\"");
  if     (typeEstring == "RFID")                     Serial2.print(idRFID[triggerE]);
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
  if(noInt == 0)    Serial2.print("");
  else              Serial2.print(String(noInt));
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
  String baper;
  char buffer[10] = {0};
  tF2BType.getText(buffer, sizeof(buffer));    
  baper = buffer;
  
  Serial2.print("tF2BTrigger.txt=");
  Serial2.print("\"");
    
  if     (baper == "")                          Serial2.print("");
  else if(baper == "RFID")                      Serial2.print(idRFID[triggerInt]);
  else if(baper == "DI" && triggerInt == 1)     Serial2.print("1,HIGH");
  else if(baper == "DI" && triggerInt == 2)     Serial2.print("1,LOW");
  else if(baper == "DI" && triggerInt == 3)     Serial2.print("2,HIGH");
  else if(baper == "DI" && triggerInt == 4)     Serial2.print("2,LOW");
  else if(baper == "DI" && triggerInt == 5)     Serial2.print("3,HIGH");
  else if(baper == "DI" && triggerInt == 6)     Serial2.print("3,LOW");
  else if(baper == "DI" && triggerInt == 7)     Serial2.print("4,HIGH");
  else if(baper == "DI" && triggerInt == 8)     Serial2.print("4,LOW");
  else if(baper == "DI" && triggerInt == 9)     Serial2.print("5,HIGH");
  else if(baper == "DI" && triggerInt == 10)    Serial2.print("5,LOW");
  else if(baper == "DO" && triggerInt == 1)     Serial2.print("1,HIGH");
  else if(baper == "DO" && triggerInt == 2)     Serial2.print("1,LOW");
  else if(baper == "DO" && triggerInt == 3)     Serial2.print("2,HIGH");
  else if(baper == "DO" && triggerInt == 4)     Serial2.print("2,LOW");
  else if(baper == "DO" && triggerInt == 5)     Serial2.print("3,HIGH");
  else if(baper == "DO" && triggerInt == 6)     Serial2.print("3,LOW");
  else if(baper == "DO" && triggerInt == 7)     Serial2.print("4,HIGH");
  else if(baper == "DO" && triggerInt == 8)     Serial2.print("4,LOW");
  else if(baper == "DO" && triggerInt == 9)     Serial2.print("5,HIGH");
  else if(baper == "DO" && triggerInt == 10)    Serial2.print("5,LOW");
  
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
