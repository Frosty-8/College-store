#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
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

    void push(char x);
    char pop();
    void display();
    char isempty() {
        return head == NULL;
    }
};

void Stack::push(char x) {
    Node *nn = new Node;
    if (nn == NULL) {
        cout << "Stack full";
        exit(0);
    }
    nn->data = x;
    nn->link = head;
    head = nn;
}

char Stack::pop() {  // Return the popped value
    if (isempty()) {
        cout << " No data ";
        exit(0);
    }

    Node *t = head;
    char poppedValue = t->data;  // Store data before deletion
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
    Stack S;
    
    string s = " automobile ";
    string t;

    for(int i=0;i<s.size();i++){
        S.push(s[i]);
    }
    // for(int i=0;i<s.size();i++){
    //     t+=S.pop();
    // }


    S.display();

    return 0;
}
