
[BITS 64]

    global strstr
    section .text

strstr:
    push rbp
    mov rbp, rsp

    mov rdi, [rbp + 16]
    mov cl, [rbp + 24]

.loop:
    mov cl, [rsi]
    cmp cl, 0
    je strstr_end
    cmp byte [rdi], cl
    inc rsi
    inc rdi
    jmp .loop

strstr_end:
    mov rax, rdi

    mov rsp, rbp
    pop rbp
    ret
