#include "Child.h"

namespace Lab6

{

	void Child::SetAge(int age)
	{
		if (age > 17)
		{
			Person::SetAge(10);
		}
		else
		{
			Person::SetAge(age);
		}

	}

	int Child::GetAge()
	{
		return Person::GetAge();
	}

	Child* Child::GetRandomChild()
	{
		string schools[] = { "Bolton Free School", "Bray Free Primary School", "Burnley High School" };
		string surnames[] = { "Holiday", "Jacobson", "James", "Allford", "Bawerman",
			"MacAdam", "Marlow", "Bosworth", "Neal", "Conors",
			"Daniels", "Parson", "Quincy", "Richards", "Fane" };
		string names[] = { "Michael", "Joshua", "Matthew", "Ethan", "Andrew",
			"Alexander", "Tyler", "James", "John", "Samuel",
			"Christian", "Logan", "Jose", "Justin", "Gabriel" };
		int surname = rand() % 15;
		int name = rand() % 15;
		int school = rand() % 3;
		Child* newPerson = new Child();
		for (int i = 0; i <= strlen(names[name].c_str()); i++)
		{
			newPerson->Name[i] = names[name][i];
		}
		for (int i = 0; i <= strlen(surnames[surname].c_str()); i++)
		{
			newPerson->Surname[i] = surnames[surname][i];
		}
		newPerson->SetAge(rand() % 16 + 1);
		rand() % 2 == 0 ? newPerson->Sex = Male : newPerson->Sex = Female;
		if (rand() % 2 == 0)
		{
			Child* Father = new Child();
			int surnameF = rand() % 15;
			int nameF = rand() % 15;
			int surnameM = rand() % 15;
			int nameM = rand() % 15;
			for (int i = 0; i < strlen(names[nameF].c_str()); i++)
			{
				Father->Name[i] = names[nameF][i];
			}
			for (int i = 0; i < strlen(surnames[surnameF].c_str()); i++)
			{
				Father->Surname[i] = surnames[surnameF][i];
			}
			Father->SetAge(rand() % 20 + 18);
			Father->Sex = Male;
			Father->Father = (Person*)newPerson;
			newPerson->Father = Father;
			Child* Mother = new Child();

			for (int i = 0; i < strlen(names[nameM].c_str()); i++)
			{
				Mother->Name[i] = names[nameM][i];
			}
			for (int i = 0; i < strlen(surnames[surnameM].c_str()); i++)
			{
				Mother->Surname[i] = surnames[surnameM][i];
			}
			Mother->SetAge(rand() % 20 + 18);
			Mother->Sex = Female;
			Mother->Mother = (Person*)newPerson;
			newPerson->Mother = Mother;
		}
		if (rand() % 2 == 0)
		{
			for (int i = 0; i <= strlen(schools[school].c_str()); i++)
			{
				newPerson->School[i] = schools[school][i];
			}
		}
		return newPerson;
	}

	string Child::GetDescription()
	{
		string temp = Person::GetDescription();
		if (Mother != NULL && Father != NULL)
		{
			temp.append(",\n parents are ")
				.append(Mother->Name)
				.append(" ")
				.append(Mother->Surname)
				.append(" and ")
				.append(Father->Name)
				.append(" ")
				.append(Father->Surname);
		}
		else if (Mother != NULL)
		{
			temp.append(", mother is ")
				.append(Mother->Name)
				.append(" ")
				.append(Mother->Surname);
		}
		else if (Father != NULL)
		{
			temp.append(", father is ")
				.append(Father->Name)
				.append(" ")
				.append(Father->Surname);
		}
		else
		{
			temp.append("\n, parents are not specified");
		}

		if (strlen(School) != 0)
		{
			temp.append(",\n ")
				.append(School);
		}
		else
		{
			temp.append("\n, does not go to school");
		}
		return temp;
	}

}