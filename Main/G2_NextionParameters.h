// Declare your Nextion objects - Example (page = 0, id = 1, objname = "b0")
NexPage   pageE           = NexPage(0, 0, "E_Password");       // ========== Object in F0_MainMenu ==========
NexButton bEPassword      = NexButton(0, 3, "bEPassword");
NexButton bEClear         = NexButton(0, 2, "bEClear");
NexButton bEOk            = NexButton(0, 1, "bEOk");             // ========== Object in F0_MainMenu ==========

NexPage   pageF0          = NexPage(1, 0, "F0_MainMenu");       // ========== Object in F0_MainMenu ==========
NexButton bF1             = NexButton(1, 1, "bF1");
NexButton bF2             = NexButton(1, 2, "bF2");
NexButton bF3             = NexButton(1, 3, "bF3");
NexButton bF4             = NexButton(1, 4, "bF4");             // ========== Object in F0_MainMenu ==========

NexPage   pageF1A         = NexPage(2, 0, "F1A_PlayMenu");    // ========== Object in F1A_PlayMenu ==========
NexButton bF1ABack        = NexButton(2, 5, "bF1ABack");
NexButton bF1ANext        = NexButton(2, 4, "bF1ANext");
NexButton bF1AMinus       = NexButton(2, 7, "bF1AMinus");
NexButton bF1APlus        = NexButton(2, 8, "bF1APlus");
NexNumber nF1ANum         = NexNumber(2, 6, "nF1ANum");       // ========== Object in F1A_PlayMenu ==========

NexPage   pageF1B         = NexPage(3, 0, "F1B_Go");          // ========== Object in F1B_Go ==========
NexNumber nF1BPrevID      = NexNumber(3, 5, "nF1BPrevID");
NexNumber nF1BMode        = NexNumber(3, 14, "nF1BMode");
NexNumber nF1BNextID      = NexNumber(3, 7, "nF1BNextID");
NexButton bF1BCancel      = NexButton(3, 6, "bF1BCancel");
NexButton bF1BPause       = NexButton(3, 8, "bF1BPause");
NexButton bF1BGo          = NexButton(3, 9, "bF1BGo");        // ========== Object in F1B_Go ==========

NexPage   pageF2A         = NexPage(4, 0, "F2A_LogicSet");    // ========== Object in F2A_LogicSet ==========
NexButton bF2ABack        = NexButton(4, 4, "bF2ABack");
NexButton bF2ANext        = NexButton(4, 3, "bF2ANext");
NexButton bF2AUp          = NexButton(4, 20, "bF2AUp");
NexButton bF2ADown        = NexButton(4, 21, "bF2ADown");     // ========== Object in F2A_LogicSet ==========

NexPage   pageF2B         = NexPage(5, 0, "F2B_LogicSet");    // ========== Object in F2B_LogicSet ==========
NexButton bF2BBack        = NexButton(5, 4, "bF2BBack");
NexButton bF2BSave        = NexButton(5, 3, "bF2BSave");
NexButton bF2BUp          = NexButton(5, 8, "bF2BUp");
NexButton bF2BDown        = NexButton(5, 9, "bF2BDown");      // ========== Object in F2B_LogicSet ==========

NexPage   pageF3A         = NexPage(6, 0, "F3A_RFID_Data");   // ========== Object in F3A_RFID_Data ==========
NexButton bF3ABack        = NexButton(6, 6, "bF3ABack");
NexButton bF3ANext        = NexButton(6, 4, "bF3ANext");      // ========== Object in F3A_RFID_Data ==========

NexPage   pageF3B         = NexPage(7, 0, "F3B_RFID_Data");   // ========== Object in F3B_RFID_Data ==========
NexButton bF3BBack        = NexButton(7, 6, "bF3BBack");
NexButton bF3BNext        = NexButton(7, 4, "bF3BNext");
NexButton bF3BSave        = NexButton(7, 8, "bF3BSave");
NexButton bF3BDown        = NexButton(7, 14, "bF3BDown");
NexButton bF3BUp          = NexButton(7, 13, "bF3BNext");     // ========== Object in F3B_RFID_Data ==========

