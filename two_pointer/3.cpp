class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool fla[129];
        int i=1,l=0,ans=0,count=0,n=s.length();
        for(int j=0;j<=128;j++)
        fla[j]=false;
//        cout<<n;
        if(n==0)
        return 0;
//        if(n==1)
//        return 1;
        fla[s[0]]=true;
        count++;
        while(i<n)
        {
            
            if(fla[s[i]])
            {
 //               cout<<s[i]<<endl;
                if(ans<count) ans=count;
                while(s[l]!=s[i])
                {
                    fla[s[l]]=false;
                    l++;
                    count--;
                }
                l++;
                fla[s[i]]=true;
            }
            else
            {
                fla[s[i]]=true;
                count++;
            }
            i++;
        }
        if(ans<count) ans=count;
        return ans;
    }
};
