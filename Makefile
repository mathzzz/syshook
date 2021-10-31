src = syshook.c
CFLAGS=-g -fPIC


all:libsyshook.so libsyshook.a

libsyshook.so libsyshook.a:$(src:.c=.o)

$(src.c=.o):$src


libsyshook.so:$(src:.c=.o)
	gcc -g -fPIC -shared -o $@ $^

libsyshook.a:
	ar rcs $@ $^

test:
	LD_PRELOAD=${PWD}/libsyshook.so sh -c ls

clean:
	rm -f *.so *.a *.o
