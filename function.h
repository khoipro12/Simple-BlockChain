#pragma once
#include <map>
#include <sstream>
#include "json.h"
#include <vector>

//check string start with a string 
bool startwith(std::string check, std::string x) {
	std::string c = check.substr(0, x.size());
	if (c == x) {
		return true;
	}
	else {
		return false;
	}
}
//hash a string
std::string hash(std::string data) {
	SHA256 t; t(data);
	std::string result = t.getHash();
	return result;
}
//split at value

std::string get_address(json x) {
	std::ostringstream temp;
	temp << &x;
	std::string result = temp.str();
	return result;
}
	


