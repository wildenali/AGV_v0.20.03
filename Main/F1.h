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

void GOOO(){
  Serial.println("GO GO Gooo");
    
  Serial.println(idRFID[1]);
  Serial.println(idRFID[2]);
  Serial.println(idRFID[3]);
  Serial.println(idRFID[4]);
  
  
  while(true){
    nexLoop(nex_listen_list_F1B_Go);
    if(Tombol == tPAUSE)    return false;
    if(Tombol == tCANCEL)   return false;

    int x;
    x = z;
    Serial.print("NILAI x: ");
    Serial.println(x);
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
    
    Gmode = 0;// ini cuma nge reset Gmode aja
  
  }
}
