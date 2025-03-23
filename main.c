#include <stdio.h>
#include <stdlib.h>

void swap(int *, int, int);
void quickSort(int *, int *, int ,int, int ,int);
int partition(int *, int *, int , int ,int,int);

void swap(int *arr, int x, int y){
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
	
}
void quickSort(int *key, int *lock, int start,int end, int process,int size){
	int mid, i;
	if(start<end){
		process++;
		mid = partition(key, lock, start, end, process,size);
		quickSort(key, lock, start, mid-1, process,size);
		process++;
		quickSort(key, lock, mid+1, end,process,size);
	}
}

int partition(int *key, int *lock, int start, int end, int process,int size){
	int p, i, j, k, a;
	
	srand(time(NULL));
	
	int x = start + (rand() % (end - start + 1));
	
	printf("\n\n%d. Adim Secilen Key: %d\n",process,lock[x]);
	
	swap(lock, start, x);
	
	p = lock[start];
	i = start - 1;
	j = end + 1;
	do{
		do{
			i++;
			if(key[i] == p){
				k = i;		
			}	
		}while((key[i] <= p) && (i < end));
		
		do{
			j--;
			if(key[j] == p){
				k = j;
			}
		}while((key[j] > p) && (j > start));
		
		swap(key,i,j);
		
	}while(i<j);
	

	
	swap(key, i, j);
	swap(key, k, j);
	
	printf("Keyler Duzenleniyor:\n");
	
	printf("Keys: ");
	for(a=start;a<=end;a++){
		printf("%d ",key[a]);
	}
	
	printf("\nLocks: ");
	for(a=start;a<=end;a++){
		printf("%d ",lock[a]);
	} 
	printf("\n\nLocklar Key -> %d ile duzenleniyor\n",lock[start]);	
	
	i = start;
	j = end + 1;
	
	do{
		do{
			i++;	
		}while((lock[i] <= p ) && (i < end));
		do{
			j--;
		}while((lock[j] >= p) && (j > start));
		
		swap(lock, i ,j);
			
	}while(i<j); 
	
	swap(lock, i, j);
	swap(lock, start, j);
	
	printf("Keys: ");
	for(a=start;a<=end;a++){
		printf("%d ",key[a]);
	}
	
	printf("\nLocks: ");
	for(a=start;a<=end;a++){
		printf("%d ",lock[a]);
	} 
	printf("\n");
	
	printf("\nSon durum\nKeys: ");
	for(a=0;a<size;a++){
		printf("%d ",key[a]);
	}
	
	printf("\nLocks: ");
	for(a=0;a<size;a++){
		printf("%d ",lock[a]);
	} 
	
	return j;
}


int main(){
	int i, size, num, *key, *lock;
	
	FILE *fp = fopen("Data.txt","r");
	
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
	
	printf("\nKeys: ");
	for(i=0;i<size;i++){
		printf("%d ",key[i]);
	}
	
	printf("\nLocks: ");
	for(i=0;i<size;i++){
		printf("%d ",lock[i]);
	} 
	
	quickSort(key,lock,0,5,0,size);
	
	return 0;
}
