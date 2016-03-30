#!/usr/bin/env python3
# coding: utf-8
import sys
from queue import PriorityQueue

with sys.stdin as f:
    line = f.readline().strip()
    while line != '':
        [n, k] = [int(x) for x in line.split()]
        times = [int(x) for x in f.readline().strip().split()]
        graph = [[] for x in range(n*100)]
        for i in range(n):
            floors = [int(x) for x in f.readline().strip().split()]
            for j in range(1, len(floors)):
                first = i * 100 + floors[j-1]
                second = i * 100 + floors[j]
                weight = times[i] * (floors[j]-floors[j-1])
                graph[first].append((weight, second))
                graph[second].append((weight, first))
        for r in range(100):
            for i in range(n):
                first = i*100 + r
                if len(graph[first])>0:
                    for j in range(i+1, n):
                        second = j*100 + r
                        if len(graph[second])>0:
                            graph[first].append((60, second))
                            graph[second].append((60, first))
        q = PriorityQueue()
        dist = [-1]*(n*100 + 1)
        parents = [-1]*(n*100 + 1)
        graph.append([])
        for i in range(n):
            if len(graph[i*100]) > 0:
                graph[n*100].append((0, i*100))
        
        q.put((0, n*100))
        while not q.empty():
            w0, u = q.get()
            if dist[u]<0:
                dist[u] = w0
                for w, v in graph[u]:
                    if dist[v]<0:
                        q.put((w0+w, v))
        d = -1
        for i in range(n):
            u = i*100 + k
            if d<0:
                d = dist[u]
            elif dist[u] > 0:
                d  = min(d, dist[u]) 
        if d < 0:
            print ('IMPOSSIBLE')
        else:
            print (d)
        line = f.readline().strip()
        

