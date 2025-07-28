// #include "leetcode_5.h"
#include <stdc++.h>
using namespace std;

/*
// O(n^2) 穷举法
class Solution
{
  public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        // unordered_set<int> num_map;
        unordered_map<int, int> num_map;
        int max_res = 0;
        for (int idx = 0; idx < nums.size();) {
            int tmp_max_res = 0;
            int left = idx;
            for (int i = idx; i < nums.size(); i++) {
                if (num_map.count(nums[i]) == 0) {
                    tmp_max_res += nums[i];
                    num_map[nums[i]] = i;
                    continue;
                }
                left = num_map[nums[i]];
                num_map.clear();
                break;
            }
            max_res = max(max_res, tmp_max_res);
            tmp_max_res = 0;
            idx = left + 1;
        }
        return max_res;
    }
};
*/

class Solution
{
  public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int left = 0, right = 0;
        unordered_set<int> nums_set;
        int tmp_max_count = 0;
        int max_count = 0;
        while (left <= right && right < nums.size()) {
            while (right < nums.size() && nums_set.count(nums[right]) == 0) {
                tmp_max_count += nums[right];
                nums_set.insert(nums[right]);
                right++;
            }
            max_count = max(max_count, tmp_max_count);
            while (left <= right && nums[left] != nums[right]) {
                tmp_max_count -= nums[left];
                nums_set.erase(nums[left]);
                left++;
            }
            if (left < right) {
                tmp_max_count -= nums[left];
                nums_set.erase(nums[left]);
                left++;
            }
        }
        return max_count;
    }
};

int main()
{
    vector<int> nums{5,2,1,2,5,2,1,2,};
    Solution s;
    cout << s.maximumUniqueSubarray(nums) << endl;
    return 0;
}