class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mn=INT_MAX;
        int cnt=0;
        long long sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                mn=min(mn,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    cnt++;
                }
               sum+=(abs(matrix[i][j]));
            }
        }
        if(cnt%2==0){
            return sum;
        }
        return sum-(2*mn);
    }
};