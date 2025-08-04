// https://leetcode.cn/problems/trapping-rain-water/?envType=company&envId=bytedance&favoriteSlug=bytedance-thirty-days
/*
滑动窗口
双向链表
*/
class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ans;
        vector<int> deque(nums.size(), 0);
        int num_left = 1 - k, num_right = 0;
        int dq_left = 0, dq_right = 0;
        for (; num_right < nums.size(); num_left++, num_right++) {
            // 滑动窗口已满，并且删除元素为最大，那么删除dq头部
            if (num_left > 0 && nums[num_left - 1] == deque[dq_left]) {
                dq_left++;
            }
            // 从右到左，删除小于入队的新元素的内容
            while(dq_right >= dq_left && deque[dq_right] < nums[num_right]){
                --dq_right;
            }
            // 新元素入队
            deque[++dq_right] = nums[num_right];
            if (num_left >= 0) {
                ans.push_back(deque[dq_left]);
            }
        }
        return ans;
    }
};