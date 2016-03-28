#!/usr/bin/env python3
# coding: utf-8

import sys

with sys.stdin as f:
    N = int(f.readline())
    while N>0:
        graph_young = dict()
        graph_old = dict()
        locations = dict()
        names = dict()
        def get_id(location):
            l = len(locations)
            if not location in locations:
                locations[location] = l
                names[l] = location
            return locations[location]
        def add_to_graph(graph, id1, id2, length):
            if not id1 in graph:
                graph[id1] = []
            graph[id1].append((id2, length))
                
        for i in range(N):
            age, type, first, second, length =             tuple(f.readline().strip().split())
            length = int(length)
            id1 = get_id(first)
            id2 = get_id(second)
            if age == 'Y':
                graph = graph_young
            if age == 'M':
                graph = graph_old
            add_to_graph(graph, id1, id2, length)
            if type == 'B':
                add_to_graph(graph, id2, id1, length)
        [source, dest] = [get_id(x) for x in f.readline().strip().split()]        

        num_locations = len(locations)
        gy = [[float('inf')] * len(locations) for x in range(num_locations)]
        go = [[float('inf')] * len(locations) for x in range(num_locations)]
        for s in graph_young:
            for (d, l) in graph_young[s]:
                gy[s][d] = l
        for s in graph_old:
            for (d, l) in graph_old[s]:
                go[s][d] = l
        for i in range(num_locations):
            gy[i][i] = 0
            go[i][i] = 0

        for k in range(num_locations):
            for i in range(num_locations):
                for j in range(num_locations):
                    gy[i][j] = min(gy[i][j], gy[i][k] + gy[k][j])
                    go[i][j]= min(go[i][j], go[i][k] + go[k][j])

        total = float('inf')
        loc = None
        # if source == dest:
        #     total = 0
        #     loc = [names[source]]
        for k in range(num_locations):
            t = gy[source][k] + go[dest][k]
            if t < float('inf'):
                if t < total:
                    total = t
                    loc = [names[k]]
                elif t==total:
                    loc.append(names[k])
        if loc:
            print (total, ' '.join(sorted(loc)))
        else:
            print ('You will never meet.')
        N = int(f.readline())
        

