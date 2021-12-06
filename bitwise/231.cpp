class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long i=2;
        if(n==1) return true;
        while(i<=n)
        {
            if(i==n) return true;
            i*=2;
        }
        return false;

    }
};
