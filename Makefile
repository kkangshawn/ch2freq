ifndef CFLAGS
CFLAGS = -MMD -Wall -O2 -g
endif

OBJS_ch += ch2freq.o
OBJS_freq += freq2ch.o

all: ch2freq freq2ch

ch2freq: $(OBJS_ch)
	@gcc -o ch2freq $(OBJS_ch)
	@echo "  LD " $@

freq2ch: $(OBJS_freq)
	@gcc -o freq2ch $(OBJS_freq)
	@echo "  LD " $@

%.o: %.c
	@gcc -c -o $@ $(CFLAGS) $<
	@echo "  CC " $<


clean:
	@rm -f *.d *.o
	@rm -f ch2freq freq2ch
	@echo "  clean done"
