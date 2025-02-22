#include<iostream>
using namespace std;

void remove(int arr[],int &len_arr,int n){
    if(len_arr==0){
        cout<<"Array is empty";
        return;
    }
    for(int i=0;i<len_arr;i++){
        if(arr[i]==n){
            for(int j=i;j<len_arr-1;j++){
                arr[j]=arr[j+1];
            }
            len_arr--;
            i--;
        }       
    }
}

int main(){
    int arr[6] = {2,3,4,5,5,7};
    int n;
    cout << "Enter the number to remove : ";
    cin >> n;

    int len_arr = 6;
    remove(arr,len_arr,n);

    cout <<" Updated Array : ";
    for (int i=0;i<len_arr;i++){
        cout<<arr[i]<<" ";
    }
}