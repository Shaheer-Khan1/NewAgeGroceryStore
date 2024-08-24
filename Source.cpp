#include "Header.h"
#include <iostream>
#include <iomanip>

using namespace std;

void retrieve() {
	Feedback temp;
	string f = "Feedback.bin";

	ifstream mm(f, ios::binary);
	while (mm.read((char*)&temp, sizeof(temp))) {
		temp.Display();
	}
	mm.close();
}


int main() {
	int Choose,Showpass;
	cout << setfill('-') << setw(121) << "WELCOME TO NEW AGE GROCERY STORE" <<setw(90)<<setfill('-');
	cout << ""<<setfill('_') << setw(236) << endl;
	retrieve();
	cout << "\nPress 1 for Registration" << endl << "Press 2 for Login" << endl;
	cout << "" << setfill('_') << setw(236) << endl;
	cin >> Choose;
	if (Choose == 1) {
		cout << setfill('-') << setw(113) << "Register Yourself" << setw(98) << setfill('-') ;
	}

	if (Choose == 2) {
		cout << setfill('-') << setw(121) << "Login to your Account" << setw(90) << setfill('-');
		Login obj;
		//obj2.login();
		bool x1=obj.login();
		while (x1 != true) {

			cout << "Incorrect ID or Password\nTry Again:" << endl;
			x1=obj.login();
		}
		//Registration oj;
		//string usertemp = obj.postf();
			cout << "Login Successfull! " << endl;
			cout << "Press 1 to logout!\nPress any key to continue. " << endl;
			int x;
			cin >> x;
			if (x == 1) {
				main();
			}
			system("pause");
			HomeScreenAndSubMenu obj1(obj.postf());
			obj1.Display(obj);
			//obj1.display();

	}

	if (Choose == 1) {
		Registration obj;
		obj.infoCheck();
		system("CLS");
		cout << setfill('-') << setw(121) << "WELCOME TO NEW AGE GROCERY STORE" << setw(90) << setfill('-');
		obj.Display();
		obj.insertObject(obj);
		cout << "Registration Successfull, Press 1 to Show Password Again:" << endl;
		cin >> Showpass;
		if (Showpass == 1) {
			cout << obj.getpassword()<<endl;
		}
		system("pause");
		system("cls");
		main();

	}
}