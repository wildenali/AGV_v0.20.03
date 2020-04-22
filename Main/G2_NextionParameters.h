// Declare your Nextion objects - Example (page = 0, id = 1, objname = "b0")
NexPage   pageE           = NexPage(1, 0, "E_Password");       // ========== Object in F0_MainMenu ==========
NexButton bEPassword      = NexButton(1, 3, "bEPassword");
NexButton bEClear         = NexButton(1, 2, "bEClear");
NexButton bEOk            = NexButton(1, 1, "bEOk");             // ========== Object in F0_MainMenu ==========

NexPage   pageF0          = NexPage(2, 0, "F0_MainMenu");       // ========== Object in F0_MainMenu ==========
NexButton bF1             = NexButton(2, 1, "bF1");
NexButton bF2             = NexButton(2, 2, "bF2");
NexButton bF3             = NexButton(2, 3, "bF3");
NexButton bF4             = NexButton(2, 4, "bF4");             // ========== Object in F0_MainMenu ==========

NexPage   pageF1A         = NexPage(3, 0, "F1A_PlayMenu");    // ========== Object in F1A_PlayMenu ==========
NexButton bF1ABack        = NexButton(3, 5, "bF1ABack");
NexButton bF1ANext        = NexButton(3, 4, "bF1ANext");
NexButton bF1AMinus       = NexButton(3, 7, "bF1AMinus");
NexButton bF1APlus        = NexButton(3, 8, "bF1APlus");
NexNumber nF1ANum         = NexNumber(3, 6, "nF1ANum");       // ========== Object in F1A_PlayMenu ==========

NexPage   pageF1B         = NexPage(4, 0, "F1B_Go");          // ========== Object in F1B_Go ==========
NexNumber nF1BMode        = NexNumber(4, 12, "nF1BMode");
NexButton bF1BCancel      = NexButton(4, 5, "bF1BCancel");
NexButton bF1BStop        = NexButton(4, 6, "bF1BStop");
NexButton bF1BGo          = NexButton(4, 7, "bF1BGo");        // ========== Object in F1B_Go ==========

NexPage   pageF2A         = NexPage(5, 0, "F2A_LogicSet");    // ========== Object in F2A_LogicSet ==========
NexButton bF2ABack        = NexButton(5, 4, "bF2ABack");
NexButton bF2ANext        = NexButton(5, 3, "bF2ANext");
NexButton bF2AUp          = NexButton(5, 20, "bF2AUp");
NexButton bF2ADown        = NexButton(5, 21, "bF2ADown");     // ========== Object in F2A_LogicSet ==========

NexPage   pageF2B         = NexPage(6, 0, "F2B_LogicSet");    // ========== Object in F2B_LogicSet ==========
NexButton bF2BBack        = NexButton(6, 4, "bF2BBack");
NexButton bF2BSave        = NexButton(6, 3, "bF2BSave");
NexText   tF2BNo          = NexText(6, 13, "tF2BNo");
NexText   tF2BMode        = NexText(6, 12, "tF2BMode");
NexText   tF2BType        = NexText(6, 14, "tF2BType");
NexText   tF2BTrigger     = NexText(6, 15, "tF2BTrigger");
NexText   tF2BAction      = NexText(6, 16, "tF2BAction");
NexButton bF2BUp          = NexButton(6, 5, "bF2BUp");
NexButton bF2BDown        = NexButton(6, 6, "bF2BDown");      // ========== Object in F2B_LogicSet ==========

NexPage   pageF3A         = NexPage(7, 0, "F3A_RFID_Data");   // ========== Object in F3A_RFID_Data ==========
NexButton bF3ABack        = NexButton(7, 4, "bF3ABack");
NexButton bF3ANext        = NexButton(7, 5, "bF3ANext");
NexButton bF3ADown        = NexButton(7, 6, "bF3ADown");
NexButton bF3AUp          = NexButton(7, 7, "bF3ANext");     // ========== Object in F3A_RFID_Data ==========

