#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *link;
};

class linklist{
    Node *head;
public:
    linklist(){
        head=NULL;
    }
    
    ~linklist(){
        if (head == NULL) return;

        Node *current = head;
        Node *next;

        do {
            next = current->link;
            delete current;
            current = next;
        } while (current != head);

        head = NULL;
    }

    void create();
    void display();
    void reverse();
    void addatrear();
    void deleterear();
};

void linklist::create(){
    Node *nn, *temp;
    int n, i;
    cout<< " Enter the no. of nodes : ";
    cin>>n;

    if(n==0){
        cout<<" List cannot be created ";
        return; 
    }

    for(i=0;i<n;i++){
        nn = new Node;
        cout << " \n Enter data for node : " ;
        cin>>nn->data;
        cout<<nn->data<< " stored in node "<<i<<endl;
        
        nn->link = nullptr;

        if(i==0){
            head = nn;
            temp = nn;
        }else{
            temp->link = nn;
            temp = nn;
        }
    }
    temp->link = head;

    cout<< " List created. \n "<<endl;
}

void linklist::display(){
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node *t = head;
    do {
        cout << t->data << " -> ";
        t = t->link;
    } while (t != head); 

    cout << head->data << endl; 
}

void linklist::reverse(){
    if(head==NULL) return;

    Node *prev=NULL;
    Node *curr=head;
    Node *next=NULL;
    Node *tail=head;
    do{
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }while(curr!=head);
    head->link=prev;
    head=prev;
}

void linklist::addatrear(){
    // If list is empty, create a new node as the head
    if(head == NULL){
        Node *nn = new Node;
        cout << "Enter the node to be inserted at rear : ";
        cin >> nn->data;
        head = nn;
        nn->link = head;
        return;
    }

    // Create new node
    Node *nn = new Node;
    cout << "Enter the node to be inserted at rear : ";
    cin >> nn->data;

    // Find the last node
    Node *t = head;
    while(t->link != head){
        t = t->link;
    }

    // Insert the new node
    nn->link = head;  // New node points to head
    t->link = nn;     // Last node points to new node
}

void linklist::deleterear(){
    // If list is empty
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    
    // If only one node
    if(head->link == head){
        delete head;
        head = NULL;
        return;
    }

    // Find the last and second-to-last nodes
    Node *t = head;
    Node *prev = NULL;

    // Traverse until we reach the last node
    while(t->link != head){
        prev = t;
        t = t->link;
    }

    // Disconnect the last node
    prev->link = head;
    
    // Delete the last node
    delete t;
}

int main(){
    linklist lst;

    lst.create();
    cout << "Original List: ";
    lst.display();

    lst.reverse();
    cout << "Reversed List: ";
    lst.display();

    lst.addatrear();
    cout << "List after adding at rear: ";
    lst.display();

    lst.deleterear();
    cout << "List after deleting rear: ";
    lst.display();

    return 0;
}