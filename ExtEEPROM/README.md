# ExtEEPROM
Библиотека для внешего i2c EEPROM
Пока проверена работа на AT24C32 на модуле DS3231

Простая библиотека с простыми функциями

## Использование:
1) Подключаем библиотеку
2) Объявляем объект класса ExtEEPROM
3) Функции:
  
## Инициализация:
    1) void setup(int EEPROMAdr, int size) (Адрес, кол-во памяти (в килобайтах))
  
## Считывание:
    1) byte ReadByte(int adr) (адрес)
    2) int ReadInt(int adr) (адрес)
    3) float ReadFloat(int adr) (адрес)

## Запись:
	1) void WriteByte(byte bt, int adr) (значение, адрес)
	2) void WriteInt(int in, int adr) (значение, адрес)
	3) void WriteFloat(float fl, int adr) (значение, адрес)


***Библиотеки от Crazy_Geeks***
