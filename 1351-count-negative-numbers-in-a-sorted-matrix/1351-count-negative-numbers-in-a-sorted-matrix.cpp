class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0;
        int n=grid.size();
        int m=grid[0].size();
        int j=0;
        int ans=0;
        while(i<n){
             if(j>=m){
                j=0;
                i++;
            }
            if(i>=n){
                break;
            }
             if(grid[i][j]>=0){
                 j++;
            }
            else{
                cout<<j<<" ";
                ans+=(m-j);
                i++;
                j=0;
            }
           
        }
        return ans;
    }
};