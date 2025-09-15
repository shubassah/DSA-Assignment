#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);          

    queue<char> q;
    int count[256] = {0};     
    cout << "Output: ";
    for (char ch : s) {
        if (ch == ' ') continue;   
        count[(unsigned char)ch]++;  
        q.push(ch);                 

        
        while (!q.empty() && count[(unsigned char)q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
    return 0;
}
