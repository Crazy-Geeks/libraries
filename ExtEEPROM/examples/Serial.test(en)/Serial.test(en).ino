/* made by Crazy_Geeks community
 * https://github.com/Crazy-Geeks
 * developer - https://vk.com/Cover_Enya
 */

#include <ExtEEPROM.h>
#define EEPROM_adr 0x57 //i2c adress of memory
//!!!(standart adr in DS3231 0x57, in AT24C** - 0x50)!!!

ExtEEPROM eeprom; //define of object class ExtEEPROM

const byte _byte_ = 25;
const int _int_ = 226;
const float _float_ = 3.8976;

void setup(){
  eeprom.setup(EEPROM_adr, 32); //(adress, memory in KILOBYTES)
  //as usual, number after AT24C** - amount of memory in KB
  Serial.begin(9600);

  eeprom.WriteByte(_byte_, 2); //(value, adress) 
  eeprom.WriteInt(_int_, 3); 
  eeprom.WriteFloat(_float_, 5);

  Serial.print("Byte: ");
  Serial.print(_byte_);
  Serial.print("\nInt: ");
  Serial.print(_int_);
  Serial.print("\nFloat: ");
  Serial.print(_float_, 4);
  Serial.print("\nOK!\n"); //'user interface'
  
  byte res_byte = eeprom.ReadByte(2); //(adress)
  int res_int = eeprom.ReadInt(3);
  float res_float = eeprom.ReadFloat(5);
  
  Serial.println("\nResult from EEPROM:");
  Serial.print("Byte: ");
  Serial.print(res_byte);
  Serial.print("\nInt: ");
  Serial.print(res_int);
  Serial.print("\nFloat: ");
  Serial.print(res_float, 4);

}

void loop() {
  
}
