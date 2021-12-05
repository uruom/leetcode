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
    void insert(ListNode* list1,ListNode* list2)
    {
        if(list2!=NULL)
        {
            if(list1->next!=NULL)
            {
                if(list1->next->val<=list2->val)
                insert(list1->next,list2);
                else 
                {
                    ListNode* list=list1->next;
                    ListNode* list_2=list2->next;
                    list1->next=list2;
                    list2->next=list;
                    insert(list2,list_2);
                }
            }
            else
            list1->next=list2;
        }

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL||list2==NULL)
        {
            if(list1==NULL) return list2;
            else return list1;
        }
        if(list1->val<list2->val)
        {
            insert(list1,list2);
            return list1;
        }
        else
        {
            insert(list2,list1);
            return list2;
        }
    }
};
