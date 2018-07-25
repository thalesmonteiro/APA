
all: 
	gcc Ordenacao.c -o main
	clear
	./main

compile:
	gcc Ordenacao.c -o main

clean:
	rm main