NexPage   pageF3B         = NexPage(8, 0, "F3B_RFID_Data");   // ========== Object in F3B_RFID_Data ==========
NexButton bF3BBack        = NexButton(8, 4, "bF3BBack");
NexButton bF3BNext        = NexButton(8, 5, "bF3BNext");
NexButton bF3BPrevID      = NexButton(8, 6, "bF3BSPrevID");
NexButton bF3BNextID      = NexButton(8, 7, "bF3BNextID");
NexButton bF3BSave        = NexButton(8, 8, "bF3BSave");      // ========== Object in F3B_RFID_Data ==========

NexPage   pageF3C         = NexPage(9, 0, "F3C_RFID_Data");   // ========== Object in F3C_RFID_Data ==========
NexButton bF3CBack        = NexButton(9, 4, "bF3CBack");
NexButton bF3CDelete      = NexButton(9, 5, "bF3CDelete");
NexButton bF3CDown        = NexButton(9, 6, "bF3CPrevID");
NexButton bF3CUp          = NexButton(9, 7, "bF3CNextID");     // ========== Object in F3C_RFID_Data ==========

NexPage   pageF3D         = NexPage(10, 0, "F3D_RFID_Data");   // ========== Object in F3D_RFID_Data ==========
NexButton bF3DYes         = NexButton(10, 5, "bF3DYes");
NexButton bF3DNo          = NexButton(10, 4, "bF3DNo");        // ========== Object in F3D_RFID_Data ==========

NexPage   pageF4A         = NexPage(11, 0, "F4A_MachineSet");   // ========== Object in F4A_MachineSet ==========
NexNumber nF4ASpeed       = NexNumber(11, 12, "nF4ASpeed");
NexNumber nF4AAccel       = NexNumber(11, 13, "nF4AAccel");
NexButton bF4ABack        = NexButton(11, 4, "bF4ABack");
NexButton bF4ANext        = NexButton(11, 3, "bF4ANext");
NexButton bF4AMinus       = NexButton(11, 10, "bF4AMinus");
NexButton bF4APlus        = NexButton(11, 11, "bF4APlus");  // ========== Object in F4A_MachineSet ==========

NexPage   pageF4B         = NexPage(12, 0, "F4B_MachineSet");   // ========== Object in F4B_MachineSet ==========
NexNumber nF4BGainP       = NexNumber(12, 14, "nF4BGainP");
NexNumber nF4BGainI       = NexNumber(12, 15, "nF4BGainI");
NexNumber nF4BGainD       = NexNumber(12, 16, "nF4BGainD");
NexButton bF4BBack        = NexButton(12, 4, "bF4BBack");
NexButton bF4BNext        = NexButton(12, 3, "bF4BNext");
NexButton bF4BMinus       = NexButton(12, 10, "bF4BMinus");
NexButton bF4BPlus        = NexButton(12, 11, "bF4BPlus");      // ========== Object in F4B_MachineSet ==========

NexPage   pageF4C         = NexPage(13, 0, "F4C_MachineSet");   // ========== Object in F4C_MachineSet ==========
NexButton bF4CBack        = NexButton(13, 6, "bF4CBack");
NexButton bF4CNext        = NexButton(13, 7, "bF4CNext");
NexButton bF4CMinus       = NexButton(13, 10, "bF4BMinus");
NexButton bF4CPlus        = NexButton(13, 11, "bF4BPlus");
NexButton bF4CPrevDist    = NexButton(13, 8, "bF4CPrevDist");
NexButton bF4CNextDist    = NexButton(13, 9, "bF4CNextDist");
NexNumber nF4CNoRefDist   = NexNumber(13, 4, "nF4CNoRefDist");  // referensi distance
NexNumber nF4CRefDist     = NexNumber(13, 5, "nF4CRefDist");   // ========== Object in F4C_MachineSet ==========

