/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // Recursive
#if 0
class Solution {
public:
    /// Strategy
    ///     - Goal: Reverse the links in the linked list with the returned pointer being the new head
    ///     - Algorithm: Walk to the end and return the last node but cache the current next
    ///     - Time Complexity: Linear
    ///     - Space Complexity: Linear
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        auto next = head->next;
        if (next == nullptr) {
            return head;
        }
        
        auto list = reverseList(head->next);
        next->next = head;
        head->next = nullptr;
        return list;
    }
};

#endif

// Iterative
class Solution {
public:
    /// Strategy
    ///     - Goal: Reverse the links in the linked list with the returned pointer being the new head
    ///     - Algorithm: Iteratively swap the current and next pointer until we reach the end
    ///     - Time Complexity: Linear
    ///     - Space Complexity: Constant
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr, *current = head;
        while (current != nullptr) {
            auto tmp = current->next;
            current->next = previous;
            previous = current;
            current = tmp;
        }

        return previous;
    }
};
