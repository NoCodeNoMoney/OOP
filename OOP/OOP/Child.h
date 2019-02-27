#pragma once
#include "Person6.h"

namespace Lab6
{

	class Child : public Person
	{
	public:
		Person * Mother;
		Person* Father;
		char School[100];
		virtual void SetAge(int age) override;
		virtual int GetAge()override;
		virtual string GetDescription() override;
		static Child* GetRandomChild();

	};

}