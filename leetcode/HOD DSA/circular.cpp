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
        
        nn->link = nullptr; // Initialize link to nullptr

        if(i==0){
            head = nn; // First node becomes head
            temp = nn; // Temp points to the head
        }else{
            temp->link = nn; // Link previous node to current
            temp = nn; // Move temp to current node
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

int main(){
    linklist lst;

    lst.create();
    lst.display();

    lst.reverse();
    lst.display();
}
