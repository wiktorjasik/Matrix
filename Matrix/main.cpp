#include "Matrix.h"

int main()
{
	Matrix a, b;
	int choose;
	for (;;)
	{
		system("cls");
		cout << "KALKULATOR MACIERZY\n\n";
		cout << "1. Wpisz macierze a i b\n";
		cout << "2. Wczytaj macierze a i b z pliku\n";
		cout << "3. Wypelnij macierze a i b losowymi cyframi\n";
		cout << "4. Dzialanie a+b\n";
		cout << "5. Dzialanie a-b\n";
		cout << "6. Dzialanie a*b\n";
		cout << "7. Zapisz macierze do pliku\n";
		cout << "8. Wyjscie\n\n";
		cout << "Twoj wybor: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			system("cls");
			cin >> a >> b;
			system("pause");			
			break;
		case 2:
			system("cls");
			a.loadA();
			b.loadB();
			system("pause");
			break;
		case 3:
			system("cls");
			a.random();
			b.random();
			cout << "Pomyslnie wypelniono macierze a i b losowymi cyframi\n";
			system("pause");
			break;
		case 4:
			system("cls");
			cout << a + b << endl;
			system("pause");
			break;
		case 5:
			system("cls");
			cout << a - b << endl;
			system("pause");
			break;
		case 6:
			system("cls");
			cout << a * b << endl;
			system("pause");
			break;
		case 7:
			system("cls");
			a.saveA();
			b.saveB();
			system("pause");
			break;
		case 8:
			system("cls");
			exit(0);
			system("pause");
			break;
		default:
			system("cls");
			cout << "Niepoprawny wybor\n";
			system("pause");
			break;
		}
	}
	
	return 0;
}