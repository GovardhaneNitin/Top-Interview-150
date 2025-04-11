/**
 * Definition for singly-linked list.
 */
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

#include <iostream>
#include <vector>
using namespace std;

// Helper function to create a linked list from a vector
ListNode *createList(const vector<int> &values)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int val : values)
    {
        if (!head)
        {
            head = new ListNode(val);
            tail = head;
        }
        else
        {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
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

// Test cases
int main()
{
    Solution solution;

    // Test Case 1: Both lists are empty
    ListNode *list1 = nullptr;
    ListNode *list2 = nullptr;
    ListNode *result = solution.mergeTwoLists(list1, list2);
    cout << "Test Case 1: ";
    printList(result); // Expected Output: (empty)

    // Test Case 2: One list is empty
    list1 = createList({1, 2, 4});
    list2 = nullptr;
    result = solution.mergeTwoLists(list1, list2);
    cout << "Test Case 2: ";
    printList(result); // Expected Output: 1 2 4

    // Test Case 3: Both lists have elements
    list1 = createList({1, 2, 4});
    list2 = createList({1, 3, 4});
    result = solution.mergeTwoLists(list1, list2);
    cout << "Test Case 3: ";
    printList(result); // Expected Output: 1 1 2 3 4 4

    // Test Case 4: Lists with repeated values
    list1 = createList({1, 1, 1});
    list2 = createList({1, 1, 1});
    result = solution.mergeTwoLists(list1, list2);
    cout << "Test Case 4: ";
    printList(result); // Expected Output: 1 1 1 1 1 1

    // Test Case 5: Lists with negative values
    list1 = createList({-3, -2, -1});
    list2 = createList({-4, -3, -2});
    result = solution.mergeTwoLists(list1, list2);
    cout << "Test Case 5: ";
    printList(result); // Expected Output: -4 -3 -3 -2 -2 -1

    // Test Case 6: Large input lists
    vector<int> large1(1000, 1); // 1000 elements of value 1
    vector<int> large2(1000, 2); // 1000 elements of value 2
    list1 = createList(large1);
    list2 = createList(large2);
    result = solution.mergeTwoLists(list1, list2);
    cout << "Test Case 6: ";
    printList(result); // Expected Output: 1000 ones followed by 1000 twos

    return 0;
}