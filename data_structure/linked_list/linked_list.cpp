template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };
    
    explicit LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList();

    void PushFront(const T& value);

    void PushBack(const T& value);

    void PopFront();

    void PopBack();

    T& Top() { 
        return head->value; 
    }
    const T& Top() const { 
        return head->value; 
    }

    T& Back() { 
        return tail->value; 
    }
    const T& Back() const { 
        return tail->value; 
    }

    int Size() const { 
        return size; 
    }

    bool Empty() const { 
        return head == nullptr;
    }

    inline T& operator [](int index) {
        return Find(index)->value;
    }
private:
    Node* head = nullptr;
    Node* tail = nullptr;      
    int size = 0;

    Node* Find(int index) {
        Node* tmp = head;
        for(int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp;
    }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        PopFront();
    }
}

template <typename T>
void LinkedList<T>::PushFront(const T& value) {
    if (size == 0) {
        PushBack(value);
    }
    auto node = new Node{value};
    node->next = head;
    head = node;
    size++;
}

template <typename T>
void LinkedList<T>::PushBack(const T& value) {
    auto node = new Node{value};
    node->next = nullptr;
    if (head) {
        tail->next = node;
        tail = node;
    }
    else {
        head = node;
        tail = node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::PopFront() {
    if (size <= 0) {
        return;
    }

    if (size > 1) {
        Node* new_head = head->next;
        delete head;
        head = new_head;
        size--;
    }
    else {
        delete(head);
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
}

template <typename T>
void LinkedList<T>::PopBack() {
    if (size <= 0) {
        return;
    }
    
    if (size >= 2) {
        Node* new_tail = Find(size - 2);
        delete(new_tail->next);
        new_tail->next = nullptr;
        tail = new_tail;
        size--;
    }
    else {
        delete(head);
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
}
