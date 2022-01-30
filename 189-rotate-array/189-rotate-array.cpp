class Solution {
public:
    void reverse(vector<int>& arr,int m,int n)
    {
        while(m<n)
        {
            int temp=arr[m];
            arr[m]=arr[n];
            arr[n]=temp;
            m++;
            n--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
        int size=nums.size();
        k=k%size;
        reverse(nums,0,size-1);
        reverse(nums,0,k-1);
        reverse(nums,k,size-1);
        
        /*vector<int> temp(size);
        
        for(int i=0;i<size;i++)
            temp[i]=nums[i];
        int m=0;
        for(int i=size-k;i<size;i++)
            nums[m++]=temp[i];
        
        for(int i=0;i<=k;i++)
        {
            nums[m++]=temp[i];
        }*/
        
        
    }
};