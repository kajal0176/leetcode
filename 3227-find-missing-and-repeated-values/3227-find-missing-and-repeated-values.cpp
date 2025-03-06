class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xr=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                xr^=grid[i][j];
            }
        }
        int n=grid.size();
        for(int i=1;i<=n*n;i++){
           
                xr^=i;
            
        }
        int rgt=(xr& ~(xr-1));
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((rgt&grid[i][j])!=0){
                    one^=grid[i][j];
                }
                else{
                    zero^=grid[i][j];
                }
            }
        }
       
        for(int i=1;i<=n*n;i++){
            
               if((rgt&i)!=0){
                one^=i;
               }
               else{
                zero^=i;
               }
           
        }
        // cout<<one<<" "<<zero<<" ";
        int cnt=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==zero){
                cnt++;
            }
        }
       }
       if(cnt==2){
        return {zero,one};
       }
       return {one,zero};
    }
};