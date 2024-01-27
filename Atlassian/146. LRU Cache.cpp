// https://leetcode.com/problems/lru-cache/
// TC: O(N)
// SC: O(N)

class LRUCache {
public:
    struct Node{
        int key;
        int val;
        struct Node*next;
        struct Node*prev;

        Node(int k, int v){
            key=k;
            val=v;
            next=NULL;
            prev=NULL;
        }
    };

    int maxSize,currSize;
    Node*head;
    Node*tail;
    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {
        maxSize=capacity;
        currSize=0;
        head=NULL;
        tail=NULL;
    }

    void moveToTail(Node*node){
        if(node==tail)
            return;
        if(node==head)
        {
           head=head->next;
           head->prev=NULL;
        }
        else
        {
           node->prev->next=node->next;
           node->next->prev=node->prev;
        }
        node->prev=tail;
        node->next=NULL;
        tail->next=node;
        tail=node;
    }


     void deleteAtHead(){
        Node*temp=head;
        head=head->next;
        if(head)
            head->prev=NULL;
        else 
            tail=head;

        delete(temp);
        currSize--;
    }

    void addToTail(Node*node){
        if(!tail){
            head=node;
            tail=node;
        }
        else
        {
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
        currSize++;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        moveToTail(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->val=value;
            moveToTail(mp[key]);
            return;
        }
        
        if(maxSize<=currSize){
            mp.erase(head->key);
            deleteAtHead();
        }

        mp[key]=new Node(key,value);
        addToTail(mp[key]);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

