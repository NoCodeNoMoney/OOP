#include "UILab5.h"



void ShowLists(Lab5::PersonList list1, Lab5::PersonList list2)
	{
		cout << "List 1: " << "\t\t" << "||" << "\t\t" << "List 2:" << endl << endl;
		int i = 0;
		int k = 1;
		while (list1.Find(i) != NULL && list2.Find(i) != NULL)
		{
			cout << left << "Person " << k << ": " << "\t\t" << "||" << "\t\t" << "Person " << k << ": " << endl << endl;
			if (strlen(list1.Find(i)->Surname) > 6)
				cout << left << "Surname: " << list1.Find(i)->Surname << "\t" << "||" << "\t\t" << "Surname: "
				<< list2.Find(i)->Surname << endl;
			else
				cout << left << "Surname: " << list1.Find(i)->Surname << "\t\t" << "||" << "\t\t" << "Surname: "
				<< list2.Find(i)->Surname << endl;
			cout << left << "Name: " << list1.Find(i)->Name << "\t\t" << "||" << "\t\t" << "Name: " << list2.Find(i)->Name << endl;
			cout << left << "Sex:   " << list1.Find(i)->Sex << "\t\t" << "||" << "\t\t" << "Sex: " << list2.Find(i)->Sex << endl;
			cout << left << "Age:   " << list1.Find(i)->Age << "\t\t" << "||" << "\t\t" << "Age: " << list2.Find(i)->Age << endl << endl;;
			i++;
			k++;
		}
		while (list1.Find(i) != NULL)
		{
			cout << "Person " << k << ": " << "\t\t" << "||" << endl << endl;
			if (strlen(list1.Find(i)->Surname) > 6)
				cout << "Surname: " << list1.Find(i)->Surname << "\t" << "||" << endl;
			else
				cout << "Surname: " << list1.Find(i)->Surname << "\t\t" << "||" << endl;
			cout << "Name: " << list1.Find(i)->Name << "\t\t" << "||" << endl;
			cout << "Sex:   " << list1.Find(i)->Sex << "\t\t" << "||" << endl;
			cout << "Age:   " << list1.Find(i)->Age << "\t\t" << "||" << endl << endl;;
			i++;
			k++;
		}
		while (list2.Find(i) != NULL)
		{
			cout << "\t\t\t" << "||" << "\t\t" << "Person " << k << ": " << endl << endl;
			cout << "\t\t\t" << "||" << "\t\t" << "Surname: " << list2.Find(i)->Surname << endl;
			cout << "\t\t\t" << "||" << "\t\t" << "Name: " << list2.Find(i)->Name << endl;
			cout << "\t\t\t" << "||" << "\t\t" << "Sex: " << list2.Find(i)->Sex << endl;
			cout << "\t\t\t" << "||" << "\t\t" << "Age: " << list2.Find(i)->Age << endl << endl;;
			i++;
			k++;
		}
	}



	void UILab5()
	{
		setlocale(0, "");
		srand(time(0));
		Lab5::PersonList list1;
		Lab5::PersonList list2;
		Lab5::Person p;



		list1.Add(&list1.GetRandomPerson());
		list1.Add(&list1.GetRandomPerson());
		list1.Add(&list1.GetRandomPerson());

		list2.Add(&list2.GetRandomPerson());
		list2.Add(&list2.GetRandomPerson());
		list2.Add(&list2.GetRandomPerson());


		ShowLists(list1, list2);

		system("pause");


		cout << "Add new person in list1: " << endl << endl;
		list1.Add(&list1.GetRandomPerson());
		ShowLists(list1, list2);
		system("pause");

		cout << "Copy person 2 from list1 in list2: " << endl << endl;
		list2.Add(list1.Find(1));
		ShowLists(list1, list2);
		system("pause");


		cout << "Delete person 2 from list1 in list2: " << endl << endl;
		list1.RemoveAt(1);
		ShowLists(list1, list2);

		system("pause");


		cout << "Clear list 2: " << endl << endl;
		list2.Clear();
		ShowLists(list1, list2);


		system("pause");

	}




