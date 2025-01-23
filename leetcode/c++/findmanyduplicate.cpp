#include<bits/stdc++.h>
using namespace std;

vector<int> findduplicate(vector<int> &arr){
    int n = arr.size();
    vector<int> result;
    vector<int> freqArr(n);
    
    for(int i=0;i<n;i++){
        freqArr[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        if(freqArr[i]>1){
            result.push_back(i);
        }
    }

    if(result.empty()){
        cout<<"No duplicates found";
    }
    return result;
}

int main(){
    vector<int> arr = {3,3,4,5,6,6,1,7,2,4,5};

    vector<int> duplicates=findduplicate(arr);

    for(int element : duplicates){
        cout<<"Duplicate Elements are : "<<element<<" "<<endl;
    }
    return 0;
}