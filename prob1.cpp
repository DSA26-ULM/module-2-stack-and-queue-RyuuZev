#include "stack.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// ================= STACK IMPLEMENTATION =================

void init(Stack* s) {
    s->top = s->data - 1;
}

bool isEmpty(const Stack* s) {
    return s->top < s->data;
}

bool isFull(const Stack* s) {
    return s->top == s->data + MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) throw overflow_error("full");
    s->top++;
    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) throw underflow_error("empty");
    s->top--;
}

int peek(const Stack* s) {
    if (isEmpty(s)) throw underflow_error("empty");
    return *(s->top);
}

// ================= MAIN (SOAL 2) =================
#ifndef UNIT_TEST

int main() {
    Stack s;
    init(&s);

    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line);
    string token;

    while (ss >> token) {
        // angka
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            push(&s, stoi(token));
        }
        else {
            int b = peek(&s); pop(&s);
            int a = peek(&s); pop(&s);

            int res;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") res = a / b;

            push(&s, res);
        }
    }

    cout << peek(&s) << endl;
    return 0;
}

#endif