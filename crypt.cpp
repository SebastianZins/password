#include "crypt.h"

#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> encrypt(std::vector<std::string> file, std::string pin, std::string password){
	// This function enrypts a given text (given as array of strings, where one element is one line of the text)
	// Besides the text the funtion needs a pin consisting of atleast 4 numbers in a string
	// also a password string. The text will be encrypted using these two components.
	int tmp;
	unsigned int password_it=0, i=0, j=0;
	std::vector<std::string> file_cpy;
	std::string password_comb = pin + password;
	std::string tmp_string = "";
	while(i < file.size()){
		if(password_it >= password_comb.size()){
			password_it = 0;
		}
		if(j >= file[i].size()){
			j = 0;
			i ++;
			file_cpy.push_back(tmp_string);
			tmp_string = "";
		}else{
			tmp = (int) file[i][j] - 32 + password_comb[password_it];
			if(tmp >= 0){
				if(tmp > 95){
					tmp -= 95;
				}
				tmp += 32;
				tmp_string.push_back((char) tmp);
			}
			j++;
			password_it++;
		}
	}
	return file_cpy;
}

std::vector<std::string> decrypt(std::vector<std::string> file, std::string pin, std::string password){
	// This function derypts a given text (given as array of strings, where one element is one line of the text)
	// Besides the text the funtion needs a pin consisting of atleast 4 numbers in a string
	// also a password string. The text will be decrypted using these two components.
	int tmp;
	unsigned int password_it=0, i=0, j=0;
	std::vector<std::string> file_cpy;
	std::string password_comb = pin + password;
	std::string tmp_string = "";

	while(i < file.size()){
		if(password_it >= password_comb.size()){
			password_it = 0;
		}
		if(j >= file[i].size()){
			j = 0;
			i ++;
			file_cpy.push_back(tmp_string);
			tmp_string = "";
		}else{
			tmp = (int) file[i][j] - 32 - password_comb[password_it];
			if(tmp < 0){
				tmp += 95;
			}
			tmp += 32;
			tmp_string.push_back((char) tmp);

			j++;
			password_it++;
		}
	}
	return file_cpy;
}

std::map<std::string, std::vector<std::string>> transform(std::vector<std::string> file){
	std::map<std::string, std::vector<std::string>> table;

	std::vector<std::string> line;
	std::string word = "";

	std::cout << std::endl;

	for(unsigned int i = 0; i < file.size(); i++){
		for(unsigned int j = 0; j < file[i].size(); j++){
			if(file[i][j] != ' '){
				word += file[i][j];
			}else{
				line.push_back(word);
				word = "";
			}
		}
		if(word != ""){
			line.push_back(word);
			word = "";
		}

		for(unsigned int k = 0; k < line.size(); k++){
			std::cout << line[k] << " ";
		}std::cout << std::endl;

		line.clear();

	}


	return table;
}


