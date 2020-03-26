String dummyDataRFID(){
  String res;
  if(analogRead(1) == 0)                                res = "0000000100";
  else if(analogRead(1) > 0 && analogRead(1) <= 1000)   res = "0000000101";
  else if(analogRead(1) > 1000)                         res = "0000000102";

  return res;
}
