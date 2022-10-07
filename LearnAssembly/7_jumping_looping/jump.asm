; jump.asm 

extern printf 
section .data
  number_1      dq    40 
  number_2      dq    41
  fmt_1         db    "number_1 >= number_2", 10, 0
  fmt_2         db    "number_1 < number_2", 10, 0 

section .bss
section .text 
  global main 
main: 
  ; 
  push  rbp 
  mov   rbp, rsp
  ; 
  mov   rax, [number_1]
  mov   rbx, [number_2]
  cmp   rax, rbx 
  jge   greator      
  ; 
  mov   rdi, fmt_2 
  mov   rax, 0 
  call  printf 
  jmp   exit 
  ; 
greator:
  mov   rdi, fmt_1 
  mov   rax, 0 
  call  printf 
  ;
exit: 
  mov   rsp, rbp 
  pop   rbp 

  ret