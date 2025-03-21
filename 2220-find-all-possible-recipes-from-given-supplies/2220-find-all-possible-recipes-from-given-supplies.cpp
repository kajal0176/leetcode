class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      unordered_map<string,vector<string>>graph;
        int n=recipes.size();
         unordered_map<string,int>indegree;
        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                graph[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
       
        for(int i=0;i<supplies.size();i++){
            q.push(supplies[i]);
            indegree[supplies[i]]=0;
        }
        unordered_set<string>st;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            st.insert(it);
            for(auto adj:graph[it]){
                indegree[adj]--;
                if(indegree[adj]==0){
                    q.push(adj);
                }
            }
        }
        // for(auto it:st){
        //     cout<<it<<" ";
        // }
        vector<string>ans;
        for(int i=0;i<recipes.size();i++){
            if(st.find(recipes[i])!=st.end()){
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};