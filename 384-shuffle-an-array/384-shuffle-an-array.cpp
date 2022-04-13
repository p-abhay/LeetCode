class Solution {
    vector<int> arr, org;
public:
    Solution(vector<int>& nums) {
        org = nums;
        arr = nums;
    }
    
    vector<int> reset() {
        arr = org;
        return arr;
    }
    
    vector<int> shuffle() {
        rec(arr, arr.size());
        return arr;
    }
private:
    void rec(vector<int>& arr, int n) {
        if(n == 1)
            return;
        int idx = (rand() % n);
        swap(arr[idx], arr[n - 1]);
        rec(arr, n - 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */