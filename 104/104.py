#!/usr/bin/env python3
# coding: utf-8

import sys
def floyd(rates1):
    n = len(rates1)
    nxt = [list(range(n))  for x in range(n)]
    rates = [[rates1[i][j] for j in range(n)] for i in range(n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                temp = rates[i][k] * rates[k][j]
                if rates[i][j] < temp:
                    rates[i][j] = temp
                    nxt[i][j] = nxt[i][k]
    return rates, nxt

def print_out(rates1, rates, nxt):
    n = len(rates)
    best_length = n + 2
    best_path = []
    best_val = 0
    for i in range(n):
        if rates[i][i] > 1.01:
            path = [i]
            k = nxt[i][i]
            value = rates1[i][k]
            path.append(k)
            while len(path) < n + 2:
                if (k==i and value > 1.01):
                    break
                k2 = nxt[k][i]
                value *= rates1[k][k2]
                k = k2
                path.append(k)       
            if len(path) < best_length:
                best_path = path
                best_length = len(path)
                best_val = value
    if best_length < n + 2:
        print (' '.join([str(x+1) for x in best_path]))
    else:
        print ('no arbitrage sequence exists')
                    
with sys.stdin as f:
    line = f.readline()
    while line!='':
        n = int(line)
        rates = []
        for i in range(n):
            row = [float(x) for x in f.readline().strip().split()]
            row.insert(i, 1.0)
            rates.append(row)
        rates2, nx = floyd(rates)
        print_out(rates, rates2, nx)
        line = f.readline()

