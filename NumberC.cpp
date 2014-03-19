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
#include <math.h>
#include "bigint-2010.04.30/BigIntegerLibrary.hh"

using namespace std;

class Numbers {
private:
	int input;
	string resultBin;
	string resulBin_Hex;

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
	BigInteger binaryToBase10(BigInteger n) {

		BigInteger output = 0;

		for (BigInteger i = 0; n > 0; i++) {

			if (n % 10 == 1) {
				output += powerB(2, i);
			}
			n /= 10;
		}

		return output;
	}
	BigInteger powerB(BigInteger base, BigInteger exponent) {

		BigInteger ans = 1;
		for (BigInteger i = 0; i < exponent; i++) {
			ans *= base;
		}
		return ans;
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
		cout << "Conversion result: " + toBeReversed + "_OCT" << endl;
		return string(toBeReversed);
	}

	BigInteger octal_decimal(BigInteger n) /* Function to convert octal to decimal */
	{
		BigInteger decimal = 0, i = 0, rem;
		while (n != 0) {
			rem = n % 10;
			n /= 10;
			decimal += rem * powerB(8, i);
			++i;
		}
		return decimal;
	}

	string bigDecimal2Hex(BigInteger value) {
		string result;
		BigInteger n, ar[10], i, j;
		n = value;
		for (i = 0; n != 0; i++) {
			ar[i.toUnsignedInt()] = n % 16;

			n = n / 16;

		}

		/*
		 * do {
		 hexa[i] = y % 16;
		 y = y / 16;
		 i--;

		 } while (y > 0);
		 */
		i--;
		cout << "Sali del primer for" << endl;
		cout << j << endl;
		for (j = i; j >= 0; j--) {
			cout << j << endl;
			cout << "Muerte del programa" << endl;
			cout << ar[j.toInt()] << endl;
			if (ar[j.toUnsignedInt()] == 10) {
				cout << "A";
				result.push_back('A');
			} else if (bigIntegerToString(ar[j.toInt()]) == "11") {
				cout << "B";
				result.push_back('B');
			} else if (bigIntegerToString(ar[j.toInt()]) == "12") {
				cout << "C";
				result.push_back('C');
			} else if (bigIntegerToString(ar[j.toInt()]) == "13") {
				cout << "D";
				result.push_back('D');
			} else if (bigIntegerToString(ar[j.toInt()]) == "14") {
				cout << "E";
				result.push_back('E');
			} else if (bigIntegerToString(ar[j.toInt()]) == "15") {
				cout << "F";
				result.push_back('F');
			} else {
				cout << ar[j.toInt()];
				//BigInteger big = ar[j];
				string ab = bigIntegerToString(ar[j.toInt()]);
				char ch = ab.at(ab.length() - 1);

				string number = bigIntegerToString(ar[j.toInt()]);
				result.push_back(ch);
				//cout << number + " This is the magic number" << endl;
			}
		}
		cout << endl;

		return result;
	}

	BigInteger hexCharToDec(char c) {
		if (c >= 'A' && c <= 'F')
			return 10 + (c - 'A');
		else
			// 0 - 9
			return c - '0';
	}
	BigInteger hex_to_decimal(string hex_in) {
		BigInteger dec = 0;

		for (unsigned int i = 0; i < hex_in.length(); i++) {
			char hexChar = hex_in[i];
			dec = dec * 16 + hexCharToDec(hexChar);
		}
		return dec;

	}

	BigInteger hexadecimal_to_decimal(char character) {
		BigInteger answer = (BigInteger) character - (BigInteger) ('0');

		if (answer >= 0 && answer <= 9) {
			return answer;
		} else {
			return (BigInteger) character - (BigInteger) ('A') + 10;
		}
	}

