.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC
; ebp es equivalente a r6
; esp es equivalente a r7

push ebp
mov ebp, esp

push ebx
push ecx
; no se guarda eax porque es lo que devuelve el proc.

mov eax, [ebp + 8] ; num1 -> eax
mov ebx, [ebp + 12] ; num2 -> ebx
mov ecx, [ebp + 16] ; num3 -> ecx

and eax, 000000FFh ; Máscara de los 8 bits más bajos de num1
and ebx, 00000080h ; Máscara del 8vo bit de num2
and ecx, 00000080h ; Máscara del 8vo bit de num3

; Se compara num2 con num3
; Como ambos solo tienen el octavo bit, se pueden comparar
; sin necesidad de mover los bits.
cmp ebx, ecx
je bcTrue
mov edx, 0
jmp nextOne
bcTrue:
mov edx, 1
nextOne:
; El estado de la comprobación se guarda en edx

; Se comprueba que num1 > 238
cmp eax, 238
ja bmTrue
mov ebx, 0
jmp nextTwo
bmTrue:
mov ebx, 1
nextTwo:
; El estado de la comprobación se guarda en ebx

; Se comprueban que se hayan cumplido ambas condiciones
; Esto ocurre si ebx y edx son ambas 1.
mov eax, 0
cmp ebx, 1
je initCheck
jmp final
initCheck:
cmp ebx, edx
je finalCheck
jmp final
finalCheck:
mov eax, 1
final:

pop ecx
pop ebx
pop ebp
ret
IsValidAssembly ENDP

END