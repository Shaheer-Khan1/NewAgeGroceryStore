#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <istream>
#include <fstream>
#include <conio.h>
using namespace std;

#pragma once

class SuperMarket {
private:
	string name;
	string city;
	int branch_no;
	int branch[];
public:
	SuperMarket() {
		name = "\0";
		city = "\0";
		branch_no = 0;
	}

	void setsmname(string x) {
		name = "";
	}

	string getmname() {
		return name;
	}

	void setbn(int x) {
		branch_no = x;
	}

	int getbn() {
		return branch_no;
	}

	void city_(string x) {

		cout << "Enter name of city (START WITH CAPITAL LETTER)";
		cin >> x;

		while (x != "Lahore" && x != "Islamabad" && x != "Peshawar") {
			cout << "We don't have a branch in this city yet! Please Enter again: ";
			cin >> x;
		}
		city = x;

	}

	string getcity() {
		return city;
	}

};

class user {
private:
	char gender[10];
	char cnic[20];
	char phonenumber[20];
	char address[100];
	char username[20];
	char password[20];
public:
	char post[20];

	void Display() {
		cout << gender << endl;
		cout << cnic << endl;
		cout << username << endl;
		cout << phonenumber << endl;
	}

	user() {

		for (int i = 0; i < 100; i++) {
			address[i] = '\0';
		}
		for (int i = 0; i < 20; i++) {
			post[i] = '\0';
			cnic[i] = '\0';
			phonenumber[i] = '\0';
			username[i] = '\0';
			password[i] = '\0';
			

		}
		for (int i = 0; i < 10; i++) {
			gender[i] = '\0';
		}
	}

	string getpost() {
		return post;
	}

	string getgender() {
		return gender;
	}

	string getcnic() {
		return cnic;
	}

	string getphonenumber() {
		return phonenumber;
	}

	string getaddress() {
		return address;
	}

	string getusername() {
		return username;
	}

	string getpassword() {
		return password;
	}

	void setpost(string x) {
		for (int i = 0; x[i] != '\0'; i++) {
			post[i] = x[i];
		}
	}

	void setgender(string g) {
		for (int i = 0; g[i] != '\0'; i++) {
			gender[i] = g[i];
		}
	}

	void setcnic(string c) {
		for (int i = 0; c[i] != '\0'; i++) {
			cnic[i] = c[i];
		}
	}

	void setpassword(string p) {
		for (int i = 0; p[i] != '\0'; i++) {
			password[i] = p[i];
		}
	}

	void setaddress(string a) {
		for (int i = 0; a[i] != '\0'; i++) {
			address[i] = a[i];
		}
	}

	void setphonenumber(string pn) {
		for (int i = 0; pn[i] != '\0'; i++) {
			password[i] = pn[i];
		}
	}

	void setusername(string un) {
		for (int i = 0; un[i] != '\0'; i++) {
			username[i] = un[i];
		}
	}

};

// Derived class (child)
class admin : public user {

private:

	char gender[10];
	char cnic[20];
	char phonenumber[20];
	char address[100];
	char username[20];
	char password[20];
	public:

		user* u = new admin(*this);

		virtual void Display() {
			cout << gender << endl;
			cout << cnic << endl;
			cout << username << endl;
			cout << phonenumber << endl;

		}
	admin() {
		setusername("ShaheerAdmin");
		setpassword("Admin_1234");
		setaddress("islamabad");
		setcnic("1234567891234");
		setphonenumber("03358859992");
		setgender("male");
		setpost("admin");
	}
};

class costumer : public user {
private:
	float regularity;
	char gender[10];
	char cnic[20];
	char phonenumber[20];
	char address[100];
	char username[20];
	char password[20];
public:
	user* u = new costumer(*this);
	virtual void Display() {
		cout << gender << endl;
		cout << cnic << endl;
		cout << username << endl;
		cout << phonenumber << endl;

	}

	costumer() {
		regularity = 0;
	}

	void increg() {
		regularity++;
	}

	void setreg(float x) {
		regularity = x;
	}
	float getreg() {
		return regularity;
	}
};


class manager : public user {
private:
	char gender[10];
	char cnic[20];
	char phonenumber[20];
	char address[100];
	char username[20];
	char password[20];
public:
	user* u = new manager(*this);
	manager(){}
	manager(string x, string y, string z,  string a, string b, string c) {
		setusername(x);
		setpassword(y);
		setaddress(z);
		setcnic(a);
		setphonenumber(b);
		setgender(c);
		//setpost("admin");
	}
public:
	virtual void Display() {
		cout << gender << endl;
		cout << cnic << endl;
		cout << username << endl;
		cout << phonenumber << endl;

	}

};

