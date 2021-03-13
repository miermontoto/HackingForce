.386
.model flat, C

.code

IsValidAssembly PROC
; ebp es equivalente a r6
; esp es equivalente a r7
; Primero se completa el "Prólogo"

push ebp
mov ebp, esp

push ebx
push ecx
; no se guarda eax porque es lo que devuelve el procedimiento

mov eax, [ebp + 8 ] ; num1 -> eax
mov ebx, [ebp + 12] ; num2 -> ebx
mov ecx, [ebp + 16] ; num3 -> ecx

and eax, 000000FFh ; Máscara de los 8 bits más bajos de num1
and ebx, 00000080h ; Máscara del 8vo bit de num2
and ecx, 00000080h ; Máscara del 8vo bit de num3

; Se comprueba: eax > 238
cmp eax, 238
ja firstCheck
jmp wrong ; Si no es verdad, no es necesario comprobar más, ya que no puede
          ; darse que ambas sean correctas.
firstCheck:

; Se comprueba: ebx == ecx
; Como ambos solo tienen el octavo bit, se pueden comparar
; sin necesidad de mover los bits.
cmp ebx, ecx
je secondCheck
jmp wrong

secondCheck:
mov eax, 1
jmp final

wrong:
mov eax, 0

final:

pop ecx
pop ebx
pop ebp
ret
IsValidAssembly ENDP

END