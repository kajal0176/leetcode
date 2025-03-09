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
          if(q.size()==0||q.back()!=colors[j%n]){
            q.push_back(colors[j%n]);
            if(abs(j-i+1)==k){
               // cout<<j%n<<" ";
                ans++;
               // q.pop_front();
                i++;
                
            }
          }
          else{
            
            q.push_back(colors[j%n]);
            i=j;
          }
         
          j++;
        }
       
        return ans;
    }
};