DAY = 8

all: clean compile run

compile:
	gcc $(DAY).c matrix.c -o $(DAY).exe
run: $(DAY).exe
	./$(DAY).exe $(input.txt)
clean:
	rm -f $(DAY).exe
