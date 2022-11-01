#include <iostream>
#include <iterator>
#include <type_traits>
#include <assert.h>
#include "my_stack.hpp"

using namespace std;

template<typename T> void printStack(Stack<T> &stack);
template<typename T> ostream& operator<<(ostream& stream, Stack<T> &stack);

// driver code
int main()
{
    // Exercise 2 Driver code
    cout << "----------------------------- Testing Ex2: -----------------------------" << endl;
    Stack<int> stack;
    stack.push(34); stack.push(-34); stack.push(67);
    stack.push(234); stack.push(0); stack.push(18);

    cout << "Left most element represnts the bottom element, right most represents the top element" << endl;
    cout << stack << endl;
    
    assert(stack.size() == 6);

    cout << "Pop once ..." << endl;
    stack.pop();

    assert(stack.top() == 0);
    cout << "Top Element: " << stack.top() << endl;

    assert(stack.empty() == false);
    cout << stack << endl;
    cout << "IsEmpty? " << (stack.empty() ? "Yes" : "No") << endl;

    cout << "remove all elements..." << endl;
    while (!stack.empty()) {
        stack.pop();
    }

    assert(stack.empty() == true);
    cout << "IsEmpty? " << (stack.empty() ? "Yes" : "No") << endl;

    stack.pop(); // does nothing
    cout << stack.top() << endl; // gives an error or an expected behavior

    // Exercise 3 driver Code
    cout << endl << endl;
    cout << "----------------------------- Testing Ex3: -----------------------------" << endl;

    Stack<int> a;
    a.push(1); a.push(2);
    cout << a << endl;

    Stack<int> b;
    b.push(3); b.push(4);
    cout << b << endl;

    Stack<int> c = a + b;
    cout << c << endl;
    cout << c.top() << endl;
    return 0;
}

/*
    description:
        check if the stack is empty or not
    returns:
        true, if the stack is empty. False otherwise.
*/
template<typename T> bool Stack<T>::empty() const {
    return this->list.empty();
}

/*
    description:
        pushes an element to the stack
*/
template<typename T> void Stack<T>::push(const T &item) {
    this->list.emplace_front(item);
}

/*
    returns:
        the element at the top of the stack
*/
template<typename T> const T Stack<T>::top() const {
    return this->list.front();
}

/*
    description:
        removes an element from the top of the stack
        does nothing if the stack is empty
*/
template<typename T> void Stack<T>::pop() {
    if (this->empty()) return;
    this->list.pop_front();
}

/*
    returns:
        number of elements in the stack
*/
template<typename T> int Stack<T>::size() const {
    return this->list.size();
}

/*
    description:
        prints the content of the stack recursively from bottom to top
        prints nothing if the stack is empty or null
*/
template<typename T> void printStack(Stack<T> &stack) {
    if (stack.empty()) {
        return;
    }

    // get the top element
    T current = stack.top();
    // pop the top element
    stack.pop();

    // recursively call printStack til the stack is empty
    printStack(stack);

    // print current element
    cout << current << " ";

    // push back the element
    stack.push(current);
}

template<typename T> ostream& operator<<(ostream& stream, Stack<T> &stack) {
    printStack(stack);
    return stream;
}


/*
    description:
        a friend function which overloads the + operator
        to merge two stacks
    returns:
        a pointer to new stack with both stack1 and stack2 elements merged in order
*/
template<typename T> Stack<T> operator+(Stack<T> &stack1, Stack<T> &stack2) {
    Stack<T> *result = new Stack<T>();
    // iterating through the private list (we can do that since we have friendship), then
    // push stack1 content to result stack

    // since in the push implementation
    // behind the scenes the push added to the front of the list
    // you need to push starting from the back of the list
    // so that the front will be at the top
    for (auto it = stack1.list.rbegin(); it != stack1.list.rend(); ++it) {
        result->push(*it);
    }   
    // push stack2 content to result stack
    for (auto it = stack2.list.rbegin(); it != stack2.list.rend(); ++it) {
        result->push(*it);
    }

    return *result;
}