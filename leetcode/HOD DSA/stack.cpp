#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *link;
};

class Stack {
    Node *head;

public:
    Stack() {
        head = NULL; // Fixed initialization
    }

    ~Stack() {
        while (head != NULL) {
            Node *temp = head;
            head = head->link;
            delete temp;
        }
    }

    void push(int x);
    int pop();
    void display();
    int isempty() {
        return head == NULL;
    }
};

void Stack::push(int x) {
    Node *nn = new Node;
    if (nn == NULL) {
        cout << "Stack full";
        exit(0);
    }
    nn->data = x;
    nn->link = head;
    head = nn;
}

int Stack::pop() {  // Return the popped value
    if (isempty()) {
        cout << " No data ";
        exit(0);
    }

    Node *t = head;
    int poppedValue = t->data;  // Store data before deletion
    head = head->link;
    delete t;

    return poppedValue; // Return the popped value
}

void Stack::display() {
    if (isempty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node *t = head;
    while (t != NULL) {
        cout << " | " << t->data << " | ";
        t = t->link;
    }
    cout << " X " << endl;
}

int main() {
    Stack s;

    s.push(10);
    s.push(12);
    s.push(11);
    s.push(22);
    s.display();

    cout << "Popped: " << s.pop() << endl;
    s.display();

    return 0;
}
