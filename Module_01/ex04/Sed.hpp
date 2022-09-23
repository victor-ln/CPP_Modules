#ifndef SED_HPP_
# define SED_HPP_

#include <fstream>
#include <iostream>
#include <cstdlib>

class Sed
{
	private:
		std::string		_fileName;
		std::string		_replaceFileName;
		std::wstring	_strToFind;
		std::wstring	_replacement;
		std::wifstream	_fileToRead;
		std::wofstream	_fileToWrite;
		bool			_strMatched;

		bool			_openFile(void);
		bool			_createFileToWrite(void);
		bool			_initFiles(void);
		void			_writeInNewFile(std::wstring);
		std::wstring	_readFromFile(void);
		void			_replace(std::size_t pos, std::wstring& buffer);
		void			_convertCharToUnicode(const char *str, std::wstring& to);

	public:
		Sed(char *, char *, char *);

		void	execute(void);
};

# endif /* SED_HPP_ */
