class Solution {
public:
static bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
    bool maxSubstringLength(string s, int k) {
        unordered_map<char,int>first,last;
        for(int i=0;i<s.size();i++){
            last[s[i]]=i;
            if(first.find(s[i])==first.end()){
                first[s[i]]=i;
            }
        }
        vector<pair<int,int>>intervals;
        int mx=0;
        for(auto it:first){
            //if(first.find(s[i]))
           int f=first[it.first];
           int l=last[it.first];
           for(int i=f;i<=l;i++){
            f=min(f,first[s[i]]);
            l=max(l,last[s[i]]);
           }
            if(f==0&&l==s.size()-1)continue;
            intervals.push_back({f,l});
        }
       sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i].first<<" "<<intervals[i].second<<" ";
        }
       int cnt=0;
       int prev=-1;
       for(int i=0;i<intervals.size();i++){
        if(prev<intervals[i].first){
            cnt++;
            prev=intervals[i].second;
        }
        
       }
       return cnt>=k;
    }
};