#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>



typedef struct student
{
	char name[20];	
	int score;    
    struct student *next;
} studentData;//define node of list and name it studentData type

int menu_select();//Menu Function
studentData *Readfromfile(studentData *head);//read from file and create a ordered list according to name
studentData *Query(studentData *head, char *name);//query according to name
studentData *insert(studentData *head, studentData *p);//insert
studentData *del(studentData *head,char *name);//delete
void DisplayAll(studentData *head);//display all records
char *askInput();
int menu_select()
{
	char i;
	do{
		printf("1.create list(read from file)\n");
		printf("2.display all records\n");
		printf("3.insert a record\n");
		printf("4.delete a record\n");
		printf("5.query\n");		
		printf("0.exit\n");
		printf("Please input index(0-5):");
		i=getchar();		
	}while(i<'0' || i>'5');
	return (i-'0');	
}



int main()
{
	studentData *head,*p;
	char temp[20];
	head=NULL;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
				system("cls");
			printf("CREATING  LIST FROM THE FILE \"data.txt\"\n");
			head = Readfromfile(head);
				break;
		case 2:
				system("cls");
			DisplayAll(head);
				break;
		case 3:		
				system("cls");
			printf("INSERT HAVE BEEN INVOKED\n");
				char *bufName = askInput();
				int bufScore;printf(" ENTER SCORE: ");
				scanf("%d", &bufScore);
				printf("ALLOCATED NEW SIZE\n");
				strcpy(p->name, bufName);
				p->score = bufScore;
				head = insert(head, p);
				break;
		case 4:			
				system("cls");    
			printf("DELETE HAVE BEEN INVOKED\n");
				char *delName = askInput();
				head = del(head, delName);
				break;
		case 5:
				if(head == NULL)
				{
					system("cls");  
					printf(" CURRENTLY LIST  IS EMPTY NOTHING TO SEARCH\n");
					break;
				}
				char *bufferCp = askInput();
				//printf("SEARCHING: %s\n", bufferCp);
			 p = Query(head, bufferCp);
			//	printf("FINISHED  PROCESSING\n");
			if(p != NULL )
			{
					system("cls"); 
				printf("NAME: %s   SCORE: %d\n", p->name, p->score);
			}
			else
				printf("THE STUDENT %s DOES NOT HAVE A RECORD\n",temp);
				break;
		
		case 0:
				system("cls");
			 printf("GOOD BYE\n");
				exit(0);

		}
	}
}

studentData *Readfromfile(studentData *head)
{
	char names[100][20], tmpName[20];// a copy of names upto 100 students of 20 characters length for each name;
	int score[100], tmpScore;//The corresponding score for each student;
	char buffer[30];
	int numOfStudent =0, i, j;
	FILE *fp;
	
	if((fp = fopen("data.txt", "r")) == NULL) //Error handle if it fails to open the file
	{
		int errnum = errno;
		fprintf(stderr, "ERROR OPENING FILE: %s\n", strerror(errnum));
		exit(0);
	}
	while(fgets(buffer, sizeof(buffer), fp) != NULL) // read line by line and store each line into a buffer
	{
		sscanf(buffer, "%s %d", names[numOfStudent], &score[numOfStudent]);//format the read buffer into name and score array corresponding 
		                                                                     //to number  of student;
		printf("%s\n", buffer);
		printf("NAME: %s  SCORE %d\n", names[numOfStudent], score[numOfStudent]);
		numOfStudent++; // Increment number of student;
	}
	printf("SUCCESSFULLY CREATED TEMPORARY ARRAY TO STORE BEFORE CREATING LIST:-\n");
	//now sort the names before making the list;
	for(i=0; i< numOfStudent-1; i++)
	{
		for(j=i; j <numOfStudent; j++)
		{
			if(strcmp(names[i], names[j]) > 0) // if the name that was read first is greater than the latter, swap the two
			{
				strcpy(tmpName, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], tmpName);
				
				tmpScore = score[i];
				score[i] = score[j];
				score[j] = tmpScore;
			}
		}
	}
	printf("SUCCESSFULLY SORTED THE ARRAY IN ORDER OF NAME\n");
	//now create the list from this array
	studentData  *tmpStack ;

	tmpStack = NULL;
	for(i=0; i < numOfStudent; i++)
	{
		studentData	*current =  malloc(sizeof(studentData));
	strcpy(current->name, names[i]);
	current->score = score[i];
	current->next = NULL;
		//printf("CREATING LIST FOR %s %d \n", names[i], score[i]);
		if(head == NULL)
		{
			tmpStack = current;
			head = current;
		}
		else
		{
			tmpStack->next = current;
			tmpStack = current;
		}
		//printf("SAVEDD: %s  %d\n", tmpStack->name, tmpStack->score);
	}
	printf("LIST SUCCESSFULLY CREATED\n");
	DisplayAll(head);
	return  head;
}//end readfile function ends;
//display functions here
void DisplayAll(studentData *head)
{
studentData *stackbuffer = head;
printf("LIST OF STUDENSTS AND THEIR SCORE NOW:- \n");
while(stackbuffer != NULL)
{
	printf("%s <-----> %d\n", stackbuffer->name, stackbuffer->score);
  stackbuffer = stackbuffer->next;
}
	
}
studentData *Query(studentData *head, char *name)
{
	//printf("INSIDE QUERY NOW\n");
	studentData *stackbuffer = head;
	//printf("SEARCHING FOR %s ", name);
	while(stackbuffer != NULL)
	{
		//printf("COMPARING: %s AND %s\n", stackbuffer->name, name);
		if(strcmp(stackbuffer->name, name))
		{
			printf("FOUND A MATCH\n");
			return stackbuffer;
		}
		stackbuffer = stackbuffer->next;
	}
	return NULL;
}

studentData *insert(studentData *head, studentData *p)
{
	if(head == NULL)//if the head is empty then create list first then insert student
	{
		head = Readfromfile(head);
	}
	studentData *bufferStack = head;
	studentData *preV;
	preV = malloc(sizeof(studentData));
	while(strcmp(p->name, bufferStack->name) > 0)
	{
		preV = bufferStack;
		bufferStack = bufferStack->next;
	}
	p->next = bufferStack;
	preV->next = p;
	DisplayAll(head);
	return head;
}

studentData *del(studentData *head,char *name)
{
	if(head == NULL)
	{
		printf("STACK IS EMPTY NOTHING TO DELETE\n");
		return NULL;
	}
	studentData *bufferStack = head;
	studentData *prev;
	prev = malloc(sizeof(studentData));
	bool foundMatch = false;
	while(bufferStack->next != NULL)
	{
		if(strcmp(bufferStack->name, name) == 0)
		{
			//printf("FOUND %s in buffer is equal to %s\n", bufferStack->name, name);
			foundMatch = true;
			break;
		}
		else
		{
			prev = bufferStack;
			bufferStack = bufferStack->next;
		}
	}
	if(foundMatch)
	{
		prev->next = bufferStack->next;
		printf("%s HAS BEEN DELETED \n", bufferStack->name);
	}
	else
		printf("NO MATCH WAS FOUND. NOTHING WAS DELETED\n");
	return head;
}

char *askInput()
{
	printf("ENTER NAME PLZ: ");
	char *c = malloc(20);
	scanf("%s",c);
	//printf("SENT: %s", c);
	return c;
}
