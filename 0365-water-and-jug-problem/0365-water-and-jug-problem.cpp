class Solution {
public:
    map<string, bool> mp;
    bool dfs(int x, int y, int currX, int currY, int target) {
        string key = to_string(currX) + "-" + to_string(currY);
        if(currX < 0 || currY < 0 || currX > x || currY > y || mp[key]) return false;
        if(currX + currY == target) return true;
        
        mp[key] = true;
        
        //fill either completely
        bool a = dfs(x, y, x, currY, target);
        bool b = dfs(x, y, currX, y, target);
        
        //completely empty either
        bool c = dfs(x, y, 0, currY, target);
        bool d = dfs(x, y, currX, 0, target);
        
        //pour from one into other until full or empty
        bool e = dfs(x, y, currX - currY, 0, target);
        bool f = dfs(x, y, 0, currY - currX, target);
        
        bool g = dfs(x, y, x, currY - x + currX, target);
        bool h = dfs(x, y, currX - y + currY, y, target);
        
        return a||b||c||d||e||f||g||h;
    }
    bool canMeasureWater(int x, int y, int target) {
        return dfs(x, y, 0, 0, target);
    }
};