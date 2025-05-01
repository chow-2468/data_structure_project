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
	int choose, order;
	BST t1;
	char file[30];

	while (choose = menu(), choose != 7) {
		if (choose == 1) {
			cout << "print in ascending or descending order according to id. Use order = 1 for ascending and order = 2 for descending." << endl;
			cout << "please key in print order";
			cin >> order;
			if (order == 1) {

			}
			else if (order == 2)
			{

			}
		}
		else if (choose == 2);
		else if (choose == 3);
		else if (choose == 4);
		else if (choose == 5);
		else if (choose == 6);
		else if (choose == 7);
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

BTNode* BST::finditem(BTNode* cur, type item) {
	if (cur->item.id == NULL) return NULL;
	if (cur->item.compare2(item))  return cur;
	if (cur->item.compare1(item))finditem(cur->left, item);
	else finditem(cur->right, item);

}

bool BST::CloneSubtree2(BTNode* cur, BTNode*& root) {
	if (cur == NULL) return true;

	root = new BTNode(cur->item);
	return CloneSubtree2(cur->left, root->left) && CloneSubtree2(cur->right, root->right);
}

bool BST::CloneSubtree(BST t1, type item) {
	if (!empty()) return false;
	if (t1.empty()) return false;


	BTNode* cur = t1.finditem(t1.root, item);
	if (cur == NULL) {
		cout << "Cannot clone subtree." << endl;
		return false;
	}

	CloneSubtree2(cur, root);

	cout << "T1:" << endl;
	t1.preOrderPrint();
	cout << "T2:" << endl;
	preOrderPrint();

	return true;
}



bool BST::printLevelNodes() {

	topDownLevelTraversal();

	return true;
}

bool BST::printPath() {
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