/*Классы*/



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
		void Add(Person * person);//добавить человека в список		
		Person* Find(int index);//найти человека по указанному индексу
		int IndexOf(Person * person);//вернуть индекс человека, если он есть в списке
		void Remove(Person * person);//удалить человека из списка
		void RemoveAt(int index);//удалить человека из списка по индексу
		void Clear();//очистить список
		int GetCount();//получить количество элементов
		int ShowInConsole(int k);//вывод персоны на экран
		void Read();//чтение персоны с клавиатуры 
		int Copy(int k);
		void AddByIndex(Person * person, int k);//добавить человека по индексу
		static Person GetRandomPerson();
		Person * FindPerson(int index);
		PersonList() { };//конструктор класса
	private:
		PersonListItem * _head;//указатель на голову списка
		PersonListItem* _tail;
		int _count;//количество элементов в списке
	};

}
