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
			cout << "������ ����!" << endl;
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
			list.head->next;//�������� ������ �� ��������� �� ������� �������
			list.head->prev = NULL; //������ ���, ���� ���������� ������ ������� ��� ������
			delete temp;//������� ��������� ������
			return list;
		}
		else if ((index == 0) && (list.head == list.tail)){     //���� ������� ������, �� � ������ ������ 1 �������
			Node* temp = list.head;
			list.head->next = NULL;	         //����	���� ��� ��� �����
			list.head = NULL;
			delete list.head;		  //������� ��������� �� ������
			return list;
		}


		Node* temp = list.tail;
		//����� ����� ����, ��� ��������� ������� �������� ��������� ��������� ������
		if (&temp->data == element){
			Node *temp = list.tail;	//���������, ��� ��� ����� �����
			list.tail = list.tail->prev;//���������� ����� ������� �����
			list.tail->next = NULL;	  //����������, ��� ������� �� ������� �����
			delete temp;	  //������� ������ �� ������� ������	                                  
			return list;

		}

		else
		{
			//���� �� ��������� ������� ����� ���-�� � �������� ������, �� ����� ��� ����� �������

			Node *temp1 = list.head, *temp2; //temp-��������� �������, temp2 �����, ����� �� �������� ������

			//cout<<count_<<"\n";
			while (temp1 != NULL && (&temp1->data != element)) temp1 = temp1->next;  //���� � ������ ���������� ��������

			temp2 = temp1;//�������� ���������� ����� ���������� ��������
			temp2->prev->next = temp1->next;	 //���������� ������, ��� ��������� �� ����� ������ ��������� ��������� - ��� ��������� �� ����������
			temp2->next->prev = temp1->prev;  //� ���������� ��� ���������� - ��� ���������� ��� ����������
			delete temp1;//������ ����� ����� ���������� ������, ������ ����� �� ������ ���������� ��������
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
				<< "[1] ������� �������� � �����" << endl
				<< "[2] ����� ������" << endl
				<< "[3] ����� �������� �� �������" << endl
				<< "[4] ������� �������� �� �������" << endl
				<< "[5] �������� �������� �� �������" << endl
				<< "[6] �������� ���������� ������" << endl
				<< "[7] ���������������� � �������� ������ Person" << endl
				<< "[0] ����� �� ���������" << endl
				<< "-------------------------------------------------" << endl
				<< "������� ����� ������� ��� �� ���������: ";
			n = CheckSymbol();
			system("cls");
			system("color 04");
			switch (n)
			{
			case 1:
				newPerson = ReadPerson();
				list = AddEnd(list, &newPerson);
				cout << "�������� ��������" << endl;
				break;

			case 2:
				ShowInConsole(list);
				break;

			case 3:
			{
				cout << "������� ������: ";
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
				cout << "������� ������: ";
				index = CheckSymbol();
				list = InsertByindex(list, &newPerson, index);
				break;

			case 5:
				cout << "������� ������: ";
				index = CheckSymbol();
				list = RemoveByIndex(list, index);
				break;
			case 6:
				list = Clear(list);
				cout << "������ ������";
				break;
			case 7:
			{
				Lab4::Person randomPerson = MakeRandomPerson();
				list = AddEnd(list, &randomPerson);
				cout << "�������� ��������" << endl;
				break;
			}
			case 0:
				key = false;
				break;

			default:
				cout << "��������� ����";
				break;
			}

		}
	}

}