/*������������ � �����������*/


#pragma once//������������ ��������� ��������� ���������� �����.
#include "Person6.h"
//�������� ����� ���������� �� Person

namespace Lab6
{
	class Adult : public Person
	{
	public:
		Person * MarriedOn = NULL;//(�������, �� ��� �����/������� ��� NULL � ���� ������)
		char WorkPlace[100];//(�������� ����� ������)
		virtual void SetAge(int age) override;
		virtual int GetAge() override;
		virtual string GetDescription() override;
		static Adult* GetRandomAdult();
	};
}