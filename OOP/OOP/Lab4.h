
/*Структуры данных и динамическая память*/


#pragma once
#include "CheckSymbol.h"

namespace Lab4{
	

	enum Sex { Female, Male };	//Перечесление для пола

	struct Person//Структура хронящая информацию для Персоны
	{
		string Surname;
		string Name;
		Sex SexPerson;
	};

	struct Node//Нода двусвязного списка
	{
		Person data;
		Node* next = NULL;
		Node* prev = NULL;

	};

	struct DoublyLinkedList//Голова и хвост двусвязного списка
	{
		Node* head = NULL;
		Node* tail = NULL;
	};

	DoublyLinkedList AddEnd(DoublyLinkedList list, Person* person);//помещает переменную типа Person в конец списка.
	void ShowInConsole(DoublyLinkedList list); //выводит на экран содержимое списка.
	Person* GetByIndex(DoublyLinkedList list, int index);//возвращающую ссылку (или указатель) на элемент списка по указанному индексу.
	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index);// удаляет из списка элемент по указанному индексу
	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person* person, int index);//помещает переменную типа
											 //Person по указанному индексу.
																					//Person ïî óêàçàííîìó èíäåêñó.
	DoublyLinkedList Clear(DoublyLinkedList list);//очищает содержимое списка. 

	Person ReadPerson();//считывает данные человека с клавиатуры.
	Person MakeRandomPerson();//возвращающую переменную типа Person, инициализированную случайными данными.
	void UILab4();//Меню

}
