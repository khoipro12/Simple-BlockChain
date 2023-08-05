#include <iostream>
#include <string>
#include <vector>
#include "sha256.h"
#include "function.h"
#include "json.h"
#include "BlockChain.h"

int main(int argc, char* argv[]) {
	//data
	std::string a[4] = { 
		"from:khoi to:eula amount:100",
		"from:miko to:khoi amount:10000",
		"from:khoi to:miko amount:900",
		"from:eimi_fukada to:khoi amount:100"
	};
	std::string c[4] = {
		"from:nahida to:miko amount:1000"
	};
	json x(a, 4);
	json y(c, 1);
	std::string name = "khoi";
	std::string name2 = "miko";
	std::string name3 = "eula";
	std::string name4 = "eimi_fukada";
	std::string name5 = "nahida";
	BlockChain t;
	t.add_block(x);
	t.add_block(y);
	t.print();
	std::cout << "So du cua " << name << ": " << t.get_balance(name) << "\n";
	std::cout << "So du cua " << name2 << ": " << t.get_balance(name2) << "\n";
	std::cout << "So du cua " << name3 << ": " << t.get_balance(name3) << "\n";
	std::cout << "So du cua " << name4 << ": " << t.get_balance(name4) << "\n";
	std::cout << "So du cua " << name5 << ": " << t.get_balance(name5) << "\n";
	return 0;
}
