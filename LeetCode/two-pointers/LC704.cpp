// 二分查找 https://leetcode.cn/problems/binary-search/ 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n - 1;  // 模板1
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }

        if(l < n && nums[l] == target)
            return l;
        return -1;
    }
};