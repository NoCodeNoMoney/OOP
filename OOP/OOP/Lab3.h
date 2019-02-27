/**/


/*Строки и пользовательские типы данных*/

#pragma once
#include "CheckSymbol.h"


namespace Lab3
{

	enum Sex { Female, Male };

	struct Person
	{
		char Surname[40];
		char Name[20];
		Sex SexPerson;
	};

	Person ReadPerson();//читает данные персоны
	void PrintPerson(Person person);//Выводит данные персоны
	int GetLength(char* str);//определяет длину подаваемой на вход строки.
	char* Concatenate(char* string1, char* string2);// возвращает новую строку, являющуюся объединением двух входных.
	char* GetSubstring(char* string, int startIndex, int charCount); /*возвращает подстроку, состоящую из charCount символов 
																	 и начинающуюся с startIndex позиции в строке string.*/
	int FindSubstring(char* string, char* substring);//производит поиск подстроки substring в строке string
	char* Uppercase(char* string);/*приводит входную строку к верхнему  регистру. 
								  Приведение к регистру касается ислючительно 
								  латинских символов, знаки препинания и цифры исходной строки  остаются в исходном состоянии. */
	char* Lowercase(char* string); //приводит входную строку к нижнему регистру.
	int Copy(char* string, char* resString, int i, int j);//Копирует строку
	void SplitFilename(char* source, char* path, char* name, char* extension);/* разделяет исходную строку source на путь path, 
																			  имя name и расширение файла extension. */
	char* ReplaceTabsOnSpaces(char* string);//заменяет символы табуляции в исходной строке на пробелы. 
	char* ReplaceSpacesOnTabs(char* string);//заменяет пробельные символы на символы табуляции 
											//в случае, если такую замену можно произвести.
	void UILab3();//Меню
	void PrintString(char* string);//печать строки
}