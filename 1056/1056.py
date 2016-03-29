#!/usr/bin/env python3
# coding: utf-8

import sys

def get_id(names, ids, name):
    if not name in names:
        d = len(names)
        names[name] = d
        ids[d] = name
    return names[name]

with sys.stdin as f:
    inp = f.read().split()
    case_cnt = 1
    p = 0
    num_nodes = int(inp[p])
    num_edges = int(inp[p+1])
    p += 2
    first_case = True
    while num_nodes > 0 or num_edges:
        names = dict()
        ids = dict()
        graph = [[float('inf')] * num_nodes for x in range(num_nodes)]
        for j in range(num_nodes):
            graph[j][j] = 0
        for j in range(num_edges):
            first = get_id(names, ids, inp[p])
            second = get_id(names, ids, inp[p+1])
            p += 2
            graph[first][second] = 1
            graph[second][first] = 1
        for k in range(num_nodes):
            for i in range(num_nodes):
                for j in range(num_nodes):
                    graph[i][j] = min(graph[i][j] ,                         graph[i][k] + graph[k][j])
        max_dist = 0
        for i in range(num_nodes):
            for j in range(num_nodes):
                if graph[i][j] > max_dist:
                    max_dist = graph[i][j]
        print ('Network %d: '%case_cnt, end='')
        if max_dist < float('inf'):
            print (max_dist)
        else:
            print ('DISCONNECTED')
        print()
        num_nodes = int(inp[p])
        num_edges = int(inp[p+1])
        p += 2
        case_cnt += 1
        

