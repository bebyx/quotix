# quotix — random quote program

Quotix is a **random quote** C program. It runs through a plain text file (LF, of course, named `quotes.txt` by default) and prints out a random line.

## Installation

### Debian

Install Quotix on Debian-based system with the `deb` release.

```bash
wget https://github.com/bebyx/quotix/releases/download/v0.1.0-beta/qtx_0.1.0_x86_64.deb && sudo apt install ./qtx_0.1.0_x86_64.deb
```

To uninstall:

```bash
sudo apt purge quotix
```

### Compile from source

Get the source code from this repo or the latest [release archives](https://github.com/bebyx/quotix/releases/tag/v0.1.0-beta), then compile and install on GNU/Linux:

```bash
make && sudo make install
```

To uninstall:

```bash
sudo make uninstall
```

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
while true; do qtx -f q_file -i %M; sleep 1; done
```
Native conky command:

```bash
${texeci 600 /usr/bin/qtx -f /home/user/.local/etc/quotix/funny_quotes.txt -i %M }
```

Also you can use the program for whatever random quote case, e.g., web app:
pipe to a file and then read from the file to take your random quote to the web page.

```bash
qtx > quote-of-the-day.html
```

## Difference to Fortune

While **Fortune** is time proven random quote program, **Quotix** is built independently with other philosophy in mind.

### Ideological:

1. an idea behind: straight aphorism instead of fortune cookies; it's reflected in the names
2. one-liner — minimalist by design; there shan't be recipes or verse!
3. GPL vs. BSD license (see [cuck licenses article](https://lukesmith.xyz/articles/cucklicenses) by [@lukesmithxyz](https://github.com/lukesmithxyz))

### Technical:

1. no format complications — just plain text one-liners (1024 character per line limit so far)
2. has built-in time iteration — matters when need to print out frequently but change quotes with slower pace
3. no regex handling, no multifile handling and other fancy stuff — it's not the goal for Quotix
4. shorter command by default (`qtx`)
5. at the moment, 8,204 B (1 package) vs. 2,154 kB (3 packages) — checked on Debian **apt**

### Sum-up

That said, Quotix is not better or worse, it's just different.

The main point is diversity as the core idea of free software: alternatives never harm, but enrich free software users and developers.

Think of **sudo** and **doas**, for example.

Even in non-free world there's Twitter and there's Facebook.

Use Fortune or use Quotix, choose what suits you best.

Or (re)write your own random quote program as you see it. :)
