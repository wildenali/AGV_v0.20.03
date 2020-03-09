uint32_t addressGmode = 0;
uint32_t Gmode;               // G for Global variable

void F1A_PlayMenu();
void F1B_Go();

void F1A_PlayMenu(){
  pageF1A.show();
  Serial.println("F1A_PlayMenu");
  Gmode = EEPROM.read(addressGmode);
  nF1ANum.setValue(Gmode);
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
        if(Gmode <= 1) Gmode = 1;
        nF1ANum.setValue(Gmode);
        EEPROM.write(addressGmode, Gmode);
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF1APlus");
        nF1ANum.getValue(&Gmode);
        Gmode += 1;
        if(Gmode >= 100) Gmode = 100;
        nF1ANum.setValue(Gmode);
        EEPROM.write(addressGmode, Gmode);
        break;
      default:
        break;
    }
  }
}

void F1B_Go(){
  pageF1B.show();
  Serial.println("F1B_Go");
  nF1BMode.setValue(Gmode);
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
        break;
      case tGO:
        Tombol = tIDLE;
        Serial.println("bF1BGo");
      default:
        break;
    }
  }
}
