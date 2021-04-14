class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        struct LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr) {}; 
    };
    LinkedNode* _dummy;
    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummy = new LinkedNode(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int curIndex = 0;
        LinkedNode* p = _dummy;
        
        while (p->next != nullptr) {
            if (curIndex == index) {
                return p->next->val;
            } else {
                p = p->next;
                curIndex++;
            }
        }

        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* tmp = new LinkedNode(val);
        tmp->next = _dummy->next;
        _dummy->next = tmp; 
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* tmp = new LinkedNode(val);
        LinkedNode* p = _dummy;

        while (p->next != nullptr) {
            p = p->next;
        }

        p->next = tmp;        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        LinkedNode* p = _dummy;
        LinkedNode* tmp = new LinkedNode(val); 
        int curIndex = 0; 

        while (p->next != nullptr) {
            if (curIndex != index) {
                p = p->next;
                curIndex++;
            } else {
                tmp->next = p->next;
                p->next = tmp;
                break;
            }
        }        
        if (curIndex == index) {
            p->next = tmp;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        LinkedNode* p = _dummy;
        int curIndex = 0; 

        while (p->next != nullptr) {
            if (curIndex != index) {
                p = p->next;
                curIndex++;
            } else {
                LinkedNode* tmp = p->next;
                p->next = tmp->next;
                delete tmp;
                break;
            }
        } 
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
