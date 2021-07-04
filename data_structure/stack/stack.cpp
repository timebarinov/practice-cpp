#include <vector>

template <typename T>
class Stack {
public:

    Stack() = default;

    void Push(const T& elem) {
        stack.push_back(elem);
    }

    void Pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
    } 

    int Size() {
        return stack.size();
    }

    bool Empty() {
        return stack.size();
    }

    T& Top() {
        if (!stack.empty()) {
            return stack.back();
        }
    }

private:
    std::vector<T> stack;
};
