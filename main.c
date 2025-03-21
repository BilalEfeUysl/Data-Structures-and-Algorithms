#include <stdio.h>
#include <stdlib.h>

void swap(int *, int, int);
void quickSort(int *, int *, int ,int );

void swap(int *arr, int x, int y){
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
	
}
void quickSort(int *key, int *lock, int start,int end){
	int mid;
	if(start<end){
		mid = partition(key, lock, start, end);
		quickSort(key, lock, start, mid-1);
		quickSort(key, lock, mid+1, end);
	}
}

int partition(int *key, int*lock, int start, int end){
	int p, i, j, k;
	int x = start + (rand() % (end - start + 1));
	
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
		}while((key[j] >= p) && (j > end));
		
		swap(key,i,j);
		
	}while(i<j);
	
	swap(key, i, j);
	swap(key, k, j);
	
	i = start;
	j = end + 1;
	
	do{
		do{
			i++;	
		}while((lock[i] <= p ) && (i < end));
		do{
			j--;
		}while((lock[i] >= p) && (j > start));
		
		swap(lock, i ,j);
			
	}while(i<j); 
	
	swap(lock, i, j);
	swap(lock, start, j);
	
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

	return 0;
}
