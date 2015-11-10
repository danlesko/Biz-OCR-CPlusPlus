#include <iostream>
#include <string>
#include "cardReader.h"

using namespace std;

int main(int argc, char *argv[]) {

	if (argc < 2) {
		cout << "Invalid number of arguments passed! Please try again!" << endl;
	}
	else {
		//Obtain files names of card passed in and for our name list
		string cardFile = argv[1];
		string nameFile = argv[2];
		//Set variables to use in loop for possible data correction
		int userArg=0;
		string newName;
		string newPhone;
		string newEmail;

		//Create a new instance of card class where card information will be stored
		cardReader *card = new cardReader(cardFile, nameFile);

		//After data processing, name, phone, and email and read out to user
		cout << "The name is: " << card->getName() << endl;
		cout << "The phone numer is: " << card->getPhoneNumber() << endl;
		cout << "The email address is: " << card->getEmailAddress() << endl;
		//This whole loop can be commented out but I wanted to give a chance for users to correct
		//any possible incorrect data
		while (userArg != 1) {
			if (userArg > 1) {
				cout << "The name is: " << card->getName() << endl;
				cout << "The phone numer is: " << card->getPhoneNumber() << endl;
				cout << "The email address is: " << card->getEmailAddress() << endl;
			}
			cout << "Is this information correct?" << endl;
			cout << "Type 1 if all is correct." << endl;
			cout << "Type 2 if name is incorrect." << endl;
			cout << "Type 3 if email is incorrect." << endl;
			cout << "Type 4 if phone number is incorrect." << endl;
			cout << "Selection: ";
			cin >> userArg;
			cin.ignore();
			switch (userArg) {
				case 2:
					cout << "Enter new name: ";
					getline(cin, newName);
					card->setName(newName);
					cout << "New name set to: " << card->getName() << endl;
					break;
				case 3:
					cout << "Enter new email address: ";
					getline(cin, newEmail);
					card->setEmailAddress(newEmail);
					cout << "New email address set to: " << card->getEmailAddress() << endl;
					break;
				case 4:
					cout << "Enter new phone number: ";
					getline(cin, newPhone);
					card->setPhoneNumber(newPhone);
					cout << "New phone number set to: " << card->getPhoneNumber() << endl;
					break;
			}
		}
		//Delete card data
		delete card;
		card = NULL;
	}

	//Comment out if not compiling with VS
	system("pause");
	return 0;
}
