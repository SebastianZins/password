#include "crypt.h"
#include "open.cpp"

#include <iostream>
#include <fstream>

int main(){

	std::vector<std::string> file_lines = read_file("text1");
	
	for(unsigned int i=0; i<file_lines.size(); i++){
		std::cout << file_lines[i] << std::endl; 
	}
	std::cout << "##########" <<std::endl;

	file_lines = encrypt(file_lines);

	std::ofstream out("text2");

	for(unsigned int i=0; i<file_lines.size(); i++){
		std::cout << file_lines[i] << std::endl; 
		out << file_lines[i] << "\n";
	}
	out.close();

	std::cout << "##########" << std::endl;

	file_lines = read_file("text2");

	file_lines = decrypt(file_lines);

	std::ofstream out1("text3");

	for(unsigned int i=0; i<file_lines.size(); i++){
		std::cout << file_lines[i] << std::endl; 
		out1 << file_lines[i] << "\n";
	}
	out1.close();

	return 0;
}