class Solution {
    
/*
Create a temporary array to store the shifted values, 
then overwrite each node value. Simple but it works...
*/
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> v(501), v2(501);
        int ln = 0;
        ListNode* orig = head;
        while (head != nullptr)
        {
            v[ln]=head->val;
            head = head->next;
            ln++;
        }
        for (int i = 0; i < ln; i++)
            v2[(i+k)%ln] = v[i];
        head = orig;
        for (int i = 0; i < ln; i++)
        {
            orig->val = v2[i];
            orig = orig->next;
        }
        return head;
    }
};