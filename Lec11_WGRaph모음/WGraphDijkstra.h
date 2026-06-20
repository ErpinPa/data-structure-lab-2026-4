#ifndef WGRAPHDIJ_H
#define WGRAPHDIJ_H

#include "WGraphPrim.h"

#define MAX_VTXS 256
#define INF 9999

class WGraphDijkstra : public WGraphPrim
{
    int dist[MAX_VTXS];
    bool found[MAX_VTXS];

public:

    int chooseVertex()
    {
        int min = INF;
        int minpos = -1;

        for (int i = 0; i < size; i++)
        {
            if (!found[i] && dist[i] < min)
            {
                min = dist[i];
                minpos = i;
            }
        }

        return minpos;
    }

    void printDistance()
    {
        for (int i = 0; i < size; i++)
            printf("%5d", dist[i]);

        printf("\n");
    }

    void ShortestPath(int start)
    {
        for (int i = 0; i < size; i++)
        {
            dist[i] = getEdge(start, i);
            found[i] = false;
        }

        found[start] = true;
        dist[start] = 0;

        for (int i = 0; i < size - 1; i++)
        {
            printf("Step %d : ", i + 1);
            printDistance();

            int u = chooseVertex();

            if (u == -1)
                return;

            found[u] = true;

            for (int w = 0; w < size; w++)
            {
                if (!found[w])
                {
                    if (dist[u] + getEdge(u, w) < dist[w])
                        dist[w] = dist[u] + getEdge(u, w);
                }
            }
        }
    }
};

#endif
