void F1A_PlayMenu();
void F1B_Go();

void GOOO();
void LetsGOOO(int responseLetsGo);

int doAction(int statusDoAction);

void doAction_Berhenti();
void doAction_Maju();
void doAction_BelokKiri();
void doAction_BelokKanan();
void doAction_BalikKiri();
void doAction_BalikKanan();
void doAction_LiftOn();
void doAction_LiftOff();
void doAction_BuzzerOn();
void doAction_BuzzerOff();
void doAction_DO(int pinDO);
void doAction_LORA(String dataDoActionLORA);

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

void F1A_PlayMenu(){
  pageF1A.show();
  Serial.println("F1A_PlayMenu");
  Gmode = 1;
  nF1ANum.setValue(Gmode);

//  for(int i = 1; i <= jumlahData; i++){
//    Serial.print(i);                Serial.print("_");
//    Serial.print(modeKe[i]);        Serial.print("_");
//    Serial.print(typeKe[i]);        Serial.print("_");
//    Serial.print(triggerKe[i]);     Serial.print("_");
//    Serial.print(actionKe[i]);      Serial.print("\n");
//  }
  
  
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
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF1APlus");
        nF1ANum.getValue(&Gmode);
        Gmode += 1;
        if(Gmode <= 1)            Gmode = 1;
        if(Gmode >= jumlahData)   Gmode = jumlahData;
        nF1ANum.setValue(Gmode);
        break;
      default:
        break;
    }
  }
}


//String nextTarget;
//String prevTarget = "";
//int urutanKe;
//int urutanLastTarget;

