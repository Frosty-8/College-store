#include<iostream>
using namespace std;

void insert(int arr[], int &len_arr, int n, int size){
    if(len_arr == size){
        cout<<"Array is full";
        return;
    }
     arr[len_arr]=n;
     len_arr++;

     for (int i = len_arr - 1;i>0;i--){
        if(arr[i-1]>arr[i]){ 
            swap(arr[i-1],arr[i]);
        }
        else{ 
            break;
        }
    return;
    }
}
int main(){
    int arr[5] = {2,3,4,5};
    int n;
    cout << "Enter the number to insert ";
    cin>>n;

    int len_arr = 4;
    insert(arr,len_arr,n,5);

    cout <<"Updated Array : ";
    for (int i=0;i<len_arr;i++){
        cout<<arr[i]<<" ";
    }

 return 0;   
}