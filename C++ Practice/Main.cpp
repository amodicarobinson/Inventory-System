#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>

// Header Files
#include "Inventory.h"
#include "Laptop.h"
using namespace std;

void inData();
void DF();
void InData(); 
void LaptopData();
int main();
void LaptopDF();

int main() {
	cout << "------------INVENTORY-----------";

	int choice;
	bool startApp = true;

	// loop for creating the Main menu
	while (startApp != false){
		cout << endl
			<< "1. - View All Saved Data\n"
			<< "2. - Data Entry \n"
			<< "3. - Laptop Data Entry\n"
			<< "4. - Labels for Data Entry Inventory\n"
			<< "5. - Cose Inventory App\n"
			<< " Enter your choice and press return: ";
		
		cin >> choice;

		switch (choice) {
		case 1:
			system("CLS");
			LaptopDF();

			// rest of code here
			break;
		case 2:
			system("CLS");
			InData();
			// rest of code here
			break;
		case 3:
			system("CLS");
			LaptopData();
			// rest of code here
			break;
		case 4:
			system("CLS");
			inData();
			cout << "Insert Text \n";
			// rest of code here
			break;
		case 5:
			system("CLS");
			cout << "closing......\n";
			startApp = false;
			break;
		default:
			cout << "Not a valid choice \n";
			cout << "Choose again \n";
			cin >> choice;
			break;
		}
	}
	return 0;
}

// Function to read the contents of the file
void DF() {
	// Creating the inventory file
	ifstream Inv("Inventory.txt");

	if (Inv.is_open())
		cout << Inv.rdbuf();

	Inv.close();
}

// Function to write new data to the Inventory file
void InData()
{
	my_inventory myObj;
	char quit = 'a';

	fstream Inv;
	Inv.open("Inventory.txt", fstream::in | fstream::out | fstream::app);
	
	cout << "Enter your initials: ";
	cin >> myObj.Init;
	cout << "Enter the date: ";
	cin >> myObj.Date;
	cout << "Enter What kind of product it is: ";
	cin >> myObj.Product;
	cout << "Enter the quantity in stock:";
	cin >> myObj.Quantity;
	
	Inv << left << setw(12) << myObj.Init
		<< left << setw(10) << myObj.Date
		<< left << setw(15) << myObj.Product
		<< right << setw(12) << myObj.Quantity
		<< '\n';

	Inv.close();

	while (quit != 'q')
	{
		cout << "Would you like to enter more data?: ";
		cin >> quit;
		if (quit == 'q')
		{
			system("CLS");
			main();
			break;
		}
		else
		{
			system("CLS");
			InData();
		}
	}
}


void inData() {
	my_inventory myObj;

	ofstream Inv("Inventory.txt");
	cout << "Enter your initials: ";
	cin >> myObj.Init;
	cout << "Enter the date: ";
	cin >> myObj.Date;
	cout << "Enter What kind of product it is: ";
	cin >> myObj.Product;
	cout << "Enter the quantity in stock: ";
	cin >> myObj.Quantity;
	Inv << left << setw(12) << "Initials"
		<< left << setw(10) << "Date"
		<< left << setw(15) << "Product"
		<< right << setw(12) << "Quantity"
		<< '\n';

	Inv << left << setw(12) << myObj.Init
		<< left << setw(10) << myObj.Date
		<< left << setw(15) << myObj.Product
		<< right << setw(12) << myObj.Quantity
		<< '\n';

}


void LaptopDF() {
	// Creating the inventory file
	ifstream LPDF("Laptops.txt");

	if (LPDF.is_open())
		cout << LPDF.rdbuf();

	LPDF.close();
}

void LaptopData() {
	HP_Laptops obj;
	char quit = 'a';

	fstream LPDF;
	LPDF.open("Laptops.txt", fstream::in | fstream::out | fstream::app);

	cout << "Enter your initials: ";
	cin >> obj.initials;	
	cout << "Enter the date: ";
	cin >> obj.date;
	cout << "Enter the computer name: ";
	cin >> obj.Cname;
	cout << obj.model << endl;
	cout << "Enter the Serial Number of the product: ";
	cin >> obj.SN;
	cout << "Enter the name of the user: ";
	cin >> obj.user;

	LPDF << left << setw(12) << obj.initials
		<< left << setw(10) << obj.date
		<< left << setw(15) << obj.Cname
		<< right << setw(20) << obj.model
		<< right << setw(15) << obj.SN
		<< right << setw(20) << obj.user
		<< '\n';

	LPDF.close();

	while (quit != 'q')
	{
		cout << "Would you like to enter more data?: ";
		cin >> quit;
		if (quit == 'q')
		{
			system("CLS");
			main();
			break;
		}
		else
		{
			system("CLS");
			InData();
		}
	}
}