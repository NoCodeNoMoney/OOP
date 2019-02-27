/*Наследование и полиморфизм*/


#pragma once//Ограничивает повторное включение одинаковых хедов.
#include "Person6.h"
//дочерний класс наследован от Person 
//оро
namespace Lab6
{
	class Adult : public Person
	{
	public:
		Person * MarriedOn = NULL;//(человек, на ком женат/замужем или NULL в ином случае)
		char WorkPlace[100];//(название места работы)
		virtual void SetAge(int age) override;
		virtual int GetAge() override;
		virtual string GetDescription() override;
		static Adult* GetRandomAdult();
	};
}
