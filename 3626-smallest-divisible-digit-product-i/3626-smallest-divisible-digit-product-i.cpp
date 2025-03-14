class Solution {
public:
bool isp(int n,int t){
    string s=to_string(n);
    int p=1;
    for(int i=0;i<s.size();i++){
        p*=(s[i]-'0');
    }
    return p%t==0;
}
    int smallestNumber(int n, int t) {
        while(!isp(n,t)){
            n++;
        }
        return n;
    }
};