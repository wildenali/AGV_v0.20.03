int sensorLine(){
  int valSensorLine = map(analogRead(15), 10, 1000, -100, 100);    // dummy sensor garis
  if(valSensorLine <= -100)  valSensorLine = -100;
  if(valSensorLine >=  100)  valSensorLine =  100;
//    Serial.print(200);
//    Serial.print(" ");
//    Serial.print(sensooooor);
//    Serial.print(" ");
//    Serial.println(-200);

  return valSensorLine;
}

