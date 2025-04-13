#include <iostream>
#include <vector>
using namespace std;

// Solution class with reverseBetween method
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        for (int i = 1; i < left; ++i)
            prev = prev->next;

        ListNode *current = prev->next;
        ListNode *next = nullptr;

        for (int i = 0; i < right - left; ++i)
        {
            next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete a linked list
void deleteLinkedList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// Test cases
int main()
{
    Solution solution;

    // Test Case 1: Normal case
    ListNode *head1 = createLinkedList({1, 2, 3, 4, 5});
    head1 = solution.reverseBetween(head1, 2, 4);
    cout << "Test Case 1: ";
    printLinkedList(head1); // Expected output: 1 4 3 2 5
    deleteLinkedList(head1);

    // Test Case 2: Reverse entire list
    ListNode *head2 = createLinkedList({1, 2, 3, 4, 5});
    head2 = solution.reverseBetween(head2, 1, 5);
    cout << "Test Case 2: ";
    printLinkedList(head2); // Expected output: 5 4 3 2 1
    deleteLinkedList(head2);

    // Test Case 3: Single element list
    ListNode *head3 = createLinkedList({1});
    head3 = solution.reverseBetween(head3, 1, 1);
    cout << "Test Case 3: ";
    printLinkedList(head3); // Expected output: 1
    deleteLinkedList(head3);

    // Test Case 4: Reverse sublist at the beginning
    ListNode *head4 = createLinkedList({1, 2, 3, 4, 5});
    head4 = solution.reverseBetween(head4, 1, 3);
    cout << "Test Case 4: ";
    printLinkedList(head4); // Expected output: 3 2 1 4 5
    deleteLinkedList(head4);

    // Test Case 5: Reverse sublist at the end
    ListNode *head5 = createLinkedList({1, 2, 3, 4, 5});
    head5 = solution.reverseBetween(head5, 3, 5);
    cout << "Test Case 5: ";
    printLinkedList(head5); // Expected output: 1 2 5 4 3
    deleteLinkedList(head5);

    // Test Case 6: Empty list
    ListNode *head6 = nullptr;
    head6 = solution.reverseBetween(head6, 1, 1);
    cout << "Test Case 6: ";
    printLinkedList(head6); // Expected output: (empty)
    deleteLinkedList(head6);

    // Test Case 7: Invalid range (left > right)
    ListNode *head7 = createLinkedList({1, 2, 3, 4, 5});
    head7 = solution.reverseBetween(head7, 4, 2);
    cout << "Test Case 7: ";
    printLinkedList(head7); // Expected output: 1 2 3 4 5 (unchanged)
    deleteLinkedList(head7);

    return 0;
}