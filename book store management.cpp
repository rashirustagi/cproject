#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
struct book
{
  char name[50];
  char author[50];
  char publisher[50];
  int price;
  int copies;
  char genre[50];
};

void insert() 
{ 
	FILE *f1,*f2;
	char ch;
	struct book b;
 	f1=fopen("records.txt","a");
	if(f1==NULL)
    { 
		printf(" \n unable to open the file"); 
		exit(0); 
   }
	else{
			do	{
					printf(" \n enter book name :"); 
					scanf("%s",&b.name);
					printf("enter author name :"); 
					scanf("%s",&b.author);
					printf("enter publisher name :"); 
					scanf("%s",&b.publisher);
					printf("enter the book price :"); 
					scanf("%d",&b.price); 
					printf("enter the no of books :"); 
					scanf("%d",&b.copies);
					printf("enter genre :");
					scanf("%s",&b.genre);
					fwrite(&b,sizeof(b),1,f1);
					printf("\n add another record?(y/n)"); 
					scanf("%c",&ch); 
				}while(ch=='y' || ch=='Y'); 
			fclose(f1);
		}	
		
}



void del()
{            
	struct book  b2;
    char bookname[50];
    FILE*f2,*f1;
    f1=fopen("records.txt","rb");
    if(f1==NULL)
        {
			printf("cannot open the file");
            exit(0);
        }  
    else
	    {
				f2=fopen("change.txt","wb");
				printf("enter the bookname\n");
				//gets(bookname);
				scanf("%s",&bookname);
				getchar();
				while(fread(&b2,sizeof(b2),1,f1))
				{
					if(bookname!= b2.name)
					fwrite(&b2,sizeof(b2),1,f2);
				}
			remove("records.txt");
			rename("change.txt","records.txt");
			fclose(f2);
			fclose(f1);
		}
}



void display()
{	FILE *f1;
	struct book b3;
	f1=fopen("records.txt","rb");
	if(f1==NULL)
	{	printf("file cannot be opened");
		exit(0);
	}
	else
	{
		while(fread(&b3,sizeof(b3),1,f1))
		printf(" book name:%s  \n author's name:%s \n publisher's name: %s \n price:%d /n no. of copies: %d \n genre: %s \n",b3.name,b3.author,b3.publisher, b3.price, b3.copies,b3.genre);
	}
	fclose(f1);
}



void update()
{ 
	char bookname[50];
	int flag=0;
	FILE *f1,*f2;	
	struct book b4;
	f1=fopen("records.txt","rb");
	f2=fopen("change.txt","wb");
	if(f1==NULL)
	{	printf("file cannot be opened");
		exit(0);
	}
	else
	{	printf("enter the book name you want to modify:"); 
		//gets(bookname); 
		scanf("%s",bookname);
		while(fread(&b4,sizeof(b4),1,f1))
    	{	 
			if(strcmp(bookname,b4.name)==0) 
       		{	 
				printf("enter name of the new book :"); 
				//gets(b4.name); 
				scanf("%s",&b4.name);
				printf("enter author's name :"); 
				//gets(b4.author); 
				scanf("%s",&b4.author);
				printf("enter publisher's name :"); 
				//gets(b4.publisher); 
				scanf("%s",&b4.publisher);
				printf("enter the price :"); 
				scanf("%d",&b4.price);
				printf("enter the no of books :"); 
				scanf("%d",&b4.copies);
				printf("enter genre:");
				//gets(b4.genre);
				scanf("%s",&b4.genre);
				fwrite(&b4,sizeof(b4),1,f2);
				flag=1;
       		}	 
			else
			fwrite(&b4,sizeof(b4),1,f2);
		}
	if(flag==0)
 		{	printf("no book available");
			exit(0);
    	} 
	}
	fclose(f2);
	fclose(f1);
	remove("records.txt");
	rename("change.txt","records.txt");
}



void search() 
{ 
	FILE *f1;
	int flag=0;
	struct book b5;
	char bookname[50];
	f1=fopen("records.txt","rb");
	printf("enter bookname"); 
	//gets(bookname);
	scanf("%s",&bookname);
	while(fread(&b5,sizeof(b5),1,f1))
        { 
			if(strcmp(bookname,b5.name)==0) 
            { 
				printf("book name:%s \n author's name:%s \n publisher's name:%s \n price: %d \n no of copies:%d \n genre: %d \n",b5.name,b5.author,b5.publisher,b5.price,b5.copies,b5.genre);
				flag=1;
			}
        } 
	if(flag==0)
	printf("no such book name exists");
	fclose(f1);
} 


int main()
{ char pass[20];
int choice;
char ch;
while(1)
	{
	printf("enter the passward \n");
	scanf("%s",pass);
	if(strcmp(pass,"@@@@")!=0)
		printf("wrong passward");
	else
		{
			do{
				printf("\n \n \n \t \t \t \t \t **********************");
				printf("\n \n   \t \t \t \t \t BOOK STORE MANAGEMENT");
				printf("\n \n  \t \t \t \t \t **********************");
				printf(" \n \t \t \t \t \t \t 1.Addition");
				printf("\n \t \t \t \t \t \t 2.Delete");
				printf("\n \t \t \t \t \t \t 3.Update");
				printf("\n \t \t \t \t \t \t 4.Search");
				printf("\n \t \t \t \t \t \t 5.Display");
				printf("\n \t \t \t \t \t \t Enter the choice:");
				scanf("%d",&choice);
 				switch(choice)
				{	case 1:insert();
							break;
				  	case 2:del();
							break;
					case 3:update();
							break;
					case 4:search();
							break;
					case 5:display();
							break;
				} 
 			printf("do you want to modify? enter y or n  \n");
 			scanf(" %c",&ch);
 			}while(ch=='y'||ch=='Y');
		}
	}
return 0;
}

 




	
