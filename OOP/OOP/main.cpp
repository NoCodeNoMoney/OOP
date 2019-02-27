#include "Lab3.h"
#include "Lab4.h"
#include "UILab5.h"
#include "UILab6.h"



void main()
{
	setlocale(0, "");
	srand(time(0));
	int n;
	while (true)
	{
		cout << endl
			<< "------------------" << endl
			<< "[1] Lab 3" << endl
			<< "[2] Lab 4" << endl
			<< "[3] Lab 5" << endl
			<< "[4] Lab 6" << endl
			//<< "[5] Lab 7" << endl
			<< "[0] Exit" << endl
			<< "------------------" << endl
			<< "Choose 0-5: ";
		n = CheckSymbol();
		system("cls");
		switch (n)
		{
		case 1:
			Lab3::UILab3(); break;
		case 2:
			Lab4::UILab4(); break;
		case 3:
			UILab5(); break;
		case 4:
			UILab6(); break;
			/*
		case 5:
			UILab7(); break;
			*/
		case 0:
			
		default:
			cout << "Повторите ввод"; break;
		}
	}
	
}