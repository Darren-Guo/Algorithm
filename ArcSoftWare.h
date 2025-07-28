#include <stdc++.h>

using namespace std;

// 虹软科技笔试题

void func_1()
{
    int array_length;
    vector<int> array;
    int target_sum;
    {
        // 输入
        cin >> array_length;
        if (array_length > 20) {
            cout << "input error\n";
            return;
        }
        array.resize(array_length);
        for (int i = 0; i < array_length; i++) {
            cin >> array[i];
        }
        cin >> target_sum;
    }
    int num1, num2;
    for (int i = 0; i < array_length; i++) {
        if (array[i] > target_sum) {
            continue;
        }
        int last_sum = target_sum - array[i];
        int iter = -1;
        for (int j = i + 1; j < array_length; j++) {
            if (array[j] == last_sum) {
                iter = j;
                break;
            }
        }
        if (iter != -1) {
            cout << i << " " << iter << endl;
            return;
        }
    }
    cout << "no answer\n";
}

void func_2()
{
    int n1, n2;
    vector<int> num1, num2;
    {
        // 输入
        cin >> n1;
        num1.reserve(n1);
        for (int i = 0; i < n1; i++) {
            cin >> num1[i];
        }
        cin >> n2;
        num2.reserve(n2);
        for (int i = 0; i < n2; i++) {
            cin >> num2[i];
        }
    }

    vector<int> res;
    int i = 0, j = 0;
    for (; i < n1 && j < n2;) {
        // 异常
        if ((i > 0 && num1[i] < num1[i - 1]) || (j > 0 && num2[j] < num2[j - 1])) {
            cout << "input error\n";
            return;
        }
        if (num1[i] < num2[j]) {
            res.push_back(num1[i]);
            i++;
        } else if (num1[i] < num2[j]) {
            res.push_back(num2[j]);
            j++;
        } else {
            res.push_back(num1[i]);
            res.push_back(num2[j]);
            i++;
            j++;
        }
    }
    while (i < n1) {
        res.push_back(num1[i]);
        i++;
    }
    while (j < n2) {
        res.push_back(num2[j]);
        j++;
    }
    {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }
}

void func_3()
{
    string version1, version2;
    cin >> version1 >> version2;
    vector<int> v1(1, 0), v2(1, 0);
    for (char c : version1) {
        if (!(c == '.' || (c <= '9' && c >= '0'))) {
            cout << "input error\n";
            return;
        }
        if (c <= '9' && c >= '0') {
            if (v1.back() > (INT32_MAX - (c - '0')) / 10) {
                cout << "input error\n";
                return;
            }
            v1.back() = v1.back() * 10 + (c - '0');
        } else {
            v1.push_back(0);
        }
    }
    for (char c : version2) {
        if (!(c == '.' || (c <= '9' && c >= '0'))) {
            cout << "input error\n";
            return;
        }
        if (c <= '9' && c >= '0') {
            if (v2.back() > (INT32_MAX - (c - '0')) / 10) {
                cout << "input error\n";
                return;
            }
            v2.back() = v2.back() * 10 + (c - '0');
        } else {
            v2.push_back(0);
        }
    }
    int min_length = std::min(v1.size(), v2.size());
    for (int i = 0; i < min_length; i++) {
        if (v1[i] > v2[i]) {
            cout << 1;
            return;
        } else if (v1[i] < v2[i]) {
            cout << -1;
            return;
        }
    }
    if (v1.size() > v2.size()) {
        cout << 1;
        return;
    } else if (v1.size() < v2.size()) {
        cout << -1;
        return;
    } else {
        cout << 0;
        return;
    }
}

struct pos {
    int x;
    int y;
    struct pos up() { return {x - 1, y}; }
    struct pos down() { return {x + 1, y}; }
    struct pos left() { return {x, y - 1}; }
    struct pos right() { return {x, y + 1}; }
    vector<struct pos> get_neighbor(){
        vector<struct pos> res{up(), down(), left(), right()};
        return res;
    }
};
void printMatrix(vector<vector<int>>&map){
    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map[i].size(); j++){
            cout << map[i][j] << ", ";
        }
        cout << endl;
    }
}

void get_input(vector<vector<char>>&map, int&n, int&m, struct pos &begin, struct pos &end){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        vector<char> tmp_vec;
        char tmp_c;
        for(int j=0; j<m; j++){
            cin >> tmp_c;
            if(tmp_c == 'B'){
                begin.x = i;
                begin.y = j;
            }
            if(tmp_c == 'F'){
                end.x = i;
                end.y = j;
            }
            tmp_vec.push_back(tmp_c);
        }
        map.push_back(tmp_vec);
    }
}

bool if_pos_path(vector<vector<char>>& map, int n, int m, struct pos cur_pos)
{
    if (cur_pos.x < 0 || cur_pos.x >= n) {
        return false;
    }
    if (cur_pos.y < 0 || cur_pos.y >= m) {
        return false;
    }
    if (map[cur_pos.x][cur_pos.y] == '1') {
        return true;
    }
    return false;
}
// todo 最短路径
void func_4()
{
    vector<vector<char>> map;
    int n, m;
    struct pos begin;
    struct pos end;
    get_input(map, n, m, begin, end);
    // dp[i][j] 表示i j点到Begin的最短距离 -1表示到不了
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[begin.x][begin.y] = 0;
    stack<struct pos> s;
    s.push(begin);
    while (!s.empty()) {
        auto top = s.top();
        s.pop();
        vector<struct pos> neighbors = top.get_neighbor();
        for (auto neighbor : neighbors) {
            if (if_pos_path(map, n, m, neighbor)) {
                if (dp[neighbor.x][neighbor.y] == -1) {
                    dp[neighbor.x][neighbor.y] = dp[top.x][top.y] + 1;
                } else {
                    dp[neighbor.x][neighbor.y] =
                        std::min(dp[neighbor.x][neighbor.y], dp[top.x][top.y] + 1);
                }
            }
        }
    }
    cout << dp[end.x][end.y] << endl;
}

int main()
{
    func_4();
    return 0;
}