NexPage   pageF3C         = NexPage(8, 0, "F3C_RFID_Data");   // ========== Object in F3C_RFID_Data ==========
NexButton bF3CBack        = NexButton(8, 3, "bF3CBack");
NexButton bF3CDelete      = NexButton(8, 5, "bF3CDelete");
NexButton bF3CDown        = NexButton(8, 18, "bF3CDown");
NexButton bF3CUp          = NexButton(8, 19, "bF3CNext");     // ========== Object in F3C_RFID_Data ==========

NexPage   pageF3D         = NexPage(9, 0, "F3D_RFID_Data");   // ========== Object in F3D_RFID_Data ==========
NexButton bF3DYes         = NexButton(9, 9, "bF3DYes");
NexButton bF3DNo          = NexButton(9, 8, "bF3DNo");        // ========== Object in F3D_RFID_Data ==========

NexPage   pageF4A         = NexPage(10, 0, "F4A_MachineSet");   // ========== Object in F4A_MachineSet ==========
NexNumber nF4ASpeed       = NexNumber(10, 12, "nF4ASpeed");
NexNumber nF4AAccel       = NexNumber(10, 13, "nF4AAccel");
NexButton bF4ABack        = NexButton(10, 4, "bF4ABack");
NexButton bF4ANext        = NexButton(10, 3, "bF4ANext");
NexButton bF4AMinus       = NexButton(10, 10, "bF4AMinus");
NexButton bF4APlus        = NexButton(10, 11, "bF4APlus");  // ========== Object in F4A_MachineSet ==========

NexPage   pageF4B         = NexPage(11, 0, "F4B_MachineSet");   // ========== Object in F4B_MachineSet ==========
NexNumber nF4BGainP       = NexNumber(11, 14, "nF4BGainP");
NexNumber nF4BGainI       = NexNumber(11, 15, "nF4BGainI");
NexNumber nF4BGainD       = NexNumber(11, 16, "nF4BGainD");
NexButton bF4BBack        = NexButton(11, 4, "bF4BBack");
NexButton bF4BNext        = NexButton(11, 3, "bF4BNext");
NexButton bF4BMinus       = NexButton(11, 10, "bF4BMinus");
NexButton bF4BPlus        = NexButton(11, 11, "bF4BPlus");      // ========== Object in F4B_MachineSet ==========

NexPage   pageF4C         = NexPage(12, 0, "F4C_MachineSet");   // ========== Object in F4C_MachineSet ==========
NexButton bF4CBack        = NexButton(12, 11, "bF4CBack");
NexButton bF4CNext        = NexButton(12, 12, "bF4CNext");
NexButton bF4CMinus       = NexButton(12, 13, "bF4BMinus");
NexButton bF4CPlus        = NexButton(12, 14, "bF4BPlus");
NexButton bF4CPrevDist    = NexButton(12, 15, "bF4CPrevDist");
NexButton bF4CNextDist    = NexButton(12, 16, "bF4CNextDist");
NexNumber nF4CDistanceA   = NexNumber(12, 4, "nF4CDistanceA");
NexNumber nF4CDistanceB   = NexNumber(12, 5, "nF4CDistanceB");
NexNumber nF4CDistanceC   = NexNumber(12, 6, "nF4CDistanceC");
NexNumber nF4CDistanceD   = NexNumber(12, 7, "nF4CDistanceD");
NexNumber nF4CDistanceE   = NexNumber(12, 8, "nF4CDistanceE");
NexNumber nF4CNoRefDist   = NexNumber(12, 9, "nF4CNoRefDist");
NexNumber nF4CRefDist     = NexNumber(12, 10, "nF4CRefDist");   // ========== Object in F4C_MachineSet ==========

NexPage   pageF4D         = NexPage(13, 0, "F4D_MachineSet");   // ========== Object in F4D_MachineSet ==========
NexButton bF4DBack        = NexButton(13, 3, "bF4DBack");
NexButton bF4DNext        = NexButton(13, 7, "bF4DNext");       // ========== Object in F4D_MachineSet ==========

