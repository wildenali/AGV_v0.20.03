#include <QMC5883LCompass.h>
QMC5883LCompass compass;

void setup_SensorCompass(){
  compass.init();
}

int sensorCompass(){

  int kompas;
  compass.read();
  
  kompas = compass.getAzimuth();
  if(kompas >= 180) kompas = kompas - 360;
  
  return kompas;
}

