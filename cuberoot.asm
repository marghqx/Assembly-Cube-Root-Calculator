section .data
    three dd 3.0       
    iter dd 1000      

section .text
    global _cuberoot

_cuberoot:
    push ebp
    mov ebp, esp

    fld dword [ebp + 8] 
    fld dword [three] 
    fdivp st1, st0    
    mov ecx, [iter]  

newton:

  
    fld st0         
    fmul st0, st0         
    fmul st0, st1          
    fld dword [ebp + 8]  
    fsubp st1, st0        

    fxch st1
    fld st0  
    fmul st0, st0
    fld dword [three]     
    fmulp st1, st0 

    fld st2
    fxch st1
    fdivp st1, st0
    fsubp st1, st0
    fxch st1
    fstp st0

    dec ecx
    jnz newton

done:
    leave
    ret
