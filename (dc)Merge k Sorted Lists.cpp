//https://leetcode.com/problems/merge-k-sorted-lists/description/

 ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        vector<int> v;
        // First push all values in vector v
        // Example : [[1,4,5],[1,3,4],[2,6]]
        for(int i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            while(head != NULL) {
                v.push_back(head->val);
                head = head->next;
            }
        }
        // Now v = [1,4,5,1,3,4,2,6]
        sort(v.begin(), v.end()); // sort vector
        // Now v = [1,1,2,3,4,4,5,6]
        ListNode* dummy = new ListNode(0); // created new list
        ListNode* t = dummy; // temporary node to iterate 
        for(int i = 0; i < v.size(); i++) {
            ListNode* temp = new ListNode(); // create a node temp
            temp->val = v[i]; // put value of each node in temp->val
            t->next = temp;  // connect with dummy node
            t = t->next;  // iteratenext
        }
        return dummy->next; 
    }
