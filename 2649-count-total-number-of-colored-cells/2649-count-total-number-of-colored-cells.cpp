class Solution {
public:
    long long coloredCells(int n) {
       if(n==1)return 1;
        long long ans=5;
        //in each step multiple of 4 no. of cell is being added eg 4,8,12......
        for(int i=3;i<=n;i++){
          long long added=4+(i-2)*4;
          ans+=added;
        }
        return ans;
    }
};