class Discount {
	char name[20];
	int count = 0;
public:
	Discount() {
		for (int i = 0; i < 20; i++) {
			name[i] != '\0';
		}
	}
	Discount(string x) {
		for (int i = 0; x[i] != '\0'; i++) {
			name[i] = x[i];
		}

		insertObject(*this);
	}

	bool compare(char* a, char* b) {
		if (a[0] == '\0') {
			return false;
		}
		for (int c = 0; a[c] != '\0'; c++) {
			if (a[c] != b[c]) {
				return false;
			}
		}
		return true;
	}

	void insertObject(Discount& obj) {
		ofstream myFile("Discount.bin", ios::binary | ios::app);
		if (myFile.write((char*)&obj, sizeof(obj))) {

		}
	}

	char* getname() {
		return name;
	}

	bool check(char arr[]) {
		Discount temp;
		ifstream myFile("Discount.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (compare(temp.getname(), arr)) {
				count++;
				}
			}
		if (count > 5) {
			return true;
		}
		}

};

class Registration {
private:
	char gender[100];
	char cnic[13];
	char phonenumber[20];
	char address[50];
	char username[50];
	char password[50];
	char city[10];

public:


	Registration() {

		for (int i = 0; i < 10; i++) {
			post[i] = 0;
			city[i] = 0;
		}


		for (int i = 0; i < 100; i++) {
			gender[i] = '\0';
		}

		for (int i = 0; i < 13; i++) {
			cnic[i] = '\0';
		}

		for (int i = 0; i < 20; i++) {
			phonenumber[i] = '\0';
		}

		for (int i = 0; i < 50; i++) {
			address[i] = '\0';
		}

		for (int i = 0; i < 50; i++) {
			username[i] = '\0';
		}

		for (int i = 0; i < 50; i++) {
			password[i] = '\0';
		}

	}

	Registration(char address[], string cnic, string phonenumber, string username, string gender, string password, string post) {


		for (int i = 0; address[i] != '\0'; i++) {
			this->address[i] = address[i];
		}

		for (int i = 0; cnic[i] != '\0'; i++) {
			this->cnic[i] = cnic[i];
		}

		for (int i = 0; phonenumber[i] != '\0'; i++) {
			this->phonenumber[i] = phonenumber[i];
		}

		for (int i = 0; username[i] != '\0'; i++) {
			this->username[i] = username[i];
		}

		for (int i = 0; gender[i] != '\0'; i++) {
			this->gender[i] = gender[i];
		}

		for (int i = 0; password[i] != '\0'; i++) {
			this->password[i] = password[i];
		}

		for (int i = 0; post[i] != '\0'; i++) {
			this->post[i] = post[i];
		}

	}

	char* getcity() {
		return city;
	}

	void setcity(string x) {
		for (int i = 0; x[i] != '\0'; i++) {
			city[i] = x[i];
		}
	}

	char post[10];
	void setpost(string x) {
		for (int i = 0; x[i]!='\0'; i++) {
			post[i] = x[i];
		}
	}
	
	bool reg=true;

	char getgender() {
		return *gender;
	}

	char getcnic() {
		return *cnic;
	}

	char getphonenumber() {
		return *phonenumber;
	}

	char getaddress() {
		return *address;
	}

	char* getusername() {
		return username;
	}

	char* getpassword() {
		return password;
	}

	void setgender(string gender) {
		for (int i = 0; gender[i] != '\0'; i++) {
			this->gender[i] = gender[i];
		}
	}

	void setcnic(string cnic) {
		for (int i = 0; cnic[i] != '\0'; i++) {
			this->cnic[i] = cnic[i];
		}
	}

	void setpassword(string password) {
		for (int i = 0; password[i] != '\0'; i++) {
			this->password[i] = password[i];
		}
	}

	void setaddress(string address) {
		for (int i = 0; address[i] != '\0'; i++) {
			this->address[i] = address[i];
		}
	}
	
	void setphonenumber(string phonenumber) {
		for (int i = 0; phonenumber[i] != '\0'; i++) {
			this->phonenumber[i] = phonenumber[i];
		}
	}

	void setusername(string username) {
		for (int i = 0; username[i] != '\0'; i++) {
			this->username[i] = username[i];
		}
	}

	void Display() {
		cout << " "<<setfill('_') << setw(121) << "REGISTRATION" << setfill('_') << setw(121);

		cout << endl;
			cout << "\nGender: " << gender << endl;;
		
			cout << "\nPhone Number: ";
			for (int i = 0; i<10; i++) {
				cout << phonenumber[i];
			}

			cout << "\nUsername: "<<username<<endl;
		
			cout << "Password: "<<password;
			
			cout << "\nCnic: ";	
			for (int i = 0; cnic[i] != '\0'; i++) {
				cout << cnic[i];
			}
		
			cout << "\nAddress: " << address << endl;

		

	}

