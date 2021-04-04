# quotix — random quote program

Quotix is a random quote C program. It runs through a plain text file (LF, of course, named `quotes.txt` by default) and prints out a random line.

## Installation

To compile and install on GNU/Linux:

```bash
make && sudo make install
```

To uninstall:

```bash
sudo make uninstall
```

And delete a source folder.

## Flags

* `-f` or `--file` to use the custom name for quote source file
* `-h` or `--help` to print hints
* `-i` to change the time iteration (each second by default):
  * format follows GNU `date` utility convention:
    * `%M` for minute
    * `%H` for hour
    * `%d` for day
  * as well as human readable format:
    * `"minute"` for minute
    * `"hour"` for hour
    * `"day"` for day
    * thanks CO!

## Use Case

[Conky](https://github.com/brndnmtthws/conky) is an obvious use case for the program — output quotix to the Conky cell and receive an inspiring quote each iteration.

Like this bash loop:

```bash
while true; do ./qtx -f q_file -i %M; sleep 1; done
```
Native conky command:

```bash
${texeci 600 /home/user/.local/bin/qtx -f /home/user/.local/etc/quotix/quotes.txt -i %M }
```

Also you can use the program for whatever random quote case, e.g., web app:
pipe to a file and then read from the file to take your random quote to the web page.

```bash
./qtx > quote-of-the-day.html
```
