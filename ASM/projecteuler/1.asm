format PE GUI 4.0

include 'ivancea.inc'

.code
    main:
        call icf_init
        mov ebx,0  ;EBX: Actual number
        mov ecx,0  ;ECX: Count
    next:
        inc ebx
        cmp ebx,1000d
        je fin
        push ecx
        mov ecx,0
        xor edx,edx
        mov eax,ebx
        push ebx
        mov ebx,3
        div ebx
        pop ebx
        cmp edx,0
        jne jump3
        inc ecx
    jump3:
        xor edx,edx
        mov eax,ebx
        push ebx
        mov ebx,5
        div ebx
        pop ebx
        cmp edx,0
        jne jump4
        inc ecx
    jump4:
        mov eax,ecx
        pop ecx
        cmp eax,0
        je next
        add ecx,ebx
        jmp next
    fin:
        mov eax,ecx
        call writenumber
        invoke Sleep,-1

.end main
