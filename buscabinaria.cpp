#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	FILE *f;
	int tam,qtd,inicio,fim,meio;
	const char* procurado;
	argv[1]="cep_ordenado.dat";
	f= fopen(argv[1],"rb");
	fseek(f,0,SEEK_END);
	tam= ftell(f);
	qtd=tam/sizeof(FILE);
	inicio=0;
	fim= qtd-1;
	bool achei=false;
	procurado="2755170";
		
	while (inicio<=fim&&!achei)
	{
		meio =(inicio+fim)/2;
		fseek(f,meio*sizeof(FILE),SEEK_SET);
		fread(f,sizeof(FILE),1,f);
		
		if (meio==*procurado){
			achei=true;
			printf("CEP encontrado");
			
			
		}
		else if (*procurado>meio){
			inicio=meio+1;
		}
		else {
			fim=meio-1;
	
		}
		
	
		

	}
	if (achei==false){
			printf ("CEP nao encontrado");
			
		}
	
	fclose(f);
	
}