void F1B_Go(){
  pageF1B.show();
  Serial.println("F1B_Go");
// ================== disini untuk menentukan siapa si Next Target ============================
  int totalKe[1+jumlahData];
  for(int i = 1; i <= jumlahData; i++){ // reset totalKe[]
    totalKe[i] = 0;
    Serial.print(totalKe[i]);
  }
  
  Serial.println("\n");
  for(int j = 1; j <= jumlahData; j++){
    for(int i = 1; i <= jumlahData; i++){
      if(modeKe[i] == j){
        totalKe[j] += 1;
      }
    }
  }
  urutanKe = 0;
  for(int i = 1; i < Gmode; i++){
    urutanKe += totalKe[i];
  }
  urutanKe = urutanKe + 1;

  if(typeKe[urutanKe] == 1){
    nextTarget = idRFID[triggerKe[urutanKe]];
  }
  else if(typeKe[urutanKe] == 2){
    nextTarget = stringDI(triggerKe[urutanKe]);
  }
  else if(typeKe[urutanKe] == 3){
    nextTarget = stringLORA(triggerKe[urutanKe]);
  }
  else{
    nextTarget = "TIDAK ADA";
  }
  Serial.print("urutanKe    : ");  Serial.println(urutanKe);
  Serial.print("Gmode       : ");  Serial.println(Gmode);
  Serial.print("TIPEnya     : ");  Serial.println(typeKe[urutanKe]);
  Serial.print("TRIGGER DI  : ");  Serial.println(triggerKe[urutanKe]);
  Serial.print("Action DI   : ");  Serial.println(actionKe[urutanKe]);
  Serial.print("nextTarget  : ");  Serial.println(nextTarget);

  Serial.println("=========================================");
  Serial.print("totalKe[");   Serial.print(Gmode);
  Serial.print("] : ");       Serial.println(totalKe[Gmode]);
  urutanLastTarget = totalKe[Gmode] + urutanKe - 1;
  Serial.print("urutanLastTarget:");   Serial.println(urutanLastTarget);
  
  nF1BMode.setValue(Gmode);
  Serial2.print("gF1BStatusMode.txt=");
  Serial2.print("\"");
  Serial2.print("Stanby <->");
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  
  Serial2.print("tF1BNextTarget.txt=");
  Serial2.print("\"");
  Serial2.print(nextTarget);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff); 

  Serial2.print("tF1BNextAction.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionKe[urutanKe]));
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
      case tSTOP:
        Tombol = tIDLE;
        Serial.println("bF1BStop");

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

int response = 0;

void GOOO(){
  response = 0;
  Serial.println("GO GO Gooo");

  Serial2.print("tF1BNextTarget.txt=");
  Serial2.print("\"");
  Serial2.print(nextTarget);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  
  Serial2.print("tF1BNextAction.txt=");
  Serial2.print("\"");
  Serial2.print(stringAction(actionKe[urutanKe]));
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  
  String scanRFID;
  String messageFromLora;
  messageFromLora = "";
  
  while(true)
  { 
    LetsGOOO(response);
    
    nexLoop(nex_listen_list_F1B_Go);
    Usb.Task();

//    Serial.println(scanRFID);
    
    if(scanFinished == true){
      scanRFID = scanResult;
      scanFinished = false;
      scanResult = "";
    }
    
    if(Tombol == tSTOP)    return false;
    if(Tombol == tCANCEL)   return false;
    
    switch(typeKe[urutanKe]){
      case typeRFID:
        if(idRFID[triggerKe[urutanKe]] == scanRFID && nextTarget == idRFID[triggerKe[urutanKe]])
        {
          prevTarget = idRFID[triggerKe[urutanKe]];
          actionKe[urutanKe];
          stringAction(actionKe[urutanKe]); // ini untuk tampilan ke serial monitor

          Serial.print(" urutanKe       : ");   Serial.println(urutanKe);
          Serial.print(" prevTarget     : ");   Serial.println(prevTarget);
          Serial.print(" stringAction   : ");   Serial.println(stringAction(actionKe[urutanKe]));

          Serial.print(" nowRFID        : ");   Serial.println(scanRFID);
          Serial.print(" actionKe[]     : ");   Serial.println(actionKe[urutanKe]);
          response = doAction(actionKe[urutanKe]);

          if(urutanKe == urutanLastTarget){
            Tombol = tCANCEL;
            return false;
          }
          
          Serial2.print("tF1BPrevTarget.txt=");
          Serial2.print("\"");
          Serial2.print(prevTarget);
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          
          Serial2.print("tF1BPrevAction.txt=");
          Serial2.print("\"");
          Serial2.print(stringAction(actionKe[urutanKe]));
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);

          // Tempatkan ini di bawah, karena ini increment dari urutanKe, sehingga nextTarget berubah
          urutanKe++;
          if(typeKe[urutanKe] == 1){
            nextTarget = idRFID[triggerKe[urutanKe]];
          }
          else if(typeKe[urutanKe] == 2){
            nextTarget = stringDI(triggerKe[urutanKe]);
          }
          else if(typeKe[urutanKe] == 3){
            nextTarget = stringLORA(triggerKe[urutanKe]);
          }
          Serial.print(" nextTarget     : ");   Serial.println(nextTarget);
          Serial.print(" stringAction   : ");   Serial.println(stringAction(actionKe[urutanKe]));

          
          Serial2.print("tF1BNextTarget.txt=");
          Serial2.print("\"");
          Serial2.print(nextTarget);
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);

          Serial2.print("tF1BNextAction.txt=");
          Serial2.print("\"");
          Serial2.print(stringAction(actionKe[urutanKe]));
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          
          Serial.print(" urutanKe-------: ");   Serial.println(urutanKe);
        }
        break;
      case typeDI:
        bool statusDI;
        if(nextTarget.substring(5,6) == "H")  statusDI = HIGH;
        else                                  statusDI = LOW;
        
        if(digitalRead(digitalInput[(nextTarget.substring(3,4)).toInt()]) == statusDI && nextTarget == stringDI(triggerKe[urutanKe]))
        {
          prevTarget = stringDI(triggerKe[urutanKe]);
          actionKe[urutanKe];
          stringAction(actionKe[urutanKe]); // ini untuk tampilan ke serial monitor

          Serial.print(" urutanKe       : ");   Serial.println(urutanKe);
          Serial.print(" prevTarget     : ");   Serial.println(prevTarget);
          Serial.print(" stringAction   : ");   Serial.println(stringAction(actionKe[urutanKe]));

          Serial.print(" nowRFID        : ");   Serial.println(scanRFID);
          Serial.print(" actionKe[]     : ");   Serial.println(actionKe[urutanKe]);
          response = doAction(actionKe[urutanKe]);

          if(urutanKe == urutanLastTarget){
            Tombol = tCANCEL;
            return false;
          }
          
          Serial2.print("tF1BPrevTarget.txt=");
          Serial2.print("\"");
          Serial2.print(prevTarget);
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          
          Serial2.print("tF1BPrevAction.txt=");
          Serial2.print("\"");
          Serial2.print(stringAction(actionKe[urutanKe]));
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);

          // Tempatkan ini di bawah, karena ini increment dari urutanKe, sehingga nextTarget berubah
          urutanKe++;
          if(typeKe[urutanKe] == 1){
            nextTarget = idRFID[triggerKe[urutanKe]];
          }
          else if(typeKe[urutanKe] == 2){
            nextTarget = stringDI(triggerKe[urutanKe]);
          }
          else if(typeKe[urutanKe] == 3){
            nextTarget = stringLORA(triggerKe[urutanKe]);
          }
          Serial.print(" nextTarget     : ");   Serial.println(nextTarget);
          Serial.print(" stringAction   : ");   Serial.println(stringAction(actionKe[urutanKe]));

          
          Serial2.print("tF1BNextTarget.txt=");
          Serial2.print("\"");
          Serial2.print(nextTarget);
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);

          Serial2.print("tF1BNextAction.txt=");
          Serial2.print("\"");
          Serial2.print(stringAction(actionKe[urutanKe]));
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          
          Serial.print(" urutanKe-------: ");   Serial.println(urutanKe);
        }
        break;
      case typeLORA:
        if(Serial3.available()){                      // cek bahwa si lora node mengirim data cuma satu kali aja, sebenernya dia punya program otomatisasi kalau ga ke kirim, bakal ngirim lagi, karena ada callback,,,,, pokonya si lora node harus ngirim sekali aja
          messageFromLora = Serial3.readString();
        }

        if(stringLORA(triggerKe[urutanKe]) == messageFromLora && nextTarget == stringLORA(triggerKe[urutanKe]))
        {
          Serial.print(" urutanKe-------: ");   Serial.println(urutanKe);
          prevTarget = stringLORA(triggerKe[urutanKe]);
          actionKe[urutanKe];
          stringAction(actionKe[urutanKe]); // ini untuk tampilan ke serial monitor

          response = doAction(actionKe[urutanKe]);

          if(urutanKe == urutanLastTarget){
            Tombol = tCANCEL;
            return false;
          }
          
          Serial2.print("tF1BPrevTarget.txt=");
          Serial2.print("\"");
          Serial2.print(prevTarget);
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          
          Serial2.print("tF1BPrevAction.txt=");
          Serial2.print("\"");
          Serial2.print(stringAction(actionKe[urutanKe]));
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);

          // Tempatkan ini di bawah, karena ini increment dari urutanKe, sehingga nextTarget berubah
          urutanKe++;
          if(typeKe[urutanKe] == 1){
            nextTarget = idRFID[triggerKe[urutanKe]];
          }
          else if(typeKe[urutanKe] == 2){
            nextTarget = stringDI(triggerKe[urutanKe]);
          }
          else if(typeKe[urutanKe] == 3){
            nextTarget = stringLORA(triggerKe[urutanKe]);
          }
          Serial.print(" nextTarget     : ");   Serial.println(nextTarget);
          Serial.print(" stringAction   : ");   Serial.println(stringLORA(triggerKe[urutanKe]));

          Serial2.print("tF1BNextTarget.txt=");
          Serial2.print("\"");
          Serial2.print(nextTarget);
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);

          Serial2.print("tF1BNextAction.txt=");
          Serial2.print("\"");
          Serial2.print(stringAction(actionKe[urutanKe]));
          Serial2.print("\"");
          Serial2.write(0xff);
          Serial2.write(0xff);
          Serial2.write(0xff);
          
          Serial.print(" urutanKe-------: ");   Serial.println(urutanKe);
          messageFromLora = "";
        }
        break;
      default:
        break;  
    }


    
  }
}

