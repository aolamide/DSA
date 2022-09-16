class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
      
        string ans;
        int w;
        if (m == 1 || m == 2)
        {
            m += 12, y--;
        }
        w = (d + (2 * m) + (3 * (m + 1) / 5) + y + (y / 4) - (y / 100) + (y / 400) + 1) % 7;
        
        switch(w)
        {
            case 0 : ans="Sunday";
                break;
            case 1 : ans="Monday";
                break;
            case 2 : ans="Tuesday";
                break;
            case 3 : ans="Wednesday";
                break;
            case 4 : ans="Thursday";
                break;
            case 5 : ans="Friday";
                break;
            case 6 : ans="Saturday";
                break;
        }
        return ans;
    }
};