NexPage       pageF4D     = NexPage(14, 0, "F4D_MachineSet");   // ========== Object in F4D_MachineSet ==========
NexText       tF4DDI00    = NexText(14, 3, "tF4DDI00");
NexText       tF4DDI01    = NexText(14, 4, "tF4DDI01");
NexText       tF4DDI02    = NexText(14, 5, "tF4DDI02");
NexText       tF4DDI03    = NexText(14, 7, "tF4DDI03");
NexText       tF4DDI04    = NexText(14, 8, "tF4DDI04");
NexDSButton   btF4DDO00   = NexDSButton(14, 11, "btF4DDO00");
NexDSButton   btF4DDO01   = NexDSButton(14, 12, "btF4DDO01");
NexDSButton   btF4DDO02   = NexDSButton(14, 13, "btF4DDO02");
NexDSButton   btF4DDO03   = NexDSButton(14, 14, "btF4DDO03");
NexDSButton   btF4DDO04   = NexDSButton(14, 15, "btF4DDO04");
NexButton     bF4DBack    = NexButton(14, 9, "bF4DBack");
NexButton     bF4DNext    = NexButton(14, 10, "bF4DNext");// ========== Object in F4D_MachineSet ==========

NexPage   pageF4E         = NexPage(15, 0, "F4E_MachineSet");   // ========== Object in F4E_MachineSet ==========
NexButton bF4EBack        = NexButton(15, 3, "bF4EBack");
NexGauge  zF4ELineSensor  = NexGauge(15, 5, "zF4ELineSensor");
NexText   tF4ELineSensor  = NexText(15, 6, "tF4ELineSensor");  // ========== Object in F4E_MachineSet ==========

NexTouch *nex_listen_list_E_Password[]      = {&pageE, &bEPassword, &bEClear, &bEOk, NULL};                                   // ========== list of E_Password ==========
NexTouch *nex_listen_list_F0_MainMenu[]     = {&pageF0, &bF1, &bF2, &bF3, &bF4,NULL};                                   // ========== list of F0_MainMenu ==========
NexTouch *nex_listen_list_F1A_PlayMenu[]    = {&pageF1A, &bF1ABack, &bF1ANext, &bF1AMinus, &bF1APlus, NULL};            // ========== list of F1A_PlayMenu ==========
NexTouch *nex_listen_list_F1B_Go[]          = {&pageF1B, &bF1BCancel, &bF1BStop, &bF1BGo, NULL};                       // ========== list of F1B_Go  ==========
NexTouch *nex_listen_list_F2A_LogicSet[]    = {&pageF2A, &bF2ABack, &bF2ANext, &bF2AUp, &bF2ADown, NULL};               // ========== list of F2A_LogicSet  ==========
NexTouch *nex_listen_list_F2B_LogicSet[]    = {&pageF2B, &bF2BBack, &bF2BSave, &bF2BUp, &bF2BDown, &tF2BNo, &tF2BMode, &tF2BType, &tF2BTrigger, &tF2BAction, NULL};               // ========== list of F2B_LogicSet  ==========
NexTouch *nex_listen_list_F3A_RFID_Data[]   = {&pageF3A, &bF3ABack, &bF3ANext, &bF3ADown, &bF3AUp, NULL};                                   // ========== list of F3A_RFID_Data ==========
NexTouch *nex_listen_list_F3B_RFID_Data[]   = {&pageF3B, &bF3BBack, &bF3BNext, &bF3BPrevID, &bF3BNextID, &bF3BSave, NULL};    // ========== list of F3B_RFID_Data ==========
NexTouch *nex_listen_list_F3C_RFID_Data[]   = {&pageF3C, &bF3CBack, &bF3CDelete, &bF3CDown, &bF3CUp, NULL};             // ========== list of F3C_RFID_Data ==========
NexTouch *nex_listen_list_F3D_RFID_Data[]   = {&pageF3D, &bF3DYes, &bF3DNo, NULL};                                      // ========== list of F3D_RFID_Data ==========
NexTouch *nex_listen_list_F4A_MachineSet[]  = {&pageF4A, &bF4ABack, &bF4ANext, &bF4AMinus, &bF4APlus, &nF4ASpeed, &nF4AAccel, NULL};            // ========== list of F4A_MachineSet ==========
NexTouch *nex_listen_list_F4B_MachineSet[]  = {&pageF4B, &bF4BBack, &bF4BNext, &bF4BMinus, &bF4BPlus, &nF4BGainP, &nF4BGainI, &nF4BGainD, NULL};            // ========== list of F4B_MachineSet ==========
NexTouch *nex_listen_list_F4C_MachineSet[]  = {&pageF4C, &bF4CBack, &bF4CNext, &bF4CMinus, &bF4CPlus, &bF4CPrevDist, &bF4CNextDist, NULL};                         // ========== list of F4C_MachineSet ==========
NexTouch *nex_listen_list_F4D_MachineSet[]  = {&pageF4D, &bF4DBack, &bF4DNext, &btF4DDO00, &btF4DDO01, &btF4DDO02, &btF4DDO03, &btF4DDO04, NULL};                    // ========== list of F4D_MachineSet ==========
NexTouch *nex_listen_list_F4E_MachineSet[]  = {&pageF4E, &bF4EBack, &tF4ELineSensor, NULL};                                   // ========== list of F4E_MachineSet ==========

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
void bF1BStop_PopCallback(void *ptr)    {Tombol = tSTOP;}
void bF1BGo_PopCallback(void *ptr)      {Tombol = tGO;}       // ========== Callback in F1B_Go ==========

