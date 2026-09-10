class Node{
public:
    int key;
    int data ;
    Node* prev;
    Node* next;
    Node(int keyy ,int val){
        key = keyy;
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int capacity;
    int count = 0;
    map<int , Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1 , -1 );
   
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;
        Node* cur = mp[key];
        if(cur!=head->next){
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        Node* headnext = head->next;
        headnext->prev = cur;
        cur->next = headnext;
        cur->prev = head;
        head->next = cur;
        }
         return mp[key]->data;
       

    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            Node* cur = mp[key];
            cur->data = value;
            get(key);
        }
        else{
            if(count == capacity){
                Node* cur = tail->prev;
                tail->prev = cur->prev;
                cur->prev->next = tail;
                cur->next = nullptr;
                cur->prev = nullptr;
                mp.erase(cur->key);
            }
            else{
                count++;
            }
            Node* cur = new Node(key , value);
            mp[key] = cur;
            Node* headnext = head->next;
            headnext->prev = cur;
            cur->next = headnext;
            cur->prev = head;
            head->next = cur;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */