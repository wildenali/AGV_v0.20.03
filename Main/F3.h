void F3A_RFID_Data();
void F3B_RFID_Data();
void F3C_RFID_Data();
void F3D_RFID_Data();

void F3A_RFID_Data(){
  pageF3A.show();
  Serial.println("F3A_RFID_Data");

  int noA, noB, noC;
  noID = 1;
  noA = noID + 0;
  noB = noID + 1;
  noC = noID + 2;
  
  Serial2.print("nF3ANoA.val=");
  Serial2.print(noA);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.print("nF3ANoB.val=");
  Serial2.print(noB);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.print("nF3ANoC.val=");
  Serial2.print(noC);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF3ARFIDA.txt=");
  Serial2.print("\"");
  Serial2.print(idRFID[noA]);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.print("tF3ARFIDB.txt=");
  Serial2.print("\"");
  Serial2.print(idRFID[noB]);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.print("tF3ARFIDC.txt=");
  Serial2.print("\"");
  Serial2.print(idRFID[noC]);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  scanResult = "";
  Serial2.print("tF3ARFIDRead.txt=");
  Serial2.print("\"");
  Serial2.print(scanResult);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  while(true){
    nexLoop(nex_listen_list_F3A_RFID_Data);
    Usb.Task();

    if(scanFinished == true){
      Serial2.print("tF3ARFIDRead.txt=");
      Serial2.print("\"");
      Serial2.print(scanResult);
      Serial2.print("\"");
      Serial2.write(0xff);
      Serial2.write(0xff);
      Serial2.write(0xff);
      scanFinished = false;
      scanResult = "";
    }
    
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
        
        noID = 1;
        noA = noID + 0;
        noB = noID + 1;
        noC = noID + 2;
        
        Serial2.print("nF3ANoA.val=");
        Serial2.print(noA);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("nF3ANoB.val=");
        Serial2.print(noB);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("nF3ANoC.val=");
        Serial2.print(noC);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
      
        Serial2.print("tF3ARFIDA.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noA]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("tF3ARFIDB.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noB]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("tF3ARFIDC.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noC]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF3ADown");
        noID++;
        if(noID >= jumlahData - 2)  noID = jumlahData - 2;    //if(noID >= 8)  noID = 8;
        noA = noID + 0;
        noB = noID + 1;
        noC = noID + 2;
        Serial2.print("nF3ANoA.val=");
        Serial2.print(noA);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("nF3ANoB.val=");
        Serial2.print(noB);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("nF3ANoC.val=");
        Serial2.print(noC);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("tF3ARFIDA.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noA]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("tF3ARFIDB.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noB]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("tF3ARFIDC.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noC]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF3AUp");
        noID--;
        if(noID <= 3)  noID = 3;
        noA = noID - 2;
        noB = noID - 1;
        noC = noID - 0;
        Serial2.print("nF3ANoA.val=");
        Serial2.print(noA);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("nF3ANoB.val=");
        Serial2.print(noB);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("nF3ANoC.val=");
        Serial2.print(noC);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("tF3ARFIDA.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noA]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("tF3ARFIDB.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noB]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.print("tF3ARFIDC.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noC]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      default:
        break;
    }
  }
}


void F3B_RFID_Data(){
  pageF3B.show();
  Serial.println("F3B_RFID_Data");

  noID = 1;
  
  Serial2.print("nF3BNoID.val=");
  Serial2.print(noID);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF3BRFID.txt=");
  Serial2.print("\"");
  Serial2.print(idRFID[noID]);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  
  String saveScanResult;
  while(true){
    nexLoop(nex_listen_list_F3B_RFID_Data);
    Usb.Task();
    
    if(scanFinished == true){
      saveScanResult = scanResult;
      Serial2.print("tF3BRFIDRead.txt=");
      Serial2.print("\"");
      Serial2.print(saveScanResult);
      Serial2.print("\"");
      Serial2.write(0xff);
      Serial2.write(0xff);
      Serial2.write(0xff);
      scanFinished = false;
      scanResult = "";
    }
    
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

        noID = 1;
        Serial2.print("nF3BNoID.val=");
        Serial2.print(noID);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("tF3BRFID.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noID]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF3BUp");
        
        noID++;
        if(noID >= jumlahData)  noID = jumlahData;
        Serial2.print("nF3BNoID.val=");
        Serial2.print(noID);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("tF3BRFID.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noID]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF3BDown");

        noID--;
        if(noID <= 1)  noID = 1;
        Serial2.print("nF3BNoID.val=");
        Serial2.print(noID);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        
        Serial2.print("tF3BRFID.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noID]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      case tSAVE:
        Tombol = tIDLE;
        Serial.println("bF3BSave");
        pageF3B.show();
        Serial2.print("nF3BNoID.val=");
        Serial2.print(noID);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        idRFID[noID] = saveScanResult;
        
        Serial2.print("tF3BRFID.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noID]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        EEPROM_writeString(addressGidRFID[noID], idRFID[noID]);
        break;
      default:
        break;
    }
  }
}

void F3C_RFID_Data(){
  pageF3C.show();
  Serial.println("F3C_RFID_Data");

  noID = 1;
  
  Serial2.print("nF3CNoID.val=");
  Serial2.print(noID);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF3CRFID.txt=");
  Serial2.print("\"");
  Serial2.print(idRFID[noID]);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  
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
        Serial2.print("nF3CNoID.val=");
        Serial2.print(noID);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("tF3CRFID.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noID]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      case tUP:
        Tombol = tIDLE;
        Serial.println("bF3CUp");

        noID--;
        if(noID <= 1)  noID = 1;
        Serial2.print("nF3CNoID.val=");
        Serial2.print(noID);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("tF3CRFID.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noID]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      case tDOWN:
        Tombol = tIDLE;
        Serial.println("bF3CDown");

        noID++;
        if(noID >= jumlahData)  noID = jumlahData;
        Serial2.print("nF3CNoID.val=");
        Serial2.print(noID);
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);

        Serial2.print("tF3CRFID.txt=");
        Serial2.print("\"");
        Serial2.print(idRFID[noID]);
        Serial2.print("\"");
        Serial2.write(0xff);
        Serial2.write(0xff);
        Serial2.write(0xff);
        break;
      default:
        break;
    }
  }
}

void F3D_RFID_Data(){
  pageF3D.show();
  Serial.println("F3D_RFID_Data");
  
  Serial2.print("nF3DNoID.val=");
  Serial2.print(noID);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  Serial2.print("tF3DRFID.txt=");
  Serial2.print("\"");
  Serial2.print(idRFID[noID]);
  Serial2.print("\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  
  while(true){
    nexLoop(nex_listen_list_F3D_RFID_Data);
    switch(Tombol){
      case tYES:
        Tombol = tIDLE;
        Serial.println("bF3DYes");
        
        idRFID[noID] = "";
        EEPROM_writeString(addressGidRFID[noID], idRFID[noID]);

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
