class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=0,cou=0,n=s.size()-1;
        char a;
        while(l<=n)
        {
            if(s[r]!=' '&&r!=n)
            r++;
            else
            {
                cou=r+1;
                if(r!=n)
                r--;
                while(l<r)
                {
                    a=s[l];
                    s[l]=s[r];
                    s[r]=a;
                    l++;
                    r--;
                }
                l=cou;
                r=cou;
            }
        }
        return s;
    }
};
