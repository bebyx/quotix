binpath := /usr/local/bin
datapath := /usr/local/share

all:
	mkdir -p target
	gcc src/*.c -o target/qtx -DDATAPATH=\"${datapath}/quotix/quotes.list\"

install:
	mkdir -p ${binpath}
	cp target/qtx ${binpath}/qtx
	mkdir -p ${datapath}/quotix/
	cp assets/quotes.list ${datapath}/quotix/quotes.list

uninstall:
	rm ${binpath}/qtx
	cd ${datapath} && rm -r quotix/

clean:
	rm -r target

check:
	target/qtx -f assets/quotes.list -i %M
