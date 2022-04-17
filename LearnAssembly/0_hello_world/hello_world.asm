; hello_world.asm 

section .data
  msg   db    "hello, world", 0
  NL    db    0xa

section .bss
section .text
  global main 

main:
  mov   rax, 1    ; to write
  mov   rdi, 1    ; to stdout
  mov   rsi, msg  ; 
  mov   rdx, 12   ;
  syscall 
  mov   rax, 1    ; write
  mov   rdi, 1    ; stdout
  mov   rsi, NL   ; new line
  mov   rdx, 1    ; length 1
  syscall
  mov   rax, 60   ; exit 
  mov   rdi, 0    ; success 
  syscall

; pointer (array)
; db 8 bits byte
; dw 16 bits word 
; dd 32 bits double word
; dq 64 bits quad word

; equ (constant)
; pi equ 3.1416

; bss : block started by symbol 
; uninitialized data 
; resb, resw, resd, resq 

; example 
; darray resd 20   ;; size 20 double word uninitialized memory 



