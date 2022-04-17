; memory.asm 
section .data

  bnum        db    123 
  wnum        dw    12345 
  warray      times     5     dw    0
  ; 
  dnum        dd    12345
  qnum_1      dq    12345
  text_1      db    "abc", 0 
  qnum_2      dq    3.141592654
  text_2      db    "cde", 0 

section .bss 
  bvar        resb      1
  dvar        resb      1 
  wvar        resw      10 
  qvar        resq      3

section .text 
  global main 

main: 
  ; 
  push    rbp 
  mov     rbp, rsp 
  ; 
  lea     rax, [bnum]
  mov     rax, bnum 
  ; 
  mov     rax, [bnum]
  mov     [bvar], rax 
  lea     rax, [bvar]
  lea     rax, [wnum]
  mov     rax, [wnum]
  ; 
  lea     rax, [text_1]
  mov     rax, text_1
  ; 
  mov     rax, text_1+1
  lea     rax, [text_1+1]
  ; 
  mov     rax, [text_1]
  mov     rax, [text_1+1]
  ; 
  mov     rsp, rbp 
  pop     rbp
  ; 
  ret
