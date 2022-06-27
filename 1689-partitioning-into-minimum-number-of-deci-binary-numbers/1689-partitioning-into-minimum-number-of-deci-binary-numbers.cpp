class Solution {
public:
    int minPartitions(string n) {
        int max_digit = -1;
        for(int i = 0; i < n.size(); i++) {
            int curr_digit = n[i] - '0';
            max_digit = max(max_digit, curr_digit);
        }
        return max_digit;
    }
};