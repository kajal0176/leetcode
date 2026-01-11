class Solution {
    int solve(vector<int>& nums2) {
        vector<int>v;
        stack<int>st;
        
        int n=nums2.size();
        st.push(n-1);
        v.push_back(n);
        
        for(int i=n-2;i>=0;i--){
          while(!st.empty()&&nums2[st.top()]>=nums2[i]){
              st.pop();
          }
          if(st.empty()){
              v.push_back(n);
          }
          else{
              v.push_back(st.top());
          }
          st.push(i);
        }

        reverse(v.begin(),v.end());
        vector<int>prev;
        prev.push_back(-1);
        stack<int>s1;
        s1.push(0);
        for(int i=1;i<n;i++){
            while(!s1.empty()&&nums2[s1.top()]>=nums2[i]){
              s1.pop();
          }
          if(s1.empty()){
              prev.push_back(-1);
          }
          else{
              prev.push_back(s1.top());
          }
          s1.push(i);
        }
        int ans=INT_MIN;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
        int w=v[i]-prev[i]-1;
       // cout<<w<<" ";
        ans=max(ans,w*nums2[i]);
    }
    return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>v(matrix[0].size());
     //   v=matrix[0][0];
       
        for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
              v[j]=matrix[i][j]-'0';
              
          }
          break;
       
        }
         int ans=solve(v);
        for(int i=1;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
              if(matrix[i][j]=='1')
              v[j]=v[j]+matrix[i][j]-'0';
              else{
                  v[j]=0;
              }
          }
         ans=max(solve(v),ans);
        }
        return ans;
    }
};