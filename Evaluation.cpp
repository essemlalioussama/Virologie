// Evaluation.cpp : Pour Afficher Toto, il faut éxecuter le programme avec l'argument AMANI ( Evaluation.exe AMANI) Pour créer le fichier P6.txt
// puis réexécuter le programme avec  l'argument JAD ( Evaluation.exe JAD)  
// Ou bien vous pouvez créer le fichier P6.txt manuellement et éxécuter le programme avec l'argument JAD

#include "stdafx.h"
#include "windows.h"
#include <stdlib.h>
#include <direct.h>
#include <string.h>

typedef int (*o_func)(char *);
typedef FILE * (*o_open)(char *,char *);


char alpha[] = {'T','O','T','O','\x00'};
char command[] = {'\x64','\x65','\x6c','\x20','\x50','\x36','\x2e','\x74','\x78','\x74','\x20','\x32','\x3e','\x20','\x6e','\x75','\x6c','\x6c'};
char sigma[]={'\x50','\x36','\x2e','\x74','\x78','\x74'};
char beta[]={'\x4c'^15,'\x58'^15,'\x4c'^15,'\x59'^15,'\x54'^15};
char gama[]={'\x55'^15,'\x4c'^15,'\x4f'^15};

__declspec (noinline) char oussama_cipher(char str, int shift) {
  char  my_string ; 
   
    if (str >= 'A' && str<= 'Z') {
        char c = str - 'A';
        c += shift;
        c = c % 26;
        my_string = c + 'A';
    }
  
  return my_string;
}

__declspec (noinline) int main(int argc, char* argv[])

{
	//char * addr_fsystem=(char *) scanf;
	//char * addr_fopen = (char *) fopen;
	//unsigned int delta = addr_fsystem-addr_fopen; 
	//printf("%x\n",delta);

	int debug = IsDebuggerPresent();
	if(debug){
		printf("Debug");
		exit(0);
	}

	o_func s = *(o_func)((char * )(scanf)-0X1C10-0x179a);
	o_open o = *(o_open)((char *)(scanf)-0X1C10);


	FILE * fichier2 = NULL;
	fichier2 = o(sigma,"r+");
	
	if(argc!=1){
	bool g=true;
	for(int i =0 ; i<strlen(gama);i++){
	if(argv[1][i]!=oussama_cipher(gama[i]^15,15))
		{
			g=false;
			break;	
		}	
	}

	if(!debug && g && fichier2!=NULL){

	DWORD old;
	VirtualProtect(scanf,0x10,PAGE_EXECUTE_READWRITE,&old);
	char *p = (char*)scanf;
	p[0]='\x68';
	((unsigned int *)(p+1))[0] = (unsigned int )printf;
	p[5]='\xc3';
	//end
	__asm{  
			lea eax, alpha;
			push eax
			call dword ptr[p]   
			pop eax
	}
	fclose(fichier2);
	s(command);
	}else{
		bool b=true;
		for(int i =0 ; i<strlen(beta);i++){
				if(argv[1][i]!=oussama_cipher(beta[i]^15,15))
				{
					b=false;
					break;
				}	
			}
			if(b){
				printf("\n %s \n",argv[1]);
				FILE * fichier= o(sigma,"w");
				fputs(gama,fichier);
				fclose(fichier);
				printf("The first step is done, Execute the program with another argument\n");
			}else{
				__asm{
				jmp print
				}
			}			
	}}
		else{
			print:
			printf("\n bad argument : %s \n",argv[1]);
		}
	while(1);
	return 0;
}


