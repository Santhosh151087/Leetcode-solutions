class Solution {
public:
    #define ll long long int
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src ==dst)
        return 0;
        
        vector<vector<pair<ll, ll>>> near(n);
        for(auto cur : flights){
            near[cur[0]].push_back({(ll)cur[1] ,(ll) cur[2]});
        }
    //    priority_queue<pair<ll , ll>,
    //    vector<pair<ll,ll>>,
    //    greater<pair<ll,ll>>> qu;
    queue<pair<ll , ll>> qu;
       vector<ll> dis(n , INT_MAX);
       dis[src] = 0;
       qu.push({0 , src});// cost , node
       int step = 0;
       while(!qu.empty()){
        if(step == k+2)
        break;
         
        int size = qu.size();
        for(int i=0;i<size;i++){
         auto [cost , node] = qu.front();
        qu.pop();
        
        if(dis[node]< cost)
        continue;
        dis[node] = cost;
        for(auto [adj , acost] :near[node] ){
          ll total = acost + cost;
          if(dis[adj]<total)
          continue;
          qu.push({total  , adj});  
        }
        }
        step++;
       }
      
       return dis[dst]==INT_MAX?-1:dis[dst];
    }
};