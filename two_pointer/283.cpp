class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int num_zero=0;
        for(int i=0;i<n;i++)
        {
            nums[i-num_zero]=nums[i];
            if(nums[i-num_zero]==0) num_zero++;
        }
        for(int i=n-1;i>n-1-num_zero;i--)
        nums[i]=0;
        

    }
};
