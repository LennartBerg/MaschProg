SECTION .data  ; /* contains initialized data */

SECTION .bss   ; /* contains uninitialized data */

SECTION .text  ; /* contains code

GLOBAL _start  ;

_start:        ; int main(void){
    nop        ;   /* do not remove the "nop" */
    mov edx, 0
    mov eax, 0xffffffff
    mov ebx, 8
    div ebx ; 0xffffffff / 8 liegt nun in eax vor.
    mov ebx, 16
    mul ebx ; (0xffffffff / 8) * 16 liegt nun in edx:eax vor.
               ;   return 0;
end:mov eax, 1 ;   /* the exit system call
    mov ebx, 0 ;      no errorcode
    int 80h    ;      execute system call */
               ; }

