class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r=nums.size()-1,l=0,mid=(l+r)/2;
        while((nums[mid]!=target)&&(l!=r)&&(l>=0)&&(r<nums.size()))
        {
            if(nums[mid]<target)
            {
                l=mid+1;
                mid=(l+r)/2;
            }
            else
            {
                r=mid-1;
                mid=(r+l)/2;
            }
        }
        if (l<0||r>=nums.size())
        return -1;
        else
            if (nums[mid]==target)
            return  mid;
            else return -1;

    }
};
