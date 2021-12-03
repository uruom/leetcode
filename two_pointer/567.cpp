class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         
         int n1=s1.length()-1;
         int n2=s2.length()-1;
         int l=0,r=n1;
         int flag=0;
         int flag_s1[129];
         int flag_s2[129];
         if(n1>n2)
         return false;
         for(int i=1;i<=128;i++)
         {
             flag_s1[i]=0;
             flag_s2[i]=0;
         }
         for(int i=0;i<=n1;i++)
         {
             flag_s1[s1[i]]++;
             flag_s2[s2[i]]++;
         }
         for(int i=1;i<=128;i++)
         if(flag_s1[i]==flag_s2[i])
         flag++;
         if(flag==128) return true;
         while(r<n2)
         {
             if(flag_s2[s2[l]]==flag_s1[s2[l]])
             flag--;
             flag_s2[s2[l]]--;
             if(flag_s2[s2[l]]==flag_s1[s2[l]])
             flag++;
             l++;
             r++;
             if(flag_s2[s2[r]]==flag_s1[s2[r]])
             flag--;
             flag_s2[s2[r]]++;
             if(flag_s2[s2[r]]==flag_s1[s2[r]])
             flag++;
             if(flag==128) return true;
         }
         return false;
         

    /*     while(n1+l<=n2)
         {
             r2=n1+l-1;
             r1=n1-1;
             while(r1!=0&&s1[r1]==s2[r2])
             {
                 r1--;
                 r2--;
             }
             if(r1==0&&s1[r1]==s2[r2]) return true;
             else
             {
                r2=n1+l-2;
                r1=n1-1;
                l_n=l;
                l++;
                while(s1[r1]!=s2[r2]&&r2>l_n)
                {
                    r2--;
                    l++;
                }
             }
         }
         return false;*/
    }
};
