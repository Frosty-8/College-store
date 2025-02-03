#include<iostream>
#include <climits>
using namespace std;

int getMin(int num[],int n){
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini,num[i]);

        // if(num[i]<mini){
        //     mini = num[i];
        // }
    }
    return mini;
}

int getMax(int num[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,num[i]);

        // if(num[i]>maxi){
        //     maxi = num[i];
        // }
    }
    return maxi;
}
int main(){
    int num[] = {11,2,3,4,5,6,7,8,9,10};
    int n = sizeof(num)/sizeof(num[0]);
    cout<<"Minimum Element is : "<<getMin(num,n)<<endl;
    cout<<"Maximum Element is : "<<getMax(num,n)<<endl;
    return 0;

}