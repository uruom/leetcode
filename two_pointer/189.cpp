class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int> num_rec (k);
        for(int i=0;i<k;i++)
        num_rec[i]=nums[i];
        for(int i=n-1;i>=k;i--)
        nums[(i+k)%n]=nums[i];
        for(int i=k;i<k+k;i++)
        nums[i%n]=num_rec[i-k];
       // return nums;

    }
};
