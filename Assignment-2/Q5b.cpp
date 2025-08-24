#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int tri[3*n - 2];  

    cout << "Enter elements of tri-diagonal (3n-2 values): ";
    for (int i = 0; i < 3*n - 2; i++) cin >> tri[i];

    cout << "Tri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i-j == 1) cout << tri[i-1] << " ";          
            else if (i == j) cout << tri[n-1 + i] << " ";   
            else if (j-i == 1) cout << tri[2*n-1 + i] << " "; 
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
