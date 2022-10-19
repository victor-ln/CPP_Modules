#include "../includes/MutantStack.hpp"
#include <list>

int main(void) {
    MutantStack<int>    mstack;
    std::list<int>      list;

    mstack.push(5);
    mstack.push(17);
    list.push_front(5);
    list.push_front(17);
    std::cout << mstack.top() << std::endl;
    std::cout << list.front() << std::endl;
    mstack.pop();
    list.pop_front();
    std::cout << "Size:\t" << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    list.push_front(3);
    list.push_front(5);
    list.push_front(737);
    list.push_front(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "\n\tItering elements\n\n";
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int>::iterator itS = list.begin();
    std::list<int>::iterator iteS = list.end();
    ++itS;
    --itS;
    std::cout << "\n\tItering elements\n\n";
    while (itS != iteS) {
        std::cout << *itS << std::endl;
        ++itS;
    }
    std::stack<int> s(mstack);
    return 0;
}
