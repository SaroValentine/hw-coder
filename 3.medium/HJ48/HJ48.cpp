#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val = -1) : val(val), next(nullptr) {}
};

int main()
{
    ListNode *yumhead = new ListNode(-1);
    int n;
    while (cin >> n)
    {
        int h;
        cin >> h;
        ListNode *head = new ListNode(h);
        yumhead->next = head;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            ListNode *cur = head;
            while (cur)
            {
                if (cur->val == b)
                {
                    ListNode *temp = new ListNode(a);
                    temp->next = cur->next;
                    cur->next = temp;
                    break;
                }
                cur = cur->next;
            }
        }
        int c;
        cin >> c;
        ListNode *cur = yumhead;
        while (cur->next)
        {
            if (cur->next->val == c)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }
        ListNode *temp = yumhead->next;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    return 0;
}
