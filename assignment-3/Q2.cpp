#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> s;

   
    for(char c : str) {
        s.push(c);
    }

    
    string rev = "";
    while(!s.empty()) {
        rev += s.top();
        s.pop();
    }

    return rev;
}

int main() {
    string input = "DataStructure";
    cout << "Original String: " << input << endl;

    string output = reverseString(input);
    cout << "Reversed String: " << output << endl;

    return 0;
}
