#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter non-zero elements in A and B: ";
    cin >> n1 >> n2;

    int A[100][3], B[100][3], C[200][3];
    cout << "Enter A row col val:\n";
    for (int i = 0; i < n1; i++) 
    cin >> A[i][0] >> A[i][1] >> A[i][2];
    
    cout << "Enter B (row col val):\n";
    for (int i = 0; i < n2; i++) 
    cin >> B[i][0] >> B[i][1] >> B[i][2];

    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(A[i][0]==B[j][0] && A[i][1]==B[j][1]){
            C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]+B[j][2];
            i++; j++; k++;
        }
        else if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1]))
            C[k][0]=A[i][0], C[k][1]=A[i][1], C[k][2]=A[i][2], i++, k++;
        else
            C[k][0]=B[j][0], C[k][1]=B[j][1], C[k][2]=B[j][2], j++, k++;
    }
    while(i<n1) 
    C[k][0]=A[i][0],
    C[k][1]=A[i][1],
    C[k][2]=A[i][2],
    i++,
    k++;
    while(j<n2) 
    C[k][0]=B[j][0],
    C[k][1]=B[j][1],
    C[k][2]=B[j][2],
    j++,
    k++;

    cout << "\nAddition Result:\n";
    for(int t=0;t<k;t++) 
    cout<<C[t][0]<<" "<<C[t][1]<<" "<<C[t][2]<<endl;
}