	void insertObject(Registration& obj) {
		ofstream myFile("Sample.bin", ios::binary | ios::app);
		if (myFile.write((char*)&obj, sizeof(obj))) {
			cout << " Sign Up Successfull " << endl;
			cout << "Welcome to the Family " << username << endl;

			costumer o;
			o.setusername(username);
			o.setaddress(address);
			o.setcnic(cnic);
			o.setphonenumber(phonenumber);
			o.setpassword(gender);
			if (o.getpost() == "") {
				o.setpost("costumer");
			}
		}
		else
			cout<<"Failed"<<endl;
		myFile.close();
	}
	void infoCheck();
	bool compare(char* a, char* b) {
		if (a[0] == '\0') {
			return false;
		}
		for (int c = 0; a[c] != '\0'; c++) {
			if (a[c] != b[c]) {
				return false;
			}
		}
		return true;
	}
}; 

void Registration::infoCheck() {// verifies data
	string fileName = "Sample.bin";
	bool flag = false;
	bool cflag = false;
	string xx;

	ofstream myFile1(fileName, ios::binary | ios::app);
	myFile1.close();

	
	cout << " " << setfill('_') << setw(110) << "REGISTRATION" << setfill('_') << setw(120);
	cout << "\n\n\nEnter Phone Number :";
	cin >> xx;
	setphonenumber(xx);
	cout << "Enter your gender(male/female/other): ";
	cin >> gender;
	string g(gender);
	while (g != "male" && g != "female" && g != "other") {
		cout << "Invalid Gender" << endl;
		cin >> gender;
		g = gender;
	}
	cout << "Enter address: " ;
	cin >> address;
	cout << "Enter your cnic: ";
	cin >> cnic;
	int size = 0;
	for (; cnic[size] != '\0'; size++);
		
	while (size < 13 || !cflag) {
		Registration temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (compare(temp.cnic, cnic) || size < 13) {
				cflag = false;
			}
			cflag = true;
		}
		if (temp.cnic[0] == '\0') {
			cflag = true;
		}
		myFile.close();
		if (!cflag) {
			cout << "Your cnic is incorrect!. Please enter again: ";
			cin >> cnic;
			size = 0;
			for (; cnic[size] != '\0'; size++);
		}
	}

	cout << "Enter username: ";
	cin >> username;

	Registration temp;
	ifstream myFile(fileName, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		while (compare(temp.username, username)) {
			cout << "Incorrect username!. Please enter again: ";
			cin >> username;
		}
	}
	myFile.close();
	string p="_________";
	while (p!=password) {
		cout << "\nEnter a password: ";
		cin >> password;
		p = password;
		cout << "\nReenter password: ";
		cin >> password;
		if (p != password) {
			cout << "\Passwords dont match!";
		}
	}
	size = 0;
	for (; password[size] != '\0'; size++);

	while (!flag || size < 8) {
		for (int c = 0; c < size; c++) {
			if ((password[c] > 32 && password[c] <= 47) || (password[c] >= 58 && password[c] <= 64) || (password[c] >= 91 && password[c] <= 96) || (password[c] >= 123 && password[c] <= 126)) {
				flag = true;
				break;
			}
		}

		if (!flag || size < 8) {
			cout << "Password is weak! ";
			string p;
			while (p != password) {
				cout << "\nEnter a password: ";
				cin >> password;
				p = password;
				cout << "\nReenter password: ";
				cin >> password;
				if (p != password) {
					cout << "\Passwords dont match!";
				}
			}
			size = 0;
			for (; password[size] != '\0'; size++);
		}
		if (city == "") {
			cout << "Enter your city" << endl;
			cin >> city;
		}

	}

}

class Login {
private:
	char city[10];
	char pass[20];
	char us[20];

public:
	char user[10];
	string pst;


	Login() {
		for (int i = 0; i < 20; i++) {
			pass[i] = 0;
			us[i] = 0;

		}
		pst = '\0';
		for (int i = 0; i < 10; i++) {
			user[i] = '\0';
			city[i] = '\0';
		}
	}


	bool compare(char* a, char* b) {
		if (a[0] == '\0') {
			return false;
		}
		for (int c = 0; a[c] != '\0'; c++) {
			if (a[c] != b[c]) {
				return false;
			}
		}
		return true;
	}

	char* getcity() {
		return city;
	}

