#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <locale>
#include "windows.h"
using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

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
		q = (pow(X - 1, 2) * (2*i + 1))/((2*i + 3) * pow(X + 1, 2));
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

	const double EPS = 1E-3; //the accuracy of finding the sum
	double q, a, s;
	int i;

	for (double x = 0.2; x <= 1.0; x += 0.2)
	{
		i = 0;
		if (x + 1 == 0)
		{
			SetConsoleTextAttribute(handle, 4);
			cout << "It is impossible to calculate the first element of the progression and the recurrence coefficient with x = " << x <<"\nDivision by zero is impossible!\n";
			SetConsoleTextAttribute(handle, 7);
			continue;
		}
		a = (x - 1) / (x + 1);
		s = a;

		while (abs(a) >= EPS)
		{
			q = (pow(x - 1, 2) * (2 * i + 1)) / ((2 * i + 3) * pow(x + 1, 2));
				
				a *= q;
				
				s += a;

				i++;
		}
		cout << "Coefficient x: " << setprecision(1) << setw(3) << x << " \tSum of elements: " << setprecision(3) << s << endl;
	}


	cout << "\n____________________________________________________________________\n";
}

int main()
{
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