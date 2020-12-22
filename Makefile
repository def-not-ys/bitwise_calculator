calculator: calculator.h calculator.c source.c
	gcc -g -o0 calculator.c source.c -o calculator

run:
	calculator

clean:
	rm -f calculator *.o