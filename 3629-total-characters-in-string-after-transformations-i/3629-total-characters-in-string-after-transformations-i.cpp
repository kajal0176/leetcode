class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
       vector<int>v(26,0);
       int mod=1e9+7;
        for(int i=0;i<s.size();i++){
          v[s[i]-'a']++;
        }
        int ans=0;
       while(t--){
        int t=v[25];
        for(int i=25;i>0;i--){
            if(i==25){
                ans=(ans%mod+v[i]%mod)%mod;
            }
           v[i]=v[i-1];
           
        }
        v[0]=t%mod;
        v[1]=v[1]%mod+t%mod;
       }
       return ans+s.size();
    }
};