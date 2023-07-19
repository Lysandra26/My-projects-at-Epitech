
[BITS 64]

global strchr
section .text

strchr:
    push rbp
    mov rbp, rsp

    mov rdi, rdi
    mov cl, dil

.loop:
    cmp byte [rdi], 0
    je not_found
    cmp byte [rdi], cl
    je found
    add rdi, 1
    jmp .loop

not_found:
    xor rax, rax
    jmp strchr_end

found:
    mov rax, rdi

strchr_end:
    mov rsp, rbp
    pop rbp
    ret
