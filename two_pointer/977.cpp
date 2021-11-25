class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        vector<int> num_sq(r+1);
        int val_l=nums[l]*nums[l],val_r=nums[r]*nums[r];
        while(l!=r)
        {
            if(val_l>val_r)
            {
                num_sq[r-l]=val_l;
                l++;
                val_l=nums[l]*nums[l];
            }
            else
            {
                num_sq[r-l]=val_r;
                r--;
                val_r=nums[r]*nums[r];
            }
        }
        num_sq[0]=val_l;
        return num_sq;
    }
};
