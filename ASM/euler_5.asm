format PE GUI 4.0

include 'ivancea.inc'

.data
    problem db "Smallest number evenly divisible by numbers 1 to 20",0
.code
    main:
        call icf_init
        mov ebx,1  ;EBX: Actual number
    restart:
        inc ebx
        mov ecx,0
    main_loop:
        inc ecx
        xor edx,edx
        mov eax,ebx
        div ecx
        cmp edx,0
        jnz restart
        cmp ecx,20d
        jnz main_loop
        mov eax,ebx
        call writenumber
        invoke Sleep,-1

.end main      