	bool login() {
		int x = 0;
		bool flag = false;
		string fileName = "Sample.bin";
		cout << "Enter Username: ";
		cin >> us;

		cout << "Enter Password: ";
		cin >> pass;
		Registration temp;
		//string ppt(temp.getusername());
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			//if (ppt != "") {
				if (compare(temp.getusername(), us)) {
					if (compare(temp.getpassword(), pass)) {
						char* p = temp.getcity();
						for (int i = 0; p[i] != '\0'; i++) {
							city[i] = p[i];
						}
						pst= *temp.post;
						*user = *temp.post;
						//*this = temp;
						//myFile.close();
						cout << "Login Successful." << endl << endl;
						string u(us);
						Discount(us);
						//return true;
						x = 1;
						break;
					}
				}
			//}
		}


		if (x == 1) {
			return true;
		}
		else {
			return false;
		}


	}
	string postf() {

		string cp(us);
		admin obj;
		string cmp(obj.getusername());
		if (cp == cmp) {
			return "admin\0";
		}
		else if (pst[0] == 0) {
			return "costumer\0";
		}
		else if (pst == "m") {
			return "manager";
		}
	}
	~Login() {

	}
};



class ManageProductCatalog {
private:
	char title[20];
	char category[20];
	char subc[20];
	float price;
	float amount;
public:

	char* getcat() {
		return category;
	}

	char* gettitle() {
		return title;
	}

	char* getsubc() {
		return subc;
	}

	void insertObject(ManageProductCatalog obj) {
		ofstream myFile("Catalog.bin", ios::binary | ios::app);
		if (myFile.write((char*)&obj, sizeof(obj))) {
			//cout << " Login Successfull " << endl;
		}
		else
			cout << "Failed" << endl;
		myFile.close();
	}

	void addremove() {
		int ch;
		cout << "Press 1 to add and 2 to delete:";
		cin >> ch;
		int i, j, k;
		cout << "\nEnter name of Type";
		cin >> title;
		cout << "\nEnter number of it's categories: ";
		cin >> j;
		for (int i = 0; i < j; i++) {
			cout << "\nEnter name of category: ";
			for (int l = 0; l < 10; l++) {
				cin >> category[i];
				cout << "\nEnter number of it's subcategories: ";
				cin >> k;
				for (int c = 0; c < k; c++) {
					cout << "\nEnter Name of subcategory: ";
					for (int h = 0; h < 10; h++) {
						cin >> subc[c];
					}
				}
			}
		}
		insertObject(*this);

		if (ch == 2) {
			cout << "\nPress 1 to dlt title, 2 to dlt category, 3 to dlt subcategory: ";
			int ss;
			cin >> ss;
			while (ss != 1 && ss != 2 && ss != 3) {
				cin >> ss;
			}

			if (ss == 1) {
				cout << "Enter name of title to delete" << endl;
				string t;
				cin >> t;
				ManageProductCatalog temp;
				fstream pp("Catalog.bin", ios::in, ios::out | ios::binary);
				ofstream pp_temp("temp.bin", ios::app | ios::binary);
				while (pp.read((char*)&temp, sizeof(temp))) {
					string h(temp.gettitle());
					if (t != h) {
						pp_temp.write((char*)&temp, sizeof(temp));
					}
				}

				pp.close();
				pp_temp.close();

				remove("Catalog.bin");
				rename("temp.bin", "Catalog.bin");
			}

			if (ss == 3) {
				cout << "Enter name of category to delete" << endl;
				string t;
				cin >> t;
				ManageProductCatalog temp;
				fstream pp("Catalog.bin", ios::in, ios::out | ios::binary);
				ofstream pp_temp("temp.bin", ios::app | ios::binary);
				while (pp.read((char*)&temp, sizeof(temp))) {
					string h(temp.getcat());
					if (t != h) {
						pp_temp.write((char*)&temp, sizeof(temp));
					}
				}

				pp.close();
				pp_temp.close();

				remove("Catalog.bin");
				rename("temp.bin", "Catalog.bin");
			}

			if (ss == 3) {
				cout << "Enter name of subcategory to delete" << endl;
				string t;
				cin >> t;
				ManageProductCatalog temp;
				fstream pp("Catalog.bin", ios::in, ios::out | ios::binary);
				ofstream pp_temp("temp.bin", ios::app | ios::binary);
				while (pp.read((char*)&temp, sizeof(temp))) {
					string h(temp.getsubc());
					if (t != h) {
						pp_temp.write((char*)&temp, sizeof(temp));
					}

				}

				pp.close();
				pp_temp.close();

				remove("Catalog.bin");
				rename("temp.bin", "Catalog.bin");
			}
		}
	}
	void update() {

	}

