class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0)
        return false;
        priority_queue<int , vector<int> , greater<int>> pq;
        map<int , int > freq;
        for(int n:hand){
            freq[n]++;
            if(freq[n]==1)
            pq.push(n);
        }
        while(!pq.empty()){
            int prev = -1;
            vector<int> temp ;
            for(int i=0;i<groupSize;i++){
                if(pq.empty())
                return false;
                if(prev!=-1){
                    if(prev+1!=pq.top())
                    return false;
                }
                prev = pq.top();
                freq[prev]--;
                if(freq[prev]!=0)
                temp.push_back(prev);
                // cout<<prev<<" ";

                pq.pop();
            }
            for(int n:temp)
            pq.push(n);
        }
        return true;
    }
};