int pwmKiri, pwmKanan;

void LetsGOOO(int responseLetsGo){
  
  nexLoop(nex_listen_list_F1B_Go);
  if(Tombol == tSTOP)    return false;
  if(Tombol == tCANCEL)   return false;

  if(responseLetsGo == 1){
    pwmKiri = 0;
    pwmKanan = 0;
  }else{
    pwmKiri = 225;
    pwmKanan = 225;
  }

//  Serial.print("pwmKiri: ");    Serial.print(pwmKiri);  Serial.print("\t pwmKanan: ");   Serial.println(pwmKanan);
    
}

int doAction(int statusDoAction){
       if(statusDoAction == 0)    return 0;   // kosong
  else if(statusDoAction == 1)    {doAction_Berhenti();           return 1;}   // berhenti
  else if(statusDoAction == 2)    {doAction_Maju();               return 2;}   // maju
  else if(statusDoAction == 3)    {doAction_BelokKiri();          return 3;}
  else if(statusDoAction == 4)    {doAction_BelokKanan();         return 4;}
  else if(statusDoAction == 5)    {doAction_BalikKiri();          return 5;}
  else if(statusDoAction == 6)    {doAction_BelokKanan();         return 6;}
  else if(statusDoAction == 7)    {doAction_LiftOn();             return 7;}
  else if(statusDoAction == 8)    {doAction_LiftOff();            return 8;}
  else if(statusDoAction == 9)    {doAction_BuzzerOn();           return 9;}
  else if(statusDoAction == 10)   {doAction_BuzzerOff();          return 10;}
  else if(statusDoAction == 11)   {doAction_DO(statusDoAction);   return 11;}   // seharusnya bukan (statusDoAction), tapi pin nya, ntar di benerin deh
  else if(statusDoAction == 12)   {doAction_DO(statusDoAction);   return 12;}
  else if(statusDoAction == 13)   {doAction_DO(statusDoAction);   return 13;}
  else if(statusDoAction == 14)   {doAction_DO(statusDoAction);   return 14;}
  else if(statusDoAction == 15)   {doAction_DO(statusDoAction);   return 15;}
  else if(statusDoAction == 16)   {doAction_DO(statusDoAction);   return 16;}
  else if(statusDoAction == 17)   {doAction_DO(statusDoAction);   return 17;}
  else if(statusDoAction == 18)   {doAction_DO(statusDoAction);   return 18;}
  else if(statusDoAction == 19)   {doAction_DO(statusDoAction);   return 19;}
  else if(statusDoAction == 20)   {doAction_DO(statusDoAction);   return 20;}
  else if(statusDoAction == 21)   {doAction_LORA("Tx_1");         return 21;}
  else if(statusDoAction == 22)   {doAction_LORA("Tx_2");         return 22;}
  else if(statusDoAction == 23)   {doAction_LORA("Tx_3");         return 23;}
  else if(statusDoAction == 24)   {doAction_LORA("Tx_4");         return 24;}
  else if(statusDoAction == 25)   {doAction_LORA("Tx_5");         return 25;}
}

