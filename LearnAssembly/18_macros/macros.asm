; function2.asm 
extern printf 
%define   double_it(r)    sal r, 1

%macro    printf_ 2 
  section .data 
    %%arg_1      db  %1, 0
    %%fmt_int   db  "%s %ld", 10, 0
  section .text 
    mov   rdi, %%fmt_int 
    mov   rsi, %%arg_1 
    mov   rdx, [%2]
    mov   rax, 0 
    call printf 
%endmacro 

section .data 
  number    dq  15 
section .bss 
section .text 
  global main 
main: 
  push  rbp 
  mov   rbp, rsp
  ; 
  printf_   "The number is", number 
  mov     rax, [number]
  double_it(rax) 
  mov     [number], rax 
  printf_   "The number times 2 is ", number 
  ; 
  mov rsp, rbp 
  pop rbp
  ret

; lldb works with the macros
; gdb errors on printf call 
; that's the complication. 


