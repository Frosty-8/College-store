#include<iostream>
using namespace std;

struct node{
    double data;
    node *link;
};
class stack{
    node *head;
    public:
    stack(){
        head=NULL;
    }
    void push(double x){
        node *t=new node;
        t->data=x;
        t->link=head;
        head=t;
    }
    double pop();
    int isempty(){
        return head==NULL;
    }
};

double stack::pop(){
    if(head==NULL){
        cout<<"";
        return -1;
    }
    double val = head->data;
    node *t = head;
    head = head->link;
    delete t;
    return val;
}


int isoperand(char symb){
    if((symb>='A' && symb<='Z' || symb>='a' && symb<='z'|| symb >='0' && symb <='9')){
        return 1;
    }else{
        return 0;
    }
}

double eval(char pe[80]){
    int i;
    char symb;
    double op1,op2,res,x;
    stack s1;

    for(i=0;pe[i]!='\0';i++){
        symb=pe[i];
        if(isoperand(symb)){
            if(isdigit(symb)){
                s1.push(symb - '0');
            }else{
                cout<<"Enter value of : " <<symb;
                cin>>x;
                s1.push(x);
            }
        }else{
            op2=s1.pop();
            op1=s1.pop();
            switch(symb){
                case '+': res=op1+op2; break;

                case '-': res = op1-op2; break;

                case '*': res = op1*op2; break;

                case '/': res = op1/op2; break;

                default: cout<<"Error";
            }
            s1.push(res);
        }
    }
    return (s1.pop());
}



int main(){
    char postex[80];
    double result;
    cout<<"Enter a valid postfix expression : ";
    cin>>postex;
    result = eval(postex);
    cout<<"Result = "<<result;
}