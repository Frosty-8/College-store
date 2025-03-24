#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *link;
};

class linklist
{
    Node *head;

public:
    linklist()
    {
        head = NULL;
    }

    ~linklist()
    {
        if (head == NULL)
            return;

        Node *current = head;
        Node *next;

        do
        {
            next = current->link;
            delete current;
            current = next;
        } while (current != head);

        head = NULL;
    }

    void create();
    void display();
    void reverse();
    void merge(linklist &x, linklist &y);
};

void linklist::create()
{
    Node *nn, *temp;
    int n, i;
    cout << " Enter the no. of nodes : ";
    cin >> n;

    if (n == 0)
    {
        cout << " List cannot be created ";
        return;
    }

    for (i = 0; i < n; i++)
    {
        nn = new Node;
        cout << " \n Enter data for node : ";
        cin >> nn->data;
        cout << nn->data << " stored in node " << i << endl;

        nn->link = nullptr; // Initialize link to nullptr

        if (i == 0)
        {
            head = nn; // First node becomes head
            temp = nn; // Temp points to the head
        }
        else
        {
            temp->link = nn; // Link previous node to current
            temp = nn;       // Move temp to current node
        }
    }
    temp->link = head;

    cout << " List created. \n " << endl;
}

void linklist::display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *t = head;
    do
    {
        cout << t->data << " -> ";
        t = t->link;
    } while (t != head);

    cout << " X " << endl;
}

void linklist::merge(linklist &x, linklist &y)
{
    Node *x1 = x.head;
    Node *y1 = y.head;
    Node *temp, *nn;

    if(x1 == NULL){
         head=y1;
        return;
    }

    if(y1 == NULL){
        head = x1;
        return;
    }
    do{
        nn = new Node;
        if(x1->data < y1->data){
            nn->data = x1->data;
            x1=x1->link;
        }else{
            nn->data = y1->data;
            y1=y1->link;
        }
        if(head==NULL){
            head=nn;
            temp=nn;
        }else{
            temp->link=nn;
            temp=nn;
        }

    }while(x1!=x.head & y1!=y.head);
    
    while(x1!=x.head){
        nn = new Node;
        nn->data=x1->data;
        temp->link=nn;
        temp=nn;
        x1=x1->link;
    }
    
    while(y1!=y.head){
        nn = new Node;
        nn->data=y1->data;
        temp->link=nn;
        temp=nn;
        y1=y1->link;
    }
    temp->link = head;  
}

int main()
{
    linklist lst1, lst2, lst3;
    lst1.create();
    lst1.display();

    lst2.create();
    lst2.display();

    lst3.merge(lst1, lst2);
    lst3.display();
    return 0;
}