void doAction_Berhenti(){
  // pura pura belok Berhenti
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(63488);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_Maju(){
  // pura pura belok Maju
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(34784);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_BelokKiri(){
  // pura pura belok kiri
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(1500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_BelokKanan(){
  // pura pura belok Kanan
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(64512);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_BalikKiri(){
  // pura pura Balik kiri
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(1500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(0);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_BalikKanan(){
  // pura pura Balik Kanan
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(64512);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(0);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }  
}

void doAction_LiftOn(){
  // pura pura Lift On
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(64543);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_LiftOff(){
  // pura pura Lift On
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(34815);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_BuzzerOn(){
  // pura pura Buzzer On
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(33792);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_BuzzerOff(){
  // pura pura Buzzer Off
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(50712);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_DO(int pinDO){
  // pura pura Buzzer Off
  for(int i = 0; i <= 10; i++){
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(3000 + pinDO*100);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
}

void doAction_LORA(String dataDoActionLORA){
  if(dataDoActionLORA == "Tx_1"){
    Serial3.print(dataDoActionLORA);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
  else if(dataDoActionLORA == "Tx_2"){
    Serial3.print(dataDoActionLORA);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4600);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
  else if(dataDoActionLORA == "Tx_3"){
    Serial3.print(dataDoActionLORA);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4700);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
  else if(dataDoActionLORA == "Tx_4"){
    Serial3.print(dataDoActionLORA);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4800);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
  else if(dataDoActionLORA == "Tx_5"){
    Serial3.print(dataDoActionLORA);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4900);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(4500);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
    Serial2.print("tF1BNextAction.bco=");
    Serial2.print(65504);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    delay(200);
  }
  
}
