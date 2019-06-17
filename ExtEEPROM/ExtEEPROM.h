#ifndef ExtEEPROM_h
#define ExtEEPROM_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class ExtEEPROM{
	public:
		void setup(int EEPROMAdr, int size); //указываем адрес и кол-во памяти
		byte ReadByte(int adr); //Читаем
		int ReadInt(int adr);
		float ReadFloat(int adr);
		void WriteByte(byte bt, int adr); //Пишем
		void WriteInt(int in, int adr);
		void WriteFloat(float fl, int adr);
	private:
		byte eeprom_read_byte(int deviceaddress, unsigned int eeaddress);
		void eeprom_write_byte(int deviceaddress, unsigned int eeaddress, byte data);
		int dev_adr;
		int max_adr;
};



#endif
