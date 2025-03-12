#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
};

class linklist {
    Node *head; // Declare head pointer
public:
    linklist() : head(NULL) {} // Initialize head to NULL in constructor
    void create();
    float find();
};

void linklist::create() {
    Node *nn, *temp;
    int n, i;
    cout << "Enter no. of nodes: " << endl;
    cin >> n;
    
    for (i = 0; i < n; i++) {
        nn = new Node; // Allocate memory for new node
        cout << "Enter data for node: ";
        cin >> nn->data; // Input data for the node
        
        nn->link = NULL; // Ensure new node's link is NULL
        
        if (i == 0) {
            head = nn; // First node becomes the head
            temp = nn; // Set temp to the first node
        } else {
            temp->link = nn; // Link the previous node to the new node
            temp = nn; // Move temp to the new node
        }
    }
    
    cout << "List created." << endl;
}

float linklist::find() {
    Node *t = head; // Start from the head
    float s = 0; // Initialize sum to 0
    
    while (t != NULL) { // Traverse the list
        s += t->data; // Add current node's data to sum
        t = t->link; // Move to the next node
    }
    
    return s; // Return the total sum of data
}

int main() {
    linklist lst; // Create a linked list object
    lst.create(); // Create the linked list
    float s = lst.find(); // Find the sum of all nodes' data
    cout << "Sum of all nodes: " << s << endl; // Output the sum
}
