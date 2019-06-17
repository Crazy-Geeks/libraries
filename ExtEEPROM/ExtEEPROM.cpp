
#include "ExtEEPROM.h"
#include <Wire.h>

union Int{ //преобразование int в byte[2]
	int all;
	byte b[2];
} _int;

union Float{ //преобразование float в byte[4]
	float _all;
	byte _b[4];
} _float;

byte ExtEEPROM::eeprom_read_byte(int deviceaddress, unsigned int eeaddress){
	byte rdata = 0xFF;
	Wire.beginTransmission(deviceaddress);
	Wire.write((int)(eeaddress >> 8)); // MSB
	Wire.write((int)(eeaddress & 0xFF)); // LSB
	Wire.endTransmission();
	Wire.requestFrom(deviceaddress, 1);
	if (Wire.available()) rdata = Wire.read();
	return rdata;
}

void ExtEEPROM::eeprom_write_byte( int deviceaddress, unsigned int eeaddress, byte data) {
	int rdata = data;
	Wire.beginTransmission(deviceaddress);
	Wire.write((int)(eeaddress >> 8)); // MSB
	Wire.write((int)(eeaddress & 0xFF)); // LSB
	Wire.write(rdata);
	Wire.endTransmission();
	delay(10);
}

/*_________________________*/
void ExtEEPROM::setup(int EEPROMAdr, int size){
	dev_adr = EEPROMAdr; //записываем адрес ипромки
	max_adr = size*1024; //определяем максимальный адрес
	Wire.begin();
}

byte ExtEEPROM::ReadByte(int eeadr){
	byte result;
	//if (eeadr < max_adr){
		result = eeprom_read_byte(dev_adr, eeadr); //просто без выпендрежа считываем 1 байт
	//}
	return result;
}

int ExtEEPROM::ReadInt(int eeadr){
	if (eeadr < max_adr) for (byte j = 0; j < 2; j++){ //записываем в union Int 
		_int.b[j] = eeprom_read_byte(dev_adr, (eeadr + j));
	}
	return _int.all;
}

float ExtEEPROM::ReadFloat(int eeadr){
	if (eeadr < max_adr) for (byte j = 0; j < 4; j++){ //записываем в union Int 
		_float._b[j] = eeprom_read_byte(dev_adr, (eeadr + j));
	}
	return _float._all;	
}

/*________________________*/

void ExtEEPROM::WriteByte(byte bt, int eeadr){
	byte ch;
	if (eeadr < max_adr) ch = eeprom_read_byte(dev_adr, eeadr); //просто без выпендрежа считываем 1 байт
	eeprom_write_byte(dev_adr, eeadr, bt);
	delay (10);
}

void ExtEEPROM::WriteInt(int in, int eeadr){
	if (eeadr < max_adr) for (byte j = 0; j < 2; j++){ //записываем в union Int 
		_int.b[j] = eeprom_read_byte(dev_adr, (eeadr + j));
	}
	
	if(in != _int.all){
		_int.all = in;
		for (byte j = 0; j < 2; j++){
			eeprom_write_byte(dev_adr, (eeadr + j), _int.b[j]);
			delay(10);
		}
	}
}

void ExtEEPROM::WriteFloat(float fl, int eeadr){
	if (eeadr < max_adr) for (byte j = 0; j < 4; j++){ //записываем в union Int 
		_float._b[j] = eeprom_read_byte(dev_adr, (eeadr + j));
	}
	
	if(fl != _float._all){
		_float._all = fl;
		for (byte j = 0; j < j; j++){
			eeprom_write_byte(dev_adr, (eeadr + j), _float._b[j]);
			delay(10);
		}
	}	
}

/*________________*/
