class Solution {  // 寻找重复数https://leetcode.cn/problems/find-the-duplicate-number/
public:
    int findDuplicate(vector<int>& nums) {
        // 链表找环 那个距离公式想一下就行了
        int n = nums.size();
        int slow = nums[0], fast = nums[slow];
        while(fast != slow)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }

        fast = 0;

        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};