	void retrive() {
		ManageProductCatalog temp;
		ifstream myFile("Catalog.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			temp.Display();
		}
		myFile.close();
	}

	void Display() {
		cout << "Title" << title << endl;
		cout << "Category" << category << endl;
		cout << "SubCategory" << subc << endl;
	}
	void setct(string* x) {
		//*category = *x;
	}
	void setprice(float x) {
		price = x;
	}
	void setamount(float x) {
		amount = x;
	}

	string getct() {
		//return category;
	}

	float getprice() {
		return price;
	}

	float getamount() {
		return amount;
	}
};

class StoreCheckoutSimulation {
private:
	bool check_sim;
public:
	StoreCheckoutSimulation() {
		check_sim = 0;
	}

	bool getcsim() {
		return check_sim;
	}

	void setcsim(bool x) {
		check_sim = x;
	}

	void specification() {

	}
	void simulation() {

	}
};

class ManageStoreAndUser {
private:
	bool manager;
	int stores_open;
	bool AddRem_Costumers;
	char branch[10];
public:
	ManageStoreAndUser() {
		manager = 0;
		stores_open = 0;
		AddRem_Costumers = 0;
		for (int i = 0; i < 10; i++) {
			branch[i] = '\0';
		}
	}

	bool getmanager() {
		return manager;
	}

	int getso() {
		return stores_open;
	}

	bool getarc() {
		return AddRem_Costumers;
	}

	void setm(bool x) {
		manager = x;
	}

	void so(int x) {
		stores_open = x;

	}
	void setarc(bool x) {
		AddRem_Costumers = x;
	}
	void ApproveManager() {
		cout << "Enter the branch for the manager: ";
		cin >> branch;
		Registration obj1;
		obj1.setpost("manager");
		obj1.setcity(branch);
		obj1.infoCheck();
		obj1.insertObject(obj1);
	}

	bool compare(char* a, char* b) {
		for (int c = 0; a[c] != '\0'; c++) {
			if (a[c] != b[c]) {
				return false;
			}
		}
		return true;
	}

	void AddRemoveCostumer() {
		int x = 0;
		while (x != 1 && x != 2) {
			cout << "\nPress 1 to add costumer.\nPress 2 to delete costumer: ";
			cin >> x;
		}
		if (x == 1) {
			Registration obj1;
			obj1.setpost("");
			obj1.infoCheck();
			obj1.insertObject(obj1);
		}
		else if (x == 2) {
			char name[10] = {};
			cout << "\nEnter username of costumer to Remove: ";
			cin >> name;
			Registration temp;
			fstream pp("Sample.bin", ios::in, ios::out | ios::binary);
			ofstream pp_temp("temp.bin", ios::app | ios::binary);
			while (pp.read((char*)&temp, sizeof(temp))) {

				if (!compare(temp.getusername(), name)) {
					pp_temp.write((char*)&temp, sizeof(temp));
					//}
				}

				pp.close();
				pp_temp.close();

				remove("Sample.bin");
				rename("temp.bin", "Sample.bin");
			}

		}

	}
};

struct Product {
	char* name;
	double price;
	Product() {
		name = nullptr;
		price = 0;
	}
	Product(const char n[], double p) {
		int i = 0;
		while (n[i] != '\0') i++;
		name = new char[i + 1]; name[i] = '\0';
		for (int j = 0; n[j] != '\0'; j++)
			name[j] = n[j];
		price = p;
	}

	void operator = (const Product& copy) {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
		int i = 0;
		while (copy.name[i] != '\0') i++;
		name = new char[i + 1]; name[i] = '\0';
		for (int j = 0; copy.name[j] != '\0'; j++)
			name[j] = copy.name[j];
		price = copy.price;
	}
};

class InventoryManagement {
private:
	//Product p;
	char item[10];
	char product[20];
	int n_products; //number of products
	float price;
	char Branch_City[10];
	char city[10];
public:

	bool compare(char* a, char* b) {
		for (int c = 0; a[c] != '\0'; c++) {
			if (a[c] != b[c]) {
				return false;
			}
		}
		return true;
	}

	void setCity(Login obj) {
		char* ptr = obj.getcity();
		for (int i = 0; ptr[i]!='\0'; i++) {
			Branch_City[i]=ptr[i];
		}
	}

	InventoryManagement() {
		for (int i = 0; i < 20; i++) {
			product[i] = 0;
		}
		for (int i = 0; i < 10; i++) {
			Branch_City[i] = 0;
		}
		n_products = 0;
		price = 0;
	}

