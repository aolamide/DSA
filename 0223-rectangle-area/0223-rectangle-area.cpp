class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        int ox_start = max(ax1, bx1);
        int ox_end = min(ax2, bx2);
        
        if(ox_start > ax2 || ox_start > bx2 || ox_end < ax1 || ox_end < bx1) return area;
        
        int oy_start = max(ay1, by1);
        int oy_end = min(ay2, by2);
        
        if(oy_start > by2 || oy_start > by2 || oy_end < by1 || oy_end < by1) return area;
        
        int overlap_area = (ox_end - ox_start) * (oy_end - oy_start);
        
        return area - overlap_area;
    }
};