
[BITS 64]

    global strcasecmp
    section .text

strcasecmp:
    push rbp
    mov rbp, rsp

strcasecmp_end:

    mov rsp, rbp
    pop rbp
    ret