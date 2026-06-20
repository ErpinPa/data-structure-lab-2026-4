#ifndef WGRAPHPRIM_H
#define WGRAPHPRIM_H

#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

#define MAX_VTXS 256
#define INF 9999

class WGraphPrim {
protected:
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];

public:
    WGraphPrim() {
        size = 0;

        for (int i = 0; i < MAX_VTXS; i++)
            for (int j = 0; j < MAX_VTXS; j++)
                adj[i][j] = INF;
    }

    char getVertex(int i) {
        return vertices[i];
    }

    int getEdge(int i, int j) {
        return adj[i][j];
    }

    //------------------------------------------------
    // 그래프 파일 읽기
    //------------------------------------------------
    void load(const char* filename)
    {
        ifstream fin(filename);

        if (!fin) {
            cout << "파일 열기 실패\n";
            return;
        }

        fin >> size;

        for (int i = 0; i < size; i++)
            fin >> vertices[i];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                fin >> adj[i][j];

        fin.close();
    }

    //------------------------------------------------
    // 그래프 출력
    //------------------------------------------------
    void display()
    {
        cout << endl;

        for (int i = 0; i < size; i++)
            cout << vertices[i] << " ";

        cout << endl;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (adj[i][j] == INF)
                    cout << " * ";
                else
                    cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    //------------------------------------------------
    // 최소 정점 선택
    //------------------------------------------------
    int getMinVertex(bool selected[], int dist[])
    {
        int minv = -1;
        int mindist = INF;

        for (int i = 0; i < size; i++)
        {
            if (!selected[i] && dist[i] < mindist)
            {
                mindist = dist[i];
                minv = i;
            }
        }

        return minv;
    }

    //------------------------------------------------
    // Prim MST
    //------------------------------------------------
    void Prim(int s)
    {
        bool selected[MAX_VTXS];
        int dist[MAX_VTXS];

        for (int i = 0; i < size; i++)
        {
            dist[i] = INF;
            selected[i] = false;
        }

        dist[s] = 0;

        for (int i = 0; i < size; i++)
        {
            int u = getMinVertex(selected, dist);

            if (u == -1)
                return;

            selected[u] = true;

            printf("%c ", getVertex(u));

            for (int v = 0; v < size; v++)
            {
                if (adj[u][v] != INF)
                {
                    if (!selected[v] &&
                        adj[u][v] < dist[v])
                    {
                        dist[v] = adj[u][v];
                    }
                }
            }
        }

        printf("\n");
    }
};

#endif
