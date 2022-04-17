; alive.asm 
extern    printf ;

section .data 
  msg_1       db    "Hello, World!", 10, 0
  msg_1_len   equ    $ - msg_1 - 1      ; $ is the current constant memory location
  msg_2       db    "Alive and Kicking!", 10, 0
  msg_2_len   equ   $ - msg_2 - 1  
  radius      dq    357 
  pi          dq    3.14 
  fmt_str     db    "This is our format: %f", 10, 0 ; 

section .bss 
section .text 
  global main 
main:
  push      rbp 
  mov       rbp, rsp 
  mov       rax, 1
  mov       rdi, 1
  mov       rsi, msg_1 
  mov       rdx, msg_1_len 
  syscall 

  mov       rax, 1 
  mov       rdi, 1
  mov       rsi, msg_2 
  mov       rdx, msg_2_len 
  syscall 

; print pi
  mov       rax, 1        ; 1 float
  movq      xmm0, [pi]    ; second arg - the value at the address of pi
  mov       rdi, fmt_str  ; first arg
  call      printf

  mov       rsp, rbp 
  pop       rbp 
  mov       rax, 60 
  mov       rdi, 0
  syscall