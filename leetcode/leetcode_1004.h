// https://leetcode.cn/problems/max-consecutive-ones-iii/?envType=company&envId=bytedance&favoriteSlug=bytedance-thirty-days
// 给定一个二进制数组 nums 和一个整数 k，假设最多可以翻转 k 个 0 ，则返回执行操作后 数组中连续 1 的最大个数 。
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // 定义滑动窗口的左右边界
        int k_left = 0, k_right = 0;
        // 用于记录最大连续 1 的长度
        int max_length = 0;
        // 用于记录窗口内 0 的数量
        int count0 = 0;

        // 遍历数组，扩展滑动窗口的右边界
        for (k_right = 0; k_right < nums.size(); k_right++) {
            // 如果当前元素是 0，增加 count0 的计数
            count0 += 1 - nums[k_right]; 

            // 如果窗口内的 0 的数量超过了允许翻转的 k 个 0
            while (count0 > k) {
                // 收缩滑动窗口的左边界，同时减少 count0 的计数
                count0 -= (1 - nums[k_left]);
                k_left++;
            }

            // 更新最大连续 1 的长度
            max_length = max(max_length, k_right - k_left + 1);
        }

        // 返回最大连续 1 的长度
        return max_length;
    }
};