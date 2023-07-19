
[BITS 64]

    global strcspn
    section .text

strcspn:
    push rbp
    mov rbp, rsp

strcspn_end:

    mov rsp, rbp
    pop rbp
    ret