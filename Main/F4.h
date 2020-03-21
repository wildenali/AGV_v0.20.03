void F4A_MachineSet();
void F4B_MachineSet();
void F4C_MachineSet();
void F4D_MachineSet();
void F4E_MachineSet();

void F4A_MachineSet(){
  pageF4A.show();
  Serial.println("F4A_MachineSet");
  Gspeed = EEPROM.read(addressGspeed);
  Gaccel = EEPROM.read(addressGaccel);
  nF4ASpeed.setValue(Gspeed);
  nF4AAccel.setValue(Gaccel);
  Number = numF4ASpeed;   // kondisi awal yg aktfi si numF4ASpeed
  bool LnumSpeed = false;   // L for Local variable
  bool LnumAccel = false;
  while(true){
    nexLoop(nex_listen_list_F4A_MachineSet);
    if(Number == numF4ASpeed){
      Number = numIDLE;
      Serial.println("F4A Speed");
      nF4ASpeed.Set_background_color_bco(1500);   // 1500 warna biru
      nF4AAccel.Set_background_color_bco(65535);
      LnumSpeed = true;
      LnumAccel = false;
    }
    if(Number == numF4AAccel){
      Number = numIDLE;
      Serial.println("F4A Accel");
      nF4ASpeed.Set_background_color_bco(65535);
      nF4AAccel.Set_background_color_bco(1500);
      LnumSpeed = false;
      LnumAccel = true;
    }

    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF4ABack");
        Menu = F0;
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF4ANext");
        F4B_MachineSet();
        pageF4A.show();
        Serial.println("F4A_MachineSet");
        nF4ASpeed.setValue(Gspeed);
        nF4AAccel.setValue(Gaccel);
        Number = numF4ASpeed;
        break;
      case tMINUS:
        Tombol = tIDLE;
        Serial.println("bF4AMinus");
        if(LnumSpeed){
          nF4ASpeed.getValue(&Gspeed);
          Gspeed -= 1;
          if(Gspeed <= 1) Gspeed = 1;
          nF4ASpeed.setValue(Gspeed);
          EEPROM.write(addressGspeed, Gspeed); 
        }
        if(LnumAccel){
          nF4AAccel.getValue(&Gaccel);
          Gaccel -= 1;
          if(Gaccel <= 1) Gaccel = 1;
          nF4AAccel.setValue(Gaccel);
          EEPROM.write(addressGaccel, Gaccel); 
        }
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF4APlus");
        if(LnumSpeed){
          nF4ASpeed.getValue(&Gspeed);
          Gspeed += 1;
          if(Gspeed >= 10) Gspeed = 10;
          nF4ASpeed.setValue(Gspeed);
          EEPROM.write(addressGspeed, Gspeed); 
        }
        if(LnumAccel){
          nF4AAccel.getValue(&Gaccel);
          Gaccel += 1;
          if(Gaccel >= 10) Gaccel = 10;
          nF4AAccel.setValue(Gaccel);
          EEPROM.write(addressGaccel, Gaccel); 
        }
        break;
      default:
        break;
    }
  }
}

