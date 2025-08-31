#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, result="";
    cout << "Enter a string: ";
    cin>>str;

    for(char c : str) {
        char ch = tolower(c);
        if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u')
            result += c;
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}

