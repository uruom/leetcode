class Solution {
public:
    int hammingWeight(uint32_t n) {
        long long ans=0;
        while(n!=0)
        {
            if(n&1==1)
            ans+=1;
            n=n>>1;
        }
        return ans;
    }
};
