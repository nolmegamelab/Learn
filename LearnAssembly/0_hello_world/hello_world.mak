# makefile for hello_world.asm 

hello_world: hello_world.o 
	gcc -o hello_world hello_world.o -no-pie

hello_world.o : hello_world.asm 
	nasm -f elf64 -g -F dwarf hello_world.asm -l hello_world.lst

clean: 
	rm hello_world hello_world.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent