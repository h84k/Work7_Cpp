#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <locale>
#include "windows.h"
using namespace std;

int menu()
{
	cout << "Choose one of the menu items:" << endl;
	cout << "1. Task 1" << endl;
	cout << "2. Task 2" << endl;
	cout << "0. Exit!" << endl << endl;
	cout << "Your choice: ";
	char opt;
	cin >> opt;
	return opt;
}

void task1()
{
	cout << "\n\n_______________________________TASK_1_______________________________" << endl << endl;
	const int N = 6;
	const double X = 0.6;
	double a1 = -0.25, s = a1, a2 = a1, q = 0;
	int reg;

	cout << "Show the result of each iteration?" << endl;
	cout << "Your choice (1 - yes): ";
	cin >> reg;
	if (reg == 1)
	{
		cout << "\n\tq: " << setw(5) << setprecision(4) << q
			<< "\t\ta[0]: " << setw(20) << setprecision(14) << a2
			<< "\t\tS: " << setw(20) << setprecision(14) << s << endl;
	}

	for (int i = 0; i < N-1; i++)
	{
		
		q = (2*i * pow(X, 2) + pow(X, 2) - 4*i * X - 2 * X + 2*i + 1) /
			(2*i * pow(X, 2) + 4*i * X + 2*i + 3 * pow(X, 2) + 6 * X + 3);
		a2 = a1 * q;
		s += a2;
		if (reg == 1)
		{
			cout << "\tq: " << setw(5) << setprecision(4) << q
				<< "\t\ta[" << i + 1 << "]: " << setw(22) << setprecision(14) << a2
				<< "\t\tS: " << setw(20) << setprecision(14) << s << endl;
		}
		a1 = a2;
	}
	cout << "\n____________________________________________________________________\n";
	cout << "\nÑoefficient x: " << X << "\nThe number of elements n: " << N << "\nSum of elements S: " << s;
}
void task2()
{
	cout << "\n\n_______________________________TASK_2_______________________________" << endl << endl;

	for (double x = 0.2; x <= 1.0; x += 0.2)
	{
		int i = 0;

		double q, a = -0.25, s;
		s = a;

		while (abs(a) >= 0.001)
		{
			q = (2 * i * pow(x, 2) + pow(x, 2) - 4 * i * x - 2 * x + 2 * i + 1) / 
				(2 * i * pow(x, 2) + 4 * i * x + 2 * i + 3 * pow(x, 2) + 6 * x + 3);

			a *= q;
			
			s += a;

			i++;
		}
		cout << "Ñoefficient x: " << setprecision(1) << setw(3) << x << " \tSum of elements: " << setprecision(3) << s << endl;
	}


	cout << "\n____________________________________________________________________\n";
}

int main()
{
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true)
	{
		cout << "Kachanov Artem 315A Var. 4" << endl << endl;

		switch (menu())
		{
		case '0':
			return EXIT_SUCCESS;
		case '1':
		{
			task1();
			break;
		}
		case '2':
		{
			task2();
			break;
		}
		default:
		{
			SetConsoleTextAttribute(handle, 4);
			cout << "\nWrong choice, try again!";
			break;
		}
		}
		cout << "\n\n";
		SetConsoleTextAttribute(handle, 2);
		cout << "<<<Press any key>>>\n";
		system("pause>nul");
		SetConsoleTextAttribute(handle, 7);
		system("cls");
	}
	return EXIT_SUCCESS;
}