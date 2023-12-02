class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        if(head==NULL|| head->next==NULL) return NULL;
        if(n==1)
        {
            ListNode* temp = head;
            head=temp->next;
        }else {
            ListNode* curr=head;
            ListNode* prev=NULL;
            int count=1;
            while(count<=n)
            {
                prev=curr;
                curr=curr->next;
                count++;
            }
            prev->next=curr->next;
        }
       return head ;
    }
};