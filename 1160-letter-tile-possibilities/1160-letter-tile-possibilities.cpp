class Solution {
public:
void solve(string s,int ind,string tmp,set<string>&st){
    if(tmp.size()>0)
    st.insert(tmp);
    int ans=0;
    for(int i=ind;i<s.size();i++){
        if(i!=ind&&s[i]==s[i-1])continue;
        tmp+=s[i];
        solve(s,i+1,tmp,st);
        tmp.pop_back();
    }
    return;
}
void recurPermute(string s, string x, set<string> &res) {

    if (s.size() == 0) {
        
        res.insert(x);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        recurPermute(s.substr(1), x + s[0], res);
        rotate(s.begin(), s.begin() + 1, s.end());
    }
}
    int numTilePossibilities(string tiles) {
        set<string> res;
    recurPermute(tiles, "", res);
    int ans=0;
    set<string>s;
    for(auto it:res){
        //cout<<it<<" ";
        solve(it,0,"",s);
    }
    return s.size();
    }
};