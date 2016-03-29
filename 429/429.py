#!/usr/bin/env python3
# coding: utf-8

import sys
from queue import Queue

def get_id(words, word):
    if not word in words:
        words[word] = len(words)
    return words[word]

def diff(w1, w2):
    if len(w1)!=len(w2):
        return False
    cnt = 0
    for i in range(len(w1)):
        if w1[i]!=w2[i]:
            cnt+=1
        if cnt > 1:
            break
    return cnt==1

def add_edge(graph, words, w1, w2):
    n1 = get_id(words, w1)
    n2 = get_id(words, w2)
    graph[n1].append(n2)
    graph[n2].append(n1)
    
def bfs(source, dest, graph):
    num_nodes = len(graph)
    dist = [-1] * num_nodes
    q = Queue()
    q.put(source)
    dist[source] = 0
    while dist[dest]<0 and not q.empty():
        current = q.get()
        for node in graph[current]:
            if dist[node] < 0:
                dist[node] = dist[current] + 1
                q.put(node)
    return dist[dest]
        

with sys.stdin as f:
    num_cases = int(f.readline())
    f.readline()
    for case_cnt in range(num_cases):
        words = dict()
        word = f.readline().strip()
        while word!='*':
            get_id(words, word)
            word = f.readline().strip()
        num_words = len(words)
        graph = [[] for x in range(num_words)]
        word_list = list(words.keys())
        for i in range(num_words):
            for j in range(i, num_words):
                w1 = word_list[i]
                w2 = word_list[j]
                if diff(w1, w2):
                    add_edge(graph, words, w1, w2)

        pair = f.readline().strip()
        while pair!='':
            [source, dest] = pair.split()
            s = get_id(words, source)
            d = get_id(words, dest)
            if case_cnt > 0:
                print ()
            print (source, dest, bfs(s, d, graph))
            pair = f.readline().strip()
        

