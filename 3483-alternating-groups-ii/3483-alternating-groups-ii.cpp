class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>q;
        int i=0;
        int j=0;
        int ans=0;
        int n=colors.size();
        while(j<2*colors.size()){
           // cout<<j<<" ";
           if(i>=colors.size())return ans;
           q.push_back(colors[j%n]);
          
           if(q.size()>1&&q[j%n]==q[(j-1)%n]){
            i=j;
          }
           if(j-i+1==k){
            ans++;
            i++;
           }
          j++;
        }
       
        return ans;
    }
};