class Solution {
public:
void permutation(string s,vector<string>&ans,int ind){
    if(ind==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[i],s[ind]);
        permutation(s,ans,ind+1);
        swap(s[i],s[ind]);
    }
}
    string smallestNumber(string pattern) {
        string st="";
        for(int i=1;i<=pattern.size()+1;i++){
            st+=(to_string(i));
        }
        vector<string>temp;
        permutation(st,temp,0);
        for(auto it:temp){
            string s=it;
            int f=1;
            for(int i=0;i<pattern.size();i++){
                if(pattern[i]=='I'&&s[i]-'0'>=s[i+1]-'0'){
                    f=0;
                    break;
                }
                if(pattern[i]=='D'&&s[i]-'0'<=s[i+1]-'0'){
                    f=0;
                    break;
                }
            }
            if(f==1){
                return s;
            }
        }
        return "";
    }
};