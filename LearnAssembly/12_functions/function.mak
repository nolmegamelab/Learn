# makefile for hello_world.asm 

function: function.o 
	gcc -o function function.o -no-pie

function.o : function.asm 
	nasm -f elf64 -g -F dwarf function.asm -l function.lst

clean: 
	rm function function.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent