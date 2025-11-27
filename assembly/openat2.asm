section .data
    filename db "numbers.txt", 0          ; File to create/write
    buffer   times 32 db 0                ; Temporary buffer for ASCII text

section .bss
    len resq 1                            ; Store length of string for write

section .text
    global _start

_start:

    ; === openat syscall ===
    mov rax, 257               ; syscall number for openat (Linux x86-64)
    mov rdi, -100              ; dirfd = AT_FDCWD  (current working directory)
    lea rsi, [rel filename]    ; pointer to filename string
    mov rdx, 0x241             ; flags = O_CREAT | O_WRONLY | O_TRUNC (octal 0o241 = 0x241)
    mov r10, 0o644             ; mode = rw-r--r-- (0644)
    syscall                    ; returns file descriptor in RAX

    mov r12, rax               ; save file descriptor for later writes

    ; === Loop to write numbers 1 to 5 ===
    mov rcx, 1                 ; loop counter (1 to 5)

write_loop:
    cmp rcx, 6                 ; stop when rcx = 6
    je done_writing

    ; convert integer to ASCII
    mov rax, rcx               ; number to convert
    add al, '0'                ; convert digit → ASCII
    mov [buffer], al           ; store ASCII character in buffer

    ; append newline '\n'
    mov byte [buffer+1], 10    ; ASCII 10 = newline

    ; calculate length = 2 bytes ('digit' + '\n')
    mov qword [len], 2

    ; === write syscall ===
    mov rax, 1                 ; syscall number for write
    mov rdi, r12               ; file descriptor (returned by openat)
    lea rsi, [rel buffer]      ; address of buffer to write
    mov rdx, [len]             ; number of bytes to write
    syscall                    ; write(fd, buffer, len)

    inc rcx                    ; next number
    jmp write_loop

done_writing:
    ; === close syscall ===
    mov rax, 3                 ; syscall number for close
    mov rdi, r12               ; file descriptor to close
    syscall

    ; === exit syscall ===
    mov rax, 60                ; syscall number for exit
    xor rdi, rdi               ; exit status 0
    syscall