	char* getc() {
		return Branch_City;
	}

	char* getproduct() {
		return product;
	}

	int getnp() {
		return n_products;
	}

	float getprice() {
		return price;
	}
	
	void ret() {
		for (int i = 0; i < 3; i++) {
			InventoryManagement temp;
			string f="";
			if (i == 0) {
				cout << "\n\nTAXILA INVENTORY " << endl;
				f = "i_Taxila.bin";
			}

			if (i == 1) {
				cout << "\n\nISLAMABAD INVENTORY " << endl;
				f = "i_Islamabad.bin";
			}

			if (i == 2) {
				cout << "\n\nFAISALABAD Inventory: " << endl;
				f = "i_Faisalabad.bin";
			}

			ifstream mm(f, ios::binary);
			while (mm.read((char*)&temp, sizeof(temp))) {
				temp.Display();
			}
			mm.close();
		}
	}

	void Display() {
		//cout << "ALL INVENTORY" << endl;
		if (Branch_City != "Taxila " && Branch_City != "Islamabad" && Branch_City != "Faisalabad") {
			int x = rand() % 3;
			//if()
		}
		cout << "Product: " << product << " Price: " << price << " Quantity: " << n_products << " Available in " << Branch_City[0] << endl;
	}

	void add(){
		cin >> product;
		cin >> price;
		cin >> n_products;
		string city(Branch_City);



		string file = "";
		if (city[0] == 'T'){
			file = "i_Taxila.bin";
		}
		else if (city[0] == 'I') {
			file = "i_Islamabad.bin";
		}
		else if (city[0] == 'F') {
			file = "i_Faisalabad.bin";
		}
		ofstream myFile(file, ios::binary | ios::app);
		if (myFile.write((char*)&*this, sizeof(InventoryManagement)))
			cout << "Added sucessfully!" << endl;
		else
			cout << "Adding Failed" << endl;
		myFile.close();

		ofstream all("Inventory_All.bin", ios::binary | ios::app);
		if (all.write((char*)&*this, sizeof(InventoryManagement)))
			cout << "Added sucessfully!" << endl;
		else
			cout << "Adding Failed" << endl;
		all.close();
	}

	char* getcity() {
		return Branch_City;
	}


	void dlt() {
		string item;
		cout << "\nEnter Item to delete: " << endl;
		cin >> item;
		string city(Branch_City);
		string str = "";
		if (city == "Taxila") {
			str = "i_Taxila.bin";
		}
		else if (city == "Islamabad") {
			str = "i_islamabad.bin";
		}
		else if (city == "Faisalabad") {
			str = "i_Faisalabad.bin";
		}
		InventoryManagement temp;
		fstream pp(str, ios::in, ios::out | ios::binary);
		ofstream pp_temp("temp.bin", ios::app | ios::binary);
		while (pp.read((char*)&temp, sizeof(temp))) {
			string str(temp.getproduct());
			if (item!=str) {
			pp_temp.write((char*)&temp, sizeof(temp));
			}
		}



		pp.close();
		pp_temp.close();

		if (city == "Taxila") {
			remove("i_Taxila.bin");
			rename("temp.bin", "i_Taxila.bin");
		}
		else if (city == "Islamabad") {
			remove("i_Islamabad.bin");
			rename("temp.bin", "i_Islamabad.bin");
		}
		else if (city == "Faisalabad") {
			remove("i_Faisalabad.bin");
			rename("temp.bin", "i_Faisalabad.bin");
		}

	}
	void search() {

		cout << "\nEnter Desired product: ";
		cin >> product;
		InventoryManagement temp;
		//string ppt(temp.getusername());
		ifstream myFile("Inventory_All.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			//if (ppt != "") {
			if (compare(temp.getproduct(), product)) {
			
					cout << "Product Available! " << endl;
						cout << "City: " << Branch_City;
				}

			}

			//}

		}

	void Update() {

	}
	
	
};

class Inventory : public InventoryManagement {
private:
	float price[30];
	char items[30][10];
public:
	Inventory() {
		for (int i = 0; i < 30; i++) {
			price[i] = 0;
		}
		
		for (int i = 0; i < 30; i++) {
			for (int j = 0; i < 10; i++) {
				items[i][j] = '\0';
			}
		}
	}

	//void setprice(float x) {
	//	price = x;
	//}

	//float getprice() {
	//	return price;
	//}
};

class OnlineShopping {
private:
	char city[10];
	char item[20];
	int price;
	int q;
	//bool addtocart;
	bool checkout;
	char feedback[30];
public:

