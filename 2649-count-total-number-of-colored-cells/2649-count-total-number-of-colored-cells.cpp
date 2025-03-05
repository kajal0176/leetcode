class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return 1;
        if(n==2)return 5;
        long long ans=coloredCells(n-1);
        long long added=4+(n-2)*4;
        return ans+added;
    }
};