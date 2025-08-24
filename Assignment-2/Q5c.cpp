#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int lower[n*(n+1)/2];
    cout << "Enter elements row by row : ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> lower[i];

    cout << "Lower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << lower[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
