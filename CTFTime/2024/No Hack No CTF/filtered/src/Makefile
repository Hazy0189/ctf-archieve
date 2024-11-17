.PHONY: all
.PHONY: cleanup
.PHONY: install

all: chal

cleanup: chal
	rm chal
	
install: chal
	cp chal ../share/
	cp flag ../share/

chal: main.c
	gcc -zexecstack $^ -o $@
