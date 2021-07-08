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
        return IndexOf(index)->value;
    }

private:    
    Node* head = nullptr;
    Node* tail = nullptr;      
    int size = 0;

    
    int cached_index = 0;
    Node* cached_node = nullptr;
    
    Node* IndexOf(int index);
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
    auto new_node = new Node{value};
    new_node->next = head;
    head = new_node;
    size++;
}

template <typename T>
void LinkedList<T>::PushBack(const T& value) {
    auto new_node = new Node{value};
    new_node->next = nullptr;
    if (head) {
        tail->next = new_node;
        tail = new_node;
    }
    else {
        head = new_node;
        tail = new_node;
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
    cached_index = 0;
    cached_node = nullptr;
}

template <typename T>
void LinkedList<T>::PopBack() {
    if (size <= 0) {
        return;
    }
    
    if (size >= 2) {
        Node* new_tail = IndexOf(size - 2);
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
    cached_index = 0;
    cached_node = nullptr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::IndexOf(int index) {
    if (cached_index < index && cached_node) {
        Node* tmp = cached_node;
        for(int i = cached_index; i < index; i++) {
            tmp = tmp->next;                
            cached_index++; 
        }
        cached_node = tmp;
        return tmp;
    }
    else {
        Node* tmp = head;
        cached_index = 0;
        for(int i = 0; i < index; i++) {
            tmp = tmp->next;
            cached_index++;
        }
        cached_node = tmp;
        return tmp;
    }
}
