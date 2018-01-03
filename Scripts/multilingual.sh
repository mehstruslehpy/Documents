#!/bin/sh
gcc -xc -include stdio.h - <<"XXXX"
int main() {printf("Hello world\n");}
XXXX
./a.out
python - <<"XXXX"
print("Wow neat")
XXXX

