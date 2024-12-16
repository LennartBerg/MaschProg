N EQU 32

SECTION .data     ; /* contains initialized data */
a DD 43
i DD 0

SECTION .bss      ; /* contains uninitialized data */

SECTION .text     ; /* contains code */

GLOBAL _start     ;

_start:           ; int main(void){
    nop
    mov ecx, [i]

f1: cmp ecx, N
    jge end
    
    mov eax, [a]
    rol eax, 1
    mov [a], eax

    jmp m1



                  ;   return 0;
end:mov eax, 1    ;   /* the exit system call
    mov ebx, 0    ;      no errorcode
    int 80h       ;      make the system call */
    ret           ; }
