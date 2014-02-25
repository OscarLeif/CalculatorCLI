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
#include "bigint-2010.04.30/BigIntegerLibrary.hh"

using namespace std;

class Numbers {
private:
	int input;
	string resultBin;
public:
	Numbers() {
		resultBin = new char();
	}
	void convertDECtoBIN(BigInteger value) {
		BigInteger remainder;
		BigInteger mod(2);
		if (value <= 1) {
			cout << value;
			return;
		}
		remainder = value % mod;
		cout << remainder << endl;
		convertDECtoBIN(value.toInt() >> 1);
		//cout << remainder;

		std::stringstream out;
		//out.putback(remainder);
		std::string s2 = bigIntegerToString(remainder);
		//std::string s = out.str();
		resultBin = s2;
		cout << s2 + " I suposse the result is there <-" << endl;
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
//New method for BigInteger
	string bigDecToBin(BigInteger number) {
		if (number == 0)
			return "0";
		if (number == 1)
			return "1";

		if (number % 2 == 0)
			return bigDecToBin(number / 2) + "0";
		else
			return bigDecToBin(number / 2) + "1";
	}
//New Method for BigInteger
	BigInteger BinToDec(string number) {
		BigInteger result = 0, pow = 1;
		//for ( BigInteger i = number.length() - 1; i >= 0; --i, pow <<= 1 )
		//  result += (number[i] - '0') * pow;

		return result;
	}
	//New Method for BigInteger
	string bigDeci2Octal(BigInteger value) {
		BigInteger total;
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
			stringConvert += bigIntegerToString(total);
		}

		ostringstream convert;   // stream used for the conversion
		string toBeReversed = stringConvert;
		reverse(toBeReversed.begin(), toBeReversed.end());
		cout << "Conversion result: " + stringConvert + "_OCT" << endl;
		return string(toBeReversed);
	}

	string bigDecimal2Hex(BigInteger value) {
		string result;
		BigInteger hexa[2] = { 0 }, x, y, i = 1;

		y = value;
		do {
			hexa[i.toInt()] = y % 16;
			y = y / 16;
			i--;
		} while (y > 0);
		for (i = 0; i < 2; i++) {
			y = hexa[i.toInt()];

			if (y == 10) {
				cout << 'A';
				result.push_back('A');
			} else if (y == 11) {
				cout << 'B';
				result.push_back('B');
			} else if (y == 12) {
				cout << 'C';
				result.push_back('C');
			} else if (y == 13) {
				result.push_back('D');
				cout << 'D';
			} else if (y == 14) {
				result.push_back('E');
				cout << 'E';
			} else if (y == 15) {
				result.push_back('F');
				cout << 'F';
			} else {
				BigInteger a = y;
				string ab = bigIntegerToString(a);
				char ch = ab.at(ab.length() - 1);
				//char* chh = ab.at(ab.length() - 1);
				result.push_back(ch);
				cout << y;
			}

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
	cout << "Calculator in CLI" << endl;

	//vectorResult.push_back("One");
	//vectorResult.push_back("Two");

	for (int var = 0; var < vectorResult.size(); var++) {
		cout << vectorResult[var] << endl;
	}
	//cout << "Here I show the last element of the vector" << endl;
	//cout << vectorResult[vectorResult.size() - 1] << endl;

	cout << "Waiting commands " << endl;
	int integer;
	cin >> command;
	while (command != "bye") {

		if (isInteger(command)) {
			vectorResult.push_back(command);
			cout << "Added the element " + command << endl;
		}

		if (command == "stk" || command == "SKT") {
			cout << "Stack !!!!" << endl;
			for (int var = 0; var < vectorResult.size(); var++) {
				cout << vectorResult[var] << endl;
			}
		}
		if (command == "bin" || command == "BIN") {
			string number = vectorResult[vectorResult.size() - 1];
			cout << number << endl;
			if (isInteger(number)) {

				BigInteger result = stringToBigInteger(number);
				//stringstream(number) >> result;
				//num.convertDECtoBIN(result);
				//num.convertDECtoBIN(result);
				cout << result;

				vectorResult.push_back(num.bigDecToBin(result) + "_BIN");
			}

		}

		if (command == "oct" || command == "OCT") {
			string number = vectorResult[vectorResult.size() - 1];
			if (isInteger(number)) {
				BigInteger result = stringToBigInteger(number);
				//stringstream(number) >> result;
				cout << "Number to convert to OCT: " + number << endl;

				vectorResult.push_back(num.bigDeci2Octal(result) + "_OCT");
			}
		}

		if (command == "hex" || command == "HEX") {
			string number = vectorResult[vectorResult.size() - 1];
			if (isInteger(number)) {
				int result;
				stringstream(number) >> result;
				BigInteger a = stringToBigInteger(number);
				cout << "Number to convert to HEX: " + number << endl;
				//num.bigDecimal2Hex(a);
				vectorResult.push_back(num.bigDecimal2Hex(a) + "_HEX");
			}
		}

		if (command == "big") {
			cout << "Big Integer test: " << endl;
			BigInteger a;
			string str = "43443243243242";
			cout << "Enter a integer: " << endl;
			cout << "the number will be : a * a * a * a * a * a * a * a"
					<< endl;
			int result;
			cin >> result;

			a = result;
			//stringstream("3324324323423432432") >> result;

			vectorResult.push_back(
					bigIntegerToString(a * a * a * a * a * a * a * a));
			cout << (a * a * a * a * a * a * a * a) << endl;

		}

		if (command == "bye") {
			exit(0);
		}

		if (command == "dump" || command == "DUMP") {
			//std::ofstream output_file("./result.txt"); //carpeta antes de donde esta el exe
			std::ofstream output_file("result.txt");
			std::ostream_iterator<std::string> output_iterator(output_file,
					"\n");
			std::copy(vectorResult.begin(), vectorResult.end(),
					output_iterator);
			cout << "File dumped in the same folder of this exe" << endl;
		}
		if (command == "clc" || command == "CLC") {
			system("cls");
		}

		if (command == "add" || command == "ADD") {
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
		if (command == "sub" || command == "SUB") {
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
		if (command == "mul" || command == "MUL") {
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

		if (command == "div" || command == "div") {
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
		if (command == "swap" || command == "SWAP") {
			string objFinal;
			string objFirst;

			objFinal = vectorResult[vectorResult.size() - 1];
			objFirst = vectorResult[vectorResult.size() - 2];

			vectorResult.erase(vectorResult.end() - 1);
			vectorResult.erase(vectorResult.end() - 1);

			vectorResult.push_back(objFinal);
			vectorResult.push_back(objFirst);
			cout << "Swaped !!" << endl;

		}
		if (command == "neg" || command == "NEG") {
			string objFinal = vectorResult[vectorResult.size() - 1];
			BigInteger number = stringToBigInteger(objFinal);
			number = number * -1;
			cout << "This is the new number: " + bigIntegerToString(number)
					<< endl;
			vectorResult.push_back(bigIntegerToString(number));
		}
		if (command == "help" || command == "?") {
			cout << "This is a simple calculator using CLI" << endl;
			cout << "This the list of commands" << endl;
			cout << "add, sub, mul, div, neg" << endl;
			cout
					<< "if you write a number it will be stored to save it just type dump. "
					<< endl;
			cout
					<< "Of course you can also convert to Binary, Octal and Hex number"
					<< endl;
			cout << "The comands are bin, hex, oct" << endl;
			cout << "To exit just write, bye" << endl;
		}

		cout << "waiting new command" << endl;
		cin >> command;

	} //fin del while.
	cout << "bye bye !!!!!" << endl;
	return 0;

}

