#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0;  
    int choice;

    while (true) {
        
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Size of elements: ";
            cin >> n;
            cout << "Enter " << n << " numbers: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        }
        else if (choice == 2) {
            cout << "Array: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (choice == 3) {
            int pos, val;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = val;
            n++;

            cout << "Array after insertion: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (choice == 4) {
            int pos;
            cout << "Enter position: ";
            cin >> pos;

            if (pos >= 0 && pos < n) {
                int deleted = arr[pos]; 
                for (int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;

                cout << "Deleted element: " << deleted << endl;
                cout << "Array after deletion: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 5) {
            int val, found = -1;
            cout << "Enter number to search: ";
            cin >> val;

            for (int i = 0; i < n; i++) {
                if (arr[i] == val) {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                cout << "Element " << val << " found at index " << found << endl;
            else
                cout << "Element not found!\n";
        }
        else if (choice == 6) {
            cout << "exit\n";
            break;
        }
        else {
            cout << "you are going too far\n";
        }
    }

    return 0;
}
