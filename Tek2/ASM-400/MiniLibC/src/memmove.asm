[BITS 64]

global memmove
section .text

memmove:
    push rbp
    mov rbp, rsp

    mov rsi, rsi
    mov rdi, rdi
    mov rcx, rdx

    cmp rsi, rdi
    jge memmory
    add rsi, rcx
    add rdi, rcx
    std

memmory:
    rep movsb
    cld

memmove_end:
    mov rsp, rbp
    pop rbp
    ret
