class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int cnt=0;
        while(j<blocks.size()){
          if(blocks[j]=='W'){
            cnt++;
          }
          if(j-i+1==k){
            ans=min(ans,cnt);
            while(i<=j&&blocks[i]!='W'){
               i++;
            }
            if(i<=j&&blocks[i]=='W'){
                i++;
                cnt--;
            }
          }
          j++;
        }
        return ans;
    }
};