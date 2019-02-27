
/*Обобщения в C++*/

#pragma once
#include "CheckSymbol.h"

namespace Lab7
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
		friend std::ostream& operator<<(std::ostream& os, Person& p)
		{
			os << "Surname: " << p.Surname << std::endl;
			os << "Name: " << p.Name << std::endl;
			os << "Age: " << p.Age << std::endl;
			os << "Sex: " << p.Sex << std::endl;
			return os;
		}
		bool operator==(const Person& right)
		{
			return(!strcmp(Name, right.Name) &&
				!strcmp(Surname, right.Surname) &&
				Age == right.Age && Sex == right.Sex) ? true : false;
		}
	};

	template <class T>
	class TemplateListItem
	{
	public:
		TemplateListItem(T person)
		{
			Value = person;
		}
		T Value;
		TemplateListItem* Next = NULL;
		TemplateListItem* Prev = NULL;

		bool operator==(const TemplateListItem& right)
		{
			return Value == right.Value ? true : false;
		}
	};

	template <typename T>
	class TemplateList
	{
	public:
		friend std::ostream& operator<<(std::ostream& os, TemplateList& list)
		{
			TemplateListItem<T>* temp = list._head;
			cout << "Подсписок: ";
			while (temp != NULL)
			{
				cout << temp->Value << "  ";
				temp = temp->Next;
			}
			return os;
		}

		bool operator==(const TemplateList& right)
		{
			TemplateListItem<T>* temp = _head;
			TemplateListItem<T>* temp2 = right._head;
			while (temp != NULL)
			{
				if (temp != temp2)
				{
					return false;
				}
				temp = temp->Next;
				temp2 = temp2->Next;
			}
			return true;
		}

		void Add(T element)
		{
			TemplateListItem<T>* temp = new TemplateListItem<T>(element);
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

		void InsertByIndex(T element, int index)
		{
			if (_head == NULL || index < 0)
			{
				return;
			}

			TemplateListItem<T>* temp = _head;
			int i = 0;
			while (i < index)
			{
				temp = temp->Next;
				i++;
				if (temp == NULL)
				{
					Add(element);
					return;
				}
			};

			if (temp == _head)
			{
				TemplateListItem<T>* newNode = new TemplateListItem<T>(element);
				_head->Prev = newNode;
				newNode->Next = _head;

				_head = newNode;
				return;
			}

			if (temp == _tail)
			{
				TemplateListItem<T>* newNode = new TemplateListItem<T>(element);
				_tail->Prev->Next = newNode;
				newNode->Prev = _tail->Prev;
				newNode->Next = _tail;
				_tail->Prev = newNode;
				_tail->Next = NULL;
				return;
			}


			if (temp != NULL)
			{
				TemplateListItem<T>* newNode = new TemplateListItem<T>(element);
				temp->Prev->Next = newNode;
				newNode->Prev = temp->Prev;
				newNode->Next = temp;
				temp->Prev = newNode;
			}
			return;
		}

		T* Find(int index)
		{
			if (index < 0)
			{
				return NULL;
			}
			int i = 0;
			TemplateListItem<T>* temp = _head;
			while (i < index)
			{
				if (temp == NULL)
				{
					return NULL;
				}
				temp = temp->Next;
				i++;
			};
			return &temp->Value;
		}

		int IndexOf(T element)
		{
			TemplateListItem<T>* temp = _head;
			int index = 0;
			while (temp != NULL)
			{
				if (temp->Value == element)
				{
					return index;
				}
				index++;
				temp = temp->Next;
			}
			return -1;
		}

		void Remove(T element)
		{
			TemplateListItem<T>* temp = _head;
			while (temp != NULL)
			{
				if (temp->Value == element)
				{
					if (_head == temp)
					{
						if (temp->Next == NULL)
						{
							_head = NULL;
							_tail = NULL;
							break;
						}
						_head->Next->Prev = NULL;
						_head = _head->Next;
						break;
					}

					if (_tail == temp)
					{
						_tail->Prev->Next = NULL;
						_tail = _tail->Prev;
						break;
					}

					if (_head != temp && _tail != temp)
					{
						temp->Prev->Next = temp->Next;
						temp->Next->Prev = temp->Prev;
						break;
					}
				}
				temp = temp->Next;
			}
		}

		void RemoveAt(int index)
		{
			T* person = Find(index);
			TemplateListItem<T>* temp = _head;
			while (temp != NULL)
			{
				if (temp->Value == *person)
				{
					if (_head == temp)
					{
						if (temp->Next == NULL)
						{
							_head = NULL;
							_tail = NULL;
							break;
						}
						_head->Next->Prev = NULL;
						_head = _head->Next;
						break;
					}

					if (_tail == temp)
					{
						_tail->Prev->Next = NULL;
						_tail = _tail->Prev;
						break;
					}

					if (_head != temp && _tail != temp)
					{
						temp->Prev->Next = temp->Next;
						temp->Next->Prev = temp->Prev;
						break;
					}
				}
				temp = temp->Next;
			}
		}

		void Clear()
		{

		}

		int GetCount()
		{
			int count = 0;
			TemplateListItem<T>* temp = _head;
			while (temp != NULL)
			{
				temp = temp->Next;
				count++;
			}
			return count;
		}

		void ShowInConsole()
		{
			TemplateListItem<T>* temp = _head;
			while (temp != NULL)
			{
				cout << temp->Value << endl;
				temp = temp->Next;
			}

			if (_head != NULL)
			{
				cout << "-------------------------------------------------" << endl;
				cout << "head = " << _head->Value << endl;
				cout << "tail = " << _tail->Value << endl;
				cout << "-------------------------------------------------" << endl;
			}
			else
			{
				cout << "head = NULL " << " tail = NULL " << endl;
			}
		}

		static Person GetRandomPerson()
		{
			string surnames[] = { "Holiday", "Jacobson", "James", "Allford", "Bawerman",
				"MacAdam", "Marlow", "Bosworth", "Neal", "Conors",
				"Daniels", "Parson", "Quincy", "Richards", "Fane" };

			string names[] = { "Michael", "Joshua", "Matthew", "Ethan", "Andrew",
				"Alexander", "Tyler", "James", "John", "Samuel",
				"Christian", "Logan", "Jose", "Justin", "Gabriel" };
			int surname = rand() % 15;
			int name = rand() % 15;
			Person newPerson;
			newPerson.Age = rand() % 30 + 18;
			for (int i = 0; i <= strlen(names[name].c_str()); i++)
			{
				newPerson.Name[i] = names[name][i];
			}
			for (int i = 0; i <= strlen(surnames[surname].c_str()); i++)
			{
				newPerson.Surname[i] = surnames[surname][i];
			}
			newPerson.Sex = Male;
			return newPerson;
		}

		TemplateList() { }
	private:
		TemplateListItem<T> * _head;
		TemplateListItem<T>* _tail;
		int _count;
	};
}