void F4B_MachineSet(){
  pageF4B.show();
  Serial.println("F4B_MachineSet");
  GgainP = EEPROM.read(addressGgainP);
  GgainI = EEPROM.read(addressGgainI);
  GgainD = EEPROM.read(addressGgainD);
  nF4BGainP.setValue(GgainP);
  nF4BGainI.setValue(GgainI);
  nF4BGainD.setValue(GgainD);
  Number = numF4BGainP;   // kondisi awal yg aktfi si numF4ASpeed
  bool LnumGainP = false;
  bool LnumGainI = false;
  bool LnumGainD = false;
  while(true){
    nexLoop(nex_listen_list_F4B_MachineSet);
    if(Number == numF4BGainP){
      Number = numIDLE;
      Serial.println("F4B GainP");
      nF4BGainP.Set_background_color_bco(1500);   // 1500 warna biru
      nF4BGainI.Set_background_color_bco(65535);
      nF4BGainD.Set_background_color_bco(65535);
      LnumGainP = true;
      LnumGainI = false;
      LnumGainD = false;
    }
    if(Number == numF4BGainI){
      Number = numIDLE;
      Serial.println("F4B GainI");
      nF4BGainP.Set_background_color_bco(65535);   // 1500 warna biru
      nF4BGainI.Set_background_color_bco(1500);
      nF4BGainD.Set_background_color_bco(65535);
      LnumGainP = false;
      LnumGainI = true;
      LnumGainD = false;
    }
    if(Number == numF4BGainD){
      Number = numIDLE;
      Serial.println("F4B GainD");
      nF4BGainP.Set_background_color_bco(65535);   // 1500 warna biru
      nF4BGainI.Set_background_color_bco(65535);
      nF4BGainD.Set_background_color_bco(1500);
      LnumGainP = false;
      LnumGainI = false;
      LnumGainD = true;
    }
    
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF4BBack");
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF4BNext");
        F4C_MachineSet();
        pageF4B.show();
        Serial.println("F4B_MachineSet");
        nF4BGainP.setValue(GgainP);
        nF4BGainI.setValue(GgainI);
        nF4BGainD.setValue(GgainD);
        Number = numF4BGainP;
        break;
      case tMINUS:
        Tombol = tIDLE;
        Serial.println("bF4BMinus");
        if(LnumGainP){
          nF4BGainP.getValue(&GgainP);
          GgainP -= 1;
          if(GgainP <= 1) GgainP = 1;
          nF4BGainP.setValue(GgainP);
          EEPROM.write(addressGgainP, GgainP);
        }
        if(LnumGainI){
          nF4BGainI.getValue(&GgainI);
          GgainI -= 1;
          if(GgainI <= 1) GgainI = 1;
          nF4BGainI.setValue(GgainI);
          EEPROM.write(addressGgainI, GgainI);
        }
        if(LnumGainD){
          nF4BGainD.getValue(&GgainD);
          GgainD -= 1;
          if(GgainD <= 1) GgainD = 1;
          nF4BGainD.setValue(GgainD);
          EEPROM.write(addressGgainD, GgainD);
        }
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF4BPlus");
        if(LnumGainP){
          nF4BGainP.getValue(&GgainP);
          GgainP += 1;
          if(GgainP >= 10) GgainP = 10;
          nF4BGainP.setValue(GgainP);
          EEPROM.write(addressGgainP, GgainP); 
        }
        if(LnumGainI){
          nF4BGainI.getValue(&GgainI);
          GgainI += 1;
          if(GgainI >= 10) GgainI = 10;
          nF4BGainI.setValue(GgainI);
          EEPROM.write(addressGgainI, GgainI); 
        }
        if(LnumGainD){
          nF4BGainD.getValue(&GgainD);
          GgainD += 1;
          if(GgainD >= 10) GgainD = 10;
          nF4BGainD.setValue(GgainD);
          EEPROM.write(addressGgainD, GgainD); 
        }
        break;
      default:
        break;
    }
  }
}


