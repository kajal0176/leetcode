class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(temp.size()>=part.size()){
                int j=part.size()-1;
                int k=temp.size()-1;
                while(j>=0&&k>=0){
                    if(part[j]==temp[k]){
                        j--;
                        k--;
                    }
                    else break;
                }
                if(j<0){
                  temp=temp.substr(0,temp.size()-part.size());
                }
            }
        }
        return temp;
    }
};