# makefile for hello_world.asm 

alive: alive.o 
	gcc -o alive alive.o -no-pie

alive.o : alive.asm 
	nasm -f elf64 -g -F dwarf alive.asm -l alive.lst

clean: 
	rm alive alive.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent