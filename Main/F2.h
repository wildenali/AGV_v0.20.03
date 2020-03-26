void F2A_LogicSet();
void F2B_LogicSet();

void ModeF2A(int modeA, int modeB, int modeC, int modeD, int modeE);
void TypeF2A(int typeA, int typeB, int typeC, int typeD, int typeE);
void TriggerF2A(int triggerA, int triggerB, int triggerC, int triggerD, int triggerE);
void ActionF2A(int actionA, int actionB, int actionC, int actionD, int actionE);

void ModeF2B(int mode);
void TypeF2B(int type);
void TriggerF2B(int trigger);
void ActionF2B(int action);


void F2A_LogicSet(){
  pageF2A.show();
  Serial.println("F2A_LogicSet");
  
  int modeA = 1;
  int modeB = 2;
  int modeC = 3;
  int modeD = 4;
  int modeE = 5;

  int typeA = 1;
  int typeB = 2;
  int typeC = 3;
  int typeD = 4;
  int typeE = 5;

  int triggerA = 101;
  int triggerB = 102;
  int triggerC = 103;
  int triggerD = 104;
  int triggerE = 105;

  int actionA = modeA + triggerA;
  int actionB = modeB + triggerB;
  int actionC = modeC + triggerC;
  int actionD = modeD + triggerD;
  int actionE = modeE + triggerE;
  
  ModeF2A(modeA, modeB, modeC, modeD, modeE);
  TypeF2A(typeA, typeB, typeC, typeD, typeE);
  TriggerF2A(triggerA, triggerB, triggerC, triggerD, triggerE);
  ActionF2A(actionA, actionB, actionC, actionD, actionE);
  
  
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
        
        ModeF2A(modeA, modeB, modeC, modeD, modeE);
        TypeF2A(typeA, typeB, typeC, typeD, typeE);
        TriggerF2A(triggerA, triggerB, triggerC, triggerD, triggerE);
        ActionF2A(actionA, actionB, actionC, actionD, actionE);
        
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2ADown");

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
        actionA = triggerA + 1;
        actionB = triggerB + 1;
        actionC = triggerC + 1;
        actionD = triggerD + 1;
        actionE = triggerE + 1;
        ModeF2A(modeA, modeB, modeC, modeD, modeE);
        TypeF2A(typeA, typeB, typeC, typeD, typeE);
        TriggerF2A(triggerA, triggerB, triggerC, triggerD, triggerE);
        ActionF2A(actionA, actionB, actionC, actionD, actionE);
        
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2AUp");
        
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
        actionA = triggerA - 1;
        actionB = triggerB - 1;
        actionC = triggerC - 1;
        actionD = triggerD - 1;
        actionE = triggerE - 1;
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

void F2B_LogicSet(){
  pageF2B.show();
  Serial.println("F2B_LogicSet");
  
  int mode = 1;
  int type = 1;
  int trigger = 101;
  int action = 101;
  
  ModeF2B(mode);
  TypeF2B(type);
  TriggerF2B(trigger);
  ActionF2B(action);

//  GgainP = EEPROM.read(addressGgainP);
//  GgainI = EEPROM.read(addressGgainI);
//  GgainD = EEPROM.read(addressGgainD);
//  nF4BGainP.setValue(GgainP);
//  nF4BGainI.setValue(GgainI);
//  nF4BGainD.setValue(GgainD);
  Teks = teksMode;   // kondisi awal yg aktfi si numF4ASpeed
  bool LtexMode = false;
  bool LtexType = false;
  bool LtexTrigger = false;
  bool LtexAction = false;
  while(true){
    nexLoop(nex_listen_list_F2B_LogicSet);
    if(Teks == teksMode){
      Teks = teksIDLE;
      Serial.println("F2B teksMode");
      tF2BMode.Set_background_color_bco(1500);   // 1500 warna biru
      tF2BType.Set_background_color_bco(65535);   // 1500 warna biru
      tF2BTrigger.Set_background_color_bco(65535);
      tF2BAction.Set_background_color_bco(65535);
      LtexMode = true;
      LtexType = false;
      LtexTrigger = false;
      LtexAction = false;
    }
    if(Teks == teksType){
      Teks = teksIDLE;
      Serial.println("F2B teksType");
      tF2BMode.Set_background_color_bco(65535);
      tF2BType.Set_background_color_bco(1500);
      tF2BTrigger.Set_background_color_bco(65535);
      tF2BAction.Set_background_color_bco(65535);
      LtexMode = false;
      LtexType = true;
      LtexTrigger = false;
      LtexAction = false;
    }
    if(Teks == teksTrigger){
      Teks = teksIDLE;
      Serial.println("F2B teksTrigger");
      tF2BMode.Set_background_color_bco(65535);   // 1500 warna biru
      tF2BType.Set_background_color_bco(65535);
      tF2BTrigger.Set_background_color_bco(1500);
      tF2BAction.Set_background_color_bco(65535);
      LtexMode = false;
      LtexType = false;
      LtexTrigger = true;
      LtexAction = false;
    }
    if(Teks == teksAction){
      Teks = teksIDLE;
      Serial.println("F2B teksAction");
      tF2BMode.Set_background_color_bco(65535);   // 1500 warna biru
      tF2BType.Set_background_color_bco(65535);
      tF2BTrigger.Set_background_color_bco(65535);
      tF2BAction.Set_background_color_bco(1500);
      LtexMode = false;
      LtexType = false;
      LtexTrigger = false;
      LtexAction = true;
    }
    
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF2BBack");
        return false;
        break;
      case tSAVE:
        Tombol = tIDLE;
        Serial.println("bF2BSave");
        pageF2B.show();
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2BDown");
        if(LtexMode){
          mode++;      if(mode >= 20)     mode = 20;
          ModeF2B(mode);
        }
        if(LtexType){
          type++;      if(type >= 20)     type = 20;
          TypeF2B(type);
        }
        if(LtexTrigger){
          trigger++;   if(trigger >= 120) trigger = 120;
          TriggerF2B(trigger);
        }
        if(LtexAction){
          action++;    if(action >= 120) action = 120;
          ActionF2B(action);
        }
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2BUp");
        if(LtexMode){
          mode--;      if(mode <= 1)     mode = 1;
          ModeF2B(mode);
        }
        if(LtexType){
          type--;      if(type <= 1)     type = 1;
          TypeF2B(type);
        }
        if(LtexTrigger){
          trigger--;   if(trigger <= 101) trigger = 101;
          TriggerF2B(trigger);
        }
        if(LtexAction){
          action--;    if(action <= 101) action = 101;
          ActionF2B(action);
        }
        break;
      default:
        break;
    }
  }
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
  Serial2.print("tF2ATypeA.txt=");
  Serial2.print("\"");
  Serial2.print(typeA);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATypeB.txt=");
  Serial2.print("\"");
  Serial2.print(typeB);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATypeC.txt=");
  Serial2.print("\"");
  Serial2.print(typeC);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATypeD.txt=");
  Serial2.print("\"");
  Serial2.print(typeD);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATypeE.txt=");
  Serial2.print("\"");
  Serial2.print(typeE);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TriggerF2A(int triggerA, int triggerB, int triggerC, int triggerD, int triggerE){
  Serial2.print("tF2ATriggerA.txt=");
  Serial2.print("\"");
  Serial2.print(triggerA);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerB.txt=");
  Serial2.print("\"");
  Serial2.print(triggerB);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerC.txt=");
  Serial2.print("\"");
  Serial2.print(triggerC);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerD.txt=");
  Serial2.print("\"");
  Serial2.print(triggerD);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2ATriggerE.txt=");
  Serial2.print("\"");
  Serial2.print(triggerE);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2A(int actionA, int actionB, int actionC, int actionD, int actionE){
  Serial2.print("tF2AActionA.txt=");
  Serial2.print("\"");
  Serial2.print(actionA);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionB.txt=");
  Serial2.print("\"");
  Serial2.print(actionB);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionC.txt=");
  Serial2.print("\"");
  Serial2.print(actionC);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionD.txt=");
  Serial2.print("\"");
  Serial2.print(actionD);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF2AActionE.txt=");
  Serial2.print("\"");
  Serial2.print(actionE);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ModeF2B(int mode){
  Serial2.print("tF2BMode.txt=");
  Serial2.print("\"");
  Serial2.print(mode);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TypeF2B(int type){
  Serial2.print("tF2BType.txt=");
  Serial2.print("\"");
  Serial2.print(type);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void TriggerF2B(int trigger){
  Serial2.print("tF2BTrigger.txt=");
  Serial2.print("\"");
  Serial2.print(trigger);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void ActionF2B(int action){
  Serial2.print("tF2BAction.txt=");
  Serial2.print("\"");
  Serial2.print(action);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}
