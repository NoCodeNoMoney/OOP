

#include "PersonList.h"

namespace Lab5
{
	void PersonList::Add(Person * person)
	{
		PersonListItem* temp = new PersonListItem(*person);
		if (_head != NULL)
		{
			temp->Prev = _tail;
			_tail->Next = temp;
			_tail = temp;
		}
		else
		{
			_head = _tail = temp;
		}
	}




	Person * PersonList::Find(int index)
	{
		if (index < 0)
		{
			return NULL;
		}
		int i = 0;
		PersonListItem* temp = _head;
		while (i < index)
		{
			if (temp == NULL)
			{
				return NULL;
			}
			temp = temp->Next;
			i++;
		};
		Person *temp2 = &temp->Value;

		return temp2;

	}



	int PersonList::IndexOf(Person * person)
	{
		PersonListItem* temp = _head;
		int index = 0;
		while (temp != NULL)
		{

			if (temp->Value == *person)
			{
				return index;
			}
			index++;
			temp = temp->Next;
		}
		return -1;
	}

	void PersonList::Remove(Person * person)
	{
		PersonListItem* temp = _head;
		if (temp->Value == *person)
		{
			_head->Next;
			_head->Prev = NULL;
			delete temp;
		}
		else if ((temp->Value == *person) && (_head == _tail))
		{
			_head->Next = NULL;
			_head = NULL;
			delete _head;


		}

		if (*person == _tail->Value)
		{
			temp = _tail;
			_tail = _tail->Prev;
			_tail->Next = NULL;
			delete temp;
		}

		else
		{
			PersonListItem* temp2;
			while (temp != NULL && (&temp->Value != person))
				temp = temp->Next;
			temp2 = temp;
			temp2->Prev->Next = temp->Next;
			temp2->Next->Prev = temp->Prev;
			delete temp;
		}

	}




	void PersonList::RemoveAt(int index)
	{
		Person* person = Find(index);
		PersonListItem* temp = _head;

		if (index == 0)
		{
			_head->Next;
			_head->Prev = NULL;
			delete temp;

		}

		else if ((index == 0) && (_head == _tail))
		{
			_head->Next = NULL;
			_head = NULL;
			delete _head;

		}

		else

			if (*person == _tail->Value)
			{
				temp = _tail;
				_tail = _tail->Prev;
				_tail->Next = NULL;
				delete temp;
			}

			else
			{
				PersonListItem* temp2;
				while (temp != NULL && (&temp->Value != person))
					temp = temp->Next;
				temp2 = temp;
				temp2->Prev->Next = temp->Next;
				temp2->Next->Prev = temp->Prev;
				delete temp;
			}

	}





	void PersonList::Clear()
	{
		while (_head)
		{
			_tail = _head->Next;
			delete _head;
			_head = _tail;
		}
	}

	int PersonList::GetCount()
	{
		int count = 0;
		PersonListItem* temp = _head;
		while (temp != NULL)
		{
			temp = temp->Next;
			count++;
		}
		return count;
	}

	int PersonList::ShowInConsole(int k)
	{




		int n = 1;
		cout << endl;
		PersonListItem* temp = _head;
		while (temp != NULL)
		{
			cout << setw(16) << "List" << k << " :" << endl;
			cout << setw(16) << "Person " << n << ": " << endl << endl;
			cout << setw(16) << "Surname: " << temp->Value.Surname << endl;
			cout << setw(16) << "Name: " << temp->Value.Name << endl;
			cout << setw(16) << "Sex: " << temp->Value.Sex << endl;
			cout << setw(16) << "Age: " << temp->Value.Age << endl << endl;
			temp = temp->Next;
			n++;
		}

		if (_head != NULL)
		{
			cout << setw(16) << "-------------------------------------------" << endl;
			cout << setw(16) << "Head: " << endl << endl;
			cout << setw(16) << "Surname: " << _head->Value.Surname << endl;
			cout << setw(16) << "Name: " << _head->Value.Name << endl;
			cout << setw(16) << "Sex: " << _head->Value.Sex << endl;
			cout << setw(16) << "Age: " << _head->Value.Age << endl << endl;
			cout << setw(16) << "Tail: " << endl << endl;
			cout << setw(16) << "Surname: " << _tail->Value.Surname << endl;
			cout << setw(16) << "Name: " << _tail->Value.Name << endl;
			cout << setw(16) << "Sex: " << _tail->Value.Sex << endl;
			cout << setw(16) << "Age: " << _tail->Value.Age << endl << endl;
			cout << setw(16) << "-------------------------------------------------" << endl;
		}
		else
		{
			cout << "List is Empty " << endl;
		}


		return NULL;
	}

