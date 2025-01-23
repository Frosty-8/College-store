#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // Return the indices as a vector
                }
            }
        }
        return {}; // Return an empty vector if no solution is found
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int t = 9;
    vector<int> result = s.twoSum(nums, t);
    
    // Output the result
    cout << "Indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}