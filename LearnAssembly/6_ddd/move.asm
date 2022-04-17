; move.asm 

section .data 

  bnum      db    123 
  wnum      dw    12345
  dnum      dd    1234567890
  qnum_1    dq    1234567890123456789
  qnum_2    dq    123456 
  qnum_3    dq    3.14 

section .bss
section .text
  global main 

main: 
; prologue
  push    rbp
  mov     rbp, rsp 

; 
  mov     rax, -1     ; rax = FFF... 
  mov     al, byte [bnum]   ; 
  xor     rax, rax          ; clear 
  mov     al, byte[bnum]

  mov     rax, -1
  mov     ax, word [wnum]
  xor     rax, rax 
  mov     ax, word [wnum]

  mov     rax, -1 
  mov     eax, dword [dnum]

  mov     rax, -1
  mov     rax, qword [qnum_1]
  mov     qword [qnum_2], rax 
  mov     rax, 123456 


  movq    xmm0, [qnum_3]

; epilogue 
  mov     rsp, rbp 
  pop     rbp

  ret