void bF2ABack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F2A_LogicSet ==========
void bF2ANext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF2AUp_PopCallback(void *ptr)      {Tombol = tUP;}
void bF2ADown_PopCallback(void *ptr)    {Tombol = tDOWN;}     // ========== Callback in F2A_LogicSet ==========

void bF2BBack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F2B_LogicSet ==========
void bF2BSave_PopCallback(void *ptr)    {Tombol = tSAVE;}
void tF2BNo_PopCallback(void *ptr)      {Teks   = teksNo;}
void tF2BMode_PopCallback(void *ptr)    {Teks   = teksMode;}
void tF2BType_PopCallback(void *ptr)    {Teks   = teksType;}
void tF2BTrigger_PopCallback(void *ptr) {Teks   = teksTrigger;}
void tF2BAction_PopCallback(void *ptr)  {Teks   = teksAction;}
//void bF2BChange_PopCallback(void *ptr)  {Tombol = tCHANGE;}
void bF2BUp_PopCallback(void *ptr)      {Tombol = tUP;}
void bF2BDown_PopCallback(void *ptr)    {Tombol = tDOWN;}     // ========== Callback in F2B_LogicSet ==========

void bF3ABack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F3A_RFID_Data ==========
void bF3ANext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF3ADown_PopCallback(void *ptr)    {Tombol = tDOWN;}
void bF3AUp_PopCallback(void *ptr)      {Tombol = tUP;}       // ========== Callback in F3A_RFID_Data ==========    

void bF3BBack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F3B_RFID_Data ==========
void bF3BNext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void bF3BPrevID_PopCallback(void *ptr)  {Tombol = tUP;}
void bF3BNextID_PopCallback(void *ptr)  {Tombol = tDOWN;}      
void bF3BSave_PopCallback(void *ptr)    {Tombol = tSAVE;}      // ========== Callback in F3B_RFID_Data ==========

void bF3CBack_PopCallback(void *ptr)    {Tombol = tBACK;}     // ========== Callback in F3C_RFID_Data ==========
void bF3CDelete_PopCallback(void *ptr)  {Tombol = tDELETE;}
void bF3CDown_PopCallback(void *ptr)    {Tombol = tDOWN;}
void bF3CUp_PopCallback(void *ptr)      {Tombol = tUP;}       // ========== Callback in F3C_RFID_Data ==========

