#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"



#include	<string>

using namespace std;

bool readFile(const char *, BST *);
int menu();

int main() {
	int choose, order;
	type item;
	BST t1, t2;
	char file[30];
	BST t1; // create a BST object
	readFile("student.txt", &t1);// read the file and insert the data into the BST
	t1.display(2,1); // 

	while (choose = menu(), choose != 7) {
		if (choose == 1) {
			cout << "file name: ";
			cin >> file;
			if (!readFile(file, &t1)) cout << "cannot read file";
			else cout << "read file successful";
		}

		else if (choose == 2);

		else if (choose == 3) {
			cout << "print in ascending or descending order according to id. Use order = 1 for ascending and order = 2 for descending." << endl;
			cout << "please key in print order";
			cin >> order;
			if (order == 1 || order == 2) {

			}
			else cout << "invalid input";
		}

		else if (choose == 4) {
			cout << "please enter the clone subtree id";
			cin >> item.id;
			t2.CloneSubtree(t1, item);
		}

		else if (choose == 5);

		else if (choose == 6);
	}
	system("pause");
	return 0;
}

bool readFile(const char* filename, BST* t1) {
	
	ifstream input(filename); // open file
	if (!input) {
		cout << "Error opening file" << endl;
		return false;
	}
	Student temp; // temporary hold the student information
	char hold[100]; // hold value read from file
	char strcat_hold[100]= ""; 
	char* ptr;
	while (!input.eof()) { //get whole line untill meet '\n'
		input.getline(hold, 100, '\n');
		ptr = strchr(hold, '=') + 2; // point to the position after "= " which is the value we want
		strcpy(strcat_hold, ptr);
		temp.id = stoi(strcat_hold); // convert string to int and assign to id


		input.getline(hold, 100, '\n'); // get name
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		strncpy(temp.name, strcat_hold, size(temp.name));

		input.getline(hold, 100, '\n');// get DOB
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		strncpy(temp.DOB, strcat_hold, size(temp.DOB));

		input.getline(hold, 100, '\n'); //get address
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		strncpy(temp.address, strcat_hold, size(temp.address));

		input.getline(hold, 100, '\n');// get phone no
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		strncpy(temp.phone_no, strcat_hold, size(temp.phone_no));

		input.getline(hold, 100, '\n');// get course
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		strncpy(temp.course, strcat_hold, size(temp.course));

		input.getline(hold, 100, '\n');// get cgpa
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		temp.cgpa = stod(strcat_hold); // convert string to double and assign to cgpa

		input.ignore(); // ignore the blank line in the file
		t1->insert(temp); // insert the student information into the tree
	}
	input.close(); // close the file
	return true;
}



int menu() {
	int choose = 0;

	while (true) {
		system("cls");
		cout << "Menu" << endl;
		cout << "(1) Read data to BST" << endl;
		cout << "(2) Print deepest nodes" << endl;
		cout << "(3) Display student" << endl;
		cout << "(4) Clone Subtree" << endl;
		cout << "(5) Print Level Nodes" << endl;
		cout << "(6) Print Path" << endl;
		cout << "(7) Exit" << endl;
		cout << "Please choose an option: ";

		if (cin >> choose && choose >= 1 && choose <= 7) {
			cin.clear();
			cin.ignore(100, '\n');
			return choose;
		}
		cout << "please key in 1-7\n";
		system("pause");
		cin.clear();
		cin.ignore(100, '\n');
	}

	return true;
}