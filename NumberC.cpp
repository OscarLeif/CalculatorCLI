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
#include <algorithm>
#include <stdlib.h>
#include "convert.h"
#include <string.h>
#include <fstream>
#include <iterator>

using namespace std;
class Numbers {
private:
	int input;
	string resultBin;
public:
	Numbers() {
		resultBin = new char();
	}
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
		out.putback(remainder);

		std::string s = out.str();
		resultBin = s;
		cout << s;
	}
	string deci2binary(unsigned long n) {
		char result[(sizeof(unsigned long) * 8) + 1];
		unsigned index = sizeof(unsigned long) * 8;
		result[index] = '\0';

		do
			result[--index] = '0' + (n & 1);
		while (n >>= 1);

		return string(result + index);
	}
	string getResultBIN() {
		return resultBin;
	}
	string convertInt2String(int number) {
		if (number == 0)
			return "0";
		string temp = "";
		string returnvalue = "";
		while (number > 0) {
			temp += number % 10 + 48;
			number /= 10;
		}
		for (int i = 0; i < temp.length(); i++)
			returnvalue += temp[temp.length() - i - 1];
		return returnvalue;
	}

	string deci2Octal(long value) {
		int total;
		//cout << "Please enter a decimal: ";
		//cin >> num;
		string stringConvert;
		while (value > 0) {
			total = value % 8;
			value /= 8;
			//cout << total << "";
			std::string s;
			std::stringstream out;
			out << total;
			s = out.str();

			stringConvert += s;
		}

		ostringstream convert;   // stream used for the conversion
		string toBeReversed = stringConvert;
		reverse(toBeReversed.begin(), toBeReversed.end());
		cout << "Conversion result: " + toBeReversed + "_OCT" << endl;
		return string(toBeReversed);
	}

	string deci2hexa(long value) {
		int hexa[2] = { 0 }, x, y, i = 1;

		//cout << "Enter the value to convert to hexa: ";
		x = value;
		string result;
		y = x;

		do {
			hexa[i] = y % 16;
			y = y / 16;
			i--;

		} while (y > 0);

		for (i = 0; i < 2; i++) {
			y = hexa[i];

			if (y == 10) {
				//cout << 'A';
				result.push_back('A');
			} else if (y == 11) {
				//cout << 'B';
				result.push_back('B');
			} else if (y == 12) {
				//cout << 'C';
				result.push_back('C');
			} else if (y == 13) {
				//cout << 'D';
				result.push_back('D');
			} else if (y == 14) {
				//cout << 'E';
				result.push_back('E');
			} else if (y == 15) {
				//cout << 'F';
				result.push_back('F');
			} else {
				//cout << y;
				int a = y;
				string ab = convertInt2String(a);
				char ch = ab.at(ab.length() - 1);
				result.push_back(ch);

			}
			cout << result << endl;
		}

		return result;

	}

};

int main(int argc, char **argv) {

	Numbers num;
	string a;
	vector<string> vectorResult;
	string command;

	int numberInput;
	cout << "Hello World!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

	vectorResult.push_back("One");
	vectorResult.push_back("Two");

	for (int var = 0; var < vectorResult.size(); var++) {
		cout << vectorResult[var] << endl;
	}
	cout << "Here I show the last element of the vector" << endl;
	cout << vectorResult[vectorResult.size() - 1] << endl;

	cout << "Waiting commands " << endl;
	int integer;
	cin >> command;
	while (command != "bye") {

		if (isInteger(command)) {
			vectorResult.push_back(command);
			cout << "Added the element " + command << endl;
		}

		if (command == "stk") {
			cout << "Stack !!!!" << endl;
			for (int var = 0; var < vectorResult.size(); var++) {
				cout << vectorResult[var] << endl;
			}
		}
		if (command == "bin") {
			string number = vectorResult[vectorResult.size() - 1];
			if (isInteger(number)) {
				int result;
				stringstream(number) >> result;
				num.convertDECtoBIN(result);
				vectorResult.push_back(num.deci2binary(result) + "_BIN");
			}

		}

		if (command == "oct") {
			string number = vectorResult[vectorResult.size() - 1];
			if (isInteger(number)) {
				int result;
				stringstream(number) >> result;
				cout << "Number to convert to OCT: " + number << endl;

				vectorResult.push_back(num.deci2Octal(result) + "_OCT");
			}
		}

		if (command == "hex") {
			string number = vectorResult[vectorResult.size() - 1];
			if (isInteger(number)) {
				int result;
				stringstream(number) >> result;
				cout << "Number to convert to HEX: " + number << endl;
				num.deci2hexa(result);
				vectorResult.push_back(num.deci2hexa(result) + "_HEX");
			}
		}

		if (command == "") {
			cout << "Write a command" << endl;
		}

		if (command == "bye") {
			exit(0);
		}

		if (command == "dump") {
			//std::ofstream output_file("./result.txt"); //carpeta antes de donde esta el exe
			std::ofstream output_file("result.txt");
			std::ostream_iterator<std::string> output_iterator(output_file,
					"\n");
			std::copy(vectorResult.begin(), vectorResult.end(),
					output_iterator);
			cout << "File dumped in the same folder of this exe" << endl;
		}
		if (command == "clc") {
			system("cls");
		}

		if (command == "add") {
			//suma los dos ultimos valores del stack y el resul
			string number = vectorResult[vectorResult.size() - 1];
			string numberP = vectorResult[vectorResult.size() - 2];
			if (isInteger(number)) {
				int result;
				int resultP;
				stringstream(number) >> result;
				stringstream(numberP) >> resultP;

				int a = result + resultP;
				//int a = 10;
				stringstream ss;
				ss << a;
				string str = ss.str();
				vectorResult.push_back(str);
				cout << "Result of adition: " + a << endl;
			}
		}
		if (command == "sub") {
			//resta (subtract) los dos ultimos valores del stack y el resul
			string number = vectorResult[vectorResult.size() - 1];
			string numberP = vectorResult[vectorResult.size() - 2];
			if (isInteger(number)) {
				int result;
				int resultP;
				stringstream(number) >> result;
				stringstream(numberP) >> resultP;

				int a = result - resultP;
				//int a = 10;
				stringstream ss;
				ss << a;
				string str = ss.str();
				vectorResult.push_back(str);
				cout << "Result of adition: " + a << endl;
			}
		}
		if (command == "mul") {
			//multiplica (multiply) los dos ultimos valores del stack y el resul
			string number = vectorResult[vectorResult.size() - 1];
			string numberP = vectorResult[vectorResult.size() - 2];
			if (isInteger(number)) {
				int result;
				int resultP;
				stringstream(number) >> result;
				stringstream(numberP) >> resultP;

				int a = result * resultP;
				//int a = 10;
				stringstream ss;
				ss << a;
				string str = ss.str();
				vectorResult.push_back(str);
				cout << "Result of adition: " + a << endl;
			}
		}

		if (command == "div") {
			//multiplica (multiply) los dos ultimos valores del stack y el resul
			string number = vectorResult[vectorResult.size() - 1];
			string numberP = vectorResult[vectorResult.size() - 2];
			if (isInteger(number)) {
				int result;
				int resultP;
				stringstream(number) >> result;
				stringstream(numberP) >> resultP;

				int a = result / resultP;
				//int a = 10;
				stringstream ss;
				ss << a;
				string str = ss.str();
				vectorResult.push_back(str);
				cout << "Result of adition: " + a << endl;
			}
		}
			cout << "waiting new command" << endl;
			cin >> command;

		} //fin del while.
		cout << "bye bye !!!!!" << endl;
		return 0;

	}

