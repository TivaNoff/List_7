#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;

        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            current->next = node;
            current = current->next;

            if (node->next) {
                minHeap.push(node->next);
            }
        }

        return dummy->next;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<ListNode*> lists1;
    lists1.push_back(new ListNode(1));
    lists1.push_back(new ListNode(4));
    lists1.push_back(new ListNode(5));
    lists1[0]->next = lists1[1];
    lists1[1]->next = lists1[2];

    vector<ListNode*> lists2;
    lists2.push_back(new ListNode(1));
    lists2.push_back(new ListNode(3));
    lists2.push_back(new ListNode(4));
    lists2[0]->next = lists2[1];
    lists2[1]->next = lists2[2];

    vector<ListNode*> lists3;
    lists3.push_back(new ListNode(2));
    lists3.push_back(new ListNode(6));
    lists3[0]->next = lists3[1];

    vector<ListNode*> lists = { lists1[0], lists2[0], lists3[0] };

    Solution solution;
    ListNode* mergedList = solution.mergeKLists(lists);
    cout << "Example 1 Output: ";
    printList(mergedList);

    vector<ListNode*> emptyLists;
    ListNode* mergedEmptyList = solution.mergeKLists(emptyLists);
    cout << "Example 2 Output: ";
    printList(mergedEmptyList);

    vector<ListNode*> singleEmptyList = { nullptr };
    ListNode* mergedSingleEmptyList = solution.mergeKLists(singleEmptyList);
    cout << "Example 3 Output: ";
    printList(mergedSingleEmptyList);

    return 0;
}
