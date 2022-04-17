# makefile for hello_world.asm 

fcalc: fcalc.o 
	gcc -o fcalc fcalc.o -no-pie

fcalc.o : fcalc.asm 
	nasm -f elf64 -g -F dwarf fcalc.asm -l fcalc.lst

clean: 
	rm fcalc fcalc.o

# elf : executable and linkable format 
# -g debug, -F debug format
# dwarf : debuf with arbitrary record format 
#

# pie : position independent executable 
# no-pie means position dependent