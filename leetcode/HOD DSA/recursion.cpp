#include<iostream>
using namespace std;

void disp(int n){
    if(n==0){
        return;
    }
    disp(n-1);
    cout<<"Hello"<<endl;
}

int display(int n){
    if(n==0){
        return 0;
    }
    int s=0;
    s = n + display(n-1);
    cout<<"sum is : "<<s<<endl;
    return(s); 
}

int power(int x,int y){
    if(y==0) return (1);

    int s = 1;
    s = x * power(x,y-1);
    cout << "answer is : "<<s<<endl;
    return s;
}

int fact(int n){
    if(n==0) return 1;

    int s=0;
    s = n * fact(n-1);
    cout<<s<<endl;
    return s;
}

int mode(int n){
    if(n==0) return (0);

    int s=0;
    int l;

    l=n%10;
    n=n/10;

    s = l + mode(n);
    cout<<"sum is : "<<s<<endl;
    return s;
}

int array(int a[],int n){
    if(n==0) return 1;

    int s=0;
    s=a[n-1]+array(a,n-1);
    return s;
}

int search(int a[],int n,int t){
    if(n==0) return 1;
    t=6;
    int s;
    s = a[n-1];
    if (s==t){
       cout<<"Element found";
    }
    else{
        cout<<"Not found";
    }
}

int main(){
    cout<<"Day : 12/03/25"<<endl;

    // cout<<"First base condition : ";
    // disp(5);
    // cout<<"\n";
    // cout<<"Second add the no.of n integers condition : ";
    // display(5);
    // cout<<"\n";
    // cout<<"Third add the no.of n integers like 123 = 6 condition : ";
    // mode(123);

    // cout<<"\n";
    // power(5,3);

    // cout <<"\n";
    // fact(7);

    int arr[5] = {5,6,7,3,1};
    // int s = array(arr,5);
    // cout<<s;
    int target;
    int ss = search(arr,5,target);
    cout<<ss;

}