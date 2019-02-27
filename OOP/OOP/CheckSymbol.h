#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

inline int CheckSymbol()
{
	string n;
	int m;
	do
	{
		cin >> n;
		if (n == "0") { return 0; }
		m = atoi(n.c_str());
	} while (m == 0);
	return m;
}
