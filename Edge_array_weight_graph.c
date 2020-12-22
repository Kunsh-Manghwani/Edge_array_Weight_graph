#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int*b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

struct node{
	int data;
	struct node * next;
}*tptr;


struct edge{
	int p1;
	int p2;
	int weight;
}*eptr;

struct edge* aee[100];
int aee_size=0;
struct node* arr[100];
int w[100][100];

void edgesort(){
	 int i, j; 
   for (i = 0; i < aee_size-1; i++)         
       for (j = 0; j < aee_size-i-1; j++)  
           if (aee[j]->weight > aee[j+1]->weight) 
              swap(arr[j], arr[j+1]); 
}
int main(){
	int i,j;
	for(i=0;i<100;i++){
		arr[i]=NULL;
	}
	printf("Number of vertices in graph \n");
	int v,e;
	scanf("%d",&v);
	int a,b,we;
	printf("Number of Edges in graph \n");
	scanf("%d",&e);
	for (i=0;i<e;i++){
		scanf("%d %d %d",&a,&b,&we);
		// for a--b
		struct edge* eptr= (struct edge*)malloc(sizeof(struct edge));
		eptr->p1=a;
		eptr->p2=b;
		eptr->weight=we;
		aee[aee_size]=eptr;
		aee_size++;
		w[a][b]=we;
		struct node* ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=b;
		ptr->next=NULL;
		if(arr[a]==NULL){
			arr[a]=ptr;
		}else{
			tptr=arr[a];
			while(tptr->next !=NULL){
				tptr=tptr->next;
			}
			tptr->next=ptr;
		}
		// for b--a
		eptr= (struct edge*)malloc(sizeof(struct edge));
		eptr->p1=b;
		eptr->p2=a;
		eptr->weight=we;
		aee[aee_size]=eptr;
		aee_size++;
		w[b][a]=we;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=a;
		ptr->next=NULL;
		if(arr[b]==NULL){
			arr[b]=ptr;
		}else{
			tptr=arr[b];
			while(tptr->next !=NULL){
				tptr=tptr->next;
			}
			tptr->next=ptr;
		}
	}
	for(i=0;i<v;i++){
		tptr=arr[i];
		printf("%d ->",i);
		while(tptr!=NULL){
			printf("%d ->",tptr->data);
			tptr=tptr->next;
		}
		printf("\n");
	}
	
	printf("array of edjes\n");
	for(i=0;i<aee_size;i++){
		printf("%d - %d  :  %d\n",aee[i]->p1,aee[i]->p2,aee[i]->weight);
	}
	
	printf("edge matrix \n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d   ",w[i][j]);
		}
		printf("\n");
	}
	}
