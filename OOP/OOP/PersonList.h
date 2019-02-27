#pragma once
#include "Person.h"

namespace Lab5
{

	class PersonListItem
	{
	public:
		PersonListItem(Person person)
		{
			Value = person;
		}
		Person Value;
		PersonListItem* Next = NULL;
		PersonListItem* Prev = NULL;

	};

	class PersonList
	{
	public:
		void Add(Person * person);
		Person* Find(int index);
		int IndexOf(Person * person);
		void Remove(Person * person);
		void RemoveAt(int index);
		void Clear();
		int GetCount();
		int ShowInConsole(int k);
		void Read();
		int Copy(int k);
		void AddByIndex(Person * person, int k);
		static Person GetRandomPerson();
		Person * FindPerson(int index);
		PersonList() { };
	private:
		PersonListItem * _head;
		PersonListItem* _tail;
		int _count;
	};

}