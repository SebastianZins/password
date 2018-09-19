#include "open.hh"

#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> read_file(std::string filename){

	std::vector<std::string> file_lines;
	std::string line;
	std::ifstream file(filename);

	if(file.is_open()){
		while(getline(file, line)){
			if(line[line.size()-1] == '\n'){
				line.erase(line.end()-1);
			}
			file_lines.push_back(line);
		}
	}
	return file_lines;
}
#include <iostream>

std::vector<std::vector<std::string>> read__file(std::string filename){
	std::vector<std::vector<std::string>> file_lines;

	std::string line;
	std::ifstream file(filename);

	if(file.is_open()){
		while(getline(file, line)){
			std::vector<std::string> words;
			if(line[line.size()-1] == '\n'){
				line.erase(line.end()-1);
			}
			unsigned int i = 0;
			std::string word = ""; 
			while(i < line.size()){
				while(line[i] != ' ' && i < line.size()){
					word += line[i];
					i++;

				}
				i++;
				words.push_back(word);
				word = "";
			}
			file_lines.push_back(words);
		}
	}
	return file_lines;
}