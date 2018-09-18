#include "crypt.h"

#include <vector>
#include <string>

std::vector<std::string> encrypt(std::vector<std::string> file){

	int tmp;
	std::vector<std::string> file_cpy;
	for(unsigned int i = 0; i < file.size(); i++){
		std::string tmp_string = "";
		for(unsigned int j = 0;  j < file[i].size(); j++){
			tmp = (int) file[i][j] - 32 + 10;
			if(tmp >= 0){
				if(tmp > 95){
					tmp -= 95;
				}
				tmp += 32;
				tmp_string.push_back((char) tmp);
			}
		}
		file_cpy.push_back(tmp_string);
	}
	return file_cpy;
}

std::vector<std::string> decrypt(std::vector<std::string> file){

	int tmp;
	std::vector<std::string> file_cpy;
	for(unsigned int i = 0; i < file.size(); i++){
 		std::string tmp_string = "";
 		for(unsigned int j = 0;  j < file[i].size(); j++){
			tmp = (int) file[i][j] - 32 - 10;
			if(tmp < 0){
				tmp += 95;
			}
			tmp += 32;
			tmp_string.push_back((char) tmp);
		}
		file_cpy.push_back(tmp_string);
	}
	return file_cpy;
}







