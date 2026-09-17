/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp{
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode* , vector<ListNode*> , cmp> pq;
        for(ListNode* node : lists){
            while(node!=nullptr){
                ListNode* next = node->next;
                node->next = nullptr;
                pq.push(node);
                node = next;
            }
        }
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(!pq.empty()){
            temp->next = pq.top();
            temp = temp->next;
            pq.pop();
        }
        return head->next;
    }
};