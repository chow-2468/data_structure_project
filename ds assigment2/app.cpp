#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"



#include	<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

bool readFile(const char *, BST *);
int menu();

int main() {

	
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
	while (input.getline(hold, 100, '\n')) { //get whole line untill meet '\n'
		strncat(strcat_hold, hold, hold - strchr(hold, '=') + 1);

		temp.id = stoi(strcat_hold); // find the first '='
		strcpy(strcat_hold, ""); // clear the string

		input.getline(hold, 100, '\n'); // get name
		strncat(strcat_hold, hold, hold - strchr(hold, '=') + 1);
		strncpy(temp.name, strcat_hold, size(temp.name));
		strcpy(strcat_hold, "");

		input.getline(hold, 100, '\n');// get DOB
		strncat(strcat_hold, hold, hold - strchr(hold, '=') + 1);
		strncpy(temp.DOB, strcat_hold, size(temp.DOB));
		strcpy(strcat_hold, "");

		input.getline(hold, 100, '\n'); //get address
		strncat(strcat_hold, hold, hold - strchr(hold, '=') + 1);
		strncpy(temp.address, strcat_hold, size(temp.address));
		strcpy(strcat_hold, "");

		input.getline(hold, 100, '\n');// get phone no
		strncat(strcat_hold, hold, hold - strchr(hold, '=') + 1);
		strncpy(temp.phone_no, strcat_hold, size(temp.phone_no));
		strcpy(strcat_hold, "");

		input.getline(hold, 100, '\n');// get course
		strncat(strcat_hold, hold, hold - strchr(hold, '=') + 1);
		strncpy(temp.course, strcat_hold, size(temp.course));
		strcpy(strcat_hold, "");

		input.getline(hold, 100, '\n');// get cgpa
		strncat(strcat_hold, hold, hold - strchr(hold, '=') + 1);
		temp.cgpa = stod(strcat_hold); 

		t1->insert(temp); // insert the student information into the tree
	}
	input.close(); // close the file
	return true;
}
