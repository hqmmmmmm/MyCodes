// 判断子序列 https://leetcode.cn/problems/is-subsequence/
// 有点贪心的思想
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        int i = 0, j = 0;
        while(j < m)
        {
            if(s[i] == t[j]) 
                i++;
            j++;
        }
        return i == n;
    }
};