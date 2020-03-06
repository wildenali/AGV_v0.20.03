void F1A_PlayMenu();
void F1B_Go();

void F1A_PlayMenu(){
  pageF1A.show();
  Serial.println("F1A_PlayMenu");
  bool i = 1;
  while(i){
    nexLoop(nex_listen_list_F1A_PlayMenu);
    uint32_t number;
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF1ABack");
        Menu = F0;
        i = 0;//return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF1ANext");
        F1B_Go();
        pageF1A.show();
        Serial.println("F1A_PlayMenu");
        break;
      case tMINUS:
        Tombol = tIDLE;
        Serial.println("bF1AMinus");
        nF1ANum.getValue(&number);
        number -= 1;
        if(number <= 1) number = 1;
        nF1ANum.setValue(number);
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF1APlus");
        nF1ANum.getValue(&number);
        number += 1;
        if(number >= 100) number = 100;
        nF1ANum.setValue(number);
        break;
      default:
        break;
    }
  }
}

void F1B_Go(){
  pageF1B.show();
  Serial.println("F1B_Go"); 
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
