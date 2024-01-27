// https://leetcode.com/problems/merge-k-sorted-lists/
// TC: O(N*KlogK)
// SC: O(N)

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

class compare{
    public:
    bool operator()(ListNode*a, ListNode*b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare > min_heap;
        int k=lists.size(); 
        if(k==0)return NULL;
         for(int i=0;i<k;i++){  //O(KlogK)
            if(lists[i]!=NULL)min_heap.push(lists[i]);
         } 
         
         ListNode*head=NULL;
         ListNode*tail=NULL;
         while(min_heap.size()>0){ //O(N*KlogK)
            ListNode*top=min_heap.top();
            min_heap.pop();

            if(top->next!=NULL)min_heap.push(top->next);
            if(head==NULL){
                head=top;
                tail=top;
            }
            else{
                tail->next=top;
                tail=top;
            }
         }
        return head;
    }
};








