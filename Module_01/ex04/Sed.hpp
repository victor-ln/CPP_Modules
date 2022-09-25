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
		std::string		_strToFind;
		std::string		_replacement;
		std::ifstream	_fileToRead;
		std::ofstream	_fileToWrite;
		bool			_strMatched;

		bool			_openFile(void);
		bool			_createFileToWrite(void);
		bool			_initFiles(void);
		void			_writeInNewFile(std::string);
		std::string		_readFromFile(void);
		void			_replace(std::size_t pos, std::string& buffer);
		void			_convertCharToUnicode(const char *str, std::string& to);

	public:
		Sed(char *, char *, char *);

		void	execute(void);
};

# endif /* SED_HPP_ */
