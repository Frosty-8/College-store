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
    
    ~linklist(){
        Node *current = head;
        Node *next;
        while(current!=NULL){
            next = current->link;
            delete current;
            current=next;
        }
        head=NULL;
    }
    void create();
    float find();
    void negative();
    void display();
    void reverse();
    void single();
    int search(int key);
    void insertatHead(int x);
    int deletehead();
    void addrear(int y);
    int deleterear();
    int insertatpos(int x , int pos); 
};

void linklist::create() {
    Node *nn, *temp;
    int n, i;
    cout << "Enter no. of nodes: ";
    cin >> n;

    if(n==0){
        cout<<"List cannot be created";
    }
    if(n!=0){
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
}

void linklist::display(){
    Node *t = head;
    while(t!=NULL){
        cout<<t->data<<" -> ";
        t=t->link;
    }
    cout<<" X "<<endl;
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
        cout<<"List is empty\n"<<endl;
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

void linklist::insertatHead(int x){
    Node *t = new Node;
    t->data = x;
    t->link = head;
    head=t;

    // Node temp;
    // temp.data=x;
    // temp.link = head;
    // head=&temp;

}

int linklist::deletehead(){
    Node *t = head;
    head = t->link;
    t->link = NULL;
    delete t;
}

void linklist::addrear(int y){
    Node *nn = new Node;
    nn->data=y;
    nn->link = NULL;
    Node *t=head;
    while(t->link!=NULL){
        t=t->link;
    }t->link=nn;
}

int linklist::deleterear(){
    Node *t,*prev = NULL;
    t=head;
    int y;
    if(head==NULL){
        y=head->data;
        delete head;
        head=NULL;
        return y;
    }
    while(t->link!=NULL){
        prev=t;
        t=t->link;
    }prev->link=NULL;
    y=t->data;
    delete t;
}

int linklist::insertatpos(int x,int pos){
    Node *nn = new Node;
    nn->data=x;
    nn->link = NULL;

    if(pos == 1){
    nn->link = head;
    head=nn;
    return 0;
    }

    Node *t = head;
    for(int i=1;i<pos -1 && t!=NULL;i++){
        t=t->link;    
    }

    if(t==NULL){
        cout << "Position not found;"<<endl;
        delete nn;
        return -1;
    }
    nn->link = t->link;
    t->link = nn;
    return 0;
}



int main(){
    linklist lst; // Create a linked list object
    
    int choice;
    lst.create();
    lst.display();
    while(1){
        cout<<"1 -> Add front \n";
        cout<<"2 -> Delete front \n";
        cout<<"3 -> Add rear \n";
        cout<<"4 -> Delete rear \n";
        cout<<"5 -> Exit\n";
        cout<<"6 -> Add at position"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                int x;
                cout<<"\nElement to be inserted : ";
                cin>>x;
                lst.insertatHead(x);
                lst.display();
                break;
            
            case 2:
                lst.deletehead();
                lst.display();
                break;

            case 3:
                int y;
                cout << "Enter the element to add in rear : ";
                cin>>y;
                lst.addrear(y);
                lst.display();
                break;

            case 4:
                lst.deleterear();
                lst.display();
                break;

            case 5:
                cout<<"Exiting................";

            case 6:
                int z,pos;
                cout<<"Element to be inserted : ";
                cin>>z;
                cout<<"\nEnter the position : ";
                cin>>pos;

                lst.insertatpos(z,pos);
                lst.display();
        }break;
    }
}