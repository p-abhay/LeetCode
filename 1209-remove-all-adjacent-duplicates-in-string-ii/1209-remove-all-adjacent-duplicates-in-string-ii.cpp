class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++) {
            if(st.empty() || st.top().first != s[i])
                st.push({s[i],1});
            else {
                st.top().second += 1;
            }
            if(st.top().second == k)
                st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            ans = string(st.top().second, st.top().first) + ans;
            st.pop();
        }
        return ans;
    }
};