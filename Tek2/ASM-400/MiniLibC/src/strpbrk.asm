
[BITS 64]

    global strpbrk
    section .text

strpbrk:
    push rbp
    mov rbp, rsp

strpbrk_end:

    mov rsp, rbp
    pop rbp
    ret
