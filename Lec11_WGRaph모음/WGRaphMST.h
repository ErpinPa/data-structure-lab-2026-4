
#ifndef WGRAPHMST_H
#define WGRAPHMST_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

//=========================================================
// Heap Node
//=========================================================
class HeapNode {
private:
    int key;
    int v1;
    int v2;

public:
    HeapNode(int k = 0, int u = 0, int v = 0) {
        key = k;
        v1 = u;
        v2 = v;
    }

    int getKey() {
        return key;
    }

    int getV1() {
        return v1;
    }

    int getV2() {
        return v2;
    }

    void setKey(int k, int u, int v) {
        key = k;
        v1 = u;
        v2 = v;
    }
};

//=========================================================
// Min Heap
//=========================================================
class MinHeap {
private:
    HeapNode node[100];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 99;
    }

    HeapNode getParent(int i) {
        return node[i / 2];
    }

    void insert(int key, int u, int v) {

        if (isFull()) return;

        int i = ++size;

        while (i != 1 && key < getParent(i).getKey()) {
            node[i] = getParent(i);
            i /= 2;
        }

        node[i].setKey(key, u, v);
    }

    HeapNode remove() {

        HeapNode item = node[1];
        HeapNode temp = node[size--];

        int parent = 1;
        int child = 2;

        while (child <= size) {

            if (child < size &&
                node[child].getKey() > node[child + 1].getKey())
                child++;

            if (temp.getKey() <= node[child].getKey())
                break;

            node[parent] = node[child];

            parent = child;
            child *= 2;
        }

        node[parent] = temp;

        return item;
    }
};

//=========================================================
// Disjoint Set
//=========================================================
class VertexSets {
private:
    int parent[100];
    int size;

public:
    VertexSets(int n = 0) {

        size = n;

        for (int i = 0; i < size; i++)
            parent[i] = -1;
    }

    int findSet(int id) {

        while (parent[id] >= 0)
            id = parent[id];

        return id;
    }

    void unionSets(int s1, int s2) {
        parent[s1] = s2;
    }
};

//=========================================================
// Weighted Graph
//=========================================================
class WGraph {
protected:
    int size;
    char vertices[100];
    int adj[100][100];

public:

    WGraph() {

        size = 0;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                adj[i][j] = 0;
            }
        }
    }

    bool hasEdge(int i, int j) {
        return adj[i][j] != 0 && adj[i][j] != 9999;
    }

    int getEdge(int i, int j) {
        return adj[i][j];
    }

    char getVertex(int i) {
        return vertices[i];
    }

    void load(const char* filename) {

        ifstream fin(filename);

        if (!fin) {
            cout << "파일 열기 실패!" << endl;
            return;
        }

        fin >> size;

        for (int i = 0; i < size; i++)
            fin >> vertices[i];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fin >> adj[i][j];
            }
        }

        fin.close();
    }

    void display() {

        cout << endl;

        cout << "    ";

        for (int i = 0; i < size; i++) {
            cout << setw(5) << vertices[i];
        }

        cout << endl;

        for (int i = 0; i < size; i++) {

            cout << setw(3) << vertices[i] << " ";

            for (int j = 0; j < size; j++) {

                if (adj[i][j] == 9999)
                    cout << setw(5) << "INF";
                else
                    cout << setw(5) << adj[i][j];
            }

            cout << endl;
        }
    }
};

//=========================================================
// Kruskal MST
//=========================================================
class WGraphMST : public WGraph {

public:

    void Kruskal() {

        MinHeap heap;

        for (int i = 0; i < size - 1; i++) {

            for (int j = i + 1; j < size; j++) {

                if (hasEdge(i, j))
                    heap.insert(getEdge(i, j), i, j);
            }
        }

        VertexSets set(size);

        int edgeAccepted = 0;

        while (edgeAccepted < size - 1) {

            HeapNode e = heap.remove();

            int uset = set.findSet(e.getV1());
            int vset = set.findSet(e.getV2());

            if (uset != vset) {

                printf("간선 추가 : %c - %c (비용:%d)\n",
                    getVertex(e.getV1()),
                    getVertex(e.getV2()),
                    e.getKey());

                set.unionSets(uset, vset);

                edgeAccepted++;
            }
        }
    }
};

#endif
