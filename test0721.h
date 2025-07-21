#include <stdc++.h>

using namespace std;

// 降序划分函数：将大于基准的放左边，小于等于的放右边
int partition(vector<int>& nums, int left, int right) {
    // 设置基准
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
        // 从右往左遍历，当碰到大于基准的退出循环
        while (i < j && nums[j] <= pivot) {
            j--;
        }
        // num[j] 大于 基准，换到num[i] 的位置上，此时num[i]是基准
        if (i < j) {
            nums[i] = nums[j];
            i++;
        }
        // 从左往右遍历，当碰到小于基准的退出
        while (i < j && nums[i] >= pivot) {
            i++;
        }
        // 将nums[i]换到nums[j]上，此时nums[j]已经换到上面的nums[i]中了
        if (i < j) {
            nums[j] = nums[i];
            j--;
        }
    }
    nums[i] = pivot;
    return i;
}

vector<int> func2(vector<int> nums) {
    if (nums.empty()) return {};
    
    int n = nums.size();
    int k = static_cast<int>(n * 0.3); // 前30%的元素数量
    if (k <= 0) return {};
    
    int left = 0, right = n - 1;
    while (left <= right) {
        int p = partition(nums, left, right);
        if (p == k - 1) { // 找到目标位置
            break;
        } else if (p < k - 1) { // 目标在右半部分
            left = p + 1;
        } else { // 目标在左半部分
            right = p - 1;
        }
    }
    
    return vector<int>(nums.begin(), nums.begin() + k);
}