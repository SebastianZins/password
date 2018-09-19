#ifndef CRYPT_H
#define CRYPT_H 

#include <vector>
#include <map>
#include <string>

std::vector<std::string> encrypt(std::vector<std::string> file, std::string pin, std::string password);

std::vector<std::string> decrypt(std::vector<std::string> file, std::string pin, std::string password);

std::map<std::string, std::vector<std::string>> transform(std::vector<std::string> file);

#endif