#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int value;
    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int val = 0, SegmentTreeNode* l = nullptr, SegmentTreeNode* r = nullptr)
        : value(val), left(l), right(r) {}
};

class PersistentQueue {
public:
    PersistentQueue() : version_count(0), root(nullptr) {}

    void enqueue(int x) {
        version_count++;
        if (!root) {
            root = build(1, version_count);
        }
        root = update(root, 1, version_count, version_count, x);
    }

    int dequeue() {
        if (!root) {
            return -1; // Indicating an empty queue
        }
        return query(root, 1, version_count);
    }

    void rollback(int version) {
        if (version <= version_count) {
            root = versions[version - 1];
        }
    }

private:
    int version_count;
    SegmentTreeNode* root;
    vector<SegmentTreeNode*> versions;

    SegmentTreeNode* build(int start, int end) {
        versions = vector<SegmentTreeNode*>();
        if (start == end) {
            return new SegmentTreeNode();
        }
        int mid = (start + end) / 2;
        SegmentTreeNode* left = build(start, mid);
        SegmentTreeNode* right = build(mid + 1, end);
        return new SegmentTreeNode(0, left, right);
    }

    SegmentTreeNode* update(SegmentTreeNode* node, int start, int end, int index, int value) {
        if (start == end) {
            return new SegmentTreeNode(value);
        }
        int mid = (start + end) / 2;
        if (index <= mid) {
            SegmentTreeNode* left = update(node->left, start, mid, index, value);
            return new SegmentTreeNode(0, left, node->right);
        } else {
            SegmentTreeNode* right = update(node->right, mid + 1, end, index, value);
            return new SegmentTreeNode(0, node->left, right);
        }
    }

    int query(SegmentTreeNode* node, int start, int end) {
        if (start == end) {
            return node->value;
        }
        int mid = (start + end) / 2;
        if (node->left && node->left->value != 0) {
            return query(node->left, start, mid);
        } else {
            return query(node->right, mid + 1, end);
        }
    }
};

int main() {
    PersistentQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.dequeue() << endl; // Output: 1
    queue.enqueue(4);
    cout << queue.dequeue() << endl; // Output: 2
    queue.rollback(2);
    cout << queue.dequeue() << endl; // Output: 1

    return 0;
}
