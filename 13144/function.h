#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <string>
using namespace std;

// TODO: Implement all member functions in BaseStack
template < class T >
class BaseStack
{
public:
    // Constructor
    BaseStack();

    // Destructor
    ~BaseStack();

    // Check if the stack is empty
    bool empty();

    // Return the size of the stack
    int size();

    // Return the top element
    T& top();

    // Insert a new element at top
    void push(const T& item);

    // Delete one element from top
    void pop();

private:
    T* _stack;
    int _top;
    int capacity;
};

// TODO: Implement all member functions in BaseQueue
template < class T >
class BaseQueue
{
public:
    // Constructor
    BaseQueue();

    // Destructor
    ~BaseQueue();

    // Check if the stack is empty
    bool empty();

    // Return the size of the queue
    int size();

    // Return the front element
    T& front();

    // Insert a new element at rear
    void push(const T& item);

    // Delete one element from front
    void pop();

private:
    T* _queue;
    int _front, _rear;
    int capacity;
};

// TODO: Implement five types of cards
// card type of "INSERT"
void insert(int L);

// card type of "BOTTOM_ROW"
// The function name of "first_row" is actually misleading.
// Actually, you need to implement card type of "BOTTOM_ROW" in this function.
// Also, we purposely design the function to have return type of string,
// although we do not have a variable to receive the return value in partial judge code.
// You can think of the reason for having such design.
string first_row(int L, bool print = false);

// card type of "QUERY"
void query(int L);

// card type of "FLUSH"
void flush();

// card type of "RESET"
void reset(int L);

// The codes bellow prevent you from importing C++ containers.
// Nothing needed to be implemented below.
// Do not modify the codes below.
#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif
