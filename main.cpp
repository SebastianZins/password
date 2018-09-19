#include "crypt.h"
#include "open.cpp"

#include <iostream>
#include <fstream>

int main(){

	std::vector<std::string> file_lines = read_file("./user/SebastianZins/data");

	for(unsigned int i = 0; i < file_lines.size(); i++){
		std::cout << file_lines[i] << std::endl;
	}

	std::map<std::string, std::vector<std::string>> table = transform(file_lines);

	/*for(unsigned int i = 0; i < table["alias"].size(); i++){
		std::cout << table["alias"][i] << std::endl;
	}*/

	return 0;
}