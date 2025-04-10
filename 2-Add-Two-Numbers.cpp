#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const vector<int> &nums)
{
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    for (int num : nums)
    {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Test cases
int main()
{
    Solution solution;

    // Test Case 1: Basic case
    ListNode *l1 = createLinkedList({2, 4, 3});
    ListNode *l2 = createLinkedList({5, 6, 4});
    ListNode *result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 1: ";
    printLinkedList(result); // Expected output: 7 -> 0 -> 8

    // Test Case 2: Different lengths
    l1 = createLinkedList({1, 8});
    l2 = createLinkedList({0});
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 2: ";
    printLinkedList(result); // Expected output: 1 -> 8

    // Test Case 3: Carry over
    l1 = createLinkedList({9, 9, 9});
    l2 = createLinkedList({1});
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 3: ";
    printLinkedList(result); // Expected output: 0 -> 0 -> 0 -> 1

    // Test Case 4: Both lists are empty
    l1 = nullptr;
    l2 = nullptr;
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 4: ";
    printLinkedList(result); // Expected output: (empty list)

    // Test Case 5: One list is empty
    l1 = createLinkedList({0});
    l2 = nullptr;
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 5: ";
    printLinkedList(result); // Expected output: 0

    // Test Case 6: Large numbers
    l1 = createLinkedList({9, 9, 9, 9, 9, 9, 9});
    l2 = createLinkedList({9, 9, 9, 9});
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 6: ";
    printLinkedList(result); // Expected output: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1

    return 0;
}