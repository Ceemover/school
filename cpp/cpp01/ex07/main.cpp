#include <iostream>
#include <fstream>

int     getInfInput(std::string message, std::string &input)
{
	std::cout << message;
	getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout<<std::endl;
		std::cin.clear();
		clearerr(stdin);
		std::cin.ignore(input.size());
		return 0;
	}
	return 1;
}

std::string readFile(std::ifstream &from_file){
	std::string content;
	for (char ch; from_file.get(ch); content.push_back(ch)) {}
	return content;
}

void find_and_replace(std::string &file_content, std::string &needle, std::string &replacer){
	size_t pos = file_content.find(needle);
	while (pos != std::string::npos) {
		file_content.replace(pos, needle.length(), replacer);
		pos = file_content.find(needle, pos);
	}
}

std::string toUpperCase(std::string to_capitalize) {
	int len = to_capitalize.length();

	while (--len > -1)
		to_capitalize[len] = toupper(to_capitalize[len]);
	return to_capitalize;
}

int openFiles(std::ifstream &from_file, std::ofstream &out_file) {
	std::string from_file_name;
	while (1) {
		if (!getInfInput("Enter filename to read from: ", from_file_name) || !from_file_name.compare(""))
			std::cout << "The filename cannot be empty" << std::endl;
		else {
			from_file.open(from_file_name, std::ifstream::in);
			if (from_file.fail()) {
				std::cout << "Couldn't open file \"" << from_file_name << "\", try another one" << std::endl;
			}
			else {
				break;
			}
		}
	}
	std::string out_file_name;
	out_file_name = toUpperCase(from_file_name);
	out_file_name.append(".replace");
	out_file.open(out_file_name, std::ifstream::out | std::ifstream::trunc);
	if (out_file.fail()) {
		std::cout << "Couldn't open file \"" << out_file_name << "\", exiting" << std::endl;
		from_file.close();
		return 1;
	}
	return 0;
}

int main(void) {
	std::ifstream from_file;
	std::ofstream out_file;
	if (openFiles(from_file, out_file))
		return 1;

	std::string needle;
	while (1) {
		if (!getInfInput("Enter a phrase to replace: ", needle) || !needle.compare("")) {
			std::cout << "The phrase cannot be empty" << std::endl;
		}
		else
			break;
	}

	std::string replacer;
	while (1) {
		if (!getInfInput("Enter a phrase to replace with: ", replacer) || !replacer.compare(""))
			std::cout << "The phrase cannot be empty" << std::endl;
		else
			break;
	}

	std::string content = readFile(from_file);
	find_and_replace(content, needle, replacer);
	out_file << content;
	return 0;
}