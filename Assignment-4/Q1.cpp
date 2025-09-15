#include <iostream>
#include <cstdlib>  
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


bool isFull() {
    return (rear == SIZE - 1);
}

bool isEmpty() {
    return (front == -1 || front > rear);
}


void enqueue(int value) {
    if (isFull()) {
        cout << "\nqueue is full Cannot insert.\n";
    } else {
        if (front == -1)    
            front = 0;
        rear++;
        queue[rear] = value;
        cout << "\nInserted " << value << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "\nqueue is empty Cannot delete.\n";
    } else {
        cout << "\nDeleted " << queue[front] << endl;
        front++;
        
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void peek() {
    if (isEmpty()) {
        cout << "\nQueue is EMPTY!\n";
    } else {
        cout << "\nFront element is: " << queue[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "\nQueue is EMPTY!\n";
    } else {
        cout << "\nQueue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}


int main() {
    int choice, value;
    while (true) {
        cout << "\nQueue Menu : ";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek (Front element)";
        cout << "\n4. Display";
        cout << "\n5. Check if Empty";
        cout << "\n6. Check if Full";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    cout << "\nQueue is EMPTY.\n";
                else
                    cout << "\nQueue is NOT empty.\n";
                break;
            case 6:
                if (isFull())
                    cout << "\nQueue is FULL.\n";
                else
                    cout << "\nQueue is NOT full.\n";
                break;
            case 7:
                exit(0);
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
    return 0;
}
