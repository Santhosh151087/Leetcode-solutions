class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for(char c : tasks){
            mp[c]++;
        }
        priority_queue<int> pq;
        for(auto &cur : mp){
            // cout<<cur.second<<" ";
            pq.push(cur.second);
        }
        int total = 0;
        while(!pq.empty()){
            int cycle = n+1;
            int i = 0;
            vector<int> temp;
            while(i<cycle && !pq.empty() ){
                int cur = pq.top();
                pq.pop();
                total++;
                if(cur>1){
                    temp.push_back(cur-1);
                } 
                i++;
            }
            for(int n:temp)
            pq.push(n);
            if(pq.empty())break;// if heap is empty we dont need to empute the time 
            total+=(cycle - i);
        }
        return total;
    }
};