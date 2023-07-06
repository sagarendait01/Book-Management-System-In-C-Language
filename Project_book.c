
#include<stdio.h> 
#include<string.h> 
typedef struct book 
{ 
  int bookid; 
  char bookname[20];  
  double price; 
  char author[20]; 
  float rating; 
   
}book; 
void store (book*,int); //declaratiom
void print(book*,int); //declaratiom
void searchById(book*,int);//declaration 
void searchbybookname(book*,char);//declaration 
void searchbyauthorname(book*,char);//declaration 
void deletbyid(book*,int);//declaration
void updatebyid(book*,int);//declaration
void max(book*,int);//declaration
void min(book*,int);//declaration
int t=3;// globally declare
void main()
{ 
  book b1[t]; 
  char ch; 
  int choice; 
   
  do 
  { 
  	printf("_______________________________________________________________________________________________________________");
    printf("\n Enter Your Choice--> \n  1.Store Data:: \t 2.Print Data:: \t 3.Search by Id::\t 4.Search by Book Name::\n 5.Search by Author Namey ::\t6.Delete by Id:: \t7.Update by Id:: \t8.maximum book price:: \n 9.minimum book price::\t-->"); 
    scanf("%d",&choice); 
     
    switch(choice) 
    { 
      case 1: 
        printf("\n Entering data of books ::-->\n\n "); 
        store(b1,t); //call
      break; 
       
      case 2: 
        printf("\n Printing  data of books :: "); 
        print(b1,t); //call
      break; 
       
      case 3: 
        searchById(b1,t);//call 
      break; 
       
      case 4: 
       searchbybookname(b1,t);//call 
      break; 
       
      case 5: 
       searchbyauthorname(b1,t);//call 
      break; 
      
      case 6:
       deletbyid(b1,t);	//call
      break;
	  
	  case 7:
	  	updatebyid(b1,t);//call
	  break;
	  
	  case 8:
	  	max(b1,t);//call
	  break;
	  
	  case 9:
	  	min(b1,t);//call
	  break;
		   
      default: 
        printf("\n ******** Choice is Wrong ******** Please Enter Valid Choice....  \n\n"); 
         
       
    } 
   
    printf("\n Do You Want to Continue???? (y/n).....\n"); 
    fflush(stdin); 
    scanf("%c",&ch); 
  }while(ch=='Y' || ch=='y'); 
   
   
   
} 
void store(book*b2,int t) 
{ 
  int i; 
   
  for(i=0;i<t;i++) 
  { printf("_______________________________________________________________________________________________________________");
    printf("\nEnter the Book Id::"); 
    scanf("%d",&b2[i].bookid); 
     
    printf("Enter the Book Name::"); 
    fflush(stdin);
    //scanf("%[^'\n']s",b2[i].bookname); 
    gets(b2[i].bookname); 
     
    printf("Enter the Book Author Name::"); 
    fflush(stdin);
    gets(b2[i].author); 
    
    printf("Enter the Book Price is::"); 
    scanf("%lf",&b2[i].price); 
     
    printf("Enter the Book Rating is::"); 
    scanf("%f",&b2[i].rating); 
     
     
  } 
} 
void print(book*b2,int t) 
{ 
  int i; 
  
  for(i=0;i<t;i++) 
  { printf("_______________________________________________________________________________________________________________");
    printf("\n Book Id = %d\n Book Name = %s\n Author Name = %s\n Book Price = %.2lf \n Book Rating = %.2f\n\n",b2[i].bookid,b2[i].bookname,b2[i].author,b2[i].price,b2[i].rating); 
  } 
} 
 
void searchById (book *b,int t) 
{ 
  int id,i,flag =0; 
  	printf("_______________________________________________________________________________________________________________");
  printf("\n Enter The Id You Want to Search :: "); 
  scanf("%d",&id);  
   
  for(i=0;i<t;i++) 
  { 
    if(b[i].bookid == id) 
    { 
      flag=1; 
      printf("\n %d\t %s\t %s\t %.2lf\t %.2f\n",b[i].bookid,b[i].bookname,b[i].author,b[i].price,b[i].rating); 
    } 
  } 
   
  if(flag == 0) 
  { 
    printf("\n This Id %d Book is Not Present",id); 
  } 
} 
     
