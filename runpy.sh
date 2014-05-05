#! /bin/bash
# gcc -c test.c

# ld -static -r /usr/lib/crt1.o /usr/lib/gcc/i686-redhat-linux/4.4.4/crtbegin.o -L/usr/lib -L/lib test.o -L/usr/lib/gcc/i686-redhat-linux/4.4.4 -lgcc -lgcc_eh -lc_nonshared /usr/lib/gcc/i686-redhat-linux/4.4.4/crtend.o /usr/lib/crtn.o  -o obj.o   

./main obj.o /lib/libc.so.6 /lib/ld-2.12.so
