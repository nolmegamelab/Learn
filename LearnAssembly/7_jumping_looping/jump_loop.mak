# makefile for hello_world.asm 

jump_loop: jump_loop.o 
	gcc -o jump_loop jump_loop.o -no-pie

jump_loop.o : jump_loop.asm 
	nasm -f elf64 -g -F dwarf jump_loop.asm -l jump_loop.lst

clean: 
	rm jump_loop jump_loop.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent