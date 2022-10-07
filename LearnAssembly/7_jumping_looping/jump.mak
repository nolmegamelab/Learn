# makefile for hello_world.asm 

jump: jump.o 
	gcc -o jump jump.o -no-pie

jump.o : jump.asm 
	nasm -f elf64 -g -F dwarf jump.asm -l jump.lst

clean: 
	rm jump jump.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent