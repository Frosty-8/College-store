#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int imin = 0, imax = m, half_len = (m + n + 1) / 2;
        
        while (imin <= imax) {
            int i = (imin + imax) / 2; 
            int j = half_len - i;    

            if (i < m && nums2[j - 1] > nums1[i]) {
                
                imin = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                
                imax = i - 1;
            } else {
                
                int max_of_left;
                if (i == 0) max_of_left = nums2[j - 1];
                else if (j == 0) max_of_left = nums1[i - 1];
                else max_of_left = max(nums1[i - 1], nums2[j - 1]);
                
                
                if ((m + n) % 2 == 1) return max_of_left;
                
                int min_of_right;
                if (i == m) min_of_right = nums2[j];
                else if (j == n) min_of_right = nums1[i];
                else min_of_right = min(nums1[i], nums2[j]);
                
                return (max_of_left + min_of_right) / 2.0;
            }
        }
        
        throw invalid_argument("Input arrays are not sorted.");
    }
};

int main(){
    Solution s;
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    double result = s.findMedianSortedArrays(nums1,nums2);
    cout<<" "<<result<<endl;
    return 0;
}