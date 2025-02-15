N EQU 32

SECTION .data     ; /* contains initialized data */
a DD 43
i DD 0

SECTION .bss      ; /* contains uninitialized data */

SECTION .text     ; /* contains code */

GLOBAL _start     ;

_start:           ; int main(void){
    nop
    mov eax, [a]  ; input number
    mov ebx, 1    ; bitmask
    mov ecx, [i]  ; loop index
    mov edx, 0    ; result

l1: cmp ecx, N
    jge end       ; for i < N
    rol eax, 1    ; rotate a left
    jc c1         ; if CF == 1
r1: shl ebx, 1    ; b <<= 1
    inc ecx       ; i++
    jmp l1

c1: add edx, ebx ; res += b
    jmp r1

    ; Ergebnis liegt im edx Register vor

                  ;   return 0;
end:mov eax, 1    ;   /* the exit system call
    mov ebx, 0    ;      no errorcode
    int 80h       ;      make the system call */
    ret           ; }