void bF3DYes_PopCallback(void *ptr)     {Tombol = tYES;}      // ========== Callback in F3D_RFID_Data ==========
void bF3DNo_PopCallback(void *ptr)      {Tombol = tNO;}       // ========== Callback in F3D_RFID_Data ==========

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

// ========== Callback in F4D_MachineSet ==========
void bF4DBack_PopCallback(void *ptr)    {Tombol = tBACK;}
void bF4DNext_PopCallback(void *ptr)    {Tombol = tNEXT;}
void btF4DDO00_PopCallback(void *ptr)   {
  uint32_t buttonState;
  btF4DDO00.getValue(&buttonState);
  digitalWrite(digitalOutput[0], buttonState);
}
void btF4DDO01_PopCallback(void *ptr)   {
  uint32_t buttonState;
  btF4DDO01.getValue(&buttonState);
  digitalWrite(digitalOutput[1], buttonState);
}
void btF4DDO02_PopCallback(void *ptr)   {
  uint32_t buttonState;
  btF4DDO02.getValue(&buttonState);
  digitalWrite(digitalOutput[2], buttonState);
}
void btF4DDO03_PopCallback(void *ptr)   {
  uint32_t buttonState;
  btF4DDO03.getValue(&buttonState);
  digitalWrite(digitalOutput[3], buttonState);
}
void btF4DDO04_PopCallback(void *ptr)   {
  uint32_t buttonState;
  btF4DDO04.getValue(&buttonState);
  digitalWrite(digitalOutput[4], buttonState);
}
// ========== Callback in F4D_MachineSet ==========

void bF4EBack_PopCallback(void *ptr)    {Tombol = tBACK;}   // ========== Callback in F4E_MachineSet ==========



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
  bF1BStop.attachPop(bF1BStop_PopCallback);
  bF1BGo.attachPop(bF1BGo_PopCallback);                   // ========== Register the pop event in F1B_Go ==========
  
  bF2ABack.attachPop(bF2ABack_PopCallback);               // ========== Register the pop event in F2A_LogicSet ==========
  bF2ANext.attachPop(bF2ANext_PopCallback);
  bF2AUp.attachPop(bF2AUp_PopCallback);
  bF2ADown.attachPop(bF2ADown_PopCallback);               // ========== Register the pop event in F2A_LogicSet ==========
  
  bF2BBack.attachPop(bF2BBack_PopCallback);               // ========== Register the pop event in F2B_LogicSet ==========
  bF2BSave.attachPop(bF2BSave_PopCallback);
  tF2BMode.attachPop(tF2BMode_PopCallback);
  tF2BNo.attachPop(tF2BNo_PopCallback);
  tF2BType.attachPop(tF2BType_PopCallback);
  tF2BTrigger.attachPop(tF2BTrigger_PopCallback);
  tF2BAction.attachPop(tF2BAction_PopCallback);
  bF2BUp.attachPop(bF2BUp_PopCallback);
  bF2BDown.attachPop(bF2BDown_PopCallback);               // ========== Register the pop event in F2B_LogicSet ==========

  bF3ABack.attachPop(bF3ABack_PopCallback);               // ========== Register the pop event in F3A_RFID_Data ==========
  bF3ANext.attachPop(bF3ANext_PopCallback);
  bF3AUp.attachPop(bF3AUp_PopCallback);
  bF3ADown.attachPop(bF3ADown_PopCallback);               // ========== Register the pop event in F3A_RFID_Data ==========

  bF3BBack.attachPop(bF3BBack_PopCallback);               // ========== Register the pop event in F3B_RFID_Data ==========
  bF3BNext.attachPop(bF3BNext_PopCallback);
  bF3BPrevID.attachPop(bF3BPrevID_PopCallback);
  bF3BNextID.attachPop(bF3BNextID_PopCallback);
  bF3BSave.attachPop(bF3BSave_PopCallback);               // ========== Register the pop event in F3B_RFID_Data ==========

  bF3CBack.attachPop(bF3CBack_PopCallback);               // ========== Register the pop event in F3C_RFID_Data ==========
  bF3CDelete.attachPop(bF3CDelete_PopCallback);
  bF3CUp.attachPop(bF3CUp_PopCallback);
  bF3CDown.attachPop(bF3CDown_PopCallback);               // ========== Register the pop event in F3C_RFID_Data ==========

  bF3DYes.attachPop(bF3DYes_PopCallback);                 // ========== Register the pop event in F3D_RFID_Data ==========
  bF3DNo.attachPop(bF3DNo_PopCallback);                   // ========== Register the pop event in F3D_RFID_Data ==========

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
  bF4CPrevDist.attachPop(bF4CPrevDist_PopCallback);
  bF4CNextDist.attachPop(bF4CNextDist_PopCallback);       // ========== Register the pop event in F4C_MachineSet ==========

  bF4DBack.attachPop(bF4DBack_PopCallback);               // ========== Register the pop event in F4D_MachineSet ==========
  bF4DNext.attachPush(bF4DNext_PopCallback);
  btF4DDO00.attachPop(btF4DDO00_PopCallback);
  btF4DDO01.attachPop(btF4DDO01_PopCallback);
  btF4DDO02.attachPop(btF4DDO02_PopCallback);
  btF4DDO03.attachPop(btF4DDO03_PopCallback);
  btF4DDO04.attachPop(btF4DDO04_PopCallback);               // ========== Register the pop event in F4D_MachineSet ==========
  
  bF4EBack.attachPush(bF4EBack_PopCallback);               // ========== Register the pop event in F4E_MachineSet ==========

}

