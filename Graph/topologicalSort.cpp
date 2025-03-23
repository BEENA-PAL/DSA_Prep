//https://leetcode.com/problems/find-eventual-safe-states/?envType=problem-list-v2&envId=topological-sort


//--------------******************************-----------------//
// idea we calculate the indegree of all the node and keep removing those node which have zero indegree
//  isse hame ek aise order milta hai jo reverse order me hota hai
// jo sabse baad me element hota hai vo phle mil jaata hai and jo sabse phle hota hai vo sabse baad me milta hai
//--------------********************************---------------//


//--------------******************************-----------------//
// isse cycle bhi detect kr lete hai qki jo node cycle ka part hota hai uski indegree kabhi zero hogi hi nahi.
//--------------********************************---------------//
class Solution {
    public:
    // ek to simple jo graph given hai vo hai
    // i will make a graph reverting the edges already given in problem
    // find indegree of reversed graph
    
    // usse ye hoga ki jo terminal node hoga uski indegree zero hogi
    // then usse connected node age jo milenge reversed graph me uski indegree ko reduse krke ham dekhenge ki agar uske bhi indegree zero hai that means vo bhi terminal pe jaake finish ho rha hai
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
    
            int n = graph.size();
    
            // this is reversed edge graph
            vector<int> adj[n];
            queue<int> q;
            int indegree[n];
    
            for(int i = 0; i < n; i++) {
                    // meaning it is terminating node
                if(graph[i].size() == 0) {
                    q.push(i);
                }else{
                    for(auto v : graph[i]){
                        adj[v].push_back(i);
                    }
                }
    
                indegree[i] = graph[i].size();
            }
    
            // for(int i = 0 ; i < n; i++){
    
            //   cout<<i<<"->";
            //   for(auto y:adj[i]){
            //     cout<<y<<" ";
            //   }
            //   cout<<endl;
            // }
    
            vector<int> ans;
    
            while(!q.empty()){
                int u = q.front();
                q.pop();
                ans.push_back(u);
    
                for(auto v : adj[u]){
                    indegree[v]--;
    
                    if(indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    };