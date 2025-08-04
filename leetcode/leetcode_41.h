// https://leetcode.cn/problems/first-missing-positive/description/?envType=company&envId=bytedance&favoriteSlug=bytedance-thirty-days
/*
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
*/
class Solution
{
  public:
    int firstMissingPositive(vector<int>& nums)
    {
        // 遍历数组，将每个数字放到其正确的位置上
        for (int i = 0; i < nums.size(); i++) {
            // 如果当前数字不在正确的位置上，且满足条件，则交换数字
            while (nums[i] != i + 1) {
                // 条件：数字必须是正数，且在数组范围内，且避免重复交换
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) {
                    break; // 不满足条件则跳出循环
                }
                // 交换当前数字到正确的位置
                int idx = nums[i] - 1; // 目标位置索引
                nums[i] = nums[idx];  // 将目标位置的数字赋值到当前索引
                nums[idx] = idx + 1;  // 将当前数字放到目标位置
            }
        }

        // 再次遍历数组，找到第一个不符合条件的位置
        for (int i = 0; i < nums.size(); i++) {
            // 如果当前位置的数字不等于索引+1，则返回该索引+1
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // 如果所有数字都在正确的位置上，则返回数组最后一个数字+1
        return nums.back() + 1;
    }
};