	OnlineShopping() {
		for (int i = 0; i < 20; i++) {
			item[i] = '\0';
		}
		for (int i = 0; i < 10; i++) {
			city[i] = '\0';
		}
		price = 0;
		q = 0;
	}

	void Feedback() {
		cin >> feedback;
	}
	void Display() {
		Inventory obj;
		obj.ret();
		//obj.Display();
	}

	bool compare(char* a, char* b) {
		for (int c = 0; a[c] != '\0'; c++) {
			if (a[c] != b[c]) {
				return false;
			}
		}
		return true;
	}

	void addtocart() {
		Discount obj;
		cout << "Please re-enter your name so we can check your eligibility for discount" << endl;
		char arr[20];
		cin >> arr;
		bool c = obj.check(arr);
		if (c == true) {
			cout << "Youve won 10% discount" << endl;
		}
		bool dc = false;;
		int x;
		cout << "How many items do you want to add to cart ?";
		cin >> x;
		int i = 0;
		while (i < x) {

			cout << "\nEnter Desired product: ";
			cin >> item;
			cout << "\nEnter Quantity: ";
			cin >> q;
			cout << "\nEnter your city: ";
			cin >> city;
			InventoryManagement temp;
			//string ppt(temp.getusername());
			ifstream myFile("Inventory_All.bin", ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp))) {
				//if (ppt != "") {
				if (compare(temp.getproduct(), item)) {
					if (q <= temp.getnp()) {
						cout << "Product Available!\n Added to Cart. " << endl;
						price += temp.getprice() * temp.getnp();
						if (!compare(temp.getcity(), city)) {
							cout << "\nDifferent City\nDelivery Charges: Rs50";
							//price += 50;
							dc = true;
						}
						else if (compare(temp.getcity(), city)) {
							cout << "\nSame City\nDelivery Charges: Rs30";
							//price += 30;

						}
					}

				}

				//}

			}


			i++;
		}
		if (dc == true) {
			price += 50;
		}
		else {
			price += 30;

		}

		string city(city);
		string str = "";
		if (city == "Taxila") {
			str = "i_Taxila.bin";
		}
		else if (city == "Islamabad") {
			str = "i_islamabad.bin";
		}
		else if (city == "Faisalabad") {
			str = "i_Faisalabad.bin";
		}
		InventoryManagement temp;
		fstream pp(str, ios::in, ios::out | ios::binary);
		//ofstream pp_temp("temp.bin", ios::app | ios::binary);
		while (pp.read((char*)&temp, sizeof(temp))) {
			if (compare(item, temp.getproduct())) {

			}
			//if(item)
			//pp_temp.write((char*)&temp, sizeof(temp));
			//}
		}

		if (c == true) {
			price = price * 0.09;
		}

		buy();
	}
	void buy() {
		cout << "Your total bill is " << price << " Rs." << endl;

	}

	float getprice() {
		return price;
	}

	void setcheckout(bool x) {
		checkout = x;
	}


	bool getcheckout() {
		return checkout;
	}
};



class Payment {
private:
	float bill;
	string AccountNum;
	string Password;
	string OTP;
	string address;
	float balance=10000;
public:



	Payment() {
			srand(0);
			balance += rand() % 1000000;
		AccountNum = "\0";
		Password = "\0";
		OTP = "\0";
	}

	void setaddress(string x) {
		address = x;
	}

	void genbill(float x) {
		cout << "\nRemaining Balance: " << balance-x;
	}

	void setAN(string x) {
		AccountNum = x;
	}

	void setPass(string x) {
		AccountNum = x;
	}

	void setotp(string x) {
		OTP = x;
	}



	string getaddress() {
		return address;
	}

	string getAN() {
		return AccountNum;
	}

	string getPass() {
		return Password;
	}

	string getOTP() {
		return OTP;
	}

	void Display1() {
		cout << "Balance: " << balance << endl;
	}
};

class CreditCard : public Payment {
private:

public:

	CreditCard() {
		string x = "";
		cout << "Enter Account Number: ";
		cin >> x;
		setAN(x);
		x = "";
		cout << "\nEnter Password: ";
		cin >> x;
		setPass(x);

	}

	void Display() {
		cout << "Payment has been done through Credit Card" << endl;
	}
};

class EasyPaisa : public Payment {
private:

public:

	EasyPaisa() {
		string x = "\0";
		cout << "Enter Account Number: ";
		cin >> x;
		setAN(x);
		x = "\0";
		cout << "\nEnter Password: ";
		cin >> x;
		setPass(x);
		x = "\0";
		cout << "Enter Account Number! " << endl;
		cin >> x;
		setotp(x);
	}

