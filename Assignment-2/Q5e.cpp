#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int sym[n*(n+1)/2];
    cout << "Enter elements row by row : ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> sym[i];

    cout << "Symmetric Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << sym[k++] << " ";
        }
        for (int j = i+1; j < n; j++) {
            cout << sym[j*(j+1)/2 + i] << " ";  // use symmetry
        }
        cout << endl;
    }
    return 0;
}
