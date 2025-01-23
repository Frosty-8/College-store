#include<iostream>
#include<vector>
using namespace std;

int findduplicate(vector<int> &arr){
    int ans=0;

    for (int i =0;i<arr.size();i++){
        ans = ans^arr[i];
    }
    for(int i =1;i<arr.size();i++){
        ans=ans^i;
    }
    return ans;
}

int main(){
    vector<int> arr = {3,3,1,2,4,5};

    cout<<" Duplicate element is : "<<findduplicate(arr);
}

