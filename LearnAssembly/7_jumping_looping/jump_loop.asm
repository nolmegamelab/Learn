; jump.asm 

extern printf 
section .data
  number        dq    10000001
  fmt           db    "Sum from 0 to %ld is %ld", 10, 0 

section .bss
section .text 
  global main 
main: 
  ; 
  push  rbp 
  mov   rbp, rsp
  ; 
  mov   rbx, 0
  mov   rax, 0 
  ; 
jloop:
  add   rax, rbx 
  inc   rbx 
  cmp   rbx, [number]
  jle   jloop

  mov   rdi, fmt        ; 1st arg 
  mov   rsi, [number]   ; 2nd arg
  mov   rdx, rax        ; 3rd arg
  mov   rax, 0 
  call  printf 

  mov   rsp, rbp 
  pop   rbp 

  ret