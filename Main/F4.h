void F4A_MachineSet();
void F4B_MachineSet();
void F4C_MachineSet();
void F4D_MachineSet();
void F4E_MachineSet();

void F4A_MachineSet(){
  pageF4A.show();
  Serial.println("F4A_MachineSet");
  while(true){
    nexLoop(nex_listen_list_F4A_MachineSet);
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
        break;
      case tMINUS:
        Tombol = tIDLE;
        Serial.println("bF4AMinus");
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF4APlus");
        break;
      default:
        break;
    }
  }
}

void F4B_MachineSet(){
  pageF4B.show();
  Serial.println("F4B_MachineSet");
  while(true){
    nexLoop(nex_listen_list_F4B_MachineSet);
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
        break;
      case tMINUS:
        Tombol = tIDLE;
        Serial.println("bF4BMinus");
        break;
      case tPLUS:
        Tombol = tIDLE;
        Serial.println("bF4BPlus");
        break;
      default:
        break;
    }
  }
}

void F4C_MachineSet(){
  pageF4C.show();
  Serial.println("F4C_MachineSet");
  while(true){
    nexLoop(nex_listen_list_F4C_MachineSet);
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
        break;
      case tSET:
        Tombol = tIDLE;
        Serial.println("bF4CSet");
        break;
      default:
        break;
    }
  }
}

void F4D_MachineSet(){
  pageF4D.show();
  Serial.println("F4D_MachineSet");
  while(true){
    nexLoop(nex_listen_list_F4D_MachineSet);
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
    switch(Tombol){
      case tBACK:
        Tombol = tIDLE;
        Serial.println("bF4EBack");
        return false;
        break;
      case tLOW:
        Tombol = tIDLE;
        Serial.println("bF4ESetLow");
        break;
      case tHIGH:
        Tombol = tIDLE;
        Serial.println("bF4ESetHigh");
        break;
      default:
        break;
    }
  }
}
