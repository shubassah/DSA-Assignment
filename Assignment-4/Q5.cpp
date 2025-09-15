#include <iostream>
#include <queue>
using namespace std;

class Stack1Q {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (!q.empty()) return q.front();
        throw runtime_error("Stack is empty");
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack1Q st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << "\n";  // 30
    st.pop();
    cout << "Top after pop: " << st.top() << "\n"; // 20
    return 0;
}
