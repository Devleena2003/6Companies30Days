class solution
{
public:
    ListNode *solve(ListNode *head, bool &anyChange)
    {
        if (head == NULL)
            return head;
        ListNode *temp = head;
        int sum = 0;
        while (temp != NULL)
        {
            sum += temp->val;
            if (sum == 0)
                break;
            temp = temp->next;
        }
        if (sum == 0)
        {
            anyChange = true;
            return temp->next;
        }
        head->next = solve(head->next, anyChange);
        return head;
    }
    ListNode *removeZeroSum(ListNode *head)
    {
        while (true)
        {
            bool anyChange = false;
            head = solve(head, anyChange);
            if (head == NULL || anyChange == false)
                break;
        }
        return head;
    }
}