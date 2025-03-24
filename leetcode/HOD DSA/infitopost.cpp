#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *link;
};

class Stack {
public:
    Node *head;
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
    bool isempty() {  // Changed return type to bool for clarity
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

bool isoperand(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    else{
        return false;
    }
}

int prcd(char c){
    switch(c){
        case '$': return 3;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        case '(': return 0;  // Added to handle parenthesis correctly
        default: return 0;
    }
}

void convert(char inf[80], char pf[80]){
    Stack S;
    char symb, st_symb;
    int i, j = 0;

    for(i = 0; inf[i] != '\0'; i++){
        symb = inf[i];
        if(isoperand(symb)){
            pf[j++] = symb;
        } else if(symb == '('){
            S.push(symb);
        } else if(symb == ')'){
            while(!S.isempty()){
                st_symb = S.pop();
                if(st_symb == '(') 
                    break;
                pf[j++] = st_symb;
            }
        } else {  // Operator
            while(!S.isempty() && prcd(S.head->data) >= prcd(symb)){
                pf[j++] = S.pop();
            }
            S.push(symb);
        }
    }
    
    // Pop any remaining operators from the stack
    while(!S.isempty()){
        pf[j++] = S.pop();
    }
    
    // Add null terminator to postfix expression
    pf[j] = '\0';
}

int main() {
    char infix[80], postfix[80];
    
    cout << "Enter infix expression: ";
    cin >> infix;
    
    convert(infix, postfix);
    
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}