void G2_DigitalInput(){
  for(int i = 0; i < (sizeof(digitalInput) / sizeof(digitalInput[0])); i++){
    digitalRead(digitalInput[i]);
  }
}

void G2_DigitalInputStatusDisplay(){
  for(int i = 0; i < (sizeof(digitalInput) / sizeof(digitalInput[0])); i++){
    stateDigitalInput[i] = digitalRead(digitalInput[i]);
    if (stateDigitalInput[i] != lastStateDigitalInput[i]) {
      if      (stateDigitalInput[0] == HIGH)    tF4DDI00.Set_background_color_bco(2016);
      else if (stateDigitalInput[0] == LOW)     tF4DDI00.Set_background_color_bco(500);
      if      (stateDigitalInput[1] == HIGH)    tF4DDI01.Set_background_color_bco(2016);
      else if (stateDigitalInput[1] == LOW)     tF4DDI01.Set_background_color_bco(500);
      if      (stateDigitalInput[2] == HIGH)    tF4DDI02.Set_background_color_bco(2016);
      else if (stateDigitalInput[2] == LOW)     tF4DDI02.Set_background_color_bco(500);
      if      (stateDigitalInput[3] == HIGH)    tF4DDI03.Set_background_color_bco(2016);
      else if (stateDigitalInput[3] == LOW)     tF4DDI03.Set_background_color_bco(500);
      if      (stateDigitalInput[4] == HIGH)    tF4DDI04.Set_background_color_bco(2016);
      else if (stateDigitalInput[4] == LOW)     tF4DDI04.Set_background_color_bco(500);
      delay(10);
    }
    lastStateDigitalInput[i] = stateDigitalInput[i];
  }
}

void readDistanceSensor(){
  for(int i = 0; i < (sizeof(GdistSens) / sizeof(GdistSens[0])); i++){
    GdistSens[i] = analogRead(A0);
  }
}


String stringDI(int inputDI){
  if(inputDI == 0)         return "";
  else if(inputDI == 1)    return "DI 1,HIGH";
  else if(inputDI == 2)    return "DI 1,LOW";
  else if(inputDI == 3)    return "DI 2,HIGH";
  else if(inputDI == 4)    return "DI 2,LOW";
  else if(inputDI == 5)    return "DI 3,HIGH";
  else if(inputDI == 6)    return "DI 3,LOW";
  else if(inputDI == 7)    return "DI 4,HIGH";
  else if(inputDI == 8)    return "DI 4,LOW";
  else if(inputDI == 9)    return "DI 5,HIGH";
  else if(inputDI == 10)   return "DI 5,LOW";
}

