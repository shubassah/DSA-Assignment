#include <iostream>
using namespace std;
int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;  
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }
    return low + 1; 
}

int main() {
    int n;
    cout << "Enter the size of elememt: ";
    cin >> n;

    int arr[100];
    cout << "Enter the element: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

   
    cout << "Missing number is: " << findMissingBinary(arr, n) << endl;

    return 0;
}
