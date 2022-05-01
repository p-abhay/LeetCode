class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s_ = noHashString(s);
        string t_ = noHashString(t);
        if(s_ == t_)
            return true;
        return false;
    }
private:
    string noHashString(string s) {
        string str = "";
        for(auto ch : s) {
            if(ch == '#') {
                if(str.size() != 0) {
                    str.erase(str.size() - 1);
                }
            }
            else {
                str += ch;
            }
        }
        return str;
    }
};