NexPage   pageF4E         = NexPage(14, 0, "F4E_MachineSet");   // ========== Object in F4E_MachineSet ==========
NexButton bF4EBack        = NexButton(14, 3, "bF4EBack");
NexButton bF4ESetLow      = NexButton(14, 15, "bF4ESetLow");       
NexButton bF4ESetHigh     = NexButton(14, 16, "bF4ESetHigh");   // ========== Object in F4E_MachineSet ==========

NexTouch *nex_listen_list_E_Password[]      = {&pageE, &bEPassword, &bEClear, &bEOk, NULL};                                   // ========== list of E_Password ==========
NexTouch *nex_listen_list_F0_MainMenu[]     = {&pageF0, &bF1, &bF2, &bF3, &bF4,NULL};                                   // ========== list of F0_MainMenu ==========
NexTouch *nex_listen_list_F1A_PlayMenu[]    = {&pageF1A, &bF1ABack, &bF1ANext, &bF1AMinus, &bF1APlus, NULL};            // ========== list of F1A_PlayMenu ==========
NexTouch *nex_listen_list_F1B_Go[]          = {&pageF1B, &bF1BCancel, &bF1BPause, &bF1BGo, NULL};                       // ========== list of F1B_Go  ==========
NexTouch *nex_listen_list_F2A_LogicSet[]    = {&pageF2A, &bF2ABack, &bF2ANext, &bF2AUp, &bF2ADown, NULL};               // ========== list of F2A_LogicSet  ==========
NexTouch *nex_listen_list_F2B_LogicSet[]    = {&pageF2B, &bF2BBack, &bF2BSave, &bF2BUp, &bF2BDown, NULL};               // ========== list of F2B_LogicSet  ==========
NexTouch *nex_listen_list_F3A_RFID_Data[]   = {&pageF3A, &bF3ABack, &bF3ANext, NULL};                                   // ========== list of F3A_RFID_Data ==========
NexTouch *nex_listen_list_F3B_RFID_Data[]   = {&pageF3B, &bF3BBack, &bF3BNext, &bF3BSave, &bF3BDown, &bF3BUp, NULL};    // ========== list of F3B_RFID_Data ==========
NexTouch *nex_listen_list_F3C_RFID_Data[]   = {&pageF3C, &bF3CBack, &bF3CDelete, &bF3CDown, &bF3CUp, NULL};             // ========== list of F3C_RFID_Data ==========
NexTouch *nex_listen_list_F3D_RFID_Data[]   = {&pageF3D, &bF3DYes, &bF3DNo, NULL};                                      // ========== list of F3D_RFID_Data ==========
NexTouch *nex_listen_list_F4A_MachineSet[]  = {&pageF4A, &bF4ABack, &bF4ANext, &bF4AMinus, &bF4APlus, &nF4ASpeed, &nF4AAccel, NULL};            // ========== list of F4A_MachineSet ==========
NexTouch *nex_listen_list_F4B_MachineSet[]  = {&pageF4B, &bF4BBack, &bF4BNext, &bF4BMinus, &bF4BPlus, &nF4BGainP, &nF4BGainI, &nF4BGainD, NULL};            // ========== list of F4B_MachineSet ==========
NexTouch *nex_listen_list_F4C_MachineSet[]  = {&pageF4C, &bF4CBack, &bF4CNext, &bF4CMinus, &bF4CPlus, &bF4CPrevDist, &bF4CNextDist,
                                               &nF4CDistanceA, &nF4CDistanceB, &nF4CDistanceC, &nF4CDistanceD, &nF4CDistanceE,
                                               &nF4CNoRefDist, &nF4CRefDist,
                                               NULL
                                              };                         // ========== list of F4C_MachineSet ==========
NexTouch *nex_listen_list_F4D_MachineSet[]  = {&pageF4D, &bF4DBack, &bF4DNext, NULL};                                   // ========== list of F4D_MachineSet ==========
NexTouch *nex_listen_list_F4E_MachineSet[]  = {&pageF4E, &bF4EBack, &bF4ESetLow, &bF4ESetHigh,NULL};                    // ========== list of F4E_MachineSet ==========

