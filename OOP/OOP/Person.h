/*Классы*/


#pragma once
#include "CheckSymbol.h"

namespace Lab5
{
	enum Sex { Female, Male };

	class Person
	{
	public:
		char Name[20];
		char Surname[20];
		int Age;
		Sex Sex;
		Person() { };
		bool operator==(const Person& right)
		{
			return(!strcmp(Name, right.Name) &&
				!strcmp(Surname, right.Surname) &&
				Age == right.Age && Sex == right.Sex) ? true : false;
		}
	};

}
