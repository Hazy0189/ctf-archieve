.PHONY: all
.PHONY: cleanup
.PHONY: install

all: attachments/chal

cleanup: attachments/chal
	rm $^

install: attachments/chal
	cp -r attachments/* ../share/

attachments/chal: main.c
	gcc $^ -o $@
