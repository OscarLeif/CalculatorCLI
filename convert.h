// File: convert.h
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <string>

class BadConversion: public std::runtime_error {
public:
	BadConversion(std::string const& s) :
			std::runtime_error(s) {
	}
};

inline double convertToDouble(std::string const& s) {
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		throw BadConversion("convertToDouble(\"" + s + "\")");
	return x;
}
inline bool isInteger(const std::string & s) {
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
		return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}


