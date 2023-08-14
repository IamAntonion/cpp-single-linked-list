#pragma once
 
#include <stdexcept>
#include <algorithm>
#include <cassert>
#include <cstdlib>
 
template <typename Type>
class ArrayPtr {
public:
 
    ArrayPtr() = default;
 
    explicit ArrayPtr(size_t size) {
        if (size) {
            simple_vector_ = new Type[size]();
        } else{
            simple_vector_= nullptr;
        }
    }
 
    ArrayPtr(const ArrayPtr&) = delete;
 
    ~ArrayPtr() {
        delete[] simple_vector_;
    }
 
    ArrayPtr(const ArrayPtr& other, size_t other_size, size_t new_size) {
        simple_vector_ = new Type[new_size];
        std::copy(other.simple_vector_, other.simple_vector_ + other_size, simple_vector_);
    }
 
    Type& operator[](size_t index) noexcept {
        return simple_vector_[index];
    }
 
    const Type& operator[](size_t index) const noexcept {
        return simple_vector_[index];
    }
 
    explicit operator bool() const {
        return simple_vector_;
    }
 
    void swap(ArrayPtr& other) noexcept {
        std::swap(simple_vector_, other.simple_vector_);
    }
 
private:
    Type* simple_vector_ = nullptr;
};