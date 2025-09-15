#include <iostream>
#include <string>   
using namespace std;


void genBin(int n) {
    for (int i = 1; i <= n; i++) {
        string s;          
        for (int x = i; x; x >>= 1) {
            s = (x & 1 ? "1" : "0") + s;
        }
        cout << s << endl; 
    }
}

int main() {
    genBin(5);   
    return 0;
}
