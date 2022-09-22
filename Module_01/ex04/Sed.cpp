#include "Sed.hpp"

Sed::Sed(char *fileToRead, char *strToFind, char *replacement) {
	this->_fileName = fileToRead;;
	this->_strToFind = strToFind;
	this->_replacement = replacement;
}

bool	Sed::_openFile(void) {
	this->_fileToRead.open(this->_fileName.c_str(), std::ios::in);
	return (this->_fileToRead.is_open());
}

bool	Sed::_createFileToWrite(void) {
	this->_replaceFileName = this->_fileName + ".replace";
	this->_fileToWrite.open(this->_replaceFileName.c_str(), std::ios::out | std::ios::trunc);
	return (this->_fileToWrite.is_open());
}

bool	Sed::_initFiles(void) {
	if (!this->_openFile()) {
		std::cout << "Could not open file to read" << std::endl;
		return (false);
	}
	if (!this->_createFileToWrite()) {
		std::cout << "Could not create file to write" << std::endl;
		return (false);
	}
	return (true);
}

inline void	Sed::_replace(std::size_t pos, std::string& buffer) {
	buffer = buffer.substr(0, pos) + this->_replacement + buffer.substr(pos + this->_strToFind.length());
}

void	Sed::execute(void) {
	if (!this->_initFiles())
		return ;
	std::string	 buffer;
	std::size_t	 pos;

	while (std::getline(this->_fileToRead, buffer)) {
		pos = buffer.find(this->_strToFind);
		while (pos != std::string::npos) {
			this->_replace(pos, buffer);
			pos = buffer.find(this->_strToFind);
		}
		this->_fileToWrite << buffer << std::endl;
	}
}
