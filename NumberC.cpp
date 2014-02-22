/*
 * NumberC.cpp
 *
 *  Created on: 17/02/2014
 *      Author: Leif
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "convert.h"

using namespace std;
class Numbers {
private:
	int input;
	string resultBin;
public:
	void convertDECtoBIN(int value) {
		int remainder;

		if (value <= 1) {
			cout << value;
			return;
		}
		remainder = value % 2;
		convertDECtoBIN(value >> 1);
		cout << remainder;

		std::stringstream out;
		out << resultBin;
		resultBin = out.str();
	}
	string getResult() {
		return resultBin + "_bin";
	}

};

int main(int argc, char **argv) {

	Numbers num;
	string a;
	vector<string> vectorResult;
	string command;

	int numberInput;
	cout << "Hello World!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	//cout << "enter a number to convert to binary" << endl;
	//cin >> numberInput;
	//num.convertDECtoBIN(numberInput);
	//vectorResult.push_back(num.getResult());
	vectorResult.push_back("One");
	vectorResult.push_back("Two");

	for (int var = 0; var < vectorResult.size(); var++) {
		cout << vectorResult[var] << endl;
	}
	cout << "Here I show the last element of the vector" << endl;
	cout << vectorResult[vectorResult.size() - 1] << endl;

	cout << "Waiting commands " << endl;

	while (command != "bye") {

		int integer;
		cin >> command;
		//string buffer = "123456789";
		//cout << "String:" << buffer << endl;
		//integer=atoi(buffer.c_str());

		try {
			integer = (int) convertToDouble(command);
		} catch (bad_exception e) {

		}

		//cout << "Integer:" << integer << endl;

		if (integer >= 0) {
			cout << "Number is working" << endl;
			int i = 5;
			std::string s;
			std::stringstream out;
			out << integer;
			s = out.str();
			vectorResult.push_back(s);
			cout << integer << endl;
		}

		if (command == "stk") {
			cout << "Stack !!!!" << endl;
		}

		if (command == "bye") {
			exit(0);
		}
		cout << "waiting new command" << endl;
		cin >> command;

	} //fin del while.
	cout << "bye bye !!!!!" << endl;
	return 0;

}

