uint32_t addressGmode = 0;
uint32_t Gmode;               // G for Global variable

void F1A_PlayMenu();
void F1B_Go();

void GOOO();
//void showActionF2B(int actionInt);

void F1A_PlayMenu(){
  pageF1A.show();
  Serial.println("F1A_PlayMenu");
//  Gmode = EEPROM.read(addressGmode);
  Gmode = 1;
  nF1ANum.setValue(Gmode);

  for(int i = 1; i <= jumlahData; i++){
    Serial.print(i);                Serial.print("_");
    Serial.print(modeKe[i]);        Serial.print("_");
    Serial.print(typeKe[i]);        Serial.print("_");
    Serial.print(triggerKe[i]);     Serial.print("_");
    Serial.print(actionKe[i]);      Serial.print("\n");
  }
  
  
  while(true){
    nexLoop(nex_listen_list_F1A_PlayMenu);
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF1ABack");
        Menu = F0;
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF1ANext");
        F1B_Go();
        pageF1A.show();
        Serial.println("F1A_PlayMenu");
        nF1ANum.setValue(Gmode);
        break;
      case tMINUS:
        Tombol = tIDLE;
        Serial.println("bF1AMinus");
        nF1ANum.getValue(&Gmode);
        Gmode -= 1;
        if(Gmode <= 1)            Gmode = 1;
        if(Gmode >= jumlahData)   Gmode = jumlahData;
        nF1ANum.setValue(Gmode);
//        EEPROM.write(addressGmode, Gmode);
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF1APlus");
        nF1ANum.getValue(&Gmode);
        Gmode += 1;
        if(Gmode <= 1)            Gmode = 1;
        if(Gmode >= jumlahData)   Gmode = jumlahData;
        nF1ANum.setValue(Gmode);
//        EEPROM.write(addressGmode, Gmode);
        break;
      default:
        break;
    }
  }
}


String nextTarget;
String prevTarget = "";
int z;

void F1B_Go(){
  pageF1B.show();
  Serial.println("F1B_Go");
// ================== disini untuk menentukan siapa si Next Target ============================
  int totalKe[1+jumlahData];
  for(int i = 1; i <= jumlahData; i++){
    totalKe[i] = 0;
    Serial.print(totalKe[i]);
  }
  Serial.println("_");
  for(int j = 1; j <= jumlahData; j++){
    for(int i = 1; i <= jumlahData; i++){
      if(modeKe[i] == j){
        totalKe[j] += 1;
      }
    }
  }
  Serial.print("Gmode: ");  Serial.println(Gmode);
  z = 0;
  for(int i = 1; i < Gmode; i++){
    Serial.println(totalKe[i]);
    z += totalKe[i];
  }
  z = z + 1;
  
  Serial.print("z: ");  Serial.println(z);
  Serial.print("TIPEnya: ");  Serial.println(typeKe[z]);
  Serial.print("TRIGGER DI: ");  Serial.print(triggerKe[z]);

  
  if(typeKe[z] == 1){
    nextTarget = idRFID[z]; 
  }
  else if(typeKe[z] == 2){
    nextTarget = stringDI(triggerKe[z]);
  }
  else{
    nextTarget = "TIDAK ADA";
  }
  Serial.print("nextTarget: ");  Serial.println(nextTarget);
// ================== disini untuk menentukan siapa si Next Target ============================
  
  nF1BMode.setValue(Gmode);
  Serial2.print("gF1BStatusMode.txt=");
  Serial2.print("\"");
  Serial2.print("Stanby <->");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  
  Serial2.print("tF1BNextID.txt=");
  Serial2.print("\"");
  Serial2.print(nextTarget);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff); 
  
  while(true){
    nexLoop(nex_listen_list_F1B_Go);
    switch(Tombol){
      case tCANCEL:
        Tombol = tIDLE;
        Serial.println("bF1BCancel");
        return false;
        break;
      case tPAUSE:
        Tombol = tIDLE;
        Serial.println("bF1BPause");

        Serial2.print("gF1BStatusMode.txt=");
        Serial2.print("\"");
        Serial2.print("Stop  X");
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("bF1BGo.bco=");
        Serial2.print(50712);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        
        break;
      case tGO:
        Tombol = tIDLE;
        Serial.println("bF1BGo");
        
        for(int i = 3; i >= 1; i--){    // count down for go
          Serial2.print("gF1BStatusMode.txt=");
          Serial2.print("\"");
          Serial2.print(i);
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          delay(100);
        }
        
        Serial2.print("gF1BStatusMode.txt=");
        Serial2.print("\"");
        Serial2.print("Jalan  -->>");
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("bF1BGo.bco=");
        Serial2.print(1500);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        GOOO();
        
      default:
        break;
    }
  }
}

