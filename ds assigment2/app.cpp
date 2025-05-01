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
//int menu();

int main() {
	BST t1; // create a BST object
	readFile("student.txt", &t1);// read the file and insert the data into the BST
	t1.display(2, 1); // 

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
		ptr = strchr(hold, '=') + 2;
		strcpy(strcat_hold, ptr);
		temp.id = stoi(strcat_hold); // find the first '='


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
		temp.cgpa = stod(strcat_hold);

		input.ignore(); // ignore the blank line in the file
		t1->insert(temp); // insert the student information into the tree
	}
	input.close(); // close the file
	return true;
}
