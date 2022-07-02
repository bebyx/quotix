# quotix — random quote program

[![quotix build status](https://github.com/bebyx/quotix/actions/workflows/c.yml/badge.svg?branch=master)](https://github.com/bebyx/quotix/actions/workflows/c.yml)
[![license](https://img.shields.io/github/license/bebyx/quotix)](https://github.com/bebyx/quotix/blob/master/LICENSE.txt)

Quotix is a **random quote** C program. It runs through a plain text file (LF, of course, named `quotes.list` by default) and prints out a random line to standard output.

## Installation

### Compile from source

Get the source code from this repo or the latest [release archives](https://github.com/bebyx/quotix/releases/), then compile and install on GNU/Linux:

```bash
make && sudo make install
```

To uninstall:

```bash
sudo make uninstall
```

Default binary path is `/usr/local/bin/` and default quotes list path is `/usr/local/share/`. You can change it with Makefile variables (`binpath` and `datapath`). For example, full cycle with a changed `datapath`:

```bash
make datapath=/home/user/.local/share # stick to full path; no slash at the end is recommended
sudo make install datapath=/home/user/.local/share
sudo make uninstall datapath=/home/user/.local/share
```
### Arch

Run from the project folder:

```bash
makepkg -si
```

## Flags

* `-f` or `--file` to use the custom name for quote source file
* `-h` or `--help` to print hints
* `-i` or `--iterate` to change the time iteration (each second by default):
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
while true; do qtx -i %M; sleep 1; done
```
Native conky command:

```bash
${texeci 600 /usr/local/bin/qtx -f /home/user/.local/share/quotix/funny_quotes.list -i %M }
```

Also you can use the program for whatever random quote case, e.g., web app:
pipe to a file and then read from the file to take your random quote to the web page.

```bash
qtx > quote-of-the-day.html
```

## Difference to Fortune

While **Fortune** is time proven random quote program, **Quotix** is built independently with other philosophy in mind.

### Ideological:

1. an idea behind: straight aphorism instead of fortune cookies; it's reflected in the names of both programs
2. one-liner — minimalist by design; there shan't be recipes or verse!
3. GPL vs. BSD license (see [cuck licenses article](https://lukesmith.xyz/articles/why-i-use-the-gpl-and-not-cuck-licenses/) by [@lukesmithxyz](https://github.com/lukesmithxyz))

### Technical:

1. no format complications — just plain text one-liners (1024 ASCII characters per line limit so far)
2. comment out any line/quote with `#` at the very beginning of the one
3. has built-in time iteration — matters when need to print out frequently but change quotes with slower pace
4. no regex handling, no multifile handling and other fancy stuff — it's not the goal for Quotix
5. shorter command by default (`qtx`)

### Sum-up

That said, Quotix is not better or worse, it's just different.

The main point is diversity as the core idea of free software: alternatives never harm, but enrich free software users and developers.

Think of **sudo** and **doas**, for example.

Even in non-free world there's Twitter and there's Facebook.

Use Fortune or use Quotix, choose what suits you best.

Or (re)write your own random quote program as you see it. :)
