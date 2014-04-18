#! /bin/bash
gcc -c test.c

ld -static -r /usr/lib/crt1.o /usr/lib/crti.o /usr/lib/gcc/i686-pc-linux-gnu/4.8.2/crtbegin.o -L/usr/lib/gcc/i686-pc-linux-gnu/4.8.2 -L/usr/lib -L/lib test.o -lgcc -lgcc_eh -lc_nonshared /usr/lib/gcc/i686-pc-linux-gnu/4.8.2/crtend.o /usr/lib/crtn.o -o obj.o   

./main obj.o /usr/lib/libc.so.6 /usr/lib/ld-2.19.so
