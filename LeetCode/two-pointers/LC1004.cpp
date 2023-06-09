// 最大连续1的个数III https://leetcode.cn/problems/max-consecutive-ones-iii/
// 滑动窗口：左右两个指针组成一个"窗口",右指针不断扩张，左指针按条件收缩。
class Solution { // 这题主要处理好边界问题就行
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        int i = 0, j = 0, t = 0;
        while(i < n)
        {
            while(t <= k && j < n)
            {
                if(nums[j] == 0)
                {
                    if(t == k) 
                    {
                        res = max(res, j - i);
                        break;
                    }
                    else t++;           
                }
                j++;
                if(j == n) res = max(res, j - i);
            }
            if(nums[i++] == 0) t--;
        }
        return res;
    }
};