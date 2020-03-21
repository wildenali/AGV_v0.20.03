void F3A_RFID_Data();
void F3B_RFID_Data();
void F3C_RFID_Data();
void F3D_RFID_Data();

String dummyDataRFID(){
  int ret;
  char bufferDataRFID[100] = {0};
  if(analogRead(1) == 0)                                ret = 10001;
  else if(analogRead(1) > 0 && analogRead(1) <= 1000)   ret = 10002;
  else if(analogRead(1) > 1000)                         ret = 10003;
  
  memset(bufferDataRFID, 0, sizeof(bufferDataRFID));    // proses dari int to char
  itoa(ret, bufferDataRFID, 10);        // proses dari int to char
  return bufferDataRFID;
}

void F3A_RFID_Data(){
  pageF3A.show();
  Serial.println("F3A_RFID_Data");
  while(true){
    nexLoop(nex_listen_list_F3A_RFID_Data);
    Serial.println(dummyDataRFID());
    
    Serial2.print("tF2CRFID.txt=");
    Serial2.print("\"");
    Serial2.print(dummyDataRFID());
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF3ABack");
        Menu = F0;
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF3ANext");
        F3B_RFID_Data();
        pageF3A.show();
        Serial.println("F3A_RFID_Data");
        break;
      default:
        break;
    }
  }
}

void F3B_RFID_Data(){
  pageF3B.show();
  Serial.println("F3B_RFID_Data");
  while(true){
    nexLoop(nex_listen_list_F3B_RFID_Data);
    Serial2.print("tF3BId.txt=");
    Serial2.print("\"");
    Serial2.print(dummyDataRFID());
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF3BBack");
        return false;
        break;
      case tNEXT:
        Tombol = tIDLE;
        Serial.println("bF3BNext");
        F3C_RFID_Data();
        pageF3B.show();
        Serial.println("F3B_RFID_Data");
        break;
      case tSAVE:
        Tombol = tIDLE;
        Serial.println("bF3BSave");
        pageF3B.show();
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF3BUp");
        /*
         * Awalnya misalnya mode di pencet, nah ini bisa di edit angkanya
         * dengan cara pencet naik si tombol Up, nanti dia nambah nomornya (kalau di Mode)
         * kalau di Trigger, pilihannya ada RFID yg mana yg akan dijadikan sebgai triggernya
         * untuk aksinya bisa milih, mau stop, maju, mundur, atau lainya
         */
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF3BDown");
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

void F3C_RFID_Data(){
  pageF3C.show();
  Serial.println("F3C_RFID_Data");
  while(true){
    nexLoop(nex_listen_list_F3C_RFID_Data);
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF3CBack");
        return false;
        break;
      case tDELETE:
        Tombol = tIDLE;
        Serial.println("bF3CDelete");
        F3D_RFID_Data();
        pageF3C.show();
        Serial.println("F3C_RFID_Data");
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF3CUp");
        /*
         * Awalnya misalnya mode di pencet, nah ini bisa di edit angkanya
         * dengan cara pencet naik si tombol Up, nanti dia nambah nomornya (kalau di Mode)
         * kalau di Trigger, pilihannya ada RFID yg mana yg akan dijadikan sebgai triggernya
         * untuk aksinya bisa milih, mau stop, maju, mundur, atau lainya
         */
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF3CDown");
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

void F3D_RFID_Data(){
  pageF3D.show();
  Serial.println("F3D_RFID_Data");
  while(true){
    nexLoop(nex_listen_list_F3D_RFID_Data);
    switch(Tombol){
      case tYES:
        Tombol = tIDLE;
        Serial.println("bF3DYes");
        return false;
        break;
      case tNO:
        Tombol = tIDLE;
        Serial.println("bF3DNo");
        return false;
        break;
      default:
        break;
    }
  }
}