void searchbybookname(book*b,char t) 
{ 
 int i,sap=0; 
 char name[20]; 
 printf("_______________________________________________________________________________________________________________");
 printf("\n Enter the Book Name Want to Search :: "); 
 scanf(" %[^'\n']s",&name); 
  
 for(i=0;i<t;i++) 
 { 
  if(strcmp(b[i].bookname,name)==0) 
  { 
   sap=1; 
    printf("\n %d\t %s\t %s\t %.2lf\t %.2f\n",b[i].bookid,b[i].bookname,b[i].author,b[i].price,b[i].rating); 
        } 
 }  
 if(sap==0) 
 { 
  printf("\n Enter the valid book name ... "); 
 } 
 
} 
    
void searchbyauthorname(book*b,char t) 
{ 
 int i,sap=0; 
 char name[20]; 
 printf("\n Enter the Author Name Want to Search :: "); 
 scanf(" %[^'\n']s",&name); 
  
 for(i=0;i<t;i++) 
 { 
  if(strcmp(b[i].author,name)==0) 
  { 
   sap=1; 
    printf("\n %d\t %s\t %s\t %.2lf\t %.2f\n",b[i].bookid,b[i].bookname,b[i].author,b[i].price,b[i].rating); 
        } 
 }  
 if(sap==0) 
 { 
  printf("\n Enter the valid author name  "); 
 } 
 
}
void deletbyid(book*b2,int s)
{
	int i,j,id,flag=0;
	printf("Enter Book Id : ");
   scanf("%d",&id);
   
   
   for(i=0;i<t;i++)
   {
   		if(id==b2[i].bookid)
   		{
   			j=i;
   			
   			while(j<t-1)
   			{
   				b2[j]=b2[j+1];
   				j++;
   				
			}
				t--;
				flag=1;
				break;
			
		}	
	
	}
	if(flag==0)
	{
		printf("\n*****Invalid Book Id******\n");
	}
	
}


void updatebyid(book*b, int t)
{
	int i,id,flag=0,choice;
	printf("Enter the Update Book Id:");
	scanf("%d",&id);
	for(i=0;i<t;i++)
	{
		if(b[i].bookid==id)
		{
			printf("***********\n");
			printf("\t4:Book Price::\t5: Book Rating::");
			scanf("%d",&choice);
			printf(" Upadte Information of Book :\n");
			
		
		
	
		if(choice==4)
		{
		printf("Enter the Book Price:");
		scanf("%lf",&b[i].price);
		}
		if(choice==5)
		{
		printf("Enter the Bool Rating:");
		scanf("%f",&b[i].rating);
		}
		
		flag=1;
		break;
			
		}
		
	}
	if(flag==0)
	{
	
	printf("\n\nInvalid Book Id Number..\n");
	}
}
// maximum book price
void max(book* b, int t)
{
 
 int i, index = 0 ;
 double max;
 
 max= b[0].price;
 
 for(i=1; i<t; i++)
 {
  
  if(b[i].price > max)
  {
   max = b[i].price;
   index = i;
  }
  
 }
 
 printf("\nThe Maximum value of a book name is: %s and the price is Rs %.2lf",b[index].bookname, b[index].price);
 
}

//  Minimum Book price


void min(book* b, int t)
{
 
 int i, index = 0;
 double min ;
 
 min= b[0].price;
 
 for(i=1; i<t; i++)
 {
  
  if(b[i].price < min)
  {
   min = b[i].price;
   index = i;
  }
  
 }
 
 printf("\nThe Minimum value of a book name is: %s and the price is Rs %.2lf",b[index].bookname, b[index].price);
 
}




