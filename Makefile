all:
	mkdir -p target
	gcc src/*.c -o target/qtx

install:
	cp ./qtx /usr/bin/qtx
	mkdir /etc/quotix/
	cp ./quotes.txt /etc/quotix/quotes.txt

uninstall:
	rm /usr/bin/qtx
	cd /etc/ && rm -r ./quotix/

clean:
	rm ./qtx
