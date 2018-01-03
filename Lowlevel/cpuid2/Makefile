AS=as --32 -gstabs 
LD=ld -m elf_i386 -dynamic-linker /usr/lib32/ld-linux.so.2 -lc -L/usr/lib32/

cpuid2: 
	$(AS) -o cpuid2.o cpuid2.s
	$(LD) -o cpuid2 cpuid2.o
