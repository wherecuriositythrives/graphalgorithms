section .data
	filename db "array.txt",0
	a1 db 1,2,3,4,5,6
	
section .bss
	a2 resb 7

section .text
global _start

_start:
	mov rax, 257
	mov rdi, -100
	lea rsi, [rel filename]
	mov rdx, 577
	mov r10, 0o644
	syscall
	;; checking if the fd is 3 else exit with status 0
	cmp rax, 0
	js .fd_error
	
	mov r12, rax
	xor r9,r9
	call .cp_array
	
	;; write buffer 1
	mov rax, 1
	mov rdi, r12
	lea rsi, [rel a2]
	mov rdx, r9
	syscall
	dec r9
	;; write buffer 2
	mov rax, 1
	mov rdi, r12
	lea rsi, [rel a1]
	mov rdx, r9
	syscall
	;; close sycall
	mov rax, 3
	mov rdi, r12
	syscall
	;; exit syscall
	mov rax, 60
	mov rdi, 1
	syscall

.fd_error
	mov rax,60
	mov rdi,0
	syscall
	
.cp_array
        mov dl,[a2+r9]
	mov al,[a1+r9]
	xchg dl,al
	add dl, '0'
	add al, '0'
	mov [a2+r9],dl
	mov [a1+r9],al
	inc r9
	cmp r9,6
	jnge .cp_array
	je .nwline

.nwline
	mov byte [rel a2+r9],10
	inc r9
	ret

	
