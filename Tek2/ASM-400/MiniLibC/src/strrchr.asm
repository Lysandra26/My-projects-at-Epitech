
[BITS 64]

    global strrchr
    section .text

strrchr:
    push rbp
    mov rbp, rsp

    mov rdi, rdi
    mov cl, dil

    mov rcx, -1
    mov rax, 0
    not rcx
    cld

.loop:
    dec rdi
    inc rcx
    cmp byte [rdi], cl
    je .found
    repne scasb
    jne strrchr_end

.found:
    mov rax, rdi

strrchr_end:
    mov rsp, rbp
    pop rbp
    ret
