SECTION .data     ; /* contains initialized data */
a     DD 0x00000FFF
b     DD 0x00000111

SECTION .bss      ; /* contains uninitialized data */
c     RESD 1

SECTION .text     ; /* contains code */

GLOBAL _start     ;

_start:           ; int main(void){
    nop

    mov eax, [a]
    add eax, [b]
    shl eax, 1
    shl eax, 1
    mov ebx, 5
    sub edx, edx
    div ebx
    mov [c], eax

                  ;   return 0;
end:mov eax, 1    ;   /* the exit system call
    mov ebx, 0    ;      no errorcode
    int 80h       ;      make the system call */
    ret           ; }