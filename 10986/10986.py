#!/usr/bin/env python3
# coding: utf-8

from queue import PriorityQueue
import sys

with sys.stdin as f:
    num_cases = int(f.readline())
    for case_cnt in range(num_cases):
        [num_nodes, num_edges, source, dest] =         [int(x) for x in f.readline().strip().split()]
        graph = [[] for x in range(num_nodes)]
        for edge_cnt in range(num_edges):
            [s1, s2, w] = [int(x) for x in f.readline().strip().split()]
            graph[s1].append((s2, w))
            graph[s2].append((s1, w))
        dist = [-1] * num_nodes
        q = PriorityQueue()
        q.put((0,source))
        dist[source] = 0
        while not q.empty():
            u = q.get()[1]
            for (v,w) in graph[u]:
                if dist[v] < 0 or                 dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    q.put((dist[v], v))
                
        print ('Case #%d: '%(case_cnt+1), end='')
        if dist[dest]<0:
            print ('unreachable')
        else:
            print (dist[dest])