	string GetHexFromBin(string sBinary) {
		string rest("0x"), tmp, chr = "0000";
		int len = sBinary.length() / 4;
		chr = chr.substr(0, len);
		sBinary = chr + sBinary;
		for (int i = 0; i < sBinary.length(); i += 4) {
			tmp = sBinary.substr(i, 4);
			if (!tmp.compare("0000")) {
				rest = rest + "0";
			} else if (!tmp.compare("0001")) {
				rest = rest + "1";
			} else if (!tmp.compare("0010")) {
				rest = rest + "2";
			} else if (!tmp.compare("0011")) {
				rest = rest + "3";
			} else if (!tmp.compare("0100")) {
				rest = rest + "4";
			} else if (!tmp.compare("0101")) {
				rest = rest + "5";
			} else if (!tmp.compare("0110")) {
				rest = rest + "6";
			} else if (!tmp.compare("0111")) {
				rest = rest + "7";
			} else if (!tmp.compare("1000")) {
				rest = rest + "8";
			} else if (!tmp.compare("1001")) {
				rest = rest + "9";
			} else if (!tmp.compare("1010")) {
				rest = rest + "A";
			} else if (!tmp.compare("1011")) {
				rest = rest + "B";
			} else if (!tmp.compare("1100")) {
				rest = rest + "C";
			} else if (!tmp.compare("1101")) {
				rest = rest + "D";
			} else if (!tmp.compare("1110")) {
				rest = rest + "E";
			} else if (!tmp.compare("1111")) {
				rest = rest + "F";
			} else {
				continue;
			}
		}
		return rest;
	}

	char getHexCharacter(std::string str) {
		if (str.compare("1111") == 0)
			return 'F';
		else if (str.compare("1110") == 0)
			return 'E';
		else if (str.compare("1101") == 0)
			return 'D';
		else if (str.compare("1100") == 0)
			return 'C';
		else if (str.compare("1011") == 0)
			return 'B';
		else if (str.compare("1010") == 0)
			return 'A';
		else if (str.compare("1001") == 0)
			return '9';
		else if (str.compare("1000") == 0)
			return '8';
		else if (str.compare("0111") == 0)
			return '7';
		else if (str.compare("0110") == 0)
			return '6';
		else if (str.compare("0101") == 0)
			return '5';
		else if (str.compare("0100") == 0)
			return '4';
		else if (str.compare("0011") == 0)
			return '3';
		else if (str.compare("0010") == 0)
			return '2';
		else if (str.compare("0001") == 0)
			return '1';
		else if (str.compare("0000") == 0)
			return '0';
		else if (str.compare("111") == 0)
			return '7';
		else if (str.compare("110") == 0)
			return '6';
		else if (str.compare("101") == 0)
			return '5';
		else if (str.compare("100") == 0)
			return '4';
		else if (str.compare("011") == 0)
			return '3';
		else if (str.compare("010") == 0)
			return '2';
		else if (str.compare("001") == 0)
			return '1';
		else if (str.compare("000") == 0)
			return '0';
		else if (str.compare("11") == 0)
			return '3';
		else if (str.compare("10") == 0)
			return '2';
		else if (str.compare("01") == 0)
			return '1';
		else if (str.compare("00") == 0)
			return '0';
		else if (str.compare("1") == 0)
			return '1';
		else if (str.compare("0") == 0)
			return '0';
	}
	std::string getHexRowFails(string rowresult) {
		std::string endresult = "";

		for (int i = 0; i < rowresult.length(); i = i + 4) {
			endresult += getHexCharacter(rowresult.substr(i, 4));
		}
		return endresult;
	}

	void binary_hex(int n, char hex[]) /* Function to convert binary to hexadecimal. */
	{
		int i = 0, decimal = 0, rem;
		while (n != 0) {
			decimal += (n % 10) * pow(2, i);
			n /= 10;
			++i;
		}

		/* At this point, variable decimal contains binary number in decimal format. */
		i = 0;
		while (decimal != 0) {
			rem = decimal % 16;
			switch (rem) {
			case 10:
				hex[i] = 'A';
				break;
			case 11:
				hex[i] = 'B';
				break;
			case 12:
				hex[i] = 'C';
				break;
			case 13:
				hex[i] = 'D';
				break;
			case 14:
				hex[i] = 'E';
				break;
			case 15:
				hex[i] = 'F';
				break;
			default:
				hex[i] = rem + '0';
				break;
			}
			++i;
			decimal /= 16;
		}
		hex[i] = '\0';
		resulBin_Hex = strrev(hex); /* Function to reverse string. */
		cout << resulBin_Hex << endl;
	}

