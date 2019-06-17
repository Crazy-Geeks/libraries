# ExtEEPROM
Библиотека для внешего i2c EEPROM
Пока проверена работа на AT24C32 на модуле DS3231

Простая библиотека с простыми функциями

Использование:
1) Подключаем библиотеку
2) Объявляем объект класса ExtEEPROM
3) Функции:
  
  Инициализация:
  void setup(int EEPROMAdr, int size) (Адрес, кол-во памяти (в килобайтах))
  
  Считывание:
  byte ReadByte(int adr) (адрес)
  int ReadInt(int adr) (адрес)
  float ReadFloat(int adr) (адрес)
  
  Запись:
  void WriteByte(byte bt, int adr) (значение, адрес)
  void WriteInt(int in, int adr) (значение, адрес)
  void WriteFloat(float fl, int adr) (значение, адрес)

Библиотеки от Crazy_Geeks
