section .data
    hello db "Hello, Holberton", 0Ah, 0

section .text
    global main
    extern printf

main:
    push rbx        ; save the value of rbx
    mov rdi, hello  ; set the format string
    xor rbx, rbx    ; clear the rbx register
    call printf     ; call printf with the format string
    pop rbx         ; restore the value of rbx
    xor eax, eax    ; return 0
    ret
