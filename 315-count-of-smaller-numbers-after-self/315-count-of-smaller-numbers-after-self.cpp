class Solution {
public:
    void merge(int start, int mid, int end, vector<pair<int,int>>& _nums, vector<int>& ans) {
        vector<pair<int,int>> temp(end-start+1);
        int i = start, j = mid + 1, k = 0;
        while(i <= mid && j <= end)
        {
            if(_nums[i].first <= _nums[j].first) {
                temp[k++] = _nums[j++];
            }
            else {
                ans[_nums[i].second] += end-j+1;
                temp[k++] = _nums[i++];
            }
        }
        while(i <= mid) {
            temp[k++] = _nums[i++];
        }
        while(j <= end) {
            temp[k++] = _nums[j++];
        }
        
        for(int i = start; i <= end; i++) {
            _nums[i] = temp[i-start];
        }
    }
    void mergeSort(int start, int end, vector<pair<int,int>>& _nums, vector<int>& ans) {
        if(start >= end)
            return;
        int mid = start + (end - start)/2;
        mergeSort(start, mid, _nums, ans);
        mergeSort(mid+1, end, _nums, ans);
        merge(start, mid, end, _nums, ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> _nums(n);
        for(int i = 0; i < n; i++) {
            _nums[i] = {nums[i],i};
        }
        mergeSort(0, n-1, _nums, ans);
        return ans;
    }
};