//    Serial.print(i);                Serial.print("_");
//    Serial.print(modeKe[i]);        Serial.print("_");
//    Serial.print(typeKe[i]);        Serial.print("_");
//    Serial.print(triggerKe[i]);     Serial.print("_");
//    Serial.print(actionKe[i]);      Serial.print("\n");

void GOOO(){
  Serial.println("GO GO Gooo");
  
//  Serial2.print("tF1BNextID.txt=");
//  Serial2.print("\"");
//  Serial2.print(nextID);
//  Serial2.print("\"");
//  Serial2.write(0xff);
//  Serial2.write(0xff);
//  Serial2.write(0xff);
  
  Serial.println(idRFID[1]);
  Serial.println(idRFID[2]);
  Serial.println(idRFID[3]);
  Serial.println(idRFID[4]);
  
  
  while(true){
    nexLoop(nex_listen_list_F1B_Go);
    if(Tombol == tPAUSE)    return false;
    if(Tombol == tCANCEL)   return false;

///* // ============== versi 1.6 ==============
    int x;
//    if(Gmode == 1){
//      x = 1;
//    }
//    else if(Gmode == 2){
//      x = 5;
//    }

    x = z;
    Serial.print("NILAI x: ");
    Serial.println(x);
//    x = 1;
//    while(Gmode == 1)
//    while(Gmode)
    while(true)
    {
      // lineFollower();
      nexLoop(nex_listen_list_F1B_Go);
      if(Tombol == tPAUSE)    return false;
      if(Tombol == tCANCEL)   return false;
      
      switch(typeKe[x]){
        case typeRFID:
          if(idRFID[x] == dummyDataRFID() && nextTarget == idRFID[x])
          {
            Serial.print(" nowID: ");     Serial.print(dummyDataRFID());
            prevTarget = idRFID[x];
            
            actionKe[x];
            Serial.print(" actionKe ");   Serial.print(x);
            Serial.print(" : ");          Serial.println(stringAction(x));    //showActionF2B(actionKe[x]);
            
            x++;
            nextTarget = idRFID[x];     // ini harus ++x;
            Serial.print(" prevTarget: ");    Serial.print(prevTarget);
            Serial.print(" nextTarget: ");    Serial.print(nextTarget);
            Serial.print("\n");
  
            Serial2.print("tF1BPrevID.txt=");
            Serial2.print("\"");
            Serial2.print(prevTarget);
            Serial2.print("\"");
            Serial2.write(0xff);
            Serial2.write(0xff);
            Serial2.write(0xff);
  
            Serial2.print("tF1BNextID.txt=");
            Serial2.print("\"");
            Serial2.print(nextTarget);
            Serial2.print("\"");
            Serial2.write(0xff);
            Serial2.write(0xff);
            Serial2.write(0xff);
          }
          break;
        case typeDI:
          Serial2.print("tF1BNextID.txt=");
          Serial2.print("\"");
          Serial2.print("Ayo KEMANA");
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          break;
        default:
          break;  
      }

      
    }

//    x = 5;
//    while(Gmode == 2)
//    {
//      // lineFollower();
//      nexLoop(nex_listen_list_F1B_Go);
//      if(Tombol == tPAUSE)    return false;
//      if(Tombol == tCANCEL)   return false;
//              
//        if(idRFID[x] == dummyDataRFID() && nextTarget == idRFID[x])
//        {
//          Serial.print(" nowID: ");     Serial.print(dummyDataRFID());
//          prevTarget = idRFID[x];
//          actionKe[x];
//          Serial.print(" actionKe ");   Serial.print(x);
//          Serial.print(" : ");          Serial.println(stringAction(x));    //showActionF2B(actionKe[x]);
//          x++;
//          nextTarget = idRFID[x];     // ini harus ++x;
//          Serial.print(" prevTarget: ");    Serial.print(prevTarget);
//          Serial.print(" nextTarget: ");    Serial.print(nextTarget);
//          Serial.print("\n");
//
//          Serial2.print("tF1BPrevID.txt=");
//          Serial2.print("\"");
//          Serial2.print(prevTarget);
//          Serial2.print("\"");
//          Serial2.write(0xff);
//          Serial2.write(0xff);
//          Serial2.write(0xff);
//
//          Serial2.print("tF1BNextID.txt=");
//          Serial2.print("\"");
//          Serial2.print(nextTarget);
//          Serial2.print("\"");
//          Serial2.write(0xff);
//          Serial2.write(0xff);
//          Serial2.write(0xff);
//        } 
//    }



    
    Gmode = 0;// ini cuma nge reset Gmode aja
///* // ============== versi 1.6 ==============



  
  }
}


void showActionF2B(int actionInt){
  if     (actionInt == 0)     Serial.print("");
  else if(actionInt == 1)     Serial.print("Berhenti");
  else if(actionInt == 2)     Serial.print("Maju");
  else if(actionInt == 3)     Serial.print("Belok Kiri");
  else if(actionInt == 4)     Serial.print("Belok Kanan");
  else if(actionInt == 5)     Serial.print("Balik Kiri");
  else if(actionInt == 6)     Serial.print("Balik Kanan");
  else if(actionInt == 7)     Serial.print("Lift On");
  else if(actionInt == 8)     Serial.print("Lift Off");
  else if(actionInt == 9)     Serial.print("Buzzer On");
  else if(actionInt == 10)    Serial.print("Buzzer Off");
  else if(actionInt == 11)    Serial.print("DO 01,HIGH");
  else if(actionInt == 12)    Serial.print("DO 01,LOW");
  else if(actionInt == 13)    Serial.print("DO 02,HIGH");
  else if(actionInt == 14)    Serial.print("DO 02,LOW");
  else if(actionInt == 15)    Serial.print("DO 03,HIGH");
  else if(actionInt == 16)    Serial.print("DO 03,LOW");
  else if(actionInt == 17)    Serial.print("DO 04,HIGH");
  else if(actionInt == 18)    Serial.print("DO 04,LOW");
  else if(actionInt == 19)    Serial.print("DO 05,HIGH");
  else if(actionInt == 20)    Serial.print("DO 05,LOW");
}











/* // ============== versi 1 ==============
    while(Gmode == 1)
    {
      // lineFollower();
      if(idRFID[1] == dummyDataRFID())
      {
        actionKe[1];
        Serial.println(actionKe[1]);
      }
    }
*/ // ============== versi 1 ==============


/* // ============== versi 1.1 ==============
    while(Gmode == 1)
    {
      // lineFollower();
      Serial.print(idRFID[1]); Serial.print("\t");
      Serial.print(dummyDataRFID()); Serial.print("\t");
      if(idRFID[1] == dummyDataRFID())
      {
        actionKe[1];
        Serial.println(actionKe[1]);
      }
      else{
        Serial.println("NO");
      }
    }
*/ // ============== versi 1.1 ==============

/* // ============== versi 2 ==============
    while(Gmode == 1)
    {
      // lineFollower();
      
      for(int i = 1; i <= jumlahData; i++){
        if(type == typeRFID){
          if(idRFID[i] == dummyDataRFID())
          {
            actionKe[i];
            Serial.println(actionKe[i]);
          } 
        }
        if(type == typeDI){
          if(idRFID[i] == dummyDataRFID())
          {
            actionKe[i];
            Serial.println(actionKe[i]);
          } 
        }
        if(type == typeDO){
          if(idRFID[i] == dummyDataRFID())
          {
            actionKe[i];
            Serial.println(actionKe[i]);
          } 
        }
      }
      
    }
*/ // ============== versi 2 ==============

/* // ============== versi 1.2 ==============
    while(Gmode == 1)
    {
      // lineFollower();
      nexLoop(nex_listen_list_F1B_Go);
      if(Tombol == tPAUSE)    return false;
      if(Tombol == tCANCEL)   return false;
      
      for(int i = 1; i <= jumlahData; i++){
        if(nextTarget == dummyDataRFID())
//        if(idRFID[i] == dummyDataRFID())
        {
          Serial.print("ke ");          Serial.print(i);
          Serial.print(" : ");          Serial.print(idRFID[i]);
          Serial.print(" nowID: ");     Serial.print(dummyDataRFID());
          Serial.print(" actionKe ");   Serial.print(actionKe[i]);
          Serial.print(" : ");           showActionF2B(actionKe[i]);
          
          nextTarget = idRFID[++i];     // ini harus ++x;
          Serial.print(" nextTarget: ");    Serial.print(nextTarget);
          Serial.print("\n");
        }
      }
      
    }
    Gmode = 0;// ini cuma nge reset Gmode aja
*/ // ============== versi 1.2 ==============


