class Node {
public:
    int val;
    Node* next;

    Node(int item) : val(item), next(nullptr) {}
};

class circular_LinkedList {
private:
    Node* head;
    int len = 0;

public:
    circular_LinkedList() {
        head = nullptr;
        len = 0;
    }

    bool isempty() { return head == nullptr; }
    int size() { return len; }

    void insertFront(int item) {
        Node* node = new Node(item);

        if (isempty()) {
            head = node;
            node->next = head;
        } else {
            Node* trav = head;
            while (trav->next != head)
                trav = trav->next;

            trav->next = node;
            node->next = head;
            head = node;
        }

        len++;
    }

    void insertLast(int item) {
        Node* node = new Node(item);
        if (isempty()) {
            head = node;
            node->next = head;
        } else {
            Node* trav = head;
            while (trav->next != head)
                trav = trav->next;

            trav->next = node;
            node->next = head;
        }
        len++;
    }

    bool deleteFront() {
        if (isempty())
            return false;

        Node* del = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* trav = head;
            while (trav->next != head)
                trav = trav->next;

            head = head->next;
            trav->next = head;
        }

        delete del;
        len--;

        return true;
    }

    bool deleteLast() {
        if (isempty())
            return false;

        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* trav = head;
            while (trav->next->next != head)
                trav = trav->next;

            delete trav->next;
            trav->next = head;
        }

        len--;
        return true;
    }

    int getFront() {
        if (isempty())
            return -1;

        return head->val;
    }

    int getLast() {
        if (isempty())
            return -1;

        if (!head->next) {
            return head->val;
        }

        Node* cur = head;
        while (cur->next != head)
            cur = cur->next;

        return cur->val;
    }
};

class MyCircularDeque {
    circular_LinkedList ls;
    int Max;

public:
    MyCircularDeque(int k) { Max = k; }

    bool insertFront(int value) {
        if (ls.size() == Max)
            return false;

        ls.insertFront(value);
        return true;
    }

    bool insertLast(int value) {
        if (ls.size() == Max)
            return false;

        ls.insertLast(value);
        return true;
    }

    bool deleteFront() { return ls.deleteFront(); }

    bool deleteLast() { return ls.deleteLast(); }

    int getFront() { return ls.getFront(); }

    int getRear() { return ls.getLast(); }

    bool isEmpty() { return ls.size() == 0; }

    bool isFull() { return ls.size() == Max; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
