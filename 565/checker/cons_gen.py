#!/usr/bin/env python3

import random

def main():
    random.seed()
    inclusion_prob = random.random()
    sign_prob = random.random()
    num_cases = 100
    for i in range(num_cases):
        num_cons = random.randint(1,12)
        for j in range(num_cons):
            for k in range(16):
                if (random.random() > inclusion_prob):
                    if(random.random() > sign_prob):
                        print('+',end='')
                    else:
                        print('-',end='')
                    print(chr(ord('A')+k),end='')
            print(';')
        print('.')

if __name__ == '__main__':
    main()
