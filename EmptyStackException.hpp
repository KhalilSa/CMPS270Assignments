// I was thinking of throwing this class exception in case pop or top failed
// but the specification only requires to do nothing in that case
// So I decided to leave this header anyways

#ifndef EmptyStackException_h
#define EmptyStackException_h

#include <exception>

class EmptyStackException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Stack is empty";
  }
};

#endif