// create a linklist to store a 8bit binary no. and perform rotation operation as per the requirement of user

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
        Node *current = head;
        Node *next;
        while(current!=NULL){
            next=current->link;
            delete current;
            current=next;
        }
        head=NULL;
    }
    void create();
    void display();
    void lrotate(int n);
    void rrotate();
    int size();
    int toInteger();
};


// Time complexity is O(log n)
void linklist::create(){
    int n;
    Node *nn;
    cout<<" Enter number :";
    cin>>n;
    for(int i=n;i>0;i=i/2){
        // cout<<i%2<<"  ";
        nn = new Node;
        nn->data=i%2;
        nn->link=head;
        head=nn;
    }   
}

void linklist::display(){
    Node *t=head;
    while(t!=NULL){
        cout<<t->data<<" -> ";
        t=t->link;
    }
    cout<<"X"<<endl;
}

void linklist::lrotate(int n){
    if(head==NULL){
        cout<<"List is empty to rotate";
    }
    Node *t=head;Node *prev;
    for(int i=0;i<n;i++){
        prev = t;
        t=t->link;
    }
    while(t->link!=NULL){
        t=t->link;
    }
    t->link=head;
    head=prev->link;
    prev->link=NULL;
}
int linklist::size(){
    Node *temp=head;
    int s=0;
    while(temp!=NULL){
        temp=temp->link;
        s++;
    }
    return s;
}

void linklist::rrotate(){
    if(head==NULL){
        cout<<"List is empty to rotate";
    }
    int x;
    cout<<"Enter the no. to be right rotated : ";
    cin>>x;

    Node *t=head;
    Node *prev;
    x=size()-x;
    for(int i=0;i<x;i++){
        prev = t;
        t=t->link;
    }
    while(t->link!=NULL){
        t=t->link;
    }
    t->link=head;
    head=prev->link;
    prev->link=NULL;
}

int linklist::toInteger(){
    Node *temp =head;
    int ans=0;
    for(int i = size()-1;i>=0;i--){
        ans+= temp->data * pow(2,i);
        temp=temp->link;
    }
    return ans;
}

int main(){
    linklist lst;
    lst.create();
    lst.display();

    int n;
    cout<<"Enter the no. to do left rotate : ";
    cin>>n;

    lst.lrotate(n);
    lst.display();
    

    lst.rrotate();
    lst.display();    
    cout<<"The rotated integer is : "<<lst.toInteger()<<endl;
    
}