#include "cardReader.h"
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

cardReader::cardReader(string cardFile, string nameFile)
{
	//Calls FileExists to check to see if cardFile / nameFile exists
	//Throw exception if it does not.
	if (!FileExists(cardFile.c_str()))
	{
		throw Exceptions(cardFile + " was not found!");
	}
	else if (!FileExists(nameFile.c_str()))
	{
		throw Exceptions(nameFile + " was not found!");
	}
	//If no exceptions, create our tree
	//And then extract information from card
	else
	{
		createTree(nameFile);
		readCard(cardFile);
	}

}

bool cardReader::FileExists(const char* testFile)
{
	//creates bool variable to return
	bool openFile = true;

	//opens file for read in
	fstream infile(testFile, ios::in);
	if (infile.fail()) // if file doesn't open return print error message and exit program
	{
		cout << testFile << " was not successfully opened." << endl;
		openFile = false;
		return openFile;
	}
	else
	{
		cout << testFile << " was successfully opened." << endl;
	}

	//close file and return openFile variable
	infile.close();
	return openFile;
}

void cardReader::createTree(string nameFile)
{
	//variables to open file and get each line in file
	string getLine;
	fstream infile(nameFile.c_str(), ios::in);
	nameTree = new stringBST();

	//loop that places every name in file into our BST
	do {
		getline(infile, getLine);
		nameTree->insertNode(getLine);
	} while (!infile.eof());

	//close file
	infile.close();
}

void cardReader::readCard(string cardFile)
{
	//create variables for file retrieval processes
	string getLine;
	string answer;
	string next;
	bool nameSet = false;

	//open file
	fstream infile(cardFile.c_str(), ios::in);

	//loop to read through card file one time to find email and phone numbers
	do {
		int countNums = 0;
		getline(infile, getLine);
		stringstream ss;
		ss << getLine;

		//this loop looks at each char on a line to help determine a phone number / email address
		for (int i = 0; i < static_cast<int>(getLine.length()); i++) {
			//count digits found in a line
			if (isdigit(getLine[i]))
			{
				countNums++;
			}

			//if we find an @ and there is no space before it designating a twitter handle
			//set email address
			if (getLine[i] == '@' && getLine[i-1] != ' ') {
				emailAddress = getLine;
				break;
			}
			//else if we check countNums second and set phone number accordingly
			else if (countNums >= 10) {
				phoneNumber = getLine;
				break;
			}
			//else if ((i == getLine.length() - 1) && (nameSet == false))
			//{
			//	cout << "Is this the name? " << getLine << " (yes/no): ";
			//	cin >> answer;
			//	if (answer == "yes")
			//	{
			//		name = getLine;
			//		cin.ignore();
			//		nameSet = true;
			//		break;
			//	}
			//}
		}



	} while (!infile.eof());

	//close file
	infile.close();

	//reopen file
	fstream newInfile(cardFile.c_str(), ios::in);

	//loop to find name on card
	do {
		getline(newInfile, getLine);
		stringstream ss;
		ss << getLine;
		ss >> next;

		//this loop compare each word in a line to a name in our BST
		//time consuming but helps provide very accurate results
		do {
			if (nameTree->searchNode(next)) {
				name = getLine;
				break;
			}
		} while (ss >> next);

		//if we did not find a name on our first pass through
		//set name to first line
		//if we don't find a name this will remain the name which can be changed
		if (nameSet == false) {
			name = getLine;
			nameSet = true;
		}

	} while (!newInfile.eof());

	//close file
	newInfile.close();
	
}

string cardReader::getName()
{
	return name;
}

//THIS METHOD HAS BEEN WRITTEN TO HANDLE 10 DIGIT AMERICAN PHONE NUMBERS
string cardReader::getPhoneNumber()
{
	//new number variable
	string newNumber;
	//array of chars we want to take out
	//char chars[] = "#([]{})-: ";

	//loop to take out any alpha characters in case of TEL: xxx-xxx-xxxx
	phoneNumber.erase(remove_if(phoneNumber.begin(), phoneNumber.end(), ::isalpha), phoneNumber.end());
	phoneNumber.erase(remove_if(phoneNumber.begin(), phoneNumber.end(), ::ispunct), phoneNumber.end());


	//add the - in correct spots
	phoneNumber.insert(3, "-");
	phoneNumber.insert(7, "-");

	return phoneNumber;
}

string cardReader::getEmailAddress()
{
	return emailAddress;
}

void cardReader::setEmailAddress(string newEmail) {
	emailAddress = newEmail;
}

void cardReader::setPhoneNumber(string newPhone) {
	phoneNumber = newPhone;
}
void cardReader::setName(string newName) {
	name = newName;
}