/*
 * Button bOn component pop callback function. 
 * When the ON button is released, the LED turns on and the state text changes. 
 */
void bEPassword_PopCallback(void *ptr)  {Tombol = tPASSWORD;}                  // ========== Callback in F0_MainMenu ==========
void bEClear_PopCallback(void *ptr)     {Tombol = tCLEAR;}
void bEOk_PopCallback(void *ptr)        {Tombol = tOK;}                  // ========== Callback in F0_MainMenu ==========

void bF1_PopCallback(void *ptr)         {Menu = F1;}                  // ========== Callback in F0_MainMenu ==========
void bF2_PopCallback(void *ptr)         {Menu = F2;}
void bF3_PopCallback(void *ptr)         {Menu = F3;}
void bF4_PopCallback(void *ptr)         {Menu = F4;}                  // ========== Callback in F0_MainMenu ==========

void bF1ABack_PopCallback(void *ptr)    {Tombol = tBACK;}      // ========== Callback in F1A_PlayMenu ==========
void bF1ANext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF1AMinus_PopCallback(void *ptr)   {Tombol = tMINUS;}
void bF1APlus_PopCallback(void *ptr)    {Tombol = tPLUS;}      // ========== Callback in F1A_PlayMenu ==========

void bF1BCancel_PopCallback(void *ptr)  {Tombol = tCANCEL;}   // ========== Callback in F1B_Go ==========
void bF1BPause_PopCallback(void *ptr)   {Tombol = tPAUSE;}
void bF1BGo_PopCallback(void *ptr)      {Tombol = tGO;}       // ========== Callback in F1B_Go ==========

void bF2ABack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F2A_LogicSet ==========
void bF2ANext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF2AUp_PopCallback(void *ptr)      {Tombol = tUP;}
void bF2ADown_PopCallback(void *ptr)    {Tombol = tDOWN;}     // ========== Callback in F2A_LogicSet ==========

void bF2BBack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F2B_LogicSet ==========
void bF2BSave_PopCallback(void *ptr)    {Tombol = tSAVE;}
void bF2BUp_PopCallback(void *ptr)      {Tombol = tUP;}
void bF2BDown_PopCallback(void *ptr)    {Tombol = tDOWN;}     // ========== Callback in F2B_LogicSet ==========

void bF3ABack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F2B_LogicSet ==========
void bF3ANext_PopCallback(void *ptr)    {Tombol = tNEXT;}     // ========== Callback in F2B_LogicSet ==========

void bF3BBack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F3B_LogicSet ==========
void bF3BNext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF3BSave_PopCallback(void *ptr)    {Tombol = tSAVE;}
void bF3BDown_PopCallback(void *ptr)    {Tombol = tDOWN;}
void bF3BUp_PopCallback(void *ptr)      {Tombol = tUP;}       // ========== Callback in F3B_LogicSet ==========

void bF3CBack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F3C_LogicSet ==========
void bF3CDelete_PopCallback(void *ptr)  {Tombol = tDELETE;}
void bF3CDown_PopCallback(void *ptr)    {Tombol = tDOWN;}
void bF3CUp_PopCallback(void *ptr)      {Tombol = tUP;}       // ========== Callback in F3C_LogicSet ==========

void bF3DYes_PopCallback(void *ptr)     {Tombol = tYES;}      // ========== Callback in F3D_LogicSet ==========
void bF3DNo_PopCallback(void *ptr)      {Tombol = tNO;}       // ========== Callback in F3D_LogicSet ==========

void bF4ABack_PopCallback(void *ptr)    {Tombol = tBACK;}   // ========== Callback in F4A_MachineSet ==========
void bF4ANext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF4AMinus_PopCallback(void *ptr)   {Tombol = tMINUS;}
void bF4APlus_PopCallback(void *ptr)    {Tombol = tPLUS;}
void nF4ASpeed_PopCallback(void *ptr)   {Number = numF4ASpeed;}
void nF4AAccel_PopCallback(void *ptr)   {Number = numF4AAccel;}// ========== Callback in F4A_MachineSet ==========

