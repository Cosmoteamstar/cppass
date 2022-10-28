#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;
struct bookk {
	int id;
	char title[25];
};

int main() {

loop:
	bookk s;
	int choice, b;
	cout << "\n\n1. Add new record\n2. Read record\n3. Delete record\nChoice is:  ";
	cin >> choice;
	switch (choice) {
	case 1:
	{
		cout << "\nEnter book ID: ";
		cin >> s.id;
		cout << "Enter book title: ";
		cin >> s.title;

		ofstream sdata;
		sdata.open("book.txt", ios::app);
		sdata << endl << s.id << endl << s.title;
		sdata.close();
		goto loop;
		break;
	}
	case 2:
	{
		ifstream tdata;
		tdata.open("book.txt");
		cout << "\nBooks registered:";
		while (!tdata.eof()) {
			tdata >> s.id >> s.title;
			cout << endl << s.id << " , " << s.title;
		}
		tdata.close();
		goto loop;
		break;

	}
	case 3:
	{
		cout << "\nEnter ID of book to delete: ";
		cin >> b;
		ifstream read;
		read.open("book.txt");
		ofstream write;
		write.open("new.txt");
		while (!read.eof()) {
			read >> s.id >> s.title;
			if (s.id != b)
			{
				write << endl << s.id << endl << s.title;
			}
			else {
				cout << "\n Book deleted";
			}
		}
		write.close();
		read.close();

		if (remove("book.txt") != 0)
		{
			cout << "\nBook is not deleted";
		}
		else {
			cout << "\n";
		}
		if (rename("new.txt", "book.txt") != 0) {
			cout << "\nFile does not rename";
		}
		else {
			cout << "\n";
		}
		goto loop;
		break;
	}
	}

}