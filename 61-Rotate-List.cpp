#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution class with rotateRight method
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;

        // Find the length of the list
        ListNode *current = head;
        int length = 1;
        while (current->next)
        {
            current = current->next;
            length++;
        }

        // Connect the tail to the head to form a circular list
        current->next = head;

        // Find the new head after rotation
        k = k % length;
        int stepsToNewHead = length - k;
        ListNode *newTail = head;
        for (int i = 1; i < stepsToNewHead; i++)
        {
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;

        // Break the circular list
        newTail->next = nullptr;

        return newHead;
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
ListNode *createList(const vector<int> &values)
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
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete a linked list
void deleteList(ListNode *head)
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

    // Test case 1: Basic case
    ListNode *head1 = createList({1, 2, 3, 4, 5});
    int k1 = 2;
    ListNode *result1 = solution.rotateRight(head1, k1);
    cout << "Test case 1: ";
    printList(result1); // Expected output: 4 5 1 2 3
    deleteList(result1);

    // Test case 2: k is 0 (no rotation)
    ListNode *head2 = createList({1, 2, 3, 4, 5});
    int k2 = 0;
    ListNode *result2 = solution.rotateRight(head2, k2);
    cout << "Test case 2: ";
    printList(result2); // Expected output: 1 2 3 4 5
    deleteList(result2);

    // Test case 3: k is greater than the length of the list
    ListNode *head3 = createList({1, 2, 3, 4, 5});
    int k3 = 7; // Equivalent to k = 2 (7 % 5)
    ListNode *result3 = solution.rotateRight(head3, k3);
    cout << "Test case 3: ";
    printList(result3); // Expected output: 4 5 1 2 3
    deleteList(result3);

    // Test case 4: Empty list
    ListNode *head4 = nullptr;
    int k4 = 3;
    ListNode *result4 = solution.rotateRight(head4, k4);
    cout << "Test case 4: ";
    printList(result4); // Expected output: (empty line)
    deleteList(result4);

    // Test case 5: Single element list
    ListNode *head5 = createList({1});
    int k5 = 10;
    ListNode *result5 = solution.rotateRight(head5, k5);
    cout << "Test case 5: ";
    printList(result5); // Expected output: 1
    deleteList(result5);

    // Test case 6: All elements are the same
    ListNode *head6 = createList({7, 7, 7, 7});
    int k6 = 2;
    ListNode *result6 = solution.rotateRight(head6, k6);
    cout << "Test case 6: ";
    printList(result6); // Expected output: 7 7 7 7
    deleteList(result6);

    return 0;
}