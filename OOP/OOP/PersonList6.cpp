#include "PersonList6.h"

namespace Lab6

{


	void PersonList::Add(Person * person)
	{
		PersonListItem* temp = new PersonListItem(person);
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

	Person* PersonList::Find(int index)
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
		return temp->Value;
	}

	int PersonList::IndexOf(Person * person)
	{
		PersonListItem* temp = _head;
		int index = 0;
		while (temp != NULL)
		{
			if (temp->Value == person)
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
		while (temp != NULL)
		{
			if (temp->Value == person)
			{
				if (_head == temp)
				{
					if (temp->Next == NULL)
					{
						_head = NULL;
						_tail = NULL;
						delete temp;
						break;
					}
					_head->Next->Prev = NULL;
					_head = _head->Next;
					delete temp;
					break;
				}

				if (_tail == temp)
				{
					_tail->Prev->Next = NULL;
					_tail = _tail->Prev;
					delete temp;
					break;
				}

				if (_head != temp && _tail != temp)
				{
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					delete temp;
					break;
				}
			}
			temp = temp->Next;
		}
	}

	void PersonList::RemoveAt(int index)
	{
		Person* person = Find(index);
		PersonListItem* temp = _head;
		while (temp != NULL)
		{
			if (temp->Value == person)
			{
				if (_head == temp)
				{
					if (temp->Next == NULL)
					{
						_head = NULL;
						_tail = NULL;
						delete temp;
						break;
					}
					_head->Next->Prev = NULL;
					_head = _head->Next;
					delete temp;
					break;
				}

				if (_tail == temp)
				{
					_tail->Prev->Next = NULL;
					_tail = _tail->Prev;
					delete temp;
					break;
				}

				if (_head != temp && _tail != temp)
				{
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					delete temp;
					break;
				}
			}
			temp = temp->Next;
		}
	}


	/*
	void PersonList::RemoveAt(int index)
	{
	Person* person = Find(index);
	PersonListItem* temp = _head;

	if (index == 0)
	{
	_head=_head->Next;
	_head->Prev = NULL;
	delete _head;

	}

	else if ((index == 0) && (_head == _tail))
	{
	_head->Next = NULL;
	_head = NULL;
	delete _head;

	}

	else

	if (person == _tail->Value)
	{
	temp = _tail;
	_tail = _tail->Prev;
	_tail->Next = NULL;
	delete temp;
	}

	else
	{
	PersonListItem* temp2;
	while (temp != NULL && (temp->Value != person))
	temp = temp->Next;
	temp2 = temp;
	temp2->Prev->Next = temp->Next;
	temp2->Next->Prev = temp->Prev;
	delete temp;
	}

	}

	*/
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

	void PersonList::ShowInConsole()
	{

		PersonListItem* temp = _head;
		int i = 1;

		while (temp != NULL)
		{
			if (temp->Value->GetAge() < 18)
			{
				cout << "Person " << i << " This is a Child: " << endl << endl;
				cout << temp->Value->GetDescription() << endl << endl;
				i++;
			}
			else
			{
				cout << "Person " << i << " This is a Adult: " << endl << endl;
				cout << temp->Value->GetDescription() << endl << endl;
				i++;
			}
			temp = temp->Next;
		}

		if (_head == NULL)
		{
			cout << "List is empty! " << endl;

		}

	}

}