void bF4BBack_PopCallback(void *ptr)    {Tombol = tBACK;}   // ========== Callback in F4B_MachineSet ==========
void bF4BNext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF4BMinus_PopCallback(void *ptr)   {Tombol = tMINUS;}
void bF4BPlus_PopCallback(void *ptr)    {Tombol = tPLUS;}
void nF4BGainP_PopCallback(void *ptr)   {Number = numF4BGainP;}
void nF4BGainI_PopCallback(void *ptr)   {Number = numF4BGainI;}
void nF4BGainD_PopCallback(void *ptr)   {Number = numF4BGainD;}// ========== Callback in F4B_MachineSet ==========

void bF4CBack_PopCallback(void *ptr)    {Tombol = tBACK;}   // ========== Callback in F4C_MachineSet ==========
void bF4CNext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF4CMinus_PopCallback(void *ptr)   {Tombol = tMINUS;}
void bF4CPlus_PopCallback(void *ptr)    {Tombol = tPLUS;}
void bF4CPrevDist_PopCallback(void *ptr){Tombol = tDOWN;}
void bF4CNextDist_PopCallback(void *ptr){Tombol = tUP;}     // ========== Callback in F4C_MachineSet ==========

void bF4DBack_PopCallback(void *ptr)    {Tombol = tBACK;}   // ========== Callback in F4D_MachineSet ==========
void bF4DNext_PopCallback(void *ptr)    {Tombol = tNEXT;}   // ========== Callback in F4D_MachineSet ==========

void bF4EBack_PopCallback(void *ptr)    {Tombol = tBACK;}   // ========== Callback in F4E_MachineSet ==========
void bF4ESetLow_PopCallback(void *ptr)  {Tombol = tLOW;}
void bF4ESetHigh_PopCallback(void *ptr) {Tombol = tHIGH;}   // ========== Callback in F4E_MachineSet ==========


