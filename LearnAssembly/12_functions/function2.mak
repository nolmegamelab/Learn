# makefile for hello_world.asm 

function2: function2.o 
	gcc -o function2 function2.o -no-pie

function2.o : function2.asm 
	nasm -f elf64 -g -F dwarf function2.asm -l function2.lst

clean: 
	rm function2 function2.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent