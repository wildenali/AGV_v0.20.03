void F2A_LogicSet();
void F2B_LogicSet();

void F2A_LogicSet(){
  pageF2A.show();
  Serial.println("F2A_LogicSet");
  bool i = 1;
  while(i){
    nexLoop(nex_listen_list_F2A_LogicSet);
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF2ABack");
        Menu = F0;
        i = 0;//return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF2ANext");
        F2B_LogicSet();
        pageF2A.show();
        Serial.println("F2A_LogicSet");
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2AUp");
        /*
         * Kondisi disini adalah dimana ketika tombol Up di pencet
         * maka tabel nye nge geser ke atas gitu
         */
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2ADown");
        /*
         * Kondisi disini adalah dimana ketika tombol Down di pencet
         * maka tabel nye nge geser ke bawah gitu 
         */
        break;
      default:
        break;
    }
  }
}

void F2B_LogicSet(){
  pageF2B.show();
  Serial.println("F2B_LogicSet");
  while(true){
    nexLoop(nex_listen_list_F2B_LogicSet);
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
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF2BUp");
        /*
         * Awalnya misalnya mode di pencet, nah ini bisa di edit angkanya
         * dengan cara pencet naik si tombol Up, nanti dia nambah nomornya (kalau di Mode)
         * kalau di Trigger, pilihannya ada RFID yg mana yg akan dijadikan sebgai triggernya
         * untuk aksinya bisa milih, mau stop, maju, mundur, atau lainya
         */
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF2BDown");
        /*
         * Awalnya misalnya mode di pencet, nah ini bisa di edit angkanya
         * dengan cara pencet naik si tombol Down, nanti dia nambah nomornya (kalau di Mode)
         * kalau di Trigger, pilihannya ada RFID yg mana yg akan dijadikan sebgai triggernya
         * untuk aksinya bisa milih, mau stop, maju, mundur, atau lainya
         */
        break;
      default:
        break;
    }
  }
}
