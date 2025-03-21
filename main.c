#include <stdio.h>
#include <stdlib.h>



int main(){
	int i, size, num, *key, *lock;
	
	FILE *fp = fopen("Veri.txt","r");
	
	if(fp == NULL){
		printf("Dosya Okunamadi.\n");
	}else{
		printf("Dosya Okuma Basarili.\n");
	}
	
	fscanf(fp,"%d",&size);
	
	key = (int *)malloc(size*sizeof(int));
	lock = (int *)malloc(size*sizeof(int));
	
	for(i=0;i<size;i++){
		fscanf(fp,"%d",&num);
		key[i] = num;	
	}
	for(i=0;i<size;i++){
		fscanf(fp,"%d",&num);	
		lock[i] = num;
	}
	
	fclose(fp);

	return 0;
}
