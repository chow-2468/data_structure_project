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
	int choose, order,source;
	type item;
	BST t1, t2;
	char file[30];


	while (choose = menu(), choose != 7) {//if choose == 7, (7) Exit

		if (choose == 1) {//(1) Read data to BST 
			cout << "file name: ";
			cin >> file;
			if (!readFile(file, &t1)) cout << "Read file failure"<<endl;
			else cout << "Read file successful"<<endl;
		}

		else if (choose == 2) {//(2) Print deepest nodes 
			if (!t1.deepestNodes()) cout << "The tree is empty"<<endl;
			else cout << "The deepest node has been found" << endl;
		}

		else if (choose == 3) {//(3) Display student 

			do {
				cout << "Print in ascending or descending order according to id. Use order = 1 for ascending and order = 2 for descending." << endl;
				cout << "Please key in print order: ";
				cin >> order;
				if (!(order == 1 || order == 2))cout << "Invalid input"<<endl;
			} while (!(order == 1 || order == 2));

			do {
				cout << "Use source = 1 to print to screen and source = 2  to print to a file name student - info.txt" << endl;
				cout << "Please key in print source: ";
				cin >> source;
				if (!(source == 1 || source == 2))cout << "Invalid input"<<endl;
			} while (!(source == 1 || source == 2));

			if (!t1.display(order, source)) cout << "Display failure"<<endl;
			else cout << "Display successful" << endl;
		}

		else if (choose == 4) {//(4) Clone Subtree 
			cout << "please enter the clone subtree id: ";
			cin >> item.id;
			if (!t2.CloneSubtree(t1, item)) cout << "Cannot clone subtree." << endl;
			else cout << "Clone substree successful" << endl;
		}

		else if (choose == 5) {//(5) Print Level Nodes 
			if (!t1.printLevelNodes()) cout << "Print level nodes failure" << endl;
			else cout << "Print level nodes successful" << endl;
				
		}

		else if (choose == 6) {//(6) Print Path 
			if (!t1.printPath()) cout << "Print all external path failure" << endl;
			else cout << "Print all external path successful" << endl;
				
		}

		system("pause");
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
		
		input.getline(hold, 100, '\n'); //get address
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		strncpy(temp.address, strcat_hold, size(temp.address));
		
		input.getline(hold, 100, '\n');// get DOB
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		strncpy(temp.DOB, strcat_hold, size(temp.DOB));


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

	while (true) {//display menu
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

		if (cin >> choose && choose >= 1 && choose <= 7) {//check choose range 
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
