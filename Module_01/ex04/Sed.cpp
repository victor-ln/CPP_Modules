#include "Sed.hpp"

Sed::Sed(char *fileToRead, char *strToFind, char *replacement) {
	this->_fileName = fileToRead;
	this->_convertCharToUnicode(strToFind, this->_strToFind);
	this->_convertCharToUnicode(replacement, this->_replacement);
}

void Sed::_convertCharToUnicode(const char *str, std::wstring& to) {
	std::string		buff(str);
	wchar_t			*wBuff;

	wBuff = new wchar_t[buff.length()];
	std::mbstowcs(wBuff, buff.c_str(), buff.length());
	to = wBuff;
	delete [] wBuff;
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

inline void	Sed::_replace(std::size_t pos, std::wstring& buffer) {
	buffer = buffer.substr(0, pos) + this->_replacement + buffer.substr(pos + this->_strToFind.length());
}

std::wstring	Sed::_readFromFile(void) {
	std::wstring		readBuffer;
	std::wstring		buffer;
	std::size_t			pos;
	std::size_t			aux;

	while (std::getline(this->_fileToRead, readBuffer)) {
		aux = 0;
		while ((pos = readBuffer.find(this->_strToFind)) != std::wstring::npos && pos >= aux) {
			this->_strMatched = true;
			this->_replace(pos, readBuffer);
			aux = pos + this->_strToFind.length();
		}
		if (!this->_fileToRead.eof())
			readBuffer += '\n';
		buffer += readBuffer;
	}
	this->_fileToRead.close();
	return (buffer);
}

void	Sed::_writeInNewFile(std::wstring buffer) {
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
	std::wstring	buffer = this->_readFromFile();
	if (this->_strMatched)
		this->_writeInNewFile(buffer);
}
