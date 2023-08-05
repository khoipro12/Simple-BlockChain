#pragma once
#include <string>
#include <vector>
#include <map>

std::vector<std::string> split(std::string a, std::string sub) {
	std::vector<std::string> x;
	size_t pos = 0;
	std::string token;
	while ((pos = a.find(sub)) != std::string::npos) {
		token = a.substr(0, pos);
		x.push_back(token);
		a.erase(0, pos + sub.length());
	}
	x.push_back(a);
	return x;
}

class json {
private:
	std::vector<std::map<std::string, std::string>> x;
public:
	json() {};
	json(std::string a[], int size) {
		std::map<std::string, std::string> temp;
		for (int i = 0; i < size; i++) {
			std::vector<std::string> t1 = split(a[i], " ");
			for (int j = 0; j < t1.size(); j++) {
				std::vector<std::string> t2 = split(t1[j], ":");
				for (int k = 0; k < t2.size() - 1; k++) {
					temp[t2[k]] = t2[k + 1];
				}
			}
			x.push_back(temp);
		}
	}
	std::vector<std::map<std::string, std::string>> get_vector() {
		return x;
	}
};
