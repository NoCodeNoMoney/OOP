#pragma once
#include "Lab3.h"


namespace Lab3{

	Person Lab3::ReadPerson()
	{
		Person newPerson;
		cout << "Insert Surname: ";
		cin >> newPerson.Surname;
		cout << endl << "Insert Name: ";
		cin >> newPerson.Name;
		cout << endl << "Insert Sex: ";
		int n;

		do
		{
			n = CheckSymbol();
		} while (n != 0 && n != 1);
		switch (n)
		{
		case Female:
			newPerson.SexPerson = Female;
			break;
		case Male:
			newPerson.SexPerson = Male;
			break;
		default:
			break;
		}
		return newPerson;
	}

	Person person1;

	void PrintPerson(Person person)
	{
		cout << "Surname: " << person.Surname << endl;
		cout << "Name: " << person.Name << endl;
		if (person.SexPerson == Female)
			cout << "SexPerson: Female" << endl;
		if (person.SexPerson == Male)
			cout << "SexPerson: Male" << endl;
	}



	int GetLength(char * str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			length++;
		}
		return length;
	}

	void PrintString(char * str)
	{
		for (int i = 0; i < GetLength(str); i++)
		{
			cout << str[i];
		}cout << endl;
	}

	char * Concatenate(char * string1, char * string2)
	{
		char* newString = new char[300];
		int j = 0;

		for (int i = 0; i < GetLength(string1); i++)
		{
			newString[i] = string1[i];
			j++;
		}

		for (int i = 0; i < GetLength(string2); i++)
		{
			newString[j] = string2[i];
			j++;
		}
		newString[j] = '\0';

		return newString;
	}

	char * GetSubstring(char * string, int startIndex, int charCount)
	{
		char* newString = new char[300];
		if (startIndex < 0 || charCount < 0 || startIndex + charCount > GetLength(string))
		{
			return NULL;
		}
		int j = 0;
		for (int i = startIndex; i < startIndex + charCount; i++)
		{
			newString[j] = string[i];
			j++;
		}
		newString[j] = '\0';
		return newString;
	}

	int FindSubstring(char * string, char * substring)
	{
		if (GetLength(string) < GetLength(substring))
		{
			return -1;
		}
		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == substring[0])
			{
				bool subString = true;
				int str = ++i;
				for (int subStr = 1; subStr < GetLength(substring); subStr++)
				{
					if (str > GetLength(string))
					{
						return -1;
					}
					if (string[str] != substring[subStr])
					{
						subString = false;
					}
					str++;
				}
				if (subString)
				{
					return --i;
				}
			}
		}
		return -1;
	}

	char * Uppercase(char * string)
	{
		char* newString = new char[200];
		for (int i = 0; i < GetLength(string); i++)
		{
			newString[i] = string[i];
			newString[i + 1] = '\0';
		}

		for (int i = 0; i < GetLength(newString); i++)
		{
			if (newString[i] >= 97 && newString[i] <= 122)
			{
				newString[i] -= 32;
			}
		}
		return newString;
	}

	char * Lowercase(char * string)
	{
		char* newString = new char[200];
		for (int i = 0; i < GetLength(string); i++)
		{
			newString[i] = string[i];
			newString[i + 1] = '\0';
		}

		for (int i = 0; i < GetLength(newString); i++)
		{
			if (newString[i] >= 65 && newString[i] <= 90)
			{
				newString[i] += 32;
			}
		}
		return newString;
	}

	int Copy(char * string, char * resString, int i, int j)
	{
		while (string[i])
		{
			resString[j++] = string[i++];
		}
		resString[j] = '\0';
		return i;
	}

	void SplitFilename(char * source, char * path, char * name, char * extension)
	{

		int index = 0;
		int pointPlace;
		int subIndex = 0;
		while (source[index] != '\0')
		{
			if (source[index] == '.')
			{
				break;
			}
			index++;
		}
		if ((source[index - 1]) && (index))
		{
			pointPlace = index;
			index = Copy(source, extension, index, subIndex);

			while ((source[index] != '\\') && (index))
			{
				index--;
			}
			if (index != pointPlace - 1)
			{
				if (index)
				{
					for (subIndex = 0; subIndex < index + 1; subIndex++)
					{
						path[subIndex] = source[subIndex];
					}
					path[subIndex] = '\0';
					for (index = 0; subIndex < pointPlace;)
					{
						name[index++] = source[subIndex++];
					}
					name[index] = '\0';
				}
				else
				{
					for (index = 0; index < pointPlace; index++)
					{
						name[index] = source[index];
					}
					name[index] = '\0';
					path[0] = NULL;
				}
			}
			else
			{
				path[0] = NULL;
				extension[0] = NULL;
				name[0] = NULL;
			}
		}
		else
		{
			path[0] = NULL;
			extension[0] = NULL;
			name[0] = NULL;
		}
	}

	char * ReplaceTabsOnSpaces(char * string)
	{
		char* newString = new char[200];
		int e = 0;
		int j = 0;
		int z = 0;
		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == '\t' && (z % 4 == 0))
			{
				newString[j++] = ':';
				newString[j++] = ':';
				newString[j++] = ':';
				newString[j++] = ':';
				e += 4;
			}
			else
				if (string[i] == '\t' && (z % 4 == 1))
				{
					newString[j++] = ':';
					newString[j++] = ':';
					newString[j++] = ':';
					e += 3;
				}
				else
					if (string[i] == '\t' && (z % 4 == 2))
					{
						newString[j++] = ':';
						newString[j++] = ':';
						e += 2;
					}
					else
						if (string[i] == '\t' && (z % 4 == 3))
						{
							newString[j++] = ':';
							e += 1;
						}
						else
						{
							newString[j] = string[i];
							j++;
							e++;
							z++;
						}
		}
		newString[e] = '\0';
		return newString;
	}

	char * ReplaceSpacesOnTabs(char * string)
	{
		char* newString = new char[200];
		int e = 0;//Конец строки
		int j = 0;//Индекс элемента во входной строке
		int z = 0;//Индекс элемента в новой строке
		int k = 0;//Счетчик проблеов
		bool w = 0;//Признак входа в цикл потока пробелов.
		for (int i = 0; i < GetLength(string); i++)
		{

			j = z;
			if (string[j] == ':')
			{
				int	N0 = j;// Первое вхождение проблела
				k++;
				j++;
				while (string[j] == ':' && (j % 4 != 0))
				{
					w = 1;
					j++;//Индекс элемента в массиве
					k++;//Кол-во встретившихся подрят пробелов
				}

				int	N1 = N0 + (4 - N0 % 4);//Конечная позиция в потоке пробелов
				j = j - 1;
				if ((N1 - N0 == k) && (string[j] == ':' && (j % 4 != 0)))
				{
					newString[i] = '\t';
					z = N1 - 1;
				}
				else
				{
					newString[i] = string[z];
				}

			}

			else
			{
				newString[i] = string[z];
			}
			k = 0;
			e++;
			z++;
		}
		newString[e] = '\0';
		return newString;
	}


	void UILab3()
	{
		enum MenuEnum
		{
			ReadPersonEnum = 1, PrintPersonEnum, GetLengthEnum, ConcatenateEnum, GetSubstringEnum,
			FindSubstringEnum, UppercaseEnum, LowercaseEnum,
			SplitFilenameEnum, ReplaceTabsOnSpacesEnum, ReplaceSpacesOnTabsEnum
		};

		cout << "---Program Menu---" << endl;
		cout << "1. ReadPerson()" << endl;
		cout << "2. PrintPerson()" << endl;
		cout << "3. GetLength()" << endl;
		cout << "4. Concatenate()" << endl;
		cout << "5. GetSubstring()" << endl;
		cout << "6. FindSubstring()" << endl;
		cout << "7. Uppercase()" << endl;
		cout << "8. Lowercase()" << endl;
		cout << "9. SplitFilename()" << endl;
		cout << "10. ReplaceTabsOnSpaces()" << endl;
		cout << "11. ReplaceSpacesOnTabs()" << endl;
		cout << "12. Exit" << endl;

		bool exit = false;
		while (true)
		{
			if (exit)
			{
				break;
			}
			cout << "--------------------Choose function number for testing (1-12): " << endl;
			int n = CheckSymbol();
			cout << endl << endl;

			switch (n)
			{

			case ReadPersonEnum:
			{
				person1 = ReadPerson();
				break;
			}

			case PrintPersonEnum:
			{
				PrintPerson(person1);
				break;
			}

			case GetLengthEnum:
			{
				char* String = new char[200];
				cout << "Enter String: " << endl;
				cin.get();
				cin.getline(String, 200);
				cout << GetLength(String) << endl;
				break;
			}

			case ConcatenateEnum:
			{
				char* String0 = new char[200];
				char* String1 = new char[200];
				cout << "Enter string 1: " << endl;
				cin.get();
				cin.getline(String0, 200);
				cout << "Enter string 2: " << endl;
				cin.get();
				cin.getline(String1, 200);
				char* String2 = Concatenate(String0, String1);
				PrintString(String2);
				break;
			}

			case GetSubstringEnum:
			{

				char* String3 = new char[200];
				cout << "Enter String" << endl;
				cin.get();
				cin.getline(String3, 200);
				cout << "Enter StartIndex: " << endl;
				int k, l;
				cin >> k;
				cout << "Enter CharCount: " << endl;
				cin >> l;

				char* subString3 = GetSubstring(String3, k, l);
				if (subString3 != NULL)
					PrintString(subString3);
				break;
			}

			case FindSubstringEnum:
			{
				char* String = new char[200];
				char* SubString = new char[200];
				cout << "Enter String: " << endl;
				cin.get();
				cin.getline(String, 200);
				cout << endl;
				cout << "Enter SubString:" << endl;
				cin.get();
				cin.getline(SubString, 200);
				cout << FindSubstring(String, SubString) << endl;
				break;
			}

			case UppercaseEnum:
			{
				char* String5 = new char[200];
				cout << "Enter String: " << endl;
				cin.get();
				cin.getline(String5, 200);
				cout << Uppercase(String5) << endl;
				break;
			}

			case LowercaseEnum:
			{
				char* String5 = new char[200];
				cout << "Enter String: " << endl;
				cin.get();
				cin.getline(String5, 200);
				cout << Lowercase(String5) << endl;
				break;
			}

			case SplitFilenameEnum:
			{
				char* source6 = new char[50];
				char* path6 = new char[50];
				char* name6 = new char[50];
				char* extension6 = new char[50];
				cout << "Enter String: " << endl;

				cin.get();
				cin.getline(source6, 50);

				SplitFilename(source6, path6, name6, extension6);
				cout << "source: " << source6 << endl;
				cout << "path: " << path6 << endl;
				cout << "name: " << name6 << endl;
				cout << "extension: " << extension6 << endl;
				break;
			}

			case ReplaceTabsOnSpacesEnum:
			{
				char* String7 = new char[200];
				cout << "Enter String: " << endl;
				cin.get();
				cin.getline(String7, 200);
				cout << "!\t!\t!\t!\t!\t!" << endl;
				cout << ReplaceTabsOnSpaces(String7) << endl;
				break;
			}

			case ReplaceSpacesOnTabsEnum:
			{
				char* String7 = new char[200];
				cout << "Enter String: " << endl;
				cin.get();
				cin.getline(String7, 200);
				cout << "!\t!\t!\t!\t!\t!" << endl;
				cout << ReplaceSpacesOnTabs(String7) << endl;
				break;
			}
			case 12:
				exit = true;
				break;


			default:
				cout << "Enter Again" << endl;
				break;
			}

		}
	}

}