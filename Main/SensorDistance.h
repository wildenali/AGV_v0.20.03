int readDistanceSensor(){
  for(int i = 0; i < (sizeof(GdistSens) / sizeof(GdistSens[0])); i++){
    GdistSens[i] = analogRead(14);
    if(GdistSens[i] < GminDistSens[i])  return i;
  }
  return -1;
}
