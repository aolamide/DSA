class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> visited(rooms.size(), 0);
        
        int count = rooms.size() - 1;
        
        queue<int> q;
        
        for(int room : rooms[0]) {
            q.push(room);  
            visited[room] = true;
        }
        
        visited[0] = true;
        
        while(!q.empty()) {
            int curr = q.front();
            count--;
            if(count == 0) return true;
            q.pop();
            
            for(int room : rooms[curr]) {
                if(!visited[room]) q.push(room);
                visited[room] = true;
            }
        }
        
        return false;
    }
};