	string deci2hexaV2(BigInteger value) {
		BigInteger hexa[2] = { 0 }, x, y, i = 1;

		//cout << "Enter the value to convert to hexa: ";
		x = value;
		string result;
		y = x;

		do {
			hexa[i.toInt()] = y % 16;
			y = y / 16;
			i--;

		} while (y > 0);

		for (i = 0; i < 2; i++) {
			y = hexa[i.toInt()];

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
				BigInteger a = y;
				string ab = bigIntegerToString(a);
				char ch = ab.at(ab.length() - 1);
				result.push_back(ch);

			}
			cout << result << endl;
		}

		return result;

	}
	string binToHexa(string binaryGroup) {
		if (binaryGroup == "0000") {
			return "0";
		} else if (binaryGroup == "0001") {
			return "1";
		} else if (binaryGroup == "0010") {
			return "2";
		} else if (binaryGroup == "0011") {
			return "3";
		} else if (binaryGroup == "0100") {
			return "4";
		} else if (binaryGroup == "0101") {
			return "5";
		} else if (binaryGroup == "0110") {
			return "6";
		} else if (binaryGroup == "0111") {
			return "7";
		} else if (binaryGroup == "1000") {
			return "8";
		} else if (binaryGroup == "1001") {
			return "9";
		} else if (binaryGroup == "1010") {
			return "A";
		} else if (binaryGroup == "1011") {
			return "B";
		} else if (binaryGroup == "1100") {
			return "C";
		} else if (binaryGroup == "1101") {
			return "D";
		} else if (binaryGroup == "1110") {
			return "E";
		} else if (binaryGroup == "1111") {
			return "F";
		} else {
			return "@"; /*ERROR INDICATION*/
		}
	}

	string dec_to_hex(BigInteger a) {
		string hex = "";
		string temp;
		vector<BigInteger> remainders;
		BigInteger rem;
		if (a < 1)
			throw 1;
		while (a > 15) {
			rem = a % 16;
			a -= rem;
			a /= 16;
			remainders.push_back(rem);
		}

		remainders.push_back(a);

		reverse(remainders.begin(), remainders.end());
		int i = 0;

		while (i < remainders.size()) {
			switch (remainders[i].toInt()) {
			case 15:
				hex = hex + "F";
				break;
			case 14:
				hex = hex + "E";
				break;
			case 13:
				hex = hex + "D";
				break;
			case 12:
				hex = hex + "C";
				break;
			case 11:
				hex = hex + "B";
			case 10:
				hex = hex + "A";
				break;
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9: {
				stringstream ss;
				ss << remainders[i];
				ss >> temp;
				hex = hex + temp;
			}
				break;
			default:
				throw 2;
			}
			++i;
		}

		return hex;
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

	cout << "Waiting commands ******" << endl;
	int integer;
	cin >> command;
	while (command != "bye") {

		if (isInteger(command)) {
			vectorResult.push_back(command);
			cout << "Added the element " + command << endl;
		}

		if (command == "stk" || command == "SKT") {
			cout << "Stack !!!!" << endl;
			if (vectorResult.size() > 0) {
				for (int var = 0; var < vectorResult.size(); var++) {
					cout << vectorResult[var] << endl;
				}
			} else
				cout << "Looks like the stack is empty." << endl;
		}
		if (command == "bin" || command == "BIN") {
			if (vectorResult.size() > 0) {

				string number = vectorResult[vectorResult.size() - 1];

				char last_char = number.at(number.length() - 1);
				cout << number << endl;

				if (isInteger(number)) {

					BigInteger result = stringToBigInteger(number);
					cout << num.bigDecToBin(result) << endl;
					if (last_char == 'N') {
						cout << "This number is already a binary: " << endl;
					}
					if (last_char == 'T') {
						cout << "Convert number: ";
						cout << number << endl;
						number.erase(number.size() - 1);
						number.erase(number.size() - 1);
						number.erase(number.size() - 1);
						number.erase(number.size() - 1);
						cout << number << endl;
						BigInteger octal = stringToBigInteger(number);
						BigInteger decimal = num.octal_decimal(octal);
						string binary = num.bigDecToBin(decimal);
						cout << "The result is: ";
						cout << binary << endl;
						vectorResult.push_back(binary + "_BIN");
					}
					if (last_char == 'X') {
						cout << "Convert number: ";
						cout << number << endl;
						number.erase(number.size() - 1);
						number.erase(number.size() - 1);
						number.erase(number.size() - 1);
						number.erase(number.size() - 1);
						cout << number << endl;
						BigInteger decimal = num.hex_to_decimal(number);
						string binary = num.bigDecToBin(decimal);
						cout << "The result is: ";
						cout << binary << endl;
					}
				}
			} else
				cout << "You must enter some data first" << endl;//End of the if for the size
		}

		if (command == "oct" || command == "OCT") {
			if (vectorResult.size() > 0) {
				string number = vectorResult[vectorResult.size() - 1];
				char last_char = number.at(number.length() - 1);
				if (isInteger(number)) {
					BigInteger result = stringToBigInteger(number);
					//stringstream(number) >> result;
					cout << "Number to convert to OCT: " + number << endl;
					cout<<"The Result is: ";
					cout << num.bigDeci2Octal(result) << endl;
					//vectorResult.push_back(num.bigDeci2Octal(result) + "_OCT");
				}
				if (last_char == 'T') {
					cout << "This number is already an octal: ";
					cout << number << endl;
				}
				if (last_char == 'N') {
					cout << "Convert number: ";
					cout << number << endl;
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					cout << number << endl;
					BigInteger binary = stringToBigInteger(number);
					BigInteger decimal = num.binaryToBase10(binary);
					string octal = num.bigDeci2Octal(decimal);
					cout << "The result is: ";
					cout << octal << endl;
				}
				if (last_char == 'X') {
					cout << "Convert number: ";
					cout << number << endl;
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					cout << number << endl;
					BigInteger decimal = num.hex_to_decimal(number);
					string octal = num.bigDeci2Octal(decimal);

					cout << "The result is: ";
					cout << octal << endl;
				}
			}					//end of the if size()
			else
				cout << "You must enter some data first" << endl;
		}

		if (command == "hex" || command == "HEX") {
			if (vectorResult.size() > 0) {
				string number = vectorResult[vectorResult.size() - 1];
				char last_char = number.at(number.length() - 1);
				char hex[20];
				if (isInteger(number)) {
					int result;
					stringstream(number) >> result;
					BigInteger a = stringToBigInteger(number);
					cout << "Number to convert to HEX: " + number << endl;
					cout << num.dec_to_hex(a) << endl;
				}
				if (last_char == 'X') {
					cout << "This number is already a Hex: ";
					cout << number << endl;
				}
				if (last_char == 'N') {
					cout << "Convert number: ";
					cout << number << endl;
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					cout << number << endl;
					BigInteger binary = stringToBigInteger(number);
					BigInteger decimal = num.binaryToBase10(binary);
					string Hex = num.dec_to_hex(decimal);
					cout << "The result is: ";
					cout << hex << endl;
				}
				if (last_char == 'T') {
					cout << "Convert number: ";
					cout << number << endl;
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					cout << number << endl;
					BigInteger octal = stringToBigInteger(number);
					BigInteger decimal = num.octal_decimal(octal);
					string Hex = num.dec_to_hex(decimal);
					cout << "The result is: ";
					cout << Hex << endl;
				}
			}					//end of the if size()
			else
				cout << "You must enter some data first" << endl;
		}

		if (command == "dec" || command == "DEC") {
			if (vectorResult.size() > 0) {
				string number = vectorResult[vectorResult.size() - 1];
				char last_char = number.at(number.length() - 1);

				if (last_char == 'N') {
					cout << "Convert number: ";
					cout << number << endl;
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					cout << number << endl;
					BigInteger binary = stringToBigInteger(number);
					BigInteger decimal = num.binaryToBase10(binary);
					cout << "The result is: ";
					cout << decimal<<endl;
				}
				if (last_char == 'T') {
					cout << "Convert number: ";
					cout << number << endl;
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					cout << number << endl;
					BigInteger octal = stringToBigInteger(number);
					BigInteger decimal = num.octal_decimal(octal);
					cout << "The result is: ";
					cout << decimal<<endl;
				}
				if (last_char == 'X') {
					cout << "Convert number: ";
					cout << number << endl;
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					number.erase(number.size() - 1);
					cout << number << endl;
					BigInteger decimal = num.hex_to_decimal(number);

					cout << "The result is: ";
					cout << decimal<<endl;
				}
			} else
				cout
						<< "Probably you have a decimal number, or you must have to enter some data."
						<< endl;

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
			if (vectorResult.size() > 1) {
				//suma los dos ultimos valores del stack y el resul
				string number = vectorResult[vectorResult.size() - 1];
				string numberP = vectorResult[vectorResult.size() - 2];
				if (isInteger(number)) {
					BigInteger result = stringToBigInteger(number);
					BigInteger resultP = stringToBigInteger(numberP);

					BigInteger a = result + resultP;
					//int a = 10;

					vectorResult.push_back(bigIntegerToString(a));
					cout << "Result of the adition: " + bigIntegerToString(a)
							<< endl;
				}
			} else
				cout << "I need at least two elements to start the addition"
						<< endl;
		}
		if (command == "sub" || command == "SUB") {
			if (vectorResult.size() > 1) {
				//resta (subtract) los dos ultimos valores del stack y el resul
				string number = vectorResult[vectorResult.size() - 1];
				string numberP = vectorResult[vectorResult.size() - 2];
				if (isInteger(number)) {
					BigInteger result = stringToBigInteger(number);
					BigInteger resultP = stringToBigInteger(numberP);

					BigInteger a = result - resultP;
					//int a = 10;

					vectorResult.push_back(bigIntegerToString(a));
					cout << "Result of the subtration: " + bigIntegerToString(a)
							<< endl;
				}
			} else
				cout << "I need at least two elements to start the subtraction"
						<< endl;
		}
		if (command == "mul" || command == "MUL") {
			if (vectorResult.size() > 1) {
				//multiplica (multiply) los dos ultimos valores del stack y el resul
				string number = vectorResult[vectorResult.size() - 1];
				string numberP = vectorResult[vectorResult.size() - 2];
				if (isInteger(number)) {
					BigInteger result = stringToBigInteger(number);
					BigInteger resultP = stringToBigInteger(numberP);

					BigInteger a = result * resultP;
					//int a = 10;
					stringstream ss;

					vectorResult.push_back(bigIntegerToString(a));
					cout << "Result of the multiply: " + bigIntegerToString(a)
							<< endl;
				}
			} else
				cout << "Need at least two elemtns to multiply first" << endl;
		}

		if (command == "div" || command == "div") {
			if (vectorResult.size() > 1) {
				//multiplica (multiply) los dos ultimos valores del stack y el resul
				string number = vectorResult[vectorResult.size() - 1];
				string numberP = vectorResult[vectorResult.size() - 2];
				if (isInteger(number)) {
					BigInteger result = stringToBigInteger(number);
					BigInteger resultP = stringToBigInteger(numberP);
					if (resultP != 0) {
						BigInteger a = result / resultP;
						//int a = 10;
						stringstream ss;

						vectorResult.push_back(bigIntegerToString(a));
						cout
								<< "Result of the division: "
										+ bigIntegerToString(a) << endl;
					}
					if (resultP == 0) {
						cout
								<< "The divitions by zero is at the moment undefined, but probably that is infinity"
								<< endl;
					}
				}
			} else
				cout << "I need two elements in order to make a divison"
						<< endl;
		}
		if (command == "swap" || command == "SWAP") {
			if (vectorResult.size() > 1) {
				string objFinal;
				string objFirst;

				objFinal = vectorResult[vectorResult.size() - 1];
				objFirst = vectorResult[vectorResult.size() - 2];

				vectorResult.erase(vectorResult.end() - 1);
				vectorResult.erase(vectorResult.end() - 1);

				vectorResult.push_back(objFinal);
				vectorResult.push_back(objFirst);
				cout << "Swaped !!" << endl;
			} else
				cout << "I need two elements to swap." << endl;

		}
		if (command == "neg" || command == "NEG") {
			if (vectorResult.size() > 0) {
				string objFinal = vectorResult[vectorResult.size() - 1];
				BigInteger number = stringToBigInteger(objFinal);
				number = number * -1;
				cout << "This is the new number: " + bigIntegerToString(number);
				cout << " added to the stack." << endl;
				vectorResult.push_back(bigIntegerToString(number));
			} else
				cout << "I need any number to negate first, add some data"
						<< endl;
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

		cout << "waiting new command ******" << endl;
		cin >> command;

	} //fin del while.
	cout << "bye bye !!!!!" << endl;
	return 0;

}

