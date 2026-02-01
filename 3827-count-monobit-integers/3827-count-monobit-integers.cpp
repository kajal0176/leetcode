class Solution {
public:
    int countMonobit(int n) {
        int cnt=1;
        int num=0;
        int i=0;
        while(num<n){
            
            num+=pow(2,i);
            i++;
            if(num<=n)
            cnt++;
        }
        return cnt;
    }
};