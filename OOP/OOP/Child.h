/*Íàñëåäîâàíèå è ïîëèìîðôèçì*/



#pragma once
#include "Person6.h"
//äî÷åðíèé êëàññ íàñëåäîâàí îò Person

namespace Lab6
{

	class Child : public Person
	{
	public:
		Person * Mother;
		Person* Father;
		char School[100];//(íàçâàíèå äåòñêîãî ñàäà/øêîëû)
		virtual void SetAge(int age) override;
		virtual int GetAge()override;
		virtual string GetDescription() override;
		static Child* GetRandomChild();

	};

}
