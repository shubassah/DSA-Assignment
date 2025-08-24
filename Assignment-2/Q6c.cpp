#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter non-zero elements in A and B: ";
    cin >> n1 >> n2;

    int A[100][3], B[100][3];
    cout << "Enter A (row col val):\n";
    for (int i = 0; i < n1; i++) 
    cin >> A[i][0] >> A[i][1] >> A[i][2];
    cout << "Enter B (row col val):\n";
    for (int i = 0; i < n2; i++) 
    cin >> B[i][0] >> B[i][1] >> B[i][2];

    cout << "\nMultiplication Result:\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (A[i][1] == B[j][0]) {
                cout << A[i][0] << " " << B[j][1] << " " << A[i][2] * B[j][2] << endl;
            }
        }
    }
    return 0;
}
