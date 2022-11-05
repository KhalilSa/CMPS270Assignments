#ifndef my_stack_h
#define my_stack_h

#include <list>

template<typename T> 
class Stack;

template<typename T>
Stack<T> operator+(Stack<T> &stack1, Stack<T> &stack2);

template<typename T> class Stack {
    friend Stack operator+ <>(Stack &stack1, Stack &stack2);
    private:
        std::list<T> list;

    public:
        bool empty() const;
        void push(const T &item);
        const T top() const;
        void pop();
        int size() const;
};

#endif