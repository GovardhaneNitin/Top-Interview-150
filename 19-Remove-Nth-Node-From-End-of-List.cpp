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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head);
        ListNode *first = &dummy;
        ListNode *second = &dummy;
        for (int i = 0; i <= n; ++i)
        {
            first = first->next;
        }
        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        ListNode *nodeToRemove = second->next;
        second->next = second->next->next;
        delete nodeToRemove;
        return dummy.next;
    }
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(vector<int> values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (int i = 1; i < values.size(); ++i)
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

// Helper function to convert a linked list to a vector
vector<int> linkedListToVector(ListNode *head)
{
    vector<int> result;
    while (head)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Test cases
int main()
{
    Solution solution;

    // Test Case 1: Basic case
    ListNode *head1 = createLinkedList({1, 2, 3, 4, 5});
    int n1 = 2;
    ListNode *result1 = solution.removeNthFromEnd(head1, n1);
    cout << "Test Case 1: ";
    printLinkedList(result1); // Expected output: 1 2 3 5

    // Test Case 2: Remove the only node
    ListNode *head2 = createLinkedList({1});
    int n2 = 1;
    ListNode *result2 = solution.removeNthFromEnd(head2, n2);
    cout << "Test Case 2: ";
    printLinkedList(result2); // Expected output: (empty list)

    // Test Case 3: Remove the head node
    ListNode *head3 = createLinkedList({1, 2});
    int n3 = 2;
    ListNode *result3 = solution.removeNthFromEnd(head3, n3);
    cout << "Test Case 3: ";
    printLinkedList(result3); // Expected output: 2

    // Test Case 4: Large input
    vector<int> largeInput(1000, 1); // List of 1000 nodes with value 1
    ListNode *head4 = createLinkedList(largeInput);
    int n4 = 500;
    ListNode *result4 = solution.removeNthFromEnd(head4, n4);
    cout << "Test Case 4: ";
    printLinkedList(result4); // Expected output: List of 999 nodes with value 1

    // Test Case 5: Remove the last node
    ListNode *head5 = createLinkedList({1, 2, 3});
    int n5 = 1;
    ListNode *result5 = solution.removeNthFromEnd(head5, n5);
    cout << "Test Case 5: ";
    printLinkedList(result5); // Expected output: 1 2

    // Test Case 6: Empty list
    ListNode *head6 = nullptr;
    int n6 = 1;
    ListNode *result6 = solution.removeNthFromEnd(head6, n6);
    cout << "Test Case 6: ";
    printLinkedList(result6); // Expected output: (empty list)

    return 0;
}