# makefile for hello_world.asm 

macros: macros.o 
	gcc -o macros macros.o -no-pie

macros.o : macros.asm 
	nasm -f elf64 -g -F dwarf macros.asm -l macros.lst

clean: 
	rm macros macros.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent