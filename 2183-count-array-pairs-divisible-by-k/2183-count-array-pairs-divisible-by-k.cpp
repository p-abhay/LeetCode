class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b,a%b);
    }
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int g1;
            if(nums[i] > k)
                g1 = gcd(nums[i],k);
            else
                g1 = gcd(k,nums[i]);
            
            for(auto i : mp) {
                if(((long long)g1*i.first)%k == 0)
                    ans += i.second;
            }
            
//             if(mp.find(k/g1) != mp.end())
//                 ans += mp[k/g1];
            mp[g1] += 1;
        }
        return ans;
    }
};