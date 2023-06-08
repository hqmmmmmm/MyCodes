// 合并两个有序数组 https://leetcode.cn/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t(m + n);  // 常规双指针做法，但要开一个新数组
        int i = 0, j = 0, k = 0;

        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j]) t[k++] = nums1[i++];
            else t[k++] = nums2[j++];
        }
        while(i < m) t[k++] = nums1[i++]; // 处理某一个数组中的尾巴
        while(j < n) t[k++] = nums2[j++];

        for(i = 0; i < m + n; i++)
            nums1[i] = t[i];

    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while(i >=0 && j >= 0) // 官方逆向双指针做法，不用开新的数组。
        {
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(i >= 0) nums1[k--] = nums1[i--];
        while(j >= 0) nums1[k--] = nums2[j--];
        // 理解不会覆盖nums1。
        // 假设会覆盖nums1中的某个数，就算nums2中所有的数都比它大，那他也是刚好呆在这个位置，矛盾，不会覆盖。
    }
};
