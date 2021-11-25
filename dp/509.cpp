class Solution {
public:
    int fib(int n) {
        long long a=1,b=1,c;
        if(n==0) return 0;
        else if (n==1) return 1;
             else if (n==2) return 1; 
        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
