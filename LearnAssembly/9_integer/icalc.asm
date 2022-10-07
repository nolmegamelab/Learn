; icalc.asm 
extern printf 
section .data 
  number_1      dq    128 
  number_2      dq    19 
  neg_num       dq    -12 
  fmt           db    "The numbers are %ld and %ld", 10, 0
  fmt_int       db    "%s %ld", 10, 0 
  sum_i         db    "The sum is ", 0 
setction .bss 
  result_i      resq  1
  modulo        resq  1
section .text
  global main 
main:
  ;
  push    rbp 
  mov     rbp, rsp 
  ; 
  mov     rdi, fmt 
  mov     rsi, [number_1]
  mov     rdx, [number_2]
  mov     rax, 0 
  call    printf 
  ; 
  mov     rax, [number_1]
  add     rax, [number_2]
  mov     [result_i], rax 

  mov     rdi, fmt_int 
  mov     rsi, sum_i
  mov     rdx, [result_i]
  mov     rax, 0
  call    printf 

  mov     rsp, rbp
  pop     rbp 