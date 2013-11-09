.PHONEY : all
CFLAGS = -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE
all : 10190

10190 : 10190.o
	gcc ${CFLAGS} $< -o $@

%.o : %.c
	gcc ${CFLAGS} -c $< -o $@ 