#include "raw_memory.h"

template <typename T>
class Vector {
public:
    Vector() = default;
    Vector(size_t n);
    Vector(const Vector& other);
    Vector(Vector&& other);

    ~Vector();

    Vector& operator = (const Vector& other);
    Vector& operator = (Vector&& other) noexcept;

    void Reserve(size_t n);

    void Resize(size_t n);

    void PushBack(const T& elem);
    void PushBack(T&& elem);

    template <typename ... Args>
    T& EmplaceBack(Args&&... args);

    void PopBack();

    size_t Size() const noexcept;

    size_t Capacity() const noexcept;

    void Swap(Vector& other);

    const T& operator[](size_t i) const;
    T& operator[](size_t i);

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() noexcept;
    iterator end() noexcept;

    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    iterator Insert(const_iterator pos, const T& elem);
    iterator Insert(const_iterator pos, T&& elem);

    template <typename ... Args>
    iterator Emplace(const_iterator it, Args&&... args);

    iterator Erase(const_iterator it);

private:
    RawMemory<T> data;
    size_t size = 0;
};


template<typename T>
Vector<T>::Vector(size_t n) : data(n) {
    std::uninitialized_value_construct_n(data.buf, n);
    size = n;
}

template<typename T>
Vector<T>::Vector(const Vector& other) : data(other.size) {
    std::uninitialized_copy_n(other.data.buf, other.size, data.buf);
    size = other.size;
}

template<typename T>
Vector<T>::Vector(Vector&& other) {
    Swap(other);
}

template<typename T>
Vector<T>::~Vector() {
    std::destroy_n(data.buf, size);
}

template<typename T>
Vector<T>& Vector<T>::operator = (const Vector& other) {
    if (this == &other) return *this;
    if (other.size > data.cap) {
        Vector<T> tmp(other);
        Swap(tmp);
    }
    else {
        for (size_t i = 0; i < size && i < other.size; ++i) {
            data[i] = other[i];
        }
        if (size > other.size) {
            std::destroy_n(data.buf + other.size, size - other.size);
        }
        else if (size < other.size) {
            std::uninitialized_copy_n(
                other.data.buf + size, other.size - size, data.buf + size
            );
        }
    }
    size = other.size;
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator = (Vector&& other) noexcept {
    Swap(other);
    return *this;
}

template<typename T>
void Vector<T>::Reserve(size_t n) {
    if (n > data.cap) {
        RawMemory<T> tmp(n);
        std::uninitialized_move_n(data.buf, size, tmp.buf);
        std::destroy_n(data.buf, size);
        data.Swap(tmp);
    }
}

template<typename T>
void Vector<T>::Resize(size_t n) {
    Reserve(n);
    if (n < size) {
        std::destroy_n(data.buf + n, size - n);
    }
    else if (size < n) {
        std::uninitialized_value_construct_n(
            data.buf + size, n - size
        );
    }
    size = n;
}

template<typename T>
void Vector<T>::PushBack(const T& elem) {
    if (data.cap == size) {
        Reserve(size == 0 ? 1 : size * 2);
    }
    new (data + size) T(elem);
    ++size;
}

template<typename T>
void Vector<T>::PushBack(T&& elem) {
    if (data.cap == size) {
        Reserve(size == 0 ? 1 : size * 2);
    }
    new (data + size) T(std::move(elem));
    ++size;
}

template<typename T>
template <typename ... Args>
T& Vector<T>::EmplaceBack(Args&&... args) {
    if (data.cap == size) {
        Reserve(size == 0 ? 1 : size * 2);
    }
    auto elem = new (data + size) T(std::forward<Args>(args)...);
    ++size;
    return *elem;
}

template<typename T>
void Vector<T>::PopBack() {
    std::destroy_at(data + size - 1);
    size--;
}

template<typename T>
size_t Vector<T>::Size() const noexcept {
    return size;
}

template<typename T>
size_t Vector<T>::Capacity() const noexcept {
    return data.cap;
}

template<typename T>
void Vector<T>::Swap(Vector& other) {
    data.Swap(other.data);
    std::swap(size, other.size);
}

template<typename T>
const T& Vector<T>::operator[](size_t i) const {
    return data[i];
}

template<typename T>
T& Vector<T>::operator[](size_t i) {
    return data[i];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() noexcept {
    return data.buf;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() noexcept {
    return data + size;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const noexcept {
    return data.buf;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::end() const noexcept {
    return data + size;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const noexcept {
    return data.buf;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const noexcept {
    return data + size;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::Insert(const_iterator pos, const T& elem) {
    if (size == 0) {
        PushBack(elem);
        return begin();
    }
    const size_t pos_i = pos - cbegin();
    if (size == data.cap) {
        RawMemory<T> tmp(size == 0 ? 1 : size * 2);
        std::uninitialized_move_n(data.buf, pos_i, tmp.buf);
        std::destroy_n(data.buf, pos_i);
        new (tmp + pos_i) T(elem);
        std::uninitialized_move_n(data + pos_i, size - pos_i, tmp + pos_i + 1);
        std::destroy_n(data + pos_i, size - pos_i);
        data.Swap(tmp);
        size++;
        return data + pos_i;
    }
    else {
        for (auto i = end() - 1; i >= pos; --i) {
            std::uninitialized_move_n(i, 1, i + 1);
            std::destroy_at(i);
        }
        size++;
        new (data + pos_i) T(elem);
        return data + pos_i;
    }
}

template<typename T>
typename Vector<T>::iterator Vector<T>::Insert(const_iterator pos, T&& elem) {
    if (size == 0) {
        PushBack(std::move(elem));
        return begin();
    }
    const size_t pos_i = pos - cbegin();
    if (size == data.cap) {
        RawMemory<T> tmp(size == 0 ? 1 : size * 2);
        std::uninitialized_move_n(data.buf, pos_i, tmp.buf);
        std::destroy_n(data.buf, pos_i);
        new (tmp + pos_i) T(std::move(elem));
        std::uninitialized_move_n(data + pos_i, size - pos_i, tmp + pos_i + 1);
        std::destroy_n(data + pos_i, size - pos_i);
        data.Swap(tmp);
        size++;
        return data + pos_i;
    }
    else {
        for (auto i = end() - 1; i >= pos; --i) {
            std::uninitialized_move_n(i, 1, i + 1);
            std::destroy_at(i);
        }
        size++;
        new (data + pos_i) T(std::move(elem));
        return data + pos_i;
    }
}

template<typename T>
template <typename ... Args>
typename Vector<T>::iterator Vector<T>::Emplace(const_iterator pos, Args&&... args) {
    return Insert(pos, T(std::forward<Args>(args)...));
}

template<typename T>
typename Vector<T>::iterator Vector<T>::Erase(const_iterator pos) {
    size_t pos_i = pos - cbegin();
    std::destroy_at(pos);
    for (auto i = data + pos_i + 1; i < end(); ++i) {
        std::uninitialized_move_n(i, 1, i - 1);
        std::destroy_at(i);
    }
    size--;
    return data + pos_i;
}
