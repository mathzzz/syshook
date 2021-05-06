src = syshook.c

libsyshook.so:$(src)
	gcc -g -fPIC -shared -o $@ $(src)

test:
	LD_PRELOAD=${PWD}/libsyshook.so sh -c ls

clean:
	rm -f *.so
