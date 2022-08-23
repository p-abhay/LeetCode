class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        set<int> keys;
        keys.insert(0);
        while(!keys.empty()) {
            int key = *keys.begin();
            
            if(visited.find(key) == visited.end()) {
                visited.insert(key);
                //cout<<key<<" ";
                for(auto k : rooms[key])
                    keys.insert(k);
            }
            keys.erase(key);
            //for(auto i : visited)
             //   cout<<i<<" ";
            //cout<<"\n";
            if(visited.size() == rooms.size())
                return true;
        }
        return false;
    }
};