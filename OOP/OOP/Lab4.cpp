#include "Lab4.h"

namespace Lab4
{

	DoublyLinkedList AddEnd(DoublyLinkedList list, Person * person)
	{
		Node* temp = new Node();
		temp->data = *person;

		if (list.head != NULL)
		{
			temp->prev = list.tail;
			list.tail->next = temp;
			list.tail = temp;
		}
		else
		{
			list.head = list.tail = temp;
		}

		return list;
	}

	void ShowInConsole(DoublyLinkedList list)
	{
		cout << endl;
		Node* temp = list.head;
		int n = 1;
		while (temp != NULL)
		{
			cout << "Person " << n << ": " << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "Surname: " << temp->data.Surname << endl;
			cout << "Name: " << temp->data.Name << endl;
			cout << "Sex: " << temp->data.SexPerson << endl << endl;
			temp = temp->next;
			n++;
		}

		if (list.head != NULL)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "Head: " << endl;
			cout << "Surname: " << list.head->data.Surname << endl;
			cout << "Name: " << list.head->data.Name << endl;
			cout << "Sex: " << list.head->data.SexPerson << endl << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "Tail: " << endl;
			cout << "Surname: " << list.tail->data.Surname << endl;
			cout << "Name: " << list.tail->data.Name << endl;
			cout << "Sex: " << list.tail->data.SexPerson << endl << endl;
			cout << "-------------------------------------------------" << endl;
		}
		else
		{
			cout << "Список Пуст!" << endl;
		}
	}

	Person * GetByIndex(DoublyLinkedList list, int index)
	{
		if (index < 0)
		{
			return NULL;
		}
		int i = 0;
		Node* temp = list.head;
		while (i < index)
		{
			if (temp == NULL)
			{
				return NULL;
			}
			temp = temp->next;
			i++;
		};
		return &temp->data;
	}

	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index)
	{
		Person* element = GetByIndex(list, index);
		if (index == 0)
		{
			Node* temp = list.head;
			list.head->next;//Сдвигаем начало на следующий за началом элемент
			list.head->prev = NULL; //Делаем так, чтоб предыдущий началу элемент был пустым
			delete temp;//Удаляем удаляемое начало
			return list;
		}
		else if ((index == 0) && (list.head == list.tail)){     //Если удаляем первый, но в списке только 1 элемент
			Node* temp = list.head;
			list.head->next = NULL;	         //обну	ляем все что нужно
			list.head = NULL;
			delete list.head;		  //Удаляем указатель на начало
			return list;
		}


		Node* temp = list.tail;
		//Также может быть, что удаляемый элемент является последним элементом списка
		if (&temp->data == element){
			Node *temp = list.tail;	//Указываем, что нам нужен хвост
			list.tail = list.tail->prev;//Отодвигаем хвост немного назад
			list.tail->next = NULL;	  //Обозначаем, что впереди за хвостом пусто
			delete temp;	  //Очищаем память от бывшего хвоста	                                  
			return list;

		}

		else
		{
			//Если же удаляемый элемент лежит где-то в середине списка, то тогда его можно удалить

			Node *temp1 = list.head, *temp2; //temp-Удаляемый элемент, temp2 нужен, чтобы не потерять данные

			//cout<<count_<<"\n";
			while (temp1 != NULL && (&temp1->data != element)) temp1 = temp1->next;  //Идем к адресу удаляемого элемента

			temp2 = temp1;//Временно запоминаем адрес удаляемого элемента
			temp2->prev->next = temp1->next;	 //Записываем данные, что следующий за перед сейчас удаляемым элементом - это следующий от удаляемого
			temp2->next->prev = temp1->prev;  //а предыдущий для следующего - это предыдущий для удаляемого
			delete temp1;//теперь смело можно освободить память, удалив адрес на начало удаляемого элемента
		}
		return list;
	}

	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person * person, int index)
	{
		if (list.head == NULL || index < 0)
		{
			return list;
		}

		Node* temp = list.head;
		int i = 0;
		while (i < index)
		{
			if (temp == NULL)
			{
				return list;
			}
			temp = temp->next;
			i++;
		};

		if (temp == list.head)
		{
			Node* newNode = new Node();
			newNode->data = *person;

			list.head->prev = newNode;
			newNode->next = list.head;

			list.head = newNode;
			return list;
		}

		if (temp == list.tail)
		{
			Node* newNode = new Node();
			newNode->data = *person;
			list.tail->prev->next = newNode;
			newNode->prev = list.tail->prev;
			newNode->next = list.tail;
			list.tail->prev = newNode;
			list.tail->next = NULL;
			return list;
		}


		if (temp != NULL)
		{
			Node* newNode = new Node();
			newNode->data = *person;
			temp->prev->next = newNode;
			newNode->prev = temp->prev;
			newNode->next = temp;
			temp->prev = newNode;
		}
		return list;
	}



	DoublyLinkedList Clear(DoublyLinkedList list)
	{
		while (list.head){
			// cout<<"Del is: "<<Head->x<<"  ";
			list.tail = list.head->next;
			delete list.head;
			list.head = list.tail;
		}

		return list;
	}

	Person ReadPerson()
	{
		Person newPerson;
		cout << "Insert Surname: ";
		cin >> newPerson.Surname;
		cout << endl << "Insert Name: ";
		cin >> newPerson.Name;
		cout << endl << "Insert Sex: ";
		int n;

		do
		{
			n = CheckSymbol();
		} while (n != 0 && n != 1);
		switch (n)
		{
		case Female:
			newPerson.SexPerson = Female;
			break;
		case Male:
			newPerson.SexPerson = Male;
			break;
		default:
			break;
		}
		return newPerson;
	}

	Person MakeRandomPerson()
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
		newPerson.Name = names[name];
		newPerson.Surname = surnames[surname];
		newPerson.SexPerson = Male;
		return newPerson;
	}

	void UILab4()
	{
		srand(time(0));
		setlocale(0, "");
		system("cls");
		Lab4::DoublyLinkedList list;
		bool key = true;
		Lab4::Person newPerson;
		int n, index;
		while (key)
		{
			system("color 02");
			cout << endl
				<< "-------------------------------------------------" << endl
				<< "[1] Вставка элемента в конец" << endl
				<< "[2] Вывод списка" << endl
				<< "[3] Поиск элемента по индексу" << endl
				<< "[4] Вставка элемента по индексу" << endl
				<< "[5] Удаление элемента по индексу" << endl
				<< "[6] Очистить содержимое списка" << endl
				<< "[7] Инициализировать и добавить рандом Person" << endl
				<< "[0] Выход из программы" << endl
				<< "-------------------------------------------------" << endl
				<< "Введите номер функции для ее выолнения: ";
			n = CheckSymbol();
			system("cls");
			system("color 04");
			switch (n)
			{
			case 1:
				newPerson = ReadPerson();
				list = AddEnd(list, &newPerson);
				cout << "Персонаж добавлен" << endl;
				break;

			case 2:
				ShowInConsole(list);
				break;

			case 3:
			{
				cout << "Введите индекс: ";
				index = CheckSymbol();
				Lab4::Person* newPerson = GetByIndex(list, index);
				if (newPerson != NULL)
				{
					cout << "Surname: " << newPerson->Surname << endl;
					cout << "Name: " << newPerson->Name << endl;
					cout << "Sex: " << newPerson->SexPerson << endl;
				}
				break;
			}

			case 4:
				newPerson = ReadPerson();
				cout << "Введите индекс: ";
				index = CheckSymbol();
				list = InsertByindex(list, &newPerson, index);
				break;

			case 5:
				cout << "Введите индекс: ";
				index = CheckSymbol();
				list = RemoveByIndex(list, index);
				break;
			case 6:
				list = Clear(list);
				cout << "Список очищен";
				break;
			case 7:
			{
				Lab4::Person randomPerson = MakeRandomPerson();
				list = AddEnd(list, &randomPerson);
				cout << "Персонаж добавлен" << endl;
				break;
			}
			case 0:
				key = false;
				break;

			default:
				cout << "Повторите ввод";
				break;
			}

		}
	}

}