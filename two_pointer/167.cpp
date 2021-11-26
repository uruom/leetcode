class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        vector<int> ans (2);
        ans[0]=0;
        ans[1]=2;
        while (l<=r)
        {
            if(numbers[l]+numbers[r]<target)
                l++;
                else if(numbers[l]+numbers[r]>target)
                    r--;
                    else 
                    {
                        ans[0]=l+1;
                        ans[1]=r+1;
                        return ans;
                    }
        }
    return ans;
    }
};
