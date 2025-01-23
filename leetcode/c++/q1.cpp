#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    void uniqueOccurrences(vector<int>& arr) {
        map<int,int> frequency;

        for(int num : arr){
            frequency[num]++;
        }

        for(auto pair : frequency){
            cout<< "Element " << pair.first << " occurs " << pair.second << " times "<<endl;
        }
    }
};

int main(){
   vector<int> arr = {1,1,2,2,3,4,4};

   Solution s;
   s.uniqueOccurrences(arr);

    return 0;    
}

// #include <iostream>
// #include <vector>
// #include <map>
// #include <set>
// using namespace std;

// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         map<int, int> frequency; // Map to count occurrences

//         // Count occurrences of each element
//         for (int num : arr) {
//             frequency[num]++;
//         }

//         set<int> occurrences; // Set to store unique occurrence counts

//         // Check if all occurrence counts are unique
//         for (auto pair : frequency) {
//             if (occurrences.count(pair.second) > 0) {
//                 return false; // Duplicate occurrence count found
//             }
//             occurrences.insert(pair.second);
//         }

//         return true; // All occurrence counts are unique
//     }
// };

// int main() {
//     vector<int> arr = {1, 1, 2, 3, 2, 4, 3};

//     Solution solution;
//     bool result = solution.uniqueOccurrences(arr);

//     if (result) {
//         cout << "All elements have unique occurrences." << endl;
//     } else {
//         cout << "There are duplicate occurrence counts." << endl;
//     }

//     return 0;
// }
