# makefile for hello_world.asm 

move: move.o 
	gcc -o move move.o -no-pie

move.o : move.asm 
	nasm -f elf64 -g -F dwarf move.asm -l move.lst

clean: 
	rm move move.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent