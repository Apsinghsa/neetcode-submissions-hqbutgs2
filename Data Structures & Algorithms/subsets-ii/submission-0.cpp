class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& subsets){
        if(i>=nums.size()){
            subsets.push_back(curSet);
            return;
        }

        curSet.push_back(nums[i]);
        helper(i+1, nums, curSet, subsets);

        curSet.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]){
            i++;
        }
        helper(i+1, nums, curSet, subsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> curSet;
        helper(0, nums, curSet, subsets);

        return subsets;
    }
};