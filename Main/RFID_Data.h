String dummyDataRFID(){
  String res;
  if     (analogRead(1) == 0 && analogRead(2) == 0)                           res = "0000000105";
  else if(analogRead(1) == 0 && analogRead(2) > 0 && analogRead(2) <= 1000)   res = "0000000106";
  else if(analogRead(1) == 0 && analogRead(2) > 1000)                         res = "0000000107";
  else if(analogRead(1) > 1000 && analogRead(2) == 0)                         res = "0000000108";
  else if(analogRead(1) > 1000 && analogRead(2) > 0 && analogRead(2) <= 1000) res = "0000000109";
  else if(analogRead(1) > 1000 && analogRead(2) > 1000)                       res = "0000000110";

  return res;
}
