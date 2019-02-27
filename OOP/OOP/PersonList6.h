/*Наследование и полиморфизм*/




#pragma once
#include "Adult.h"
#include "Child.h"

namespace Lab6

{

	class PersonListItem
	{
	public:
		PersonListItem(Person * person)
		{
			Value = person;
		}
		Person* Value;
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
		void ShowInConsole();
		PersonList() { };
	private:
		PersonListItem * _head;
		PersonListItem* _tail;
		int _count;
	};

}