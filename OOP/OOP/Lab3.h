/**/







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

	Person ReadPerson();
	void PrintPerson(Person person);
	int GetLength(char* str);
	char* Concatenate(char* string1, char* string2);
	char* GetSubstring(char* string, int startIndex, int charCount);
	int FindSubstring(char* string, char* substring);
	char* Uppercase(char* string);
	char* Lowercase(char* string);
	int Copy(char* string, char* resString, int i, int j);
	void SplitFilename(char* source, char* path, char* name, char* extension);
	char* ReplaceTabsOnSpaces(char* string);
	char* ReplaceSpacesOnTabs(char* string);
	void UILab3();
	void PrintString(char* string);
}