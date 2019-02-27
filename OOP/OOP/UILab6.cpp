#include "UILab6.h"

void UILab6()
{
	setlocale(0, "");
	srand(time(0));
	Lab6::Adult* adultl1 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl2 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl3 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl4 = Lab6::Adult::GetRandomAdult();

	Lab6::Child* child1 = Lab6::Child::GetRandomChild();
	Lab6::Child* child2 = Lab6::Child::GetRandomChild();
	Lab6::Child* child3 = Lab6::Child::GetRandomChild();

	Lab6::PersonList list;
	int i = 0;
	int r = 0;
	while (i < 3)
	{
		r = rand() % 100;
		if (r == 0)
			list.Add(Lab6::Adult::GetRandomAdult());
		else
		{
			list.Add(Lab6::Child::GetRandomChild());
		}

		i++;
	}

	list.Add(adultl1);



	while (i < 6)
	{
		r = rand() % 100;
		if (r == 0)
			list.Add(Lab6::Adult::GetRandomAdult());
		else
		{
			list.Add(Lab6::Child::GetRandomChild());
		}

		i++;
	}




	list.ShowInConsole();

	Lab6::Person* find = list.Find(3);
	cout << "Find Person  " << list.IndexOf(find) << endl;
	cout << find->GetDescription() << endl;

	list.ShowInConsole();
	cout << "Remove Person  " << list.IndexOf(find) << endl;
	list.RemoveAt(3);
	list.ShowInConsole();


	system("pause");
}