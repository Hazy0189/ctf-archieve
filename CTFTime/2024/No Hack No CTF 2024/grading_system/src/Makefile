.PHONY: all
.PHONY: cleanup
.PHONY: isntall

all: chal

cleanup: chal
	rm chal

install: chal
	cp chal ../share/
	cp flag ../share/

chal: main.c
	gcc -fstack-protector $^ -o $@