	void PersonList::Read()
	{
		Person newPerson;
		bool key = true;
		while (key)
		{
			cout << endl << "Insert Surname: ";
			cin >> newPerson.Surname;
			key = false;
			for (int i = 0; i < strlen(newPerson.Surname); i++)
			{
				if (isdigit(newPerson.Surname[i]) || isspace(newPerson.Surname[i]))
				{
					key = true;
					break;
				}
				if (newPerson.Surname[i] == '-')
				{
					if (isalpha(newPerson.Surname[i + 1]))
					{
						newPerson.Surname[i + 1] = toupper(newPerson.Surname[i + 1]);
					}
					else
					{
						key = true;
						break;
					}
				}
			}
			newPerson.Surname[0] = toupper(newPerson.Surname[0]);
		}

		key = true;
		while (key)
		{
			cout << endl << "Insert Name: ";
			cin >> newPerson.Name;
			key = false;
			for (int i = 0; i < strlen(newPerson.Name); i++)
			{
				if (isdigit(newPerson.Name[i]) || isspace(newPerson.Name[i]))
				{
					key = true;
					break;
				}
				if (newPerson.Name[i] == '-')
				{
					if (isalpha(newPerson.Surname[i + 1]))
					{
						newPerson.Surname[i + 1] = toupper(newPerson.Surname[i + 1]);
					}
					else
					{
						key = true;
						break;
					}
				}
			}
			newPerson.Name[0] = toupper(newPerson.Name[0]);
		}
		cout << endl << "Insert Sex: ";
		int n;

		do
		{
			n = CheckSymbol();
		} while (n != 0 && n != 1);
		switch (n)
		{
		case Female:
			newPerson.Sex = Female;
			break;
		case Male:
			newPerson.Sex = Male;
			break;
		default:
			break;
		}

		cout << endl << "Insert Age: ";


		do
		{
			cout << "Age must be lower than 124" << endl;
			n = CheckSymbol();
		} while (n > 123);

		newPerson.Age = n;

		this->Add(&newPerson);
	}

	Person PersonList::GetRandomPerson()
	{
		string surnames[] = { "Holiday", "Jacobson", "James", "Allford", "Bawerman",
			"MacAdam", "Marlow", "Bosworth", "Neal", "Conors",
			"Daniels", "Parson", "Quincy", "Richards", "Fane" };
		string names[] = { "Michael", "Joshua", "Matthew", "Ethan", "Andrew",
			"Alexander", "Tyler", "James", "John", "Samuel",
			"Christian", "Logan", "Jose", "Justin", "Gabriel" };
		int surname = rand() % 15;
		int name = rand() % 15;
		int age = 18 + rand() % 50;
		Person newPerson;
		for (int i = 0; i <= strlen(names[name].c_str()); i++)
		{
			newPerson.Name[i] = names[name][i];
		}
		for (int i = 0; i <= strlen(surnames[surname].c_str()); i++)
		{
			newPerson.Surname[i] = surnames[surname][i];
		}
		int sex = rand() % 2;
		if (sex == 0)
			newPerson.Sex = Female;
		else
			newPerson.Sex = Male;
		newPerson.Age = age;
		return newPerson;
	}

}