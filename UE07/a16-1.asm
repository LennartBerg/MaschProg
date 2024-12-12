SECTION .data     ; /* contains initialized data */
a   DD 6
b   DD 7

SECTION .bss      ; /* contains uninitialized data */

SECTION .text     ; /* contains code */

GLOBAL _start     ;

_start:           ; int main(void){
    nop
    mov eax, [a]
    imul [b]
    ; Ergebnis ist in EDX:EAX gespeichert. EAX reicht hier aus, da 42 vollständig in EAX passt.

                  ;   return 0;
end:mov eax, 1    ;   /* the exit system call
    mov ebx, 0    ;      no errorcode
    int 80h       ;      make the system call */
    ret           ; }
