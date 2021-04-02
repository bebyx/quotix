all: install

install:
	gcc *.c -o qtx

clean:
	rm ./qtx
