#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
using namespace std;

//=========================================
// Heap Node
//=========================================
class HeapNode {
private:
    int key;
    int u;
    int v;

public:
    HeapNode(int k = 0, int _u = 0, int _v = 0) {
        key = k;
        u = _u;
        v = _v;
    }

    int getKey() const {
        return key;
    }

    int getU() const {
        return u;
    }

    int getV() const {
        return v;
    }

    void setKey(int k, int _u, int _v) {
        key = k;
        u = _u;
        v = _v;
    }
};

//=========================================
// Min Heap
//=========================================
class MinHeap {
private:
    HeapNode* node;
    int capacity;
    int size;

public:
    MinHeap(int cap = 100) {
        capacity = cap;
        size = 0;
        node = new HeapNode[capacity + 1];
    }

    ~MinHeap() {
        delete[] node;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    HeapNode getParent(int i) {
        return node[i / 2];
    }

    HeapNode getLeft(int i) {
        return node[i * 2];
    }

    HeapNode getRight(int i) {
        return node[i * 2 + 1];
    }

    //=========================================
    // INSERT
    //=========================================
    void insert(int key, int u, int v) {
        if (isFull()) return;

        int i = ++size;

        while (i != 1 && key < getParent(i).getKey()) {
            node[i] = getParent(i);
            i /= 2;
        }

        node[i].setKey(key, u, v);
    }

    //=========================================
    // DELETE MIN
    //=========================================
    HeapNode remove() {
        HeapNode root = node[1];

        HeapNode last = node[size--];

        int parent = 1;
        int child = 2;

        while (child <= size) {

            if (child < size &&
                node[child].getKey() > node[child + 1].getKey()) {
                child++;
            }

            if (last.getKey() <= node[child].getKey())
                break;

            node[parent] = node[child];

            parent = child;
            child *= 2;
        }

        node[parent] = last;

        return root;
    }

    //=========================================
    // PRINT HEAP
    //=========================================
    void display() {
        for (int i = 1; i <= size; i++) {
            cout << "("
                << node[i].getKey() << ", "
                << node[i].getU() << ", "
                << node[i].getV() << ") ";
        }
        cout << endl;
    }
};

#endif
