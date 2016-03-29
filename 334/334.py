#!/usr/bin/env python3
# coding: utf-8

import sys

def get_id(d, i, n):
    if not n in d:
        l = len(d)
        d[n] = l
        i[l] = n
    return d[n]

def add_edge(graph, first, second):
    while len(graph) <= first:
        graph.append([])
    while len(graph) <= second:
        graph.append([])
    graph[first].append(second)
    
def convert(graph):
    num = len(graph)
    adjmat = [[0]*num for x in range(num)]
    for i in range(num):
        adjmat[i][i]=1
    for (i,g) in enumerate(graph):
        for j in g:
            adjmat[i][j]=1
    return adjmat
    
with sys.stdin as f:
    case_cnt = 1
    n = int(f.readline())
    while n!=0:
        names = dict()
        ids = dict()
        graph = []
        for i in range(n):
            edge_list = f.readline().strip().split()[1:]
            for j in range(1,len(edge_list)):
                first = get_id(names, ids, edge_list[j-1])
                second = get_id(names, ids, edge_list[j])
                add_edge(graph, first, second)
        
        n2 = int(f.readline())
        for i in range(n2):
            [first, second] = [get_id(names, ids, x) for x in f.readline().strip().split()]
            add_edge(graph, first, second)
        adjmat = convert(graph)
        num_nodes = len(graph)
        for k in range(num_nodes):
            for i in range(num_nodes):
                for j in range(num_nodes):
                    adjmat[i][j] = max(adjmat[i][j], adjmat[i][k]+adjmat[k][j]-1)
        count = 0
        pairs = []
        for i in range(num_nodes):
            for j in range(i, num_nodes):
                if adjmat[i][j]==0 and adjmat[j][i]==0:
                    count += 1
                    if count < 3:
                        pairs.append('(%s,%s)'%(ids[i],ids[j]))
        if count > 0:
            print ('Case %d, %d concurrent events:'%(case_cnt, count))
            print (' '.join(pairs))
        else:
            print ('Case %d, no concurrent events.' %case_cnt)
        case_cnt += 1
        n = int(f.readline())

