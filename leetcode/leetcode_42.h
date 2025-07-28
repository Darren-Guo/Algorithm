// https://leetcode.cn/problems/trapping-rain-water/?envType=company&envId=bytedance&favoriteSlug=bytedance-thirty-days
#include <stdc++.h>

class Solution
{
  public:
    int trap(vector<int>& height)
    {
        vector<pair<int, int>> wall;
        wall.resize(height.size());
        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                wall[i].first = 0;
            } else {
                wall[i].first = wall[i - 1].first > height[i - 1] ? wall[i - 1].first : height[i - 1];
            }
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            if (i == height.size() - 1) {
                wall[i].second = 0;
            } else {
                wall[i].second = wall[i + 1].second > height[i + 1] ? wall[i + 1].second : height[i + 1];
            }
        }
        int ans = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i] < min(wall[i].first, wall[i].second)){
                ans += (min(wall[i].first, wall[i].second) - height[i]);
            }
        }
        return ans;
    }
};