#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;         
    queue<int> firstHalf; 
    queue<int> result;    

    int n, x;
    cout << "Enter even number of elements: ";
    cin >> n;

    if (n <= 0) return 0;
    if (n % 2 != 0) {
        cerr << "Please enter an even number of elements.\n";
        return 1;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        q.push(x);       
    }

    int half = n / 2;

    
    for (int i = 0; i < half; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        result.push(firstHalf.front());
        firstHalf.pop();

        result.push(q.front());
        q.pop();
    }

   
    cout << "Interleaved queue:\n";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << "\n";
    return 0;
}
