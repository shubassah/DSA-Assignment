#include <iostream>
#include <cstdlib>   
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % SIZE == front);
}


void enqueue(int value) {
    if (isFull()) {
        cout << "\nQueue is FULL! Cannot insert.\n";
    } else {
        if (front == -1) {     
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = value;
        cout << "\nInserted " << value << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "\nQueue is EMPTY! Cannot delete.\n";
    } else {
        cout << "\nDeleted " << queue[front] << endl;
        if (front == rear) {
            
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
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
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
}


int main() {
    int choice, value;
    while (true) {
        cout << "\n---- Circular Queue Menu ----";
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
