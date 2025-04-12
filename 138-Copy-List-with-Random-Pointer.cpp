#include <iostream>
#include <vector>
using namespace std;

// Solution class to copy the list with random pointers
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // Step 1: Create new nodes and interleave them with the original nodes
        Node *curr = head;
        while (curr)
        {
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign random pointers for the new nodes
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied lists
        Node *newHead = head->next;
        curr = head;
        while (curr)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            if (temp->next)
                temp->next = temp->next->next;
            curr = curr->next;
        }

        return newHead;
    }
};

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// Helper function to print the list for verification
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << "Value: " << temp->val;
        if (temp->random)
        {
            cout << ", Random points to: " << temp->random->val;
        }
        else
        {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

// Test cases
int main()
{
    Solution solution;

    // Test Case 1: Empty list
    Node *head1 = nullptr;
    Node *result1 = solution.copyRandomList(head1);
    cout << "Test Case 1: Empty list" << endl;
    printList(result1); // Expected output: (no output, as the list is empty)

    // Test Case 2: Single node with no random pointer
    Node *head2 = new Node(1);
    Node *result2 = solution.copyRandomList(head2);
    cout << "Test Case 2: Single node with no random pointer" << endl;
    printList(result2); // Expected output: Value: 1, Random points to: NULL

    // Test Case 3: Single node with random pointer pointing to itself
    Node *head3 = new Node(1);
    head3->random = head3;
    Node *result3 = solution.copyRandomList(head3);
    cout << "Test Case 3: Single node with random pointer pointing to itself" << endl;
    printList(result3); // Expected output: Value: 1, Random points to: 1

    // Test Case 4: Multiple nodes with no random pointers
    Node *head4 = new Node(1);
    head4->next = new Node(2);
    head4->next->next = new Node(3);
    Node *result4 = solution.copyRandomList(head4);
    cout << "Test Case 4: Multiple nodes with no random pointers" << endl;
    printList(result4); // Expected output: Value: 1, Random points to: NULL
                        //                 Value: 2, Random points to: NULL
                        //                 Value: 3, Random points to: NULL

    // Test Case 5: Multiple nodes with random pointers forming a chain
    Node *head5 = new Node(1);
    head5->next = new Node(2);
    head5->next->next = new Node(3);
    head5->random = head5->next;             // 1 -> 2
    head5->next->random = head5->next->next; // 2 -> 3
    head5->next->next->random = head5;       // 3 -> 1
    Node *result5 = solution.copyRandomList(head5);
    cout << "Test Case 5: Multiple nodes with random pointers forming a chain" << endl;
    printList(result5); // Expected output: Value: 1, Random points to: 2
                        //                 Value: 2, Random points to: 3
                        //                 Value: 3, Random points to: 1

    // Test Case 6: Multiple nodes with random pointers forming a cycle
    Node *head6 = new Node(1);
    head6->next = new Node(2);
    head6->next->next = new Node(3);
    head6->random = head6->next->next;       // 1 -> 3
    head6->next->random = head6;             // 2 -> 1
    head6->next->next->random = head6->next; // 3 -> 2
    Node *result6 = solution.copyRandomList(head6);
    cout << "Test Case 6: Multiple nodes with random pointers forming a cycle" << endl;
    printList(result6); // Expected output: Value: 1, Random points to: 3
                        //                 Value: 2, Random points to: 1
                        //                 Value: 3, Random points to: 2

    return 0;
}