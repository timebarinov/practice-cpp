#include <memory>

template <typename T>
struct RawMemory {
    T* buf = nullptr;
    size_t cap = 0;

    static T* Allocate(size_t n) {
        return static_cast<T*>(operator new(sizeof(T) * n));
    }

    static void Deallocate(T* buf) {
        operator delete(buf);
    }

    RawMemory() = default;

    RawMemory(size_t n) {
        buf = Allocate(n);
        cap = n;
    }

    void Swap(RawMemory& other) {
        std::swap(buf, other.buf);
        std::swap(cap, other.cap);
    }

    RawMemory(const RawMemory& other) = delete;

    RawMemory(RawMemory&& other) {
        Swap(other);
    }

    RawMemory& operator = (const RawMemory& other) = delete;
    
    RawMemory& operator = (RawMemory&& other) {
        Swap(other);
        return *this;
    }

    T* operator + (size_t index) {
        return buf + index;
    }
    const T* operator + (size_t index) const {
        return buf + index;
    }

    T& operator [] (size_t index) {
        return buf[index];
    }
    const T& operator [] (size_t index) const {
        return buf[index];
    }

    ~RawMemory() {
        Deallocate(buf);
    }
};
