/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_01_EX04_INCLUDES_SED_HPP_
#define MODULE_01_EX04_INCLUDES_SED_HPP_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

class Sed {
 public:
    Sed(char *, char *, char *);

    void    execute(void);

 private:
    std::string     _fileName;
    std::string     _replaceFileName;
    std::string     _strToFind;
    std::string     _replacement;
    std::ifstream   _fileToRead;
    std::ofstream   _fileToWrite;
    bool            _strMatched;

    bool            _openFile(void);
    bool            _createFileToWrite(void);
    void            _writeInNewFile(std::string);
    std::string     _readFromFile(void);
    void            _replace(std::size_t pos, std::string* buffer);
};

#endif /* MODULE_01_EX04_INCLUDES_SED_HPP_ */
