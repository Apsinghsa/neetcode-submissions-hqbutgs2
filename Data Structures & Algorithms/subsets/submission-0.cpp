class Solution {
public:
    void helper(int i, vector<int>nums, vector<int>& curSet, vector<vector<int>>& subsets){
        if (i==nums.size()){
            subsets.push_back(curSet);
            return;
        }

        curSet.push_back(nums[i]);
        helper(i+1, nums, curSet, subsets);

        curSet.pop_back();
        helper(i+1, nums, curSet, subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curSet;
        int n=nums.size();
        helper(0, nums, curSet, subsets);

        return subsets;
    }
};
