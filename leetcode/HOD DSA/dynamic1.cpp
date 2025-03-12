class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i=1;i<n;i++){
            vector<int> temp(i+1);
            temp[0] = ans[i-1][0];
            for(int j=1;j<i;j++){
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            temp[i]=ans[i-1][0];
            ans.push_back(temp);
        }
        return ans;
    }
};