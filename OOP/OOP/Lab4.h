
/*—труктуры данных и динамическа€ пам€ть*/


#pragma once
#include "CheckSymbol.h"

namespace Lab4{
	

	enum Sex { Female, Male };	//ѕеречесление дл€ пола

	struct Person//—труктура хрон€ща€ информацию дл€ ѕерсоны
	{
		string Surname;
		string Name;
		Sex SexPerson;
	};

	struct Node//Ќода двусв€зного списка
	{
		Person data;
		Node* next = NULL;
		Node* prev = NULL;

	};

	struct DoublyLinkedList//√олова и хвост двусв€зного списка
	{
		Node* head = NULL;
		Node* tail = NULL;
	};

	DoublyLinkedList AddEnd(DoublyLinkedList list, Person* person);//помещает переменную типа Person в конец списка.
	void ShowInConsole(DoublyLinkedList list); //выводит на экран содержимое списка.
	Person* GetByIndex(DoublyLinkedList list, int index);//возвращающую ссылку (или указатель) на элемент списка по указанному индексу.
	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index);// удал€ет из списка элемент по указанному индексу
	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person* person, int index);//помещающую переменную типа
																					//Person по указанному индексу.
	DoublyLinkedList Clear(DoublyLinkedList list);//очищает содержимое списка. 

	Person ReadPerson();//считывает данные человека с клавиатуры.
	Person MakeRandomPerson();//возвращающую переменную типа Person, инициализированную случайными данными.
	void UILab4();//ћеню

}
