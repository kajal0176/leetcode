class Solution {
public:
 void solve(int n,string temp,vector<string>&v){
     if(n==0){
        v.push_back(temp);
        return;
     }
    if(temp.size()==0||(temp.back()!='a')){
        solve(n-1,temp+"a",v);
    }
    if(temp.size()==0||(temp.back()!='b')){
        solve(n-1,temp+"b",v);
    }
    if(temp.size()==0||(temp.back()!='c')){
        solve(n-1,temp+"c",v);
    }
 }
    string getHappyString(int n, int k) {
        vector<string>v;
        solve(n,"",v);
        priority_queue<string>pq;
        if(v.size()<k){
            return "";
        }
        for(auto it:v){
           if(pq.size()==k){
            if(pq.top()>it){
                pq.pop();
            }
           }
           if(pq.size()<k){
            pq.push(it);
           }
        }
        return pq.top();
    }
};