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

// Helper function to create a linked list from a vector
ListNode *createList(const vector<int> &values)
{
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    for (int val : values)
    {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
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

// Solution class to remove duplicates from sorted list
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                {
                    head = head->next;
                }
                prev->next = head->next;
            }
            else
            {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

int main()
{
    Solution solution;

    // Test case 1: Basic case with duplicates
    ListNode *test1 = createList({1, 2, 3, 3, 4, 4, 5});
    ListNode *result1 = solution.deleteDuplicates(test1);
    cout << "Test case 1: ";
    printList(result1); // Expected output: 1 2 5
    deleteList(result1);

    // Test case 2: All elements are duplicates
    ListNode *test2 = createList({1, 1, 2, 2, 3, 3});
    ListNode *result2 = solution.deleteDuplicates(test2);
    cout << "Test case 2: ";
    printList(result2); // Expected output: (empty list)
    deleteList(result2);

    // Test case 3: No duplicates
    ListNode *test3 = createList({1, 2, 3, 4, 5});
    ListNode *result3 = solution.deleteDuplicates(test3);
    cout << "Test case 3: ";
    printList(result3); // Expected output: 1 2 3 4 5
    deleteList(result3);

    // Test case 4: Single element
    ListNode *test4 = createList({1});
    ListNode *result4 = solution.deleteDuplicates(test4);
    cout << "Test case 4: ";
    printList(result4); // Expected output: 1
    deleteList(result4);

    // Test case 5: Empty list
    ListNode *test5 = createList({});
    ListNode *result5 = solution.deleteDuplicates(test5);
    cout << "Test case 5: ";
    printList(result5); // Expected output: (empty list)
    deleteList(result5);

    // Test case 6: Large input with duplicates
    vector<int> largeInput(1000, 1);
    largeInput.insert(largeInput.end(), {2, 3, 3, 4, 4, 5});
    ListNode *test6 = createList(largeInput);
    ListNode *result6 = solution.deleteDuplicates(test6);
    cout << "Test case 6: ";
    printList(result6); // Expected output: 2 5
    deleteList(result6);

    return 0;
}