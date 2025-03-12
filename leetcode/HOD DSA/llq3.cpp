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
    linklist(){
        head=NULL;
    }  // Initialize head to NULL in constructor
    
    ~linklist(){}
    void create();
    float find();
    void negative();
    void display();
    void reverse();
    void single();
    int search(int key);
};

void linklist::create() {
    Node *nn, *temp;
    int n, i;
    cout << "Enter no. of nodes: ";
    cin >> n;
    
    for (i = 0; i < n; i++) {
        nn = new Node; // Allocate memory for new node
        cout << "\nEnter data for node: ";
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
    
    cout << "List created.\n" << endl;
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
        cout<<"List is empty\n"<<endl;
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
    while(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
} 

void linklist::single(){
    if(head==NULL){
        cout<<"List is empty\n"<<endl;
        return;
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

int linklist::search(int key){
    Node *t=head;

    while(t!=NULL){
        if(t->data==key){
            cout<<"key found";
            return key;
        }
        t=t->link;
    }
    cout<<"key not found\n";

    // while(t->data!=key && t!=NULL){
    //     t=t->link;
    // }
    // if(t!=NULL){
    //     cout<<"key found\n";
    // }else{
    //     cout<<"Not Found";
    // }

    // while( t!=NULL &&  t->data!=key) this is solution for "segmentation error"   && does not evaluates 
    // the second condition if first condition is false
}

int main() {
    linklist lst; // Create a linked list object
    int key;
    
    lst.create();
    lst.display();

    // cout<<"\nEnter the key : ";
    // cin>>key;
    // lst.search(key);

    // lst.single();
    // lst.display();

    lst.reverse();
    lst.display();


    // int i=5,j=3;
    // if(i<9 && j=4){
    //     cout<<"Hello";
    // }else{
    //     cout<<"World";
    // }
}