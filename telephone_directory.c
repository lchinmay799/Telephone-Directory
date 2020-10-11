#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char fname[10];
	char lname[10];
	int number;
	int m;
	struct node *next;
};
typedef struct node* N;
N create(N start){
N new;
N c;
char f[10],l[10];
int num,n;
printf("enter the serial number: ");
scanf("%d",&n);
while(n!=-1){
	printf("enter the first name,last name and phone number: \n");
	scanf("%s %s %d",f,l,&num);
	if(start==NULL){
		new=(N)malloc(sizeof(struct node));
		strcpy(new->fname,f);
		strcpy(new->lname,l);
		new->number=num;
		new->m=n;
		start=new;
		new->next=NULL;}
	else{
		c=start;
		new=(N)malloc(sizeof(struct node));
		strcpy(new->fname,f);
		strcpy(new->lname,l);
		new->number=num;
		new->m=n;
		new->next=NULL;
		while(c->next!=NULL)
			c=c->next;
				
		c->next=new;}
	printf("enter the serial number: ");
	scanf("%d",&n);}
return start;}
N searchid(N start,int n){
	N c=start;
	while(c!=NULL){
		if(c->m==n)
			break;
	c=c->next;}
	if(c==NULL){
		printf("\ngiven information is not there in the telephone directory bro\n");
		return NULL;}
	else
		return c;}
N searchname(N start,char *f,char *l){
	N c=start;
	while(c!=NULL){
		if((strcmp(c->fname,f)==0) && (strcmp(c->lname,l)==0))
			break;
	c=c->next;}
	if(c==NULL){
		printf("\ngiven information is not there in the telephone directory bro\n");
		return NULL;}
	else
		return c;}
void display(N start){
	N c=start;
	while(c!=NULL){
		printf("%d   %s  %s  %d\n",c->m,c->fname,c->lname,c->number);
		c=c->next;}}
int main(){
	N start=NULL;
	N c=NULL;
	char z[7];
	char f[10],l[10],w[10];
	int m;
	char d[]="name";
	char e[]="number";
	char q[]="close";
	char r[]="search";
	start=create(start);
	display(start);
	while(1)
	{
	printf("Press close to close the directory and search for searching: ");
	scanf("%s",w);
	if(strcmp(w,r)==0)
	{
	printf("enter what kind of information you know about the person [name / number]: ");
	scanf("%s",z);
	if((strcmp(z,e)==0) || (strcmp(z,d)==0))
	{
	if(strcmp(z,e)==0){
	printf("enter the serial number: ");
		scanf("%d",&m);
		c=searchid(start,m);
		if(c==NULL)
				printf("\nSorry :( entered number is not there in the directory\n");
		else{
		printf("\nPerson's Name: %s %s \n",c->fname,c->lname);
		printf("Phone NUmber: %d\n",c->number);}}
		else if(strcmp(z,d)==0){
		printf("enter the first name and last name: ");
		scanf("%s %s",f,l);
		c=searchname(start,f,l);
		if(c==NULL)
			printf("Sorry :( entered name not there in the directory...\n");
		else{
		printf("Serial Number: %d\n",c->m);
		printf("Person's Name: %s %s\n",c->fname,c->lname);
		printf("Phone Number: %d\n",c->number);}}
	}
	else
		printf("Enter a valid option either name or number...\n");
	}
	else if(strcmp(w,q)==0)
		return 0;
	else
		printf("Enter a valid option...");
	}
}

	
