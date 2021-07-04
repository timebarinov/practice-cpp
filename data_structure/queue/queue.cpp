template<typename T>
class Queue {
public:
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        Clear();
    }

    // вставляем всегда в конец
    void Push(const T& value) {
        Node* tmp = new Node();
        tmp->data = value;
        tmp->next = nullptr;
        if (head == nullptr) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void Pop() {
        Node* tmp = head;
        head = head->next;
        delete tmp; 
    }

    T& Top() {
        return head->data;
    }

    bool Empty() {
        return head == nullptr;
    }

    void Clear() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
    }

private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
};
