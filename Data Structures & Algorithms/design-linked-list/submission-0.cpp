//absolutly hated this probblem
#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;

        Node(int x) {
            val = x;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);

        // empty list
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);

        // empty list
        if (tail == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        // add at front
        if (index == 0) {
            addAtHead(val);
            return;
        }

        // add at end
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* current = head;

        // move current to the node currently at index
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        Node* node = new Node(val);
        Node* before = current->prev;

        // before <-> node
        before->next = node;
        node->prev = before;

        // node <-> current
        node->next = current;
        current->prev = node;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        // only one node in the list
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }

        // delete head
        else if (current == head) {
            head = head->next;
            head->prev = nullptr;
        }

        // delete tail
        else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }

        // delete middle node
        else {
            Node* before = current->prev;
            Node* after = current->next;

            before->next = after;
            after->prev = before;
        }

        delete current;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */