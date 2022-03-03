class Solution {
public:
    bool canCross(vector<int>& stones) {
        int destination = stones[stones.size() - 1];
        map<int,set<int>> mp;
        for(int i = 0; i < stones.size(); i++) {
            mp[stones[i]] = {};
        }
        mp[stones[0]].insert(1);
        /*for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            cout<<itr->first<<" ";
            for(auto i = itr->second.begin(); i != itr->second.end(); i++) {
                cout<<*i<<" ";
            }
            cout<<endl;
        }*/
        for(int i = 0; i < stones.size(); i++) {
            int curr_stone_pos = stones[i];
            for(auto itr = mp[curr_stone_pos].begin(); itr != mp[curr_stone_pos].end(); itr++) {
                int next_pos = curr_stone_pos + *itr;
                if(next_pos == destination)
                    return true;
                if(mp.find(next_pos) != mp.end())
                {
                    if(*itr - 1 > 0)
                        mp[next_pos].insert(*itr - 1);
                    mp[next_pos].insert(*itr);
                    mp[next_pos].insert(*itr + 1);
                }
            }
        }
        return false;
    }
};