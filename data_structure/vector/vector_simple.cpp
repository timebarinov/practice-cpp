#include <utility>

using namespace std;

template <typename T>
class VectorSimple {
public:
    VectorSimple() = default;
    explicit VectorSimple(size_t size);
    ~VectorSimple();

    T& operator[](size_t index);

    T* begin();
    T* end();

    size_t Size() const;
    size_t Capacity() const;
    void PushBack(const T& value);
    void PushBack(T&& value);

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void ExpandIfNeeded();
};

template <typename T>
inline VectorSimple<T>::VectorSimple(size_t size)
    : data(new T[size])
    , size(size)
    , capacity(size)
{
}

template <typename T>
inline VectorSimple<T>::~VectorSimple() {
    delete[] data;
}

template <typename T>
inline T& VectorSimple<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
inline size_t VectorSimple<T>::Size() const {
    return size;
}

template <typename T>
inline size_t VectorSimple<T>::Capacity() const {
    return capacity;
}

template <typename T>
inline void VectorSimple<T>::PushBack(const T& value) {
    ExpandIfNeeded();
    data[size++] = value;
}

template <typename T>
inline void VectorSimple<T>::PushBack(T&& value) {
    ExpandIfNeeded();
    data[size++] = move(value);
}

template <typename T>
inline void VectorSimple<T>::ExpandIfNeeded() {
    if (size >= capacity) {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        move(begin(), end(), new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
}

template <typename T>
inline T* VectorSimple<T>::begin() {
    return data;
}

template <typename T>
inline T* VectorSimple<T>::end() {
    return data + size;
}