	void Display() {
		cout << "Payment has been done through Easypaisa" << endl;
	}

};

class Jazzcash : public Payment {
private:
public:
	Jazzcash() {
		string x = "\0";
		cout << "Enter Account Number: ";
		cin >> x;
		setAN(x);
		x = "\0";
		cout << "\nEnter Password: ";
		cin >> x;
		setPass(x);
		x = "\0";
		cout << "Enter OTP ";
		cin >> x;
		setotp(x);
	}
	void Display() {
		cout << "Payment has been done through Jazzcash" << endl;
	}

};

class COD : public Payment {
private:
public:

	void Display() {
		cout << "Payment will be taken upon deliver" << endl;
	}
};


class Feedback {
private:
	char feedback[30];
public:
	Feedback() {
		for (int i = 0; i < 30; i++) {
			feedback[i] = '\0';
		}
	}

	void fb() {
		cout << "Please Give your feedback." << endl;
		//cin >> feedback;
		string x;
		getline(cin, x);

		for (int i = 0; i <= x.size(); i++) {
			feedback[i] = x[i];
		}

		ofstream all("Feedback.bin", ios::binary | ios::app);
		if (all.write((char*)&*this, sizeof(InventoryManagement)))
			cout << "Added sucessfully!" << endl;
		else
			cout << "Adding Failed" << endl;
		all.close();
	}

	void Display() {
		cout << "Feedback" <<feedback<< endl;
	}
	void addobj() {
		ofstream myFile("Feedback.bin", ios::binary | ios::app);
		if (myFile.write((char*)&*this, sizeof(*this))) {
			cout << "\nThankyou for the feedback" << endl;
		}
		else
			cout << "Failed" << endl;
		myFile.close();
	}
};

class HomeScreenAndSubMenu {
private:

public:
	int ch,ch1;
	string user;
	Login oi;
	 
	HomeScreenAndSubMenu(string x) {
		user = x;
		ch = 0;
		ch1 = 0;
	}
	HomeScreenAndSubMenu() {
		ch = 0;
		ch1 = 0;
	}
	void Display(Login &w) {
		if (user == "admin") {
			admin obj;
			cout << "Press 1 to Manage Product Catalog.\nPress 2 to Manage Store and Users.\nPress 3 for Checkout Store Simulation. " << endl;
			cin >> ch;
			if (ch == 1) {
				ManageProductCatalog obj1;
				obj1.Display();
				cout << "Press 1 to add/remove.\nPress 2 to Update Catalog" << endl;
				cin >> ch1;
				if (ch1 == 1) {
					obj1.addremove();
					obj1.insertObject(obj1);
					obj1.retrive();
					//obj1.Display();
				}
				else if (ch1 == 2) {
					obj1.update();
					obj1.insertObject(obj1);
					obj1.retrive();
					//obj1.Display();
				}

			}
			else if (ch == 2) {
				ManageStoreAndUser obj1;
				cout << "Press 1 to add/remove costumer.\nPress 2 to Approve Admin" << endl;
				cin >> ch1;
				switch (ch1) {
				case 1:
					obj1.AddRemoveCostumer();
					break;
				case 2:
					obj1.ApproveManager();
					break;
				}
			}
			else if (ch == 3) {
				StoreCheckoutSimulation obj1;
			}
		}
		else if (user == "costumer") {
			costumer obj2;
			cout << setw(121) << "ONLINE SHOPPING" << endl;
			OnlineShopping obj1;
			obj1.Display();
			cout << "ADD TO CART" << endl;
			obj1.addtocart();

			string pm = "\0";
			while (pm != "COD" && pm != "Jazzcash" && pm != "Easypaisa") {
				cout << "Enter a Payment Method(COD/Jazzcash/Easypaisa: " << endl;
				cin >> pm;
			}

			if (pm == "Jazzcash") {
				Jazzcash obj;
				obj.Display1();
				obj.genbill(obj1.getprice());
			}
			else if (pm == "Easypaisa") {
				EasyPaisa obj;
				obj.Display1();
				obj.genbill(obj1.getprice());
			}
			else if (pm == "COD") {
				COD obj;
				obj.Display1();
				obj.genbill(obj1.getprice());
			}

			else if (pm == "CreditCard") {
				CreditCard obj;
				obj.Display();
				obj.genbill(obj1.getprice());
			}
			Feedback obj;
			obj.fb();

		}
		else if (user == "manager") {

			//manager obj4;
			cout << setw(121) << "INVENTORY MANAGEMENT" << endl;
			InventoryManagement obj1;
			obj1.setCity(w);
			//Product p;
			obj1.add();
			obj1.ret();
			
		}
	}
};


