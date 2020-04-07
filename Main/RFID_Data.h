String dummyDataRFID(){
  String res;
  if     (analogRead(1) == 0 && analogRead(2) == 0)                                                 res = "----------";
  else if(analogRead(1) == 0 && analogRead(2) > 0 && analogRead(2) <= 1000)                         res = "2000000001";
  else if(analogRead(1) == 0 && analogRead(2) > 1000)                                               res = "2000000002";
  else if(analogRead(1) > 0 && analogRead(1) < 1000 && analogRead(2) == 0)                          res = "2000000003";
  else if(analogRead(1) > 0 && analogRead(1) < 1000 && analogRead(2) > 0 && analogRead(2) <= 1000)  res = "2000000004";
  else if(analogRead(1) > 0 && analogRead(1) < 1000 && analogRead(2) > 1000)                        res = "2000000005";
  else if(analogRead(1) > 1000 && analogRead(2) == 0)                                               res = "2000000006";
  else if(analogRead(1) > 1000 && analogRead(2) > 0 && analogRead(2) <= 1000)                       res = "2000000007";
  else if(analogRead(1) > 1000 && analogRead(2) > 1000)                                             res = "2000000008";

  return res;
}
