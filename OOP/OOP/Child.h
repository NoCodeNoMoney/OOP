/*Ќаследование и полиморфизм*/



#pragma once
#include "Person6.h"
//дочерний класс наследован от Person

namespace Lab6
{

	class Child : public Person
	{
	public:
		Person * Mother;
		Person* Father;
		char School[100];//(название детского сада/школы)
		virtual void SetAge(int age) override;
		virtual int GetAge()override;
		virtual string GetDescription() override;
		static Child* GetRandomChild();

	};

}