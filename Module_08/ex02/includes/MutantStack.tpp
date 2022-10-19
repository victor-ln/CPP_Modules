#include "./MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>::stack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>::stack(src) {}

template<typename T>
MutantStack<T>::~MutantStack(void) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& src) {
    std::stack<T> *a = this;
    std::stack<T> *b = &const_cast<MutantStack<T>&>(src);

    *a = *b;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)  {
    return iterator(this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
    return iterator(this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void)  {
    return const_iterator(this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) {
    return const_iterator(this->c.rend());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)  {
    return reverse_iterator(this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void) {
    return reverse_iterator(this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void)  {
    return const_reverse_iterator(this->c.crbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void) {
    return const_reverse_iterator(this->c.crend());
}
