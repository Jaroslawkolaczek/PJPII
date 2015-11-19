#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
using namespace std;

int MenuGlowne()
{
	string sWyborMenuGlowne;
	short siWybor = 0;



	do
	{

		cout << "\n\n\n\n\n\n\t\tWitaj w Into the darkness" << endl;
		cout << "\n\n\t1.Zagraj" << endl;
		cout << "\t2.Pomoc" << endl;
		cout << "\t3.Informacje" << endl;
		cout << "\t4.Wyjscie" << endl;

		cin >> sWyborMenuGlowne;
		system("cls");

	} while (!(sWyborMenuGlowne == "1" || sWyborMenuGlowne == "2" || sWyborMenuGlowne == "3" || sWyborMenuGlowne == "4"));
	siWybor = stoi(sWyborMenuGlowne);
	//cout << siWybor;
	return siWybor;
}
void Pozegnanie()
{
	system("cls");
	cout << "\n\n\n\n\n\n\t\tMilego Dnia\n\n\n\n\n\n";
	system("timeout 5");
}

	int main(){

		for (;;)
		{
			switch (MenuGlowne())
			{
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:
				Pozegnanie();
				return EXIT_SUCCESS;
			}
		}
	}

