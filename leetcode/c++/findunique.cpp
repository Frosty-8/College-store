#include<iostream>
using namespace std;

int findunique(int *arr,int size){
    int ans = 0;

    for(int i =0;i<size;i++){
        ans = ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[7] = {1,2,2,1,5,5,7};

    cout<<" Unique element is : "<<findunique(arr,7);

}