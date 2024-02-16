#!/usr/bin/env python3

from pwn import *

{bindings}

context.binary = {bin_name}
context.terminal = [ "wt.exe", "--", "wsl.exe", "--" ]


def conn():
    if args.LOCAL:
        r = process({proc_args})
        if args.DEBUG:
            gdb.attach(r, gdbscript=
                       '''
                       ''')
    else:
        r = remote("addr", 1337)

    return r


def main():
    r = conn()

    # good luck pwning :)

    r.interactive()


if __name__ == "__main__":
    main()