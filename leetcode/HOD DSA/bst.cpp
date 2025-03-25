// TIME COMPLEXITY FOR BST IS O(n log n) for insertion and deletion

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

class BST{
    Node *root;

    void deleteTree(Node *node){
        if(node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    
    public:
        BST(){
            root = NULL;
        }
        ~BST(){
            deleteTree(root);
            root == NULL;
        }
    void create();
    void display();
    void inOrder(Node *t){
        if(t==NULL) return;
        inOrder(t->left);
        cout<<t->data<<" ";
        inOrder(t->right);
    }
    void insertdata();
    Node* insert(Node *t,int x){
        //here we are returning poointer of the node so that we can assign it to the left or right of the parent node
        if(t==NULL){
            t = new Node;
            t->data = x;
            t->left=t->right=NULL;
            return t;
        }
        if(x<t->data){
            t->left = insert(t->left ,x);
        }else if(x>t->data){
            t->right = insert(t->right,x);
        }
        return t;
    }
};

void BST::create(){
    int n,i;
    cout<<"Enter the no .of nodes : ";
    cin>>n;
    Node *nn , *temp,*parent;
    for(i=0;i<n;i++){
        nn = new Node;
        if(nn==NULL){
            cout<<"Memory error ";
            return;
        }
        cout<<"Enter the data : ";
        cin>>nn->data;
        nn->left = nn->right = NULL;

        if(root == NULL){
            root = nn;
            continue;
        }
        else{
            temp = root;
            while(temp!=NULL){
                parent = temp;
                    if(nn->data < temp->data){
                        temp = temp->left;
                    }else{
                        temp = temp->right;
                    }
                }
                if(nn->data > parent->data){
                    parent->right = nn;
                }else{
                    parent->left = nn;
                }
            }
        }
}

void BST::display(){
    if(root == NULL){
        cout<<"Tree is empty";
    }cout<<"Inorder Traversal : ";
    inOrder(root);
    cout<<endl;

}
void BST::insertdata(){
    int x;
    cout<<"Enter the data to be inserted : ";
    cin>>x;
    insert(root,x);
}


int main(){
    BST b;
    b.create();
    b.display();
    b.insertdata();
    b.display();
    return 0;
}