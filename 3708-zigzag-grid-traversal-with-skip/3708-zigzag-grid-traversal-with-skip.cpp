class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        bool isrev=0;
        for(int i=0;i<n;i++){
            int st;
            if(isrev){
                for(int j=m-1;j>=0;j--){
                    if(j%2){
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            else{
                for(int j=0;j<m;j++){
                    if(j%2==0){
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            isrev=!isrev;
            
        }
        return ans;
    }
};