void F4C_MachineSet(){
  pageF4C.show();
  Serial.println("F4C_MachineSet");
  GnoRefDist = EEPROM.read(addressGnoRefDist);
  for(int i = 0; i < (sizeof(GminDistSens) / sizeof(GminDistSens[0])); i++){
    GminDistSens[i]   = EEPROM.read(addressGminDistSens[i]);  
  }
  nF4CNoRefDist.setValue(GnoRefDist);
  
  while(true){
    nexLoop(nex_listen_list_F4C_MachineSet);
    readDistanceSensor();

    Serial2.print("nF4CDistSen.val=");
    Serial2.print(GdistSens[GnoRefDist]);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    
    Serial2.print("nF4CRefDist.val=");    // nanti ubah menjadi nF4CMinDist 
    Serial2.print(GminDistSens[GnoRefDist]);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
      
      
     if(GdistSens[GnoRefDist] < GminDistSens[GnoRefDist]) {
       Serial2.print("nF4CRefDist.bco=");
       Serial2.print(63488);
       Serial2.write(0xff);
       Serial2.write(0xff);
       Serial2.write(0xff);
     }
     else{
       Serial2.print("nF4CRefDist.bco=");
       Serial2.print(65535);
       Serial2.write(0xff);
       Serial2.write(0xff);
       Serial2.write(0xff);
     }
    
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF4CBack");
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF4CNext");
        F4D_MachineSet();
        pageF4C.show();
        Serial.println("F4C_MachineSet");
        nF4CNoRefDist.setValue(GnoRefDist);
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF4CNextDist");
        nF4CNoRefDist.getValue(&GnoRefDist);
        GnoRefDist += 1;
        if(GnoRefDist >= 19) GnoRefDist = 19;
        nF4CNoRefDist.setValue(GnoRefDist);
        EEPROM.write(addressGnoRefDist, GnoRefDist);
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF4CPrevDist");
        nF4CNoRefDist.getValue(&GnoRefDist);
        GnoRefDist -= 1;
        if(GnoRefDist <= 0) GnoRefDist = 0;
        nF4CNoRefDist.setValue(GnoRefDist);
        EEPROM.write(addressGnoRefDist, GnoRefDist);
        break;
      case tMINUS:
        Tombol = tIDLE;
        Serial.println("bF4CMinus");
        nF4CRefDist.getValue(&GminDistSens[GnoRefDist]);    // minDistSens[GnoRefDist]
        GminDistSens[GnoRefDist] -= 1;
        if(GminDistSens[GnoRefDist] <= 1) GminDistSens[GnoRefDist] = 1;
        nF4CRefDist.setValue(GminDistSens[GnoRefDist]);
        EEPROM.write(addressGminDistSens[GnoRefDist], GminDistSens[GnoRefDist]);
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF4CPlus");
        nF4CRefDist.getValue(&GminDistSens[GnoRefDist]);
        GminDistSens[GnoRefDist] += 1;
        if(GminDistSens[GnoRefDist] >= 200) GminDistSens[GnoRefDist] = 200;   // range batas distance avoid 0 sampai 200 cm
        nF4CRefDist.setValue(GminDistSens[GnoRefDist]);
        EEPROM.write(addressGminDistSens, GminDistSens[GnoRefDist]);
        break;
      default:
        break;
    }
  }
}

void F4D_MachineSet(){
  pageF4D.show();
  Serial.println("F4D_MachineSet");
  G2_DigitalInput();
  while(true){
    nexLoop(nex_listen_list_F4D_MachineSet);
    G2_DigitalInputStatusDisplay();

    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF4DBack");
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF4DNext");
        F4E_MachineSet();
        pageF4D.show();
        G2_DigitalInput();
        Serial.println("F4D_MachineSet");
        break;
      default:
        break;
    }
  }
}

void F4E_MachineSet(){
  pageF4E.show();
  Serial.println("F4E_MachineSet");
  while(true){
    nexLoop(nex_listen_list_F4E_MachineSet);
    
    GsensorLine = random(-100, 100);
    memset(GbufferSensorLine, 0, sizeof(GbufferSensorLine));    // proses dari int to char
    itoa(GsensorLine, GbufferSensorLine, 10);        // proses dari int to char
    GsensorLine = map(GsensorLine, -100, 100, 0, 180);
    Serial2.print("zF4ELineSensor.val=");
    Serial2.print(GsensorLine);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    Serial2.print("tF4ELineSensor.txt=");
    Serial2.print("\"");
    Serial2.print(GbufferSensorLine);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF4EBack");
        return false;
        break;
      default:
        break;
    }
  }
}
