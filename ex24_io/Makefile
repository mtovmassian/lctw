CFLAGS=-Wall -g -DNDEBUG

ex24: clean
	gcc $(CFLAGS) ex24.c -o ex24

run: ex24
	./ex24

clean:
	rm -f ex24

ex24-martin: clean-martin
	gcc $(CFLAGS) ex24-martin.c -o ex24-martin

run-martin: ex24-martin
	./ex24-martin

clean-martin:
	rm -f ex24-martin

