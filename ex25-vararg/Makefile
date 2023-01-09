CFLAGS=-Wall -g -DNDEBUG

ex25: clean
	gcc $(CFLAGS) ex25.c -o ex25

run: ex25
	./ex25

clean:
	rm -f ex25

ex25-martin: clean-martin
	gcc $(CFLAGS) ex25-martin.c -o ex25-martin

run-martin: ex25-martin
	./ex25-martin

clean-martin:
	rm -f ex25-martin

