# Simple Encryptor
The program is fairly simple, the encryption consists of getting a random number, and using it as a XOR key, then splitting the byte into an offset and swapping positions.

The reversing program should take into account that the XOR key is created before the offset, but the offset must be done frist for the key to work.
