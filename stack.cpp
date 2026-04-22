#include "stack.h"
#include <stdexcept>

void init(Stack* s) {
    s->top = nullptr;
}

bool isEmpty(const Stack* s) {
    return s->top == nullptr;
}

bool isFull(const Stack* s) {
    // Karena data adalah array statis, stack penuh jika pointer top berada di elemen terakhir
    return s->top == &(s->data[MAX - 1]);
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        throw std::overflow_error("Stack Overflow: Tidak bisa push, stack penuh.");
    }
    if (isEmpty(s)) {
        s->top = s->data; // Set top ke elemen pertama array
    } else {
        s->top++;         // Geser pointer ke memori selanjutnya
    }
    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        throw std::underflow_error("Stack Underflow: Tidak bisa pop, stack kosong.");
    }
    if (s->top == s->data) {
        s->top = nullptr; // Reset ke null jika sisa 1 elemen
    } else {
        s->top--;
    }
}

int peek(const Stack* s) {
    if (isEmpty(s)) {
        throw std::underflow_error("Stack Underflow: Stack kosong.");
    }
    return *(s->top);
}