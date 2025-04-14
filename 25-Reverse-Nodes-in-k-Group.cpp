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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr = &dummy, *nex = &dummy, *pre = &dummy;
        int count = 0;
        while (curr->next)
        {
            curr = curr->next;
            count++;
        }
        while (count >= k)
        {
            curr = pre->next;
            nex = curr->next;
            for (int i = 1; i < k; ++i)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count -= k;
        }
        return dummy.next;
    }
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

// Helper function to print a vector
void printVector(const vector<int> &vec)
{
    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}

// Test cases
int main()
{
    Solution solution;

    // Test case 1: Basic case
    ListNode *head1 = createLinkedList({1, 2, 3, 4, 5});
    int k1 = 2;
    ListNode *result1 = solution.reverseKGroup(head1, k1);
    vector<int> output1 = linkedListToVector(result1);
    cout << "Test case 1: ";
    printVector(output1); // Expected output: 2 1 4 3 5

    // Test case 2: k is greater than the length of the list
    ListNode *head2 = createLinkedList({1, 2, 3});
    int k2 = 5;
    ListNode *result2 = solution.reverseKGroup(head2, k2);
    vector<int> output2 = linkedListToVector(result2);
    cout << "Test case 2: ";
    printVector(output2); // Expected output: 1 2 3

    // Test case 3: k is 1 (no reversal)
    ListNode *head3 = createLinkedList({1, 2, 3, 4});
    int k3 = 1;
    ListNode *result3 = solution.reverseKGroup(head3, k3);
    vector<int> output3 = linkedListToVector(result3);
    cout << "Test case 3: ";
    printVector(output3); // Expected output: 1 2 3 4

    // Test case 4: Empty list
    ListNode *head4 = nullptr;
    int k4 = 3;
    ListNode *result4 = solution.reverseKGroup(head4, k4);
    vector<int> output4 = linkedListToVector(result4);
    cout << "Test case 4: ";
    printVector(output4); // Expected output: (empty)

    // Test case 5: List with repeated values
    ListNode *head5 = createLinkedList({1, 1, 1, 1});
    int k5 = 2;
    ListNode *result5 = solution.reverseKGroup(head5, k5);
    vector<int> output5 = linkedListToVector(result5);
    cout << "Test case 5: ";
    printVector(output5); // Expected output: 1 1 1 1

    // Test case 6: Large input
    vector<int> largeInput(1000, 1); // List of 1000 nodes with value 1
    ListNode *head6 = createLinkedList(largeInput);
    int k6 = 500;
    ListNode *result6 = solution.reverseKGroup(head6, k6);
    vector<int> output6 = linkedListToVector(result6);
    cout << "Test case 6: ";
    printVector(output6); // Expected output: (500 reversed, followed by 500 reversed)

    return 0;
}