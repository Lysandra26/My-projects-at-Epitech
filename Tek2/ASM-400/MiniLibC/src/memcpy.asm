
[BITS 64]

    global memcpy
    section .text

memcpy:
    push rbp
    mov rbp, rsp

    mov rdi, rdi
    mov rsi, rsi
    mov rcx, rdx

    test rcx, rcx
    jz memcpy_end

    rep movsb

memcpy_end:
    mov rsp, rbp
    pop rbp
    ret
