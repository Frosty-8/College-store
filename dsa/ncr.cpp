#include<iostream>
using namespace std;
int fact (int n){
    int fact = 1;

    for (int i=1;i<=n;i++){
        fact = fact * i;
    }
    return fact;
}

int nCr(int n,int r){
    int num = fact(n);
    int denum = fact(r) * fact (n-r);
    return num/denum;
}

int main(){
    int n,r;
    cout << "enter the nos:" <<endl;
    cin>>n>>r;

    cout << "The answer is : "<<nCr(n,r)<<endl; 
}