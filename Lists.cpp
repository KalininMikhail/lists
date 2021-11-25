#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};
struct list {
    Node* firstEl;
    Node* lastEl;
    bool isEmpty() {
        return firstEl == nullptr;
    }
    void pushBack(int val) {// adding element to the end of a list (task 1)
        Node* l = new Node(val);
        if (isEmpty()) {
            firstEl = l;
            lastEl = l;
            return;
        }
        lastEl->next = l;
        lastEl = l;
    }
    void demonstrate() { // demonstrating list (task 1)
        if (isEmpty()) {
            return;
        }
        Node* f = firstEl;
        while (f) {
            cout << f->value << " ";
            f = f->next;
        }
        cout << " " << endl;
    }
    void change() { // task 2
        if (isEmpty()) {
            return;
        }
        Node* f = firstEl;
        while (f) {
            if ((f->value) % 2 == 0) {
                f->value /= 2;
            }
            else {
                f->value = 3 * (f->value) - 1;
            }
            f = f->next;
        }
    }
    void reverse() {
        Node* p = firstEl,
            * q = nullptr,
            * r;

        while (p != nullptr) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        firstEl = q;
    }
}
int main() {
    int N;
    cin >> N;
    list Test;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        Test.pushBack(val);
    }
    Test.reverse();
    Test.demonstrate();
}