void G2_NextionParameters(){
  // Register the pop event callback function of the components
  bEPassword.attachPop(bEPassword_PopCallback, &bEPassword);// ========== Register the pop event in E_Password ==========
  bEClear.attachPop(bEClear_PopCallback, &bEClear);
  bEOk.attachPop(bEOk_PopCallback, &bEOk);                 // ========== Register the pop event in E_Password ==========
  
  bF1.attachPop(bF1_PopCallback, &bF1);                   // ========== Register the pop event in F0_MainMenu ==========
  bF2.attachPop(bF2_PopCallback, &bF2);
  bF3.attachPop(bF3_PopCallback, &bF3);
  bF4.attachPop(bF4_PopCallback, &bF4);                   // ========== Register the pop event in F0_MainMenu ==========

  bF1ABack.attachPop(bF1ABack_PopCallback);               // ========== Register the pop event in F1A_PlayMenu ==========
  bF1ANext.attachPop(bF1ANext_PopCallback);               // cara nulis callback bisa gini juga
  bF1AMinus.attachPop(bF1AMinus_PopCallback);
  bF1APlus.attachPop(bF1APlus_PopCallback);               // ========== Register the pop event in F1A_PlayMenu ==========
  
  bF1BCancel.attachPop(bF1BCancel_PopCallback);           // ========== Register the pop event in F1B_Go ==========
  bF1BPause.attachPop(bF1BPause_PopCallback);
  bF1BGo.attachPop(bF1BGo_PopCallback);                   // ========== Register the pop event in F1B_Go ==========
  
  bF2ABack.attachPop(bF2ABack_PopCallback);               // ========== Register the pop event in F2A_LogicSet ==========
  bF2ANext.attachPop(bF2ANext_PopCallback);
  bF2AUp.attachPop(bF2AUp_PopCallback);
  bF2ADown.attachPop(bF2ADown_PopCallback);               // ========== Register the pop event in F2A_LogicSet ==========
  
  bF2BBack.attachPop(bF2BBack_PopCallback);               // ========== Register the pop event in F2B_LogicSet ==========
  bF2BSave.attachPop(bF2BSave_PopCallback);
  bF2BUp.attachPop(bF2BUp_PopCallback);
  bF2BDown.attachPop(bF2BDown_PopCallback);               // ========== Register the pop event in F2B_LogicSet ==========

  bF3ABack.attachPop(bF3ABack_PopCallback);               // ========== Register the pop event in F3A_RFID_Data ==========
  bF3ANext.attachPop(bF3ANext_PopCallback);               // ========== Register the pop event in F3A_RFID_Data ==========

  bF3BBack.attachPop(bF3BBack_PopCallback);               // ========== Register the pop event in F3B_LogicSet ==========
  bF3BNext.attachPop(bF3BNext_PopCallback);
  bF3BSave.attachPop(bF3BSave_PopCallback);
  bF3BUp.attachPop(bF3BUp_PopCallback);
  bF3BDown.attachPop(bF3BDown_PopCallback);               // ========== Register the pop event in F3B_LogicSet ==========

  bF3CBack.attachPop(bF3CBack_PopCallback);               // ========== Register the pop event in F3C_LogicSet ==========
  bF3CDelete.attachPop(bF3CDelete_PopCallback);
  bF3CUp.attachPop(bF3CUp_PopCallback);
  bF3CDown.attachPop(bF3CDown_PopCallback);               // ========== Register the pop event in F3C_LogicSet ==========

  bF3DYes.attachPop(bF3DYes_PopCallback);                 // ========== Register the pop event in F3D_LogicSet ==========
  bF3DNo.attachPop(bF3DNo_PopCallback);                   // ========== Register the pop event in F3D_LogicSet ==========

  bF4ABack.attachPop(bF4ABack_PopCallback);               // ========== Register the pop event in F4A_MachineSet ==========
  bF4ANext.attachPop(bF4ANext_PopCallback);
  bF4AMinus.attachPop(bF4AMinus_PopCallback);
  bF4APlus.attachPop(bF4APlus_PopCallback);
  nF4ASpeed.attachPop(nF4ASpeed_PopCallback);             
  nF4AAccel.attachPop(nF4AAccel_PopCallback);             // ========== Register the pop event in F4A_MachineSet ==========

  bF4BBack.attachPop(bF4BBack_PopCallback);               // ========== Register the pop event in F4B_MachineSet ==========
  bF4BNext.attachPop(bF4BNext_PopCallback);
  bF4BMinus.attachPop(bF4BMinus_PopCallback);
  bF4BPlus.attachPop(bF4BPlus_PopCallback);
  nF4BGainP.attachPop(nF4BGainP_PopCallback);
  nF4BGainI.attachPop(nF4BGainI_PopCallback);
  nF4BGainD.attachPop(nF4BGainD_PopCallback);             // ========== Register the pop event in F4B_MachineSet ==========

  bF4CBack.attachPop(bF4CBack_PopCallback);               // ========== Register the pop event in F4C_MachineSet ==========
  bF4CNext.attachPop(bF4CNext_PopCallback);
  bF4CMinus.attachPop(bF4CMinus_PopCallback);
  bF4CPlus.attachPop(bF4CPlus_PopCallback);
  &bF4CPrevDist
  &bF4CNextDist
  &nF4CDistanceA
  &nF4CDistanceB
  &nF4CDistanceC
  &nF4CDistanceD
  &nF4CDistanceE
  &nF4CNoRefDist
  &nF4CRefDist
  // ========== Register the pop event in F4C_MachineSet ==========

  bF4DBack.attachPop(bF4DBack_PopCallback);               // ========== Register the pop event in F4D_MachineSet ==========
  bF4DNext.attachPop(bF4DNext_PopCallback);               // ========== Register the pop event in F4D_MachineSet ==========

  bF4EBack.attachPop(bF4EBack_PopCallback);               // ========== Register the pop event in F4E_MachineSet ==========
  bF4ESetLow.attachPop(bF4ESetLow_PopCallback);
  bF4ESetHigh.attachPop(bF4ESetHigh_PopCallback);         // ========== Register the pop event in F4E_MachineSet ==========
}

