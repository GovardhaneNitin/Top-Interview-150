#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast)
        {
            if (!fast || !fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

void runTests()
{
    Solution solution;

    // Test Case 1: Empty list
    ListNode *head1 = nullptr;
    cout << "Test Case 1: " << (solution.hasCycle(head1) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: No Cycle

    // Test Case 2: Single node without cycle
    ListNode *head2 = new ListNode(1);
    cout << "Test Case 2: " << (solution.hasCycle(head2) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: No Cycle

    // Test Case 3: Single node with cycle
    ListNode *head3 = new ListNode(1);
    head3->next = head3;
    cout << "Test Case 3: " << (solution.hasCycle(head3) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: Cycle Detected

    // Test Case 4: Multiple nodes without cycle
    ListNode *head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    cout << "Test Case 4: " << (solution.hasCycle(head4) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: No Cycle

    // Test Case 5: Multiple nodes with cycle
    ListNode *head5 = new ListNode(1);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(3);
    head5->next->next->next = head5->next; // Cycle created
    cout << "Test Case 5: " << (solution.hasCycle(head5) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: Cycle Detected

    // Test Case 6: Two nodes with cycle
    ListNode *head6 = new ListNode(1);
    head6->next = new ListNode(2);
    head6->next->next = head6; // Cycle created
    cout << "Test Case 6: " << (solution.hasCycle(head6) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: Cycle Detected

    // Test Case 7: Large list without cycle
    ListNode *head7 = new ListNode(1);
    ListNode *current = head7;
    for (int i = 2; i <= 10000; ++i)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    cout << "Test Case 7: " << (solution.hasCycle(head7) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: No Cycle

    // Test Case 8: Large list with cycle
    ListNode *head8 = new ListNode(1);
    current = head8;
    ListNode *cycleNode = nullptr;
    for (int i = 2; i <= 10000; ++i)
    {
        current->next = new ListNode(i);
        current = current->next;
        if (i == 5000)
            cycleNode = current; // Mark the cycle start
    }
    current->next = cycleNode; // Create cycle
    cout << "Test Case 8: " << (solution.hasCycle(head8) ? "Cycle Detected" : "No Cycle") << endl;
    // Expected Output: Cycle Detected
}

int main()
{
    runTests();
    return 0;
}