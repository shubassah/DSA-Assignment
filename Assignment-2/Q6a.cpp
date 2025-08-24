#include <iostream>
using namespace std;

int main() {
    int r, c, n;
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> r >> c >> n;

    int mat[100][3];   
    cout << "Enter row col value:\n";
    for (int i = 0; i < n; i++)
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];

    cout << "\nTranspose:\n";
    for (int i = 0; i < n; i++)
        cout << mat[i][1] << " " << mat[i][0] << " " << mat[i][2] << endl;

    return 0;
}
