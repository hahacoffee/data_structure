#include "function.h"
#include <iostream>
#include <string>
using namespace std;

/*
In partial judge problem, you need to compile two .cpp files and a header file together.
For compile multiple .cpp files and .h headers, please refer to the following tutorial.
Chinese: 
https://github.com/htchen/i2p-nthu/blob/master/%E7%A8%8B%E5%BC%8F%E8%A8%AD%E8%A8%88%E4%B8%80/%E5%A6%82%E4%BD%95compile%E5%A4%9A%E5%80%8B%E6%AA%94%E6%A1%88/%E5%A6%82%E4%BD%95%20compile%20%E5%A4%9A%E5%80%8B%E6%AA%94%E6%A1%88.md
English (terminal command):
https://stackoverflow.com/questions/3202136/using-g-to-compile-multiple-cpp-and-h-files

For Dev C++ or other IDE, please search for the Internet. 
*/

int main(void) {
    int L, C;
    string command;
    
    cin >> L >> C;
    
    for (int i = 0; i < C; i++) {
        cin >> command;

        if (command == "INSERT") {
            insert(L);
        } 
        else if (command == "BOTTOM_ROW") {
            // The function name of "first_row" is actually misleading.
            // Actually, you need to implement card type of "BOTTOM_ROW" in this function.
            // Also, in partial judge header, we purposely design the function to have return type of string,
            // although we do not have a variable to receive the return value here.
            // You can think of the reason for having such design.
            first_row(L, true);
        } 
        else if (command == "QUERY") {
            query(L);
        } 
        else if (command == "FLUSH") {
            flush();
        }
        else if (command == "RESET") {
            reset(L);
        }
    }
}