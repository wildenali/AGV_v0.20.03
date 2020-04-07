//void EEPROM_writeString(char add,String data);
//String EEPROM_readString(char add);
void EEPROM_writeString(int add,String data);
String EEPROM_readString(int add);

void EEPROM_writeString(int add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
}
 
 
String EEPROM_readString(int add)
{
  int i;
  char data[10]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<10)   //Read until null character, 500
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
