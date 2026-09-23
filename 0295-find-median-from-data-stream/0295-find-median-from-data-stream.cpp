class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int , vector<int> , greater<int>> min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num);
        if(min_heap.size() > max_heap.size()+1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if(!max_heap.empty() && min_heap.top() < max_heap.top()){
            int temp = min_heap.top();
            min_heap.pop();
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(temp);
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
            return( ((double)min_heap.top() ) +((double)max_heap.top())) /2;
        }
        return (double)min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */