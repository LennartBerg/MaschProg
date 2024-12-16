SECTION .data     ; /* contains initialized data */
a DD 60
b DD 7

SECTION .bss      ; /* contains uninitialized data */

SECTION .text     ; /* contains code */

GLOBAL _start     ;

_start:           ; int main(void){
    nop
    mov eax, [a]
    cdq
    div [b]
    ; Ergebnis ist in EAX gespeichert. Rest ist in EDX gespeichert.
    
                  ;   return 0;
end:mov eax, 1    ;   /* the exit system call
    mov ebx, 0    ;      no errorcode
    int 80h       ;      make the system call */
    ret           ; }
