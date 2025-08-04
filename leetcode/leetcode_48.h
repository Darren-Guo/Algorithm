// 数组 数学 矩阵
// https://leetcode.cn/problems/rotate-image/?envType=company&envId=bytedance&favoriteSlug=bytedance-thirty-days
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先按照右上到左下对称，再上下对称，即可向右旋转90度角
        if(matrix.size() == 0 || matrix.size() != matrix[0].size()){
            return;
        }
        int tmp=0;
        for(int i=0; i<matrix.size(); i++){
            for (int j = 0; j <= (matrix.size() - i - 1); j++) {
                // matrix[i][j] = matrix[n-j-1][n-i-1]
                tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix[i].size() - j - 1][matrix[i].size() - i - 1];
                matrix[matrix[i].size() - j - 1][matrix[i].size() - i - 1] = tmp;
            }
        }
        vector<int> tmp_vec;
        for (int i = 0; i < matrix.size() / 2; i++) {
            tmp_vec = matrix[i];
            matrix[i] = matrix[matrix.size() - i - 1];
            matrix[matrix.size() - i - 1] = tmp_vec;
        }
    }
};