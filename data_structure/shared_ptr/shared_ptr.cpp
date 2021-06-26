#include <cstddef>
#include <utility>

template <typename T>
class SharedPtr {
public:
    SharedPtr() : ptr_(nullptr), ptr_count_(nullptr) {}

    explicit SharedPtr(T* ptr) : ptr_(ptr), ptr_count_(nullptr){
        ptr_count_ = new int(1);
    }

    SharedPtr(const SharedPtr& other) {
        ptr_ = other.ptr_;
        ptr_count_ = other.ptr_count_;
        *ptr_count_++;
    }

    SharedPtr(SharedPtr&& other) : ptr_(std::move(other.ptr_)), ptr_count_(std::move(other.ptr_count_)) {
        Reset(other);
    }
    
    SharedPtr& operator = (const SharedPtr& other) {        
        ptr_ = other.ptr_;
        ptr_count_ = other.ptr_count_;
        *ptr_count_++;
        return *this;
    }

    SharedPtr& operator = (SharedPtr&& other) {
        if (this != &other) {
            ptr_ = other.ptr_;
            ptr_count_ = other.ptr_count_;
            Reset(other);
        }
        return *this;
    }

    ~SharedPtr() {        
        if (ptr_count_) {
            if (--(*ptr_count_) == 0) {
                delete ptr_;
                delete ptr_count_;
            }
        }
    }

    T& operator * () const {
        return *ptr_;
    }

    T* operator -> () const {
        return ptr_;
    }

    void Reset(T* ptr) {
        ptr_ = nullptr;
        ptr_count_ = nullptr;
    }

    void Swap(SharedPtr& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(ptr_count_, other.ptr_count_);
    }

    T* Get() const {
        return ptr_;
    }

private:
    T* ptr_;
    int* ptr_count_;
};
