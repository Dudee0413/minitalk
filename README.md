*This project has been created as part of the 42 curriculum by zdudas.*

# Minitalk

## Description

Minitalk is a small data exchange program built using UNIX signals. The goal is to establish communication between a **client** and a **server** using only two signals: `SIGUSR1` and `SIGUSR2`.

The server listens for incoming signals and reconstructs messages bit by bit. The client encodes each character of a string into 8 bits and transmits them to the server one bit at a time. The server acknowledges each received bit, ensuring reliable communication.

Key features:
- Bit-by-bit character transmission over UNIX signals
- Server acknowledgement after every received bit (bonus)
- Support for multiple clients in sequence without restarting the server
- Unicode character support (bonus)

## Instructions

### Compilation

```bash
make
```

This will compile both `server` and `client` executables. To clean up:

```bash
make clean    # removes object files
make fclean   # removes object files and executables
make re       # full recompile
```

### Execution

**Start the server first:**
```bash
./server
```
The server will print its PID on launch. Keep this number — you'll need it for the client.

**Send a message from the client:**
```bash
./client <SERVER_PID> "your message here"
```

**Example:**
```bash
# Terminal 1
./server
# Output: Server ID: 12345

# Terminal 2
./client 12345 "Hello, 42!"
# Server output: Hello, 42!
```

Unicode strings are also supported:
```bash
./client 12345 "こんにちは"
```

## How It Works

- Each character is broken into 8 bits (MSB first).
- `SIGUSR1` represents a `0` bit, `SIGUSR2` represents a `1` bit.
- After each bit, the server sends back `SIGUSR1` as an acknowledgement.
- The client waits for the ACK before sending the next bit, preventing signal loss.
- When the server receives a null byte (`\0`), it prints a newline and resets, ready for the next client.

## Resources

- [`signal(7)` — Linux manual page](https://man7.org/linux/man-pages/man7/signal.7.html)
- [`sigaction(2)` — Linux manual page](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`kill(2)` — Linux manual page](https://man7.org/linux/man-pages/man2/kill.2.html)
- [42 Docs — Minitalk subject](https://cdn.intra.42.fr/pdf/pdf/40188/en.subject.pdf)
- [Unix Signals — Wikipedia](https://en.wikipedia.org/wiki/Signal_(IPC))

### AI Usage

AI (Claude) was used during this project for the following tasks:
- Clarifying how `sigaction` and `SA_SIGINFO` work compared to basic `signal()`
- Understanding signal queuing limitations on Linux and why acknowledgement is necessary
- Reviewing edge cases in the bit-shifting logic