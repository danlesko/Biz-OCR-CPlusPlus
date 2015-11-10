#ifndef CARDREADER_H
#define CARDREADER_H
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <functional>
#include "MyExceptions.h"
#include "stringBST.h"

using namespace std;

class cardReader {

	//private data & methods
private:
	string name;
	string phoneNumber;
	string emailAddress;
	stringBST *nameTree;

	//private method to check file existence
	bool FileExists(const char*);

	//method to initialize nameTree
	void createTree(string);

	//public data & methods
public:
	//constructor
	cardReader(string, string);

	//getters
	string getName();
	string getPhoneNumber();
	string getEmailAddress();

	//setters
	void setName(string);
	void setPhoneNumber(string);
	void setEmailAddress(string);

	//main method to read card information and properly store it
	void readCard(string);

};


#endif