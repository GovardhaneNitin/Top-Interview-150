#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lessHead = new ListNode(0);
        ListNode *greaterHead = new ListNode(0);
        ListNode *less = lessHead;
        ListNode *greater = greaterHead;

        while (head)
        {
            if (head->val < x)
            {
                less->next = head;
                less = less->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr;
        less->next = greaterHead->next;

        ListNode *newHead = lessHead->next;
        delete lessHead;
        delete greaterHead;

        return newHead;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void runTestCases()
{
    Solution solution;

    // Test Case 1: Basic case
    ListNode *head1 = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    int x1 = 3;
    std::cout << "Test Case 1: ";
    printList(solution.partition(head1, x1)); // Expected output: 1 2 2 4 3 5

    // Test Case 2: All nodes less than x
    ListNode *head2 = new ListNode(1, new ListNode(2, new ListNode(2)));
    int x2 = 3;
    std::cout << "Test Case 2: ";
    printList(solution.partition(head2, x2)); // Expected output: 1 2 2

    // Test Case 3: All nodes greater than or equal to x
    ListNode *head3 = new ListNode(4, new ListNode(5, new ListNode(6)));
    int x3 = 3;
    std::cout << "Test Case 3: ";
    printList(solution.partition(head3, x3)); // Expected output: 4 5 6

    // Test Case 4: Mixed values with duplicates
    ListNode *head4 = new ListNode(3, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(4))))));
    int x4 = 3;
    std::cout << "Test Case 4: ";
    printList(solution.partition(head4, x4)); // Expected output: 1 2 2 3 3 4

    // Test Case 5: Single node
    ListNode *head5 = new ListNode(1);
    int x5 = 2;
    std::cout << "Test Case 5: ";
    printList(solution.partition(head5, x5)); // Expected output: 1

    // Test Case 6: Empty list
    ListNode *head6 = nullptr;
    int x6 = 1;
    std::cout << "Test Case 6: ";
    printList(solution.partition(head6, x6)); // Expected output: (empty)

    // Test Case 7: Large input
    ListNode *head7 = new ListNode(1);
    ListNode *current = head7;
    for (int i = 2; i <= 1000; ++i)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    int x7 = 500;
    std::cout << "Test Case 7: ";
    printList(solution.partition(head7, x7)); // Expected output: Nodes < 500 followed by nodes >= 500
}

int main()
{
    runTestCases();
    return 0;
}