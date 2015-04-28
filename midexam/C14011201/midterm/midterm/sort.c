//
//  sort.c
//  midterm
//
//  Created by Lee Yu Hsun on 2015/4/16.
//  Copyright (c) 2015年 Yu Hsun Lee. All rights reserved.
//

#include "sort.h"
#include <stdio.h>

void swap(int m,int n)
{
	int temp;
	
	temp = m;
	m = n;
	n = temp;
}

int sort(int *v,int N){
	int i;
	
	
	for(i=0;i<N;++i){
		printf("%d,",v[i]);
	}

	printf("\nsort  ");
	*v=quicksort(N,v);
	for(i=0;i<N;++i){
		printf("%d,",v[i]);
	}
	return 1;
}

int quicksort(int N,int *v){
	int i,j=0,pivot,*less,*great,*pivots;
	int m=0,n=0,o=0;
	//pick middle point of array
	pivot=N/2;
	less=(int *) malloc(N *sizeof(int));
	great=(int *) malloc(N *sizeof(int));
	pivots=(int *) malloc(N *sizeof(int));
	if (N<=1) {
		return *v;
	}else{
		//printf("\n");
		//FOR LOOP判斷v[i]與pivot的大小
		for (i=0; i<N; ++i) {
			
			if (v[i]< v[pivot]) {
				less[m]=v[i];
				//printf("pivot:(%d,%d)\n",v[i],v[pivot]);
				m++;
			}
			else if (v[i] > v[pivot]){
				great[n]=v[i];
				//printf("pivot:(%d,%d)\n",v[i],v[pivot]);
				n++;
			}
			else if (v[i] == v[pivot]){
				
				pivots[o]=v[i];
				//printf("pivot:(%d,%d,%d)\n",v[i],v[pivot],pivots[o]);
				o++;
				
			}
			/*
			 for(k=0;k<o;++k){
				printf("%d,%d,%d\n",i,k,pivots[k]);
			 }*/
			
		}
		
		
	}
	
	
	//對less部分做qsort
	quicksort(m, less);
	
	//對great部分做qsort
	quicksort(n,great);
	
	//將less、pivot、great組合在一起
	//printf("\nless:");
	for(i=0;i<m;++i){
		//printf("\n%d,%d,",i,m);
		//printf("%d,",less[i]);
		v[j]=less[i];
		j++;
		
		
	}
	//printf("\npivots:");
	for(i=0;i<o;++i){
		//printf("\n%d,%d,",i,o);
		//printf("%d,",pivots[i]);
		//printf("%d",j);
		v[j]=pivots[i];
		j++;
		
	}
	//printf("\ngreat:");
	for(i=0;i<n;++i){
		//printf("\n%d,%d,",i,n);
		//printf("%d,",great[i]);
		//printf("%d",j);
		v[j]=great[i];
		j++;
	}
	//printf("\n");
	
	
	
	
	
	return *v;
}

int median(int *v,int N){
	int median;
	median=quickmedian(v,N,0,N);
	printf("\nmedian=%d",median);
	return median;
	
}

int quickmedian(int *v,int total, int initial, int item){
	int i;
	int pivot;
	int mid;
	int counter=initial;
	
	pivot=v[rand() %item-initial];
	swap(pivot, v[item-1]);
	mid=total/2;
	for (i=initial; i<item; i++) {
		if ((v[initial]<=pivot)) {
			swap(v[initial], v[counter]);
			counter++;
		}
	}
	
	if (counter=mid) {
		return v[mid];
	}else if (counter>mid){
		quickmedian(v, total, initial, counter-1);
	}else{
		quickmedian(v, total, counter, item);
	}
	
	return 0;
}
