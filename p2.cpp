#include "stdafx.h"
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
 
void sorter(int *list , unsigned int, int opcode);
 
 
void sorter(int* list, unsigned int count, int opcode)
{
__asm
{
 
 
 
	mov ebx, opcode  ; move opcode to ebx for comparison
	cmp ebx, 0x01    ;compare to opcode with 1
	jne Des
     

	;Assending 
	mov eax, count; initilize ecx to be zero and ecx to be a counter
	sub eax, 1
	mov esi, list
 outter_loop :
                ; copy address into esi.edi, ebp, esp are pointer registers.eax = 32 bit.
	mov edi, esi
	mov ebx, eax; init j = ebx to be zero  j = 0
 inner_loop:
	mov ecx, dword ptr[edi + 4];    ecx < -a[i + 1]
    cmp ecx, dword ptr[edi];                if  ecx < a[i]
    jg next
	mov edx, dword ptr[edi];                        edx < -a[i]
    mov dword ptr[edi], ecx;
    mov dword ptr[edi+4], edx;                      ebp < -a[i + 1]
               
next:
	add edi, 4
    sub ebx, 0x01
    cmp ebx, 0x0
    jne inner_loop
 
    sub eax, 0x01
    cmp eax,0x0;            comp i = eax count
    jne outter_loop
	
	jmp Done
 
Des :
	mov eax, count; initilize ecx to be zero and ecx to be a counter
	sub eax, 1
	mov esi, list
 outter_loop2 :
                ; copy address into esi.edi, ebp, esp are pointer registers.eax = 32 bit.
	mov edi, esi
	mov ebx, eax; init j = ebx to be zero  j = 0
 inner_loop2:
	mov ecx, dword ptr[edi + 4];    ecx < -a[i + 1]
    cmp ecx, dword ptr[edi];                if  ecx < a[i]
    jl next2
	mov edx, dword ptr[edi];                        edx < -a[i]
    mov dword ptr[edi], ecx;
    mov dword ptr[edi+4], edx;                      ebp < -a[i + 1]
               
next2:
	add edi, 4
    sub ebx, 0x01
    cmp ebx, 0x0
    jne inner_loop2
 
    sub eax, 0x01
    cmp eax,0x0;            comp i = eax count
    jne outter_loop2

	jmp Done

Done:
}
}
 
int main(int argc, char** argv)
{
        int numlist[1000], asc;
        FILE *fptr;
        /*int array[] = { 4, 2, 7, 9, 5 };
        sorter((int *)array, (unsigned int)5, (int)2);
		for(int i = 0; i < 5;i++)
		{
			printf("%d",array[i]);
		}
		*/
 
        int i = 0;
 
        if (argc != 3)
        {
        printf("Usage: %s filename asc_des\n", argv[0]);
        return 1;
        }
 
        asc = atoi (argv[2]);
        asc = (asc == 1) ? 1 : 2;
 
        printf("\n");
 
        fptr = fopen((argv[1]), "rtc");
        if (fptr == NULL)
        printf( "File %s was not opened\n",argv[1] );
        else
        {
        /* Set pointer to beginning of file: */
        fseek(fptr, 0L, SEEK_SET);
 
        /* Read data from file: */
        
        while ( fscanf(fptr, "%d", &numlist[i]) != EOF )
        {
        printf( "%d ", numlist[i] );
        i++;
        }
 
        printf( "\n\nNumber of integer = %d\n", i );
        printf( "Ascend_or_Descend = %d\n\n", asc );
        fclose( fptr );
        }
       
        sorter( numlist, i, asc);
 
        for (int j = 0; j < i; j++)
        printf( "%d ", numlist[j] );
 
        printf("\n");
        
        return 0;
}
 