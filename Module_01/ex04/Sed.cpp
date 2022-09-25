#include "Sed.hpp"

Sed::Sed(char *fileToRead, char *strToFind, char *replacement) {
	this->_fileName = fileToRead;
	this->_strToFind = strToFind;
	this->_replacement = replacement;
}

inline bool	Sed::_openFile(void) {
	this->_fileToRead.open(this->_fileName.c_str(), std::ios::in);
	return (this->_fileToRead.is_open());
}

inline bool	Sed::_createFileToWrite(void) {
	this->_replaceFileName = this->_fileName + ".replace";
	this->_fileToWrite.open(this->_replaceFileName.c_str(), std::ios::out | std::ios::trunc);
	return (this->_fileToWrite.is_open());
}

inline void	Sed::_replace(std::size_t pos, std::string& buffer) {
	buffer = buffer.substr(0, pos) + this->_replacement + buffer.substr(pos + this->_strToFind.length());
}

std::string	Sed::_readFromFile(void) {
	std::string		readBuffer;
	std::string		buffer;
	std::size_t		pos;
	std::size_t		lastPos;

	while (std::getline(this->_fileToRead, readBuffer)) {
		lastPos = 0;
		while ((pos = readBuffer.find(this->_strToFind)) != std::string::npos && pos >= lastPos) {
			this->_strMatched = true;
			this->_replace(pos, readBuffer);
			lastPos = pos + this->_strToFind.length();
		}
		if (!this->_fileToRead.eof())
			readBuffer += '\n';
		buffer += readBuffer;
	}
	this->_fileToRead.close();
	return (buffer);
}

void	Sed::_writeInNewFile(std::string buffer) {
	if (!this->_createFileToWrite()) {
		std::cout << "Could not create file to write" << std::endl;
		return ;
	}
	this->_fileToWrite << buffer;
	this->_fileToWrite.close();
}

void	Sed::execute(void) {
	if (!this->_openFile()) {
		std::cout << "Could not open file to read" << std::endl;
		return ;
	}
	std::string	buffer = this->_readFromFile();
	if (this->_strMatched)
		this->_writeInNewFile(buffer);
	else
		std::cout << "There's no matches" << std::endl;
}
