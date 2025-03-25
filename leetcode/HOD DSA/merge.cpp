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
    void displayLinear();
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

        nn->link = nullptr;

        if (i == 0)
        {
            head = nn;
            temp = nn;
        }
        else
        {
            temp->link = nn;
            temp = nn;
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

void linklist::displayLinear()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *t = head;
    Node *first = head;
    int count = 0;
    int maxCount = 1000;

    do
    {
        cout << t->data << " -> ";
        t = t->link;
        count++;
    } while (t != first && count < maxCount);

    cout << "NULL" << endl;
}

void linklist::merge(linklist &x, linklist &y)
{
    Node *x1 = x.head;
    Node *y1 = y.head;
    Node *temp = NULL;

    if(x1 == NULL){
        head = y1;
        return;
    }

    if(y1 == NULL){
        head = x1;
        return;
    }

    // Reset to start of lists
    Node *x_start = x1;
    Node *y_start = y1;

    do {
        Node *nn = new Node;
        
        if(x1->data <= y1->data){
            nn->data = x1->data;
            x1 = x1->link;
        }
        else{
            nn->data = y1->data;
            y1 = y1->link;
        }

        // Create first node of merged list
        if(head == NULL){
            head = nn;
            temp = nn;
        }
        else{
            temp->link = nn;
            temp = nn;
        }

        // Stop if we've gone through entire lists
        if(x1 == x_start || y1 == y_start)
            break;
    } while(true);

    // Add remaining elements from x list if any
    while(x1 != x_start){
        Node *nn = new Node;
        nn->data = x1->data;
        temp->link = nn;
        temp = nn;
        x1 = x1->link;
    }

    // Add remaining elements from y list if any
    while(y1 != y_start){
        Node *nn = new Node;
        nn->data = y1->data;
        temp->link = nn;
        temp = nn;
        y1 = y1->link;
    }

    // Make list circular
    if(temp != NULL)
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
    lst3.displayLinear();
    return 0;
}