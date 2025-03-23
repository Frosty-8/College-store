#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *link;
};

class doublylist{
    Node* head;
public:
    doublylist(){
        head=NULL;
    }
    ~doublylist(){
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
    void display();
    void insertatHead(int x);
};

void doublylist::create(){
    Node *nn, *temp;
    int n,i;
    cout<<"Enter no .of nodes : ";
    cin>>n;

    if(n==0){
        cout<<"Link cannot be created";
    }
    if(n!=0){
        for(i=0;i<n;i++){
            nn = new Node;
            cout<< "\n Enter data for node : ";
            cin>>nn->data;
            cout<<nn->data<<" stored in node "<<i<<endl;
            nn->link=NULL;

            if(i==0){
                head=nn;
                temp=nn;
            }else{
                temp->link = nn;
                temp = nn;
            }
        }
        cout<< " List created. \n" << endl;
    }
}

void doublylist::display(){
    Node *t = head;
    while(t!=NULL){
        cout<<t->data<<  " <-> ";
        t=t->link;
    }
    cout<<" X "<<endl;
}
void doublylist::insertatHead(int x){
    Node *t = new Node;
    t->data = x;
    t->link = head;
    head=t;
}

int main(){
    doublylist lst;

    lst.create();
    lst.display();

    lst.insertatHead(7);
    lst.display();
}