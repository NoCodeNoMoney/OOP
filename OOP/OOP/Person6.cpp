#include "Person6.h"

namespace Lab6

{

	void Person::SetAge(int age)
	{
		if (age < 0 && age < 150)
		{
			Age = 1;
		}
		else
		{
			Age = age;
		}
	}

	int Person::GetAge()
	{
		return Age;
	}

	string Person::GetDescription()
	{
		string temp;
		temp.append(Name)
			.append(" ")
			.append(Surname)
			.append(", ")
			.append(to_string(Age))
			.append(" years old");
		Sex == Male ? temp.append(", male") : temp.append(", female");
		return temp;
	}

	bool Person::operator==(const Person& right)
	{
		return(!strcmp(Name, right.Name) &&
			!strcmp(Surname, right.Surname) &&
			Age == right.Age && Sex == right.Sex) ? true : false;
	}

}