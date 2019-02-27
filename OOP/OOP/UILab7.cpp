#include "UILab7.h"

void UILab7()
{
	Lab7::TemplateList<double> doubleList;
	Lab7::TemplateList<Lab7::Person> personList;
	Lab7::TemplateList<double[5]> doubleArrayList;
	Lab7::TemplateList<Lab7::TemplateList<double>> doubleListList;

	Lab7::TemplateList<double> doubleList2;
	Lab7::TemplateList<double> doubleList3;
	Lab7::TemplateList<double> doubleList4;
	Lab7::TemplateList<double> doubleList5;
	Lab7::TemplateList<double> doubleListAdd;

	bool key = true;
	int n;
	while (key)
	{
		cout << endl
			<< "-------------------------------------------------" << endl
			<< "[1] Demonstrate on double" << endl
			<< "[2] Demonstrate on Person" << endl
			<< "[3] Demonstrate on List<double>" << endl
			<< "[0] Exit" << endl
			<< "-------------------------------------------------" << endl
			<< "Choose 0-3: ";
		n = CheckSymbol();
		system("cls");
		switch (n)
		{
		case 1:
			doubleList.Add(1.17);
			doubleList.Add(2.17);
			doubleList.Add(3.17);
			doubleList.Add(4.17);
			doubleList.Add(5.17);
			doubleList.ShowInConsole();
			doubleList.RemoveAt(2);
			doubleList.ShowInConsole();
			doubleList.InsertByIndex(4.44, 4);
			doubleList.ShowInConsole();
			break;
		case 2:
			personList.Add(personList.GetRandomPerson());
			personList.Add(personList.GetRandomPerson());
			personList.Add(personList.GetRandomPerson());
			personList.Add(personList.GetRandomPerson());
			personList.Add(personList.GetRandomPerson());
			personList.ShowInConsole();
			personList.RemoveAt(2);
			personList.ShowInConsole();
			personList.InsertByIndex(personList.GetRandomPerson(), 4);
			personList.ShowInConsole();
			break;
		case 0:
			key = false;
			break;
		case 3:
			doubleList.Add(1.1);
			doubleList.Add(2.1);
			doubleList.Add(3.1);

			doubleList2.Add(1.2);
			doubleList2.Add(2.2);
			doubleList2.Add(3.2);

			doubleList3.Add(1.3);
			doubleList3.Add(2.3);
			doubleList3.Add(3.3);

			doubleList4.Add(1.4);
			doubleList4.Add(2.4);
			doubleList4.Add(3.4);

			doubleList5.Add(1.5);
			doubleList5.Add(2.5);
			doubleList5.Add(3.5);

			doubleListList.Add(doubleList);
			doubleListList.Add(doubleList2);
			doubleListList.Add(doubleList3);
			doubleListList.Add(doubleList4);
			doubleListList.Add(doubleList5);
			doubleListList.ShowInConsole();
			doubleListList.RemoveAt(2);
			doubleListList.ShowInConsole();
			doubleListAdd.Add(4.4);
			doubleListAdd.Add(4.4);
			doubleListAdd.Add(4.4);

			doubleListList.InsertByIndex(doubleListAdd, 4);
			doubleListList.ShowInConsole();
			break;
		default:
			cout << "Повторите ввод";
			break;
		}
	}
	system("pause");
}