String stringLORA(int inputLORA){
  if(inputLORA == 0)         return "";
  else if(inputLORA == 1)    return "Rx_1";
  else if(inputLORA == 2)    return "Rx_2";
  else if(inputLORA == 3)    return "Rx_3";
  else if(inputLORA == 4)    return "Rx_4";
  else if(inputLORA == 5)    return "Rx_5";
}

String stringAction(int inputAction){
  if(inputAction == 0)         return "";
  else if(inputAction == 1)    return "Berhenti";
  else if(inputAction == 2)    return "Maju";
  else if(inputAction == 3)    return "Belok Kiri";
  else if(inputAction == 4)    return "Belok Kanan";
  else if(inputAction == 5)    return "Balik Kiri";
  else if(inputAction == 6)    return "Balik Kanan";
  else if(inputAction == 7)    return "Lift On";
  else if(inputAction == 8)    return "Lift Off";
  else if(inputAction == 9)    return "Buzzer On";
  else if(inputAction == 10)   return "Buzzer Off";
  else if(inputAction == 11)   return "DO 01,HIGH";
  else if(inputAction == 12)   return "DO 01,LOW";
  else if(inputAction == 13)   return "DO 02,HIGH";
  else if(inputAction == 14)   return "DO 02,LOW";
  else if(inputAction == 15)   return "DO 03,HIGH";
  else if(inputAction == 16)   return "DO 03,LOW";
  else if(inputAction == 17)   return "DO 04,HIGH";
  else if(inputAction == 18)   return "DO 04,LOW";
  else if(inputAction == 19)   return "DO 05,HIGH";
  else if(inputAction == 20)   return "DO 05,LOW"; 
  else if(inputAction == 21)   return "Tx_1";
  else if(inputAction == 22)   return "Tx_2";
  else if(inputAction == 23)   return "Tx_3";
  else if(inputAction == 24)   return "Tx_4";
  else if(inputAction == 25)   return "Tx_5"; 
}

void resetData(bool statusReset){
  if(statusReset == true){
    for(int i = 0; i <= jumlahData ; i++){
      mode = 0;
      type = 0;
      trigger = 0;
      action = 0;
      EEPROM.write(addressGmodeKe[i], mode);
      EEPROM.write(addressGtypeKe[i], type);
      EEPROM.write(addressGtriggerKe[i], trigger);
      EEPROM.write(addressGactionKe[i], action);    
      EEPROM_writeString(addressGidRFID[i], "");
    }
  }
}
void readDataRFID(){
  for(int i = 1; i < (sizeof(idRFID) / sizeof(idRFID[0])); i++)
  {
    idRFID[i] = EEPROM_readString(addressGidRFID[i]);
    Serial.println(idRFID[i]);
  }
}
void readDataLogicSetting(){
  for(int i = 1; i <= jumlahData ; i++)
  {
    modeKe[i]     = EEPROM.read(addressGmodeKe[i]);
    typeKe[i]     = EEPROM.read(addressGtypeKe[i]);
    triggerKe[i]  = EEPROM.read(addressGtriggerKe[i]);
    actionKe[i]   = EEPROM.read(addressGactionKe[i]);

    Serial.print(i);                Serial.print("_");
    Serial.print(modeKe[i]);        Serial.print("_");
    Serial.print(typeKe[i]);        Serial.print("_");
    Serial.print(triggerKe[i]);     Serial.print("_");
    Serial.print(actionKe[i]);      Serial.print("\n");
  }  
}

