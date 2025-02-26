class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()!=2){
            string tmp="";
            for(int i=0;i<s.size()-1;i++){
                int a=s[i]-'0';
                int b=s[i+1]-'0';
               int t=(a+b)%10;
               tmp+=to_string(t);
            }
            s=tmp;
        }
        if(s[0]==s[1]){
            return true;
        }
        return false;
    }
};