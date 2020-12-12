# What the hell is this?
It's a program that translates a message into H's.

# Why?
Because I can.

# How does it work?
Use the "e" argument to encode and the "d" argument to decode.
The input for encode cannot contain anything other than the 26 letters of the English alphabet.
```
./h e "MESSAGE"
./h d "HhHHhHhHhhHHhhHHHhhHHhhhhHHHhhHhHhh"
```

# The method behind the madness
This program uppercases the input, then for each letter in the input, it subtracts 64 from the character and then translates it into binary 'H'.
An uppercase 'H' stands for a 1, while a lowercase 'h' is a 0.