// TIME COMPLEXITY FOR BST IS O(n log n) for insertion and deletion

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class BST
{
    Node *root;

    void deleteTree(Node *node)
    {
        if (node == NULL)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        deleteTree(root);
        root == NULL;
    }
    void create();
    void display();
    void inOrder(Node *t)
    {
        if (t == NULL)
            return;
        inOrder(t->left);
        cout << t->data << " ";
        inOrder(t->right);
    }
    void insertdata();
    Node *insert(Node *t, int x)
    {
        // here we are returning pointer of the node so that we can assign it to the left or right of the parent node
        if (t == NULL)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            return t;
        }
        if (x < t->data)
        {
            t->left = insert(t->left, x);
        }
        else if (x > t->data)
        {
            t->right = insert(t->right, x);
        }
        return t;
    }
    // void deleteOne();
};

class Stack{
    Node *a[80];
    int top;
    public:
    Stack(){
        top=-1;
    }
    ~Stack(){
        top=-1;
    }
    void push(Node *t){
        a[++top] = t;
    }
    Node *pop(){
        return a[top--];
    }
    int empty(){
        top=-1 ? return 1 : return 0;
    }
};

void preOrder(Node *t){
    Stack s;
    while(t!=NULL){
        cout<<t->data<<" ";
        s.push(t);
        t=t->left;
    }
    while(!s.empty()){
        t = s.pop();
        cout<<t->data<<" ";
        t = t->right;
        while(t!=NULL){
            cout<<t->data<<" ";
            s.push(t);
            t=t->left;
        }
    }
}

void inOrder(Node *t){
    Stack s;
    while(t!=NULL){
        s.push(t);
        t=t->left;
    }
    while(!s.empty()){
        t = s.pop();
        cout<<t->data<<" ";
        t = t->right;
        while(t!=NULL){
            s.push(t);
            t=t->left;
        }
    }
}

// void BST::create()
// {
//     int n, i;
//     cout << "Enter the no .of nodes : ";
//     cin >> n;
//     Node *nn, *temp, *parent;
//     for (i = 0; i < n; i++)
//     {
//         nn = new Node;
//         if (nn == NULL)
//         {
//             cout << "Memory error ";
//             return;
//         }
//         cout << "Enter the data : ";
//         cin >> nn->data;
//         nn->left = nn->right = NULL;

//         if (root == NULL)
//         {
//             root = nn;
//             continue;
//         }
//         else
//         {
//             temp = root;
//             while (temp != NULL)
//             {
//                 parent = temp;
//                 if (nn->data < temp->data)
//                 {
//                     temp = temp->left;
//                 }
//                 else
//                 {
//                     temp = temp->right;
//                 }
//             }
//             if (nn->data > parent->data)
//             {
//                 parent->right = nn;
//             }
//             else
//             {
//                 parent->left = nn;
//             }
//         }
//     }
// }

// void BST::display()
// {
//     if (root == NULL)
//     {
//         cout << "Tree is empty";
//     }
//     cout << "Inorder Traversal : ";
//     inOrder(root);
//     cout << endl;
// }
// void BST::insertdata()
// {
//     int x;
//     cout << "Enter the data to be inserted : ";
//     cin >> x;
//     insert(root, x);
// }
// void BST::deleteOne(){
//     int key;
//     Node *temp = root; Node *parent = NULL;
//     cout<<"Enter th key to be found : ";
//     cin>>key;
//     while(temp!=NULL && temp->data!=key){
//         parent = temp;
//         if(key<temp->data){
//             temp = temp->left;
//         }else{
//             temp = temp->right;
//         }
//     }cout<<temp->data<<" Key found .";

//     if(temp->left == NULL && temp->right == NULL){
//         delete temp;
//     }
//     else if(temp->left == NULL && temp->right != NULL){
//         cout << temp->data<<"has only right child and is a successor";
//     }
//     else if(temp->left != NULL && temp->right == NULL){
//         return;
        
//     }
//     else if(temp->left != NULL && temp->right != NULL){
//         cout<<"Temp has two children";
//         Node *succ = temp->right;
//         while(succ->left!=NULL){
//             succ = succ->left;
//         }
//     }
// }

int main()
{
    // BST b;
    // b.create();
    // b.display();
    // b.insertdata();
    // b.display();

    // b.deleteOne();


    return 0;
}