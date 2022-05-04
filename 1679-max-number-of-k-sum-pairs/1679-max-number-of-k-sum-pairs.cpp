class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto i : nums)
            mp[i] += 1;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(k - nums[i]) != mp.end() && mp.find(nums[i]) != mp.end()) {
                if((k - nums[i]) == nums[i]) {
                    if((mp[nums[i]]) > 1) {
                        mp[nums[i]] -= 2;
                        ans += 1;
                        cout<<"1\n";
                    }
                    
                }
                else if((mp[k - nums[i]] > 0) && (mp[nums[i]] > 0)) {
                    mp[k - nums[i]] -= 1;
                    mp[nums[i]] -= 1;
                    ans += 1;
                    cout<<"2\n";
                }
            }
            /*else {
                mp[nums[i]] += 1;
            }*/
        }
        for(auto i : mp)
            cout<<i.first<<" "<<i.second<<"\n";
        return ans;
    }
};