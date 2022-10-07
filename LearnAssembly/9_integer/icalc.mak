# makefile for hello_world.asm 

memory: memory.o 
	gcc -o memory memory.o -no-pie

memory.o : memory.asm 
	nasm -f elf64 -g -F dwarf memory.asm -l memory.lst

clean: 
	rm memory memory.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent