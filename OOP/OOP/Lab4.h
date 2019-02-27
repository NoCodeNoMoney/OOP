
/*Ñòðóêòóðû äàííûõ è äèíàìè÷åñêàÿ ïàìÿòü*/


#pragma once
#include "CheckSymbol.h"

namespace Lab4{
	

	enum Sex { Female, Male };	//Ïåðå÷åñëåíèå äëÿ ïîëà

	struct Person//Ñòðóêòóðà õðîíÿùàÿ èíôîðìàöèþ äëÿ Ïåðñîíû
	{
		string Surname;
		string Name;
		Sex SexPerson;
	};

	struct Node//Íîäà äâóñâÿçíîãî ñïèñêà
	{
		Person data;
		Node* next = NULL;
		Node* prev = NULL;

	};

	struct DoublyLinkedList//Ãîëîâà è õâîñò äâóñâÿçíîãî ñïèñêà
	{
		Node* head = NULL;
		Node* tail = NULL;
	};

	DoublyLinkedList AddEnd(DoublyLinkedList list, Person* person);//ïîìåùàåò ïåðåìåííóþ òèïà Person â êîíåö ñïèñêà.
	void ShowInConsole(DoublyLinkedList list); //âûâîäèò íà ýêðàí ñîäåðæèìîå ñïèñêà.
	Person* GetByIndex(DoublyLinkedList list, int index);//âîçâðàùàþùóþ ññûëêó (èëè óêàçàòåëü) íà ýëåìåíò ñïèñêà ïî óêàçàííîìó èíäåêñó.
	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index);// óäàëÿåò èç ñïèñêà ýëåìåíò ïî óêàçàííîìó èíäåêñó
	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person* person, int index);//ïîìåùàþùóþ ïåðåìåííóþ òèïà
																					//Person ïî óêàçàííîìó èíäåêñó.
	DoublyLinkedList Clear(DoublyLinkedList list);//î÷èùàåò ñîäåðæèìîå ñïèñêà. 

	Person ReadPerson();//ñ÷èòûâàåò äàííûå ÷åëîâåêà ñ êëàâèàòóðû.
	Person MakeRandomPerson();//âîçâðàùàþùóþ ïåðåìåííóþ òèïà Person, èíèöèàëèçèðîâàííóþ ñëó÷àéíûìè äàííûìè.
	void UILab4();//Ìåí

}