void dummyDataRFID(bool statusDummyDataRFID){
// =========== dummy id RFID untuk testing ===========
  if(statusDummyDataRFID == true){
    idRFID[1]  = "2000000001";  idRFID[11] = "2000000011";  idRFID[21] = "2000000021";
    idRFID[2]  = "2000000002";  idRFID[12] = "2000000012";  idRFID[22] = "2000000022";
    idRFID[3]  = "2000000003";  idRFID[13] = "2000000013";  idRFID[23] = "2000000023";
    idRFID[4]  = "2000000004";  idRFID[14] = "2000000014";  idRFID[24] = "2000000024";
    idRFID[5]  = "2000000005";  idRFID[15] = "2000000015";  idRFID[25] = "2000000025";
    idRFID[6]  = "2000000006";  idRFID[16] = "2000000016";  idRFID[26] = "2000000026";
    idRFID[7]  = "2000000007";  idRFID[17] = "2000000017";  idRFID[27] = "2000000027";
    idRFID[8]  = "2000000008";  idRFID[18] = "2000000018";  idRFID[28] = "2000000028";
    idRFID[9]  = "2000000009";  idRFID[19] = "2000000019";  idRFID[29] = "2000000029";
    idRFID[10] = "2000000010";  idRFID[20] = "2000000020";  idRFID[30] = "2000000030";
    EEPROM_writeString(addressGidRFID[0], "0"); 
    for(int i = 1; i <= jumlahData; i++){
      EEPROM_writeString(addressGidRFID[i], idRFID[i]); 
    }
  }
// =========== dummy id RFID untuk testing ===========
}

void contohData(bool statusContohData){
// Contoh sampe data
  if(statusContohData == true){
    for(int i = 1; i < (sizeof(addressGmodeKe) / sizeof(addressGmodeKe[0])); i++)//  for(int i = 1; i < (sizeof(addressGnoKe) / sizeof(addressGnoKe[0])); i++)
    {
      modeKe[i]     = 0;
      typeKe[i]     = 0;
      triggerKe[i]  = 0;
      actionKe[i]   = 0;
      
      Serial.print(i);                Serial.print("_");
      Serial.print(modeKe[i]);        Serial.print("_");
      Serial.print(typeKe[i]);        Serial.print("_");
      Serial.print(triggerKe[i]);     Serial.print("_");
      Serial.print(actionKe[i]);      Serial.print("\n");
    }
    // ============= CONTOH SAMPLE AJA ======================
    modeKe[1] = 1;
    modeKe[2] = 1;
    modeKe[3] = 1;
    modeKe[4] = 1;
    modeKe[5] = 1;
    modeKe[6] = 2;
    modeKe[7] = 2;
    modeKe[8] = 2;
    modeKe[9] = 0;
    modeKe[10] = 0;
    for(int i = 11; i <= jumlahData; i++){
      modeKe[i] = 0;
    }
  
    typeKe[1] = 1;
    typeKe[2] = 1;
    typeKe[3] = 2;
    typeKe[4] = 2;
    typeKe[5] = 3;
    typeKe[6] = 1;
    typeKe[7] = 1;
    typeKe[8] = 2;
    typeKe[9] = 0;
    typeKe[10] = 0;
    for(int i = 11; i <= jumlahData; i++){
      typeKe[i] = 0;
    }
  
    triggerKe[1] = 1;
    triggerKe[2] = 2;
    triggerKe[3] = 1;
    triggerKe[4] = 5;
    triggerKe[5] = 10;
    triggerKe[6] = 4;
    triggerKe[7] = 7;
    triggerKe[8] = 3;
    triggerKe[9] = 0;
    triggerKe[10] = 0;
    for(int i = 11; i <= jumlahData; i++){
      triggerKe[i] = 0;
    }
  
    actionKe[1] = 1;
    actionKe[2] = 2;
    actionKe[3] = 10;
    actionKe[4] = 15;
    actionKe[5] = 18;
    actionKe[6] = 5;
    actionKe[7] = 3;
    actionKe[8] = 7;
    actionKe[9] = 0;
    actionKe[10] = 0;
    for(int i = 11; i <= jumlahData; i++){
      actionKe[i] = 0;
    }
  }
  // ============= CONTOH SAMPLE AJA ======================
}

