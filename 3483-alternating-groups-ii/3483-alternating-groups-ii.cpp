class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i=0;
        int j=0;
        int ans=0;
        int n=colors.size();
        int prev=-1;
        while(j<2*colors.size()){
           // cout<<j<<" ";
           //when we reached to visited starting point;
           if(i>=colors.size())return ans;
           
           if(prev!=-1&&colors[j%n]==prev){
            i=j;
            }
             prev=colors[j%n];
           if(j-i+1==k){
            ans++;
            i++;
           }
          j++;
        }
       
        return ans;
    }
};