[BITS 64]

    global strncmp
    section .text

strncmp:
    push rbp
    mov rbp, rsp

    mov rdi, rdi
    mov rsi, rsi

    xor rcx, rcx

.loop:
    mov r9b, byte[rdi]
    mov r10b, byte[rsi]
    cmp rdi, rsi
    jne notsame
    cmp byte [rdi+rcx], 0
    je same
    add rcx, 1
    jmp .loop

notsame:
    mov rax, 1
    jmp strcmp_end

same:
    xor rax, rax
    jmp strcmp_end

strcmp_end:
    mov rsp, rbp
    pop rbp
    ret