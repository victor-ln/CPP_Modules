/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_05_EX02_INCLUDES_SHRUBBERYCREATIONFORM_HPP_
#define MODULE_05_EX02_INCLUDES_SHRUBBERYCREATIONFORM_HPP_

#define TREE   "\n                     . . .\n\
                   .        .  .     ..    .\n\
                .                 .         .  .\n\
                                .\n\
                               .                ..\n\
               .          .            .              .\n\
               .            '.,        .               .\n\
               .              'b      *\n\
                .              '$    #.                ..\n\
               .    .           $:   #:               .\n\
             ..      .  ..      *#  @):        .   . .\n\
                          .     :@,@):   ,.**:'   .\n\
              .      .,         :@@*: ..**'      .   .\n\
                       '#o.    .:(@'.@*''  .\n\
               .  .       'bq,..:,@@*'   ,*      .  .\n\
                          ,p$q8,:@)'  .p*'      .\n\
                   .     '  . '@@Pp@@*'    .  .\n\
                    .  . ..    Y7'.'     .  .\n\
                              :@):.\n\
                             .:@:'.\n\
                           .::(@:."

#include <fstream>
#include <iostream>
#include <string>

#include "./Form.hpp"

class ShrubberyCreationForm : public Form {
 public:
    ShrubberyCreationForm(void);
    explicit ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm&   operator=(const ShrubberyCreationForm&);

    void        execute(const Bureaucrat& executor) const;

 private:
    std::string      _target;
};

#endif /* MODULE_05_EX02_INCLUDES_SHRUBBERYCREATIONFORM_HPP_ */
