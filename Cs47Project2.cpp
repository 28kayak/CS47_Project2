// This is the main project file for VC++ application project 
// generated using an Application Wizard.

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

int sorter (int* list, int count, int opcode)
{
__asm
{
	mov eax, 0			; zero out the result
	mov ebx, opcode		; move opcode to ebx for comparison
						
	//cmp ebx, 0x01       ;check ebx is 1 or not. true is assending order 

	
//loop:
	//do something 
	//n = n -1
	//if (n > 1)
		//goto loop 
//done:
	//return result i = esi, j = edi
	mov eax, count      ;initilize ecx to be zero and ecx to be a counter
outter_loop:
	mov esi, list       ;copy address into esi.  edi, ebp, esp are pointer registers. eax = 32 bit.
	mov edi, list 
	mov ebx,0       	;init j = ebx to be zero  j=0
inner_loop: 
	mov ecx, dword ptr[esi]
	sub ecx, dword ptr[esi+4] ;a[j]-a[j+1]
	cmp ecx, 0x00             ;determine if ecx is negative
	jb next
	
	mov edi, esi
	add edi, 0x04
	mov edx, dword ptr[edi]   ;swap
	mov ebp, dword ptr[esi]
	mov dword ptr[edi], ebp 
	mov dword ptr[esi], edx







next:
	add esi, 0x04 
	add ebx, 0x01;one increment
	cmp ebx,eax 
	jne inner_loop
	

	sub eax, 0x01		;one decrement 
	cmp eax, count		;comp i = eax count
	jne outter_loop




Des:
	mov eax, count      ;initilize ecx to be zero and ecx to be a counter
outter_loop:
	mov esi, list       ;copy address into esi.  edi, ebp, esp are pointer registers. eax = 32 bit.
	mov edi, list 
	mov ebx,0       	;init j = ebx to be zero  j=0
inner_loop: 
	mov ecx, dword ptr[esi]
	sub ecx, dword ptr[esi+4] ;a[j]-a[j+1]
	cmp ecx, 0x00             ;determine if ecx is negative
	ja next
	
	mov edi, esi
	add edi, 0x04
	mov edx, dword ptr[edi]   ;swap
	mov ebp, dword ptr[esi]
	mov dword ptr[edi], ebp 
	mov dword ptr[esi], edx







next:
	add esi, 0x04 
	add ebx, 0x01;one increment
	cmp ebx,eax 
	jne inner_loop
	

	sub eax, 0x01		;one decrement 
	cmp eax, count		;comp i = eax count
	jne outter_loop
	


}

}

int main(int argc, char** argv)
{
	int numlist[1000], asc;
	FILE *fptr;
	int array[] = {4,2,5,7,9};
	sorter( array, 5, 1);

	//int i = 0;
	
	/*if (argc != 3)
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
      fseek( fptr, 0L, SEEK_SET );

      /* Read data from file: */
	  /*
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
   */
   return 0;
}



	

