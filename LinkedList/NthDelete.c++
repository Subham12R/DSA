#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        for(int i = 0; i <= n; i++){
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
        return dummy.next;


    }

    void printList(ListNode* curr){
        while(curr){
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution s1;
    ListNode* curr = s1.removeNthFromEnd(head, 2);
    s1.printList(curr);
    return 0;
}