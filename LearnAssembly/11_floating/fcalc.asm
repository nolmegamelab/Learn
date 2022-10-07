; fcalc.asm 
extern printf 
section .data
  number_1          dq    9.0 
  number_2          dq    73.0 
  fmt               db    "The numbers are %f and %f", 10, 0 

  fmt_float         db    "%s %f", 10, 0 
  f_mul             db    "The product of %f and %f is %f", 10, 0 
  f_div             db    "The division of %f and %f is %f", 10, 0 
  f_sqrt            db    "The squareroot of %f is %f", 10, 0 
  
section .bss 
section .text 
  global main
main: 
  push    rbp
  mov     rbp, rsp 

  movsd   xmm0, [number_1]
  movsd   xmm1, [number_2]
  ; 
  mov     rdi, fmt 
  mov     rax, 2
  call    printf
  ; mul 
  movsd   xmm2,   [number_1]
  mulsd   xmm2,   [number_2]
  ;
  movsd   xmm0,   [number_1]
  movsd   xmm1,   [number_2]
  mov     rdi, f_mul
  mov     rax, 3    ; xmm0, xmm1, xmm2
  call    printf
  ; 
  ; div 
  movsd   xmm2,   [number_1]
  divsd   xmm2,   [number_2]
  ;
  movsd   xmm0,   [number_1]
  movsd   xmm1,   [number_2]
  mov     rdi, f_mul
  mov     rax, 3    ; xmm0, xmm1, xmm2
  call    printf
  ; ''
  mov     rsp, rbp 
  pop     rbp 
  ret