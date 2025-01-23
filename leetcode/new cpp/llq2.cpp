#include <iostream>
#include<vector>
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
    void negative();
    void display();
    void reverse();
    void single();
};

void linklist::create() {
    Node *nn, *temp;
    int n, i;
    cout << "Enter no. of nodes: ";
    cin >> n;
    
    for (i = 0; i < n; i++) {
        nn = new Node; // Allocate memory for new node
        cout << "Enter data for node: ";
        cin >> nn->data; // Input data for the node
        cout << nn->data << " stored in node " << i << endl;
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

void linklist::display(){
    Node *t = head;
    while(t!=NULL){
        cout<<t->data<<" -> ";
        t=t->link;
    }
    cout<<" X ";
}


float linklist::find() {
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    Node *t=head;
    int maxval = t->data;
    while(t!=NULL){
        if(t->data < maxval){
            maxval = t->data;
        }
        t=t->link;
    }
    return maxval;
}

void linklist::negative(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    Node *t=head;
    while(t!=NULL){
        if(t->data < 0){
            cout<< t->data << " ";
        }
        t=t->link;
    }
}

void linklist::reverse(){
    Node *prev,*curr,*next;
    prev=NULL;
    curr=head;
    if(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
} 

void linklist::single(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    vector<int> data;
    Node *temp=head;
    while(temp!=NULL){
        data.push_back(temp->data);
        temp=temp->link;
    }
    int n =data.size();
    for(int i=0;i< n/2 ;i++){
        swap(data[i],data[n-i-1]);
    }
    temp=head;
    int index=0;
    while(temp!=NULL){
        temp->data=data[index++];
        temp=temp->link;
    }
    
}


int main() {
    linklist lst; // Create a linked list object
    lst.create(); 
    
    
    lst.negative(); 
    
    // Output the sum
    
    lst.single();
    lst.display();
    // lst.reverse();
    
}