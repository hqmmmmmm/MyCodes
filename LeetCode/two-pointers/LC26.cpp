// 删除有序数组中的重复项 https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;  // i指针指向当前要写的地方，j指针指向当前要读的地方

        while(j < n)
        {
            if(!j || nums[j] != nums[j - 1]) // 要考虑特殊情况！！！
                nums[i++] = nums[j];
            j++;
        }
        return i;
    }
};