/* // ============== versi 1.3 ==============
    while(Gmode == 1)
    {
      // lineFollower();
      nexLoop(nex_listen_list_F1B_Go);
      if(Tombol == tPAUSE)    return false;
      if(Tombol == tCANCEL)   return false;
      
      for(int i = 1; i <= jumlahData; i++){
        Serial.print("ke ");          Serial.print(i);
        Serial.print(" : ");          Serial.print(idRFID[i]);
        Serial.print(" nowID: ");     Serial.print(dummyDataRFID());
        
        if(idRFID[i] == dummyDataRFID())
        {
          prevTarget = idRFID[i];
          actionKe[i];
          Serial.print(" actionKe ");   Serial.print(i);
          Serial.print(" : ");          showActionF2B(actionKe[i]);          
          nextTarget = idRFID[++i];     // ini harus ++x;
        }else{
          Serial.print(" actionKe ");   Serial.print(actionKe[0]);
          Serial.print(" : ");          showActionF2B(0);
        }

        Serial.print(" prevTarget: ");    Serial.print(prevTarget);
        Serial.print(" nextTarget: ");    Serial.print(nextTarget);
        Serial.print("\n");
      }
      
    }
    Gmode = 0;// ini cuma nge reset Gmode aja
*/ // ============== versi 1.3 ==============

/* // ============== versi 1.4 ==============
    while(Gmode == 1)
    {
      // lineFollower();
      nexLoop(nex_listen_list_F1B_Go);
      if(Tombol == tPAUSE)    return false;
      if(Tombol == tCANCEL)   return false;
      
      for(int i = 1; i <= jumlahData; i++){
        Serial.print("ke ");          Serial.print(i);
        Serial.print(" : ");          Serial.print(idRFID[i]);
        Serial.print(" nowID: ");     Serial.print(dummyDataRFID());
        
        if(idRFID[i] == dummyDataRFID() && nextTarget == idRFID[i])
        {
          prevTarget = idRFID[i];
          actionKe[i];
          Serial.print(" actionKe ");   Serial.print(i);
          Serial.print(" : ");          showActionF2B(actionKe[i]);          
          nextTarget = idRFID[++i];     // ini harus ++x;
        }
        else{
          Serial.print(" actionKe ");   Serial.print(actionKe[0]);
          Serial.print(" : ");          showActionF2B(0);
        }

        Serial.print(" prevTarget: ");    Serial.print(prevTarget);
        Serial.print(" nextTarget: ");    Serial.print(nextTarget);
        Serial.print("\n");
      }
      
    }
    Gmode = 0;// ini cuma nge reset Gmode aja
*/ // ============== versi 1.4 ==============

/* // ============== versi 1.5 fix ver A==============
    while(Gmode == 1)
    {
      // lineFollower();
      nexLoop(nex_listen_list_F1B_Go);
      if(Tombol == tPAUSE)    return false;
      if(Tombol == tCANCEL)   return false;
      
      for(int i = 1; i <= jumlahData; i++){
        
        if(idRFID[i] == dummyDataRFID() && nextTarget == idRFID[i])
        {
          Serial.print("ke ");          Serial.print(i);
          Serial.print(" : ");          Serial.print(idRFID[i]);
          Serial.print(" nowID: ");     Serial.print(dummyDataRFID());
        
          prevTarget = idRFID[i];
          actionKe[i];
          Serial.print(" actionKe ");   Serial.print(i);
          Serial.print(" : ");          showActionF2B(actionKe[i]);          
          nextTarget = idRFID[++i];     // ini harus ++x;

          Serial.print(" prevTarget: ");    Serial.print(prevTarget);
          Serial.print(" nextTarget: ");    Serial.print(nextTarget);
          Serial.print("\n");
        }

      }
      
    }
    Gmode = 0;// ini cuma nge reset Gmode aja
*/ // ============== versi 1.5 fix ver A==============
