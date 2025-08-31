#include <iostream>
using namespace std;

#define MAX 10
int stackArr[MAX];
int top = -1;

// Push operation
void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack is Full!" << endl;
    } else {
        stackArr[++top] = val;
        cout << val << " pushed into stack." << endl;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Popped element: " << stackArr[top--] << endl;
    }
}

// Check empty
void isEmpty() {
    if (top == -1) cout << "Stack is Empty!" << endl;
    else cout << "Stack is NOT Empty!" << endl;
}

// Check full
void isFull() {
    if (top == MAX - 1) cout << "Stack is Full!" << endl;
    else cout << "Stack is NOT Full!" << endl;
}

// Display
void display() {
    if (top == -1) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Stack elements (top → bottom): ";
        for (int i = top; i >= 0; i--) cout << stackArr[i] << " ";
        cout << endl;
    }
}

// Peek
void peek() {
    if (top == -1) cout << "Stack is Empty!" << endl;
    else cout << "Top element is: " << stackArr[top] << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\nMENU\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 7);

    return 0;
}

