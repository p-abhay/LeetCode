class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry = 1;
        for(int i = n; i >= 0; i--) {
            int sum;
            if(carry == 0)
                break;
            if((digits[i] + carry) > 9) {
                sum = digits[i] + 1;
                string s = to_string(sum);
                carry = s[0] - '0';
                digits[i] = s[1] - '0';
            }
            else {
                
                digits[i] += carry;
                carry = 0;
                sum = digits[i];
            }
            cout<<carry<<"\n";
            if((i == 0) && (sum) > 9) {
                digits.insert(digits.begin(), carry);
            }
            
                
        }
        return digits;
    }
};