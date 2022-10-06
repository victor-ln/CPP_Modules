/* Copyright © 2022 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_04_EX02_INCLUDES_BRAIN_HPP_
#define MODULE_04_EX02_INCLUDES_BRAIN_HPP_

#include <iostream>
#include <string>

class Brain {
 public:
    Brain(void);
    Brain(const Brain&);
    ~Brain(void);

    Brain&          operator=(const Brain&);

    void    removeIdea(const size_t);
    void    showIdeas(void) const;
    void    newIdea(const std::string&);

 private:
    std::string     _ideas[100];
    std::size_t     _lastIdea;
};

#endif /* MODULE_04_EX02_INCLUDES_BRAIN_HPP_ */
