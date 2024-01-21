#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//NAME:Omar Salah Eldin   BIN:16 SEC:3
//NAME:Omar Salah Hussien   BIN:17 SEC:3
//NAME:Mohamed Ayman ELSayed Mahmoud  BIN:33 SEC:3
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Define Global Values.
const int L;//size of array
int full_position=0;//the length of the hash table
int quadric=0;//global value to get key of quadric hashing (birthday+(i*i)%L
int hashvalue;//hash value for open hash
int key;//key for open hash
#define size 10//Size of open hash linked list
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------OPEN HASH TABLES---------------------------------------------------------------------------------------------------------------
struct Student//structure for a student
{
    char name[50];
    int id;
    int day, month, year;
    int score;
    struct Student*next;//pointer to go to next
    int check_full;
};
struct Student *chain[size];
// initialize all chain with null
void initialize_open_hash()//initialize the hash table according to the size
{
    for (int i=0; i<size; i++)
    {
        chain[i] = NULL;
    }
}

void insert_open_hash()
{
//create a new node
    char garbage;//garbage to delete the error in the array of char
    struct Student* Node1= NULL;
    Node1 = (struct Student*) malloc(sizeof(struct Student));//size of structure student
    Node1->next=NULL;
    printf("-----------------------------------------------------------------------\n");//Get the values from the user and save it in the new node
    printf("please insert the data of student \n");
    printf("enter the name of the student\n");
    scanf("%c", &garbage, 1);
    scanf("%[^\n]", &Node1->name, 50);
    printf("enter the ID of the student\n");
    scanf("%d",&(Node1->id));
    printf("enter the birth date of the student\n ");
    printf("enter the day\n");
    scanf("%d",&(Node1->day));
    printf("enter the month\n");
    scanf("%d",&(Node1->month));
    printf("enter the year\n");
    scanf("%d",&(Node1->year));
    printf("enter the score of the previous year\n");
    scanf("%d",&(Node1->score));
    hashvalue=gethashvalue(Node1->name);
    printf("The Hash Value is : %d \n",hashvalue );
    key = hashvalue % size;// finding the value of the key
    printf("The key is : %d \n", key );
    printf("Insert done!!!!\n");
    printf("------------------------------------------------------------------------\n");
    if(chain[key] == NULL)// check if the chain[key] is empty
    {
        chain[key] = Node1;
    }
    else// if some elements are found on chain[key]
    {
        struct Student *temp=chain[key];
        while (temp->next)
        {
            temp=temp->next;
        }
        temp->next=Node1;
        Node1->next=NULL;

    }
}
//-------------------------------------------------------------------------------------------------------------
//Function to get the key value-------------------------------------------------------------------------------
int gethashvalue(char name[50])
{
    int x =0;
    for (int i=0; i<50; i++)
    {
        x=x+name[i];
        if(name[i]==NULL)
            break;
    }
    return x;
}
//--------------------------------------------------------------------------
//Function to display the open hash------------------------------------
void display_open_hash()
{
    int i;
    for( i=0; i<size ; i++)//go to for loop
    {
        struct Student *temp = chain[i];
        while(temp != NULL)
        {
            printf("The Name of student : %s  \n", temp->name) ;
            printf("The ID of student : %d  \n", temp->id) ;
            printf("The Birth Date of student : %d / %d  / %d  \n", temp->day,temp->month,temp->year) ;
            printf("The Previous Year Score of student : %d  \n", temp->score) ;
            printf("-------------------------------------------------------------\n");
            temp=temp->next;
        }

    }
}
//--------------------------------------------------------------------------
//Function to search in open hash------------------------------------
void search_open_hash()
{
    char garpage;
    int j;
    int id3;
    int flag=1;
    char item[50];
    int hash_value;
    int key1;
    printf("please enter the name which you need to search for \n");
    scanf("%c", &garpage, 1);
    scanf("%[^\n]", item, 50);
    printf("please enter the ID which you need to search for \n");
    scanf("%d",&id3);
    hash_value=gethashvalue(item);
    key1 = hashvalue % size;

    for( j=0; j<size ; j++)
    {
        struct Student *temp = chain[j];
        while(temp)
        {
            if(id3 == temp->id)
            {
                printf("-------------------------------------------------------\n");
                printf("The student is found!!! \n ");
                printf("The Name of student : %s  \n", temp->name) ;
                printf("The ID of student : %d  \n", temp->id) ;
                printf("The Birth Date of student : %d / %d  / %d  \n", temp->day,temp->month,temp->year) ;
                printf("The Previous Year Score of student : %d  \n", temp->score) ;
                printf("------------------------------------------------------\n");
                flag=0;
            }
            temp=temp->next;
        }
    }
    if(flag==1)
    {
        printf("\n The student is not found !!!!\n------------\n");
    }
}
//---------------------------------------------------------------------------------
//Function delete in open hash
void delete_open_hash()
{
    char garpage;
    int k ;
    int id3;
    int flag=1 ;
    char item2[50];
    int Hash_Value;
    int key2;
    printf("please enter the name which you need to delete \n");
    scanf("%c", &garpage, 1);
    scanf("%[^\n]", item2, 50);
    printf("please enter the ID which you need to delete \n");
    scanf("%d",&id3);
    Hash_Value=gethashvalue(item2);
    key2 = Hash_Value % size;
    struct Student* remove=NULL;
    struct Student *temp = chain[key2];
    //search for student to be deleted
    if(temp!=NULL)
    {
        if(id3==temp->id)
        {

            remove=temp;
            temp=temp->next;
            free(remove);
            chain[key2]=temp;
            flag=0;
            printf("Deleted successfully ...\n--------\n");
        }
        else
        {
            while((temp->next)!=NULL )
            {
                if(id3==temp->next->id)
                {

                    remove=temp->next;
                    temp->next=temp->next->next;
                    free(remove);
                    flag=0;
                    printf("Deleted successfully ...\n--------\n");
                    goto Exit_delete_open;
                }
                temp=temp->next;
            }

        }
Exit_delete_open:
        if(flag==1)
        {
            printf("\n The student is not found !!!!\n------------\n");
            return 0;
        }
    }
    else
        printf("The chain is empty ,so we can't delete in it\n-------\n");
}
//------------------------------------------Closed Hash---------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//Function to insert the size of array.
void size_of_array()
{
    printf("please enter size of array : \n");//define the length of the array
    scanf("%d",&L);//read the size of array
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Function to save data in student
struct Student S1;
void save_student_Data()
{
    char garbage;
    int data;
    printf("enter name of student: \n");
    scanf("%c", &garbage, 1);
    scanf("%[^\n]",S1.name, 50);
    printf("enter ID of student: \n");
    scanf("%d", &data);
    S1.id=data;
    printf("enter Day of student: \n");
    scanf("%d", &data);
    S1.day=data;
    printf("enter month of student: \n");
    scanf("%d", &data);
    S1.month=data;
    printf("enter year of student: \n");
    scanf("%d",&data );
    S1.year=data;
    printf("enter score of student: \n");
    scanf("%d",&data );
    S1.score=data;
    S1.check_full=1;
    printf("------------------------------------------------------------------------------------------------\n");
    return S1;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//function that calculate the key of that student by birthday
int hashing_by_linear_birthday(struct  Student S1)
{
    int key_closed= (S1.day+S1.month+S1.year)%L;
    return key_closed;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//initialize the value of array of hash table
void initialize_arr(struct Student arr[])
{
    int i;
    for(i=0; i<L; i++)
    {
        arr[i].check_full=0;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Function to insert by linear .
void insert_by_linear(struct Student arr[])
{
    int position= hashing_by_linear_birthday(S1);//call the function to get the key of student by birth
    if(full_position==L)
    {
        printf("The Hash is full so can't insert student \n");
        return;
    }
    while (arr[position].check_full==1)
    {
        position++;//check if that position is full so increment and go to next of that key
        if(position==L)
            position=0;//to return to the begin of the hash table
    }
    arr[position]=S1;
    arr[position].check_full=1;
    full_position++;
    printf("The insert done\n------- \n");
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//Function to display the array
void display_array(struct Student arr[])
{
    int i;
    for(i=0; i<L; i++)
    {
        if(arr[i].check_full==0)
            printf("empty place\n-----------\n");
        else if (arr[i].check_full==1)
            printf("Name:%s\n id:%d\n birthday: %d/%d/%d\n score:%d\n------------------\n",arr[i].name,arr[i].id,arr[i].day,arr[i].month,arr[i].year,arr[i].score);
        else
            printf("empty\n---------\n");
    }
    printf("Display done.\n----------------\n");
}
//------------------------------------------------------------------------------------------------------------------
//Function delete
void delete_by_linear(struct Student arr[],int day,int month,int year, int id2)
{
    int k =0;
    int data;
    printf("enter ID of student: \n");
    scanf("%d", &data);
    id2=data;
    printf("enter Day of student: \n");
    scanf("%d", &data);
    day=data;
    printf("enter month of student: \n");
    scanf("%d", &data);
    month=data;
    printf("enter year of student: \n");
    scanf("%d",&data );
    year=data;
    printf("------------------------------------------------------------------------------------------------\n");
    if (full_position==0)
    {
        printf("The Hash is Empty so can't delete \n ");
        return;
    }
    int position =(day+month+year)%L;//to calculate the key of the student we want to delete
    for(int count_in_hash=0; count_in_hash<L; count_in_hash++)
    {
        if(arr[position].check_full!=0)
        {
            while (arr[position].check_full!=0)
            {
                if((arr[position].id==id2)&&((arr[position].day+arr[position].month+arr[position].year)%L)==((day+month+year)%L))
                {
                    printf("deleted \n");
                    arr[position].check_full=0;
                    full_position--;
                    return;
                }
                else if ((arr[position].id!=id2)&&((arr[position].day+arr[position].month+arr[position].year)%L)!=((day+month+year)%L))
                {
                    position++;
                    if(position==L)
                        position=0;
                }
                else
                {
                    position++;
                }
                if(position==L)
                    position=0;
                k++;
                if(k==L)
                    goto Exit_loob_delete;

            }
Exit_loob_delete:
            if (arr[position].check_full==0 || arr[position].id!=id2 )
                printf("The student not found\n----------------- \n ");
            goto  Exit_function_delete;

        }
        position++;
    }
Exit_function_delete:
    {}

}
//----------------------------------------------------------------------------------------------------------------------------
//Function to search by birthday and id;
void search_by_linear(struct Student arr[],int day,int month,int year, int id2)
{
    int data;
    int k =0;//Variable to check if we moved on the all hash
    printf("enter ID of student: \n");
    scanf("%d", &data);
    id2=data;
    printf("enter Day of student: \n");
    scanf("%d", &data);
    day=data;
    printf("enter month of student: \n");
    scanf("%d", &data);
    month=data;
    printf("enter year of student: \n");
    scanf("%d",&data );
    year=data;
    printf("------------------------------------------------------------------------------------------------\n");
    if (full_position==0)
    {
        printf("The Hash is Empty so no student to search on him\n-------------- \n ");
        return;
    }
    int position =(day+month+year)%L;//to calculate the key of the student we want to search on
    for(int count_in_hash=0; count_in_hash<L; count_in_hash++)
    {
        k=0;
        if(arr[position].check_full!=0)
        {
            while (arr[position].check_full!=0)
            {
                if((arr[position].id==id2)&&((arr[position].day+arr[position].month+arr[position].year)%L)==((day+month+year)%L))
                {
                    printf("Founded \n");
                    printf("Name:%s\n id:%d\n birthday: %d/%d/%d\n score:%d\n",arr[position].name,arr[position].id,arr[position].day,arr[position].month,arr[position].year,arr[position].score);
                    return;
                }
                else if ((arr[position].id!=id2)&&((arr[position].day+arr[position].month+arr[position].year)%L)==((day+month+year)%L))
                {
                    position++;

                }
                else
                {
                    position++;
                }
                if(position==L)
                    position=0;
                k++;
                if(k==L)
                    goto Exit_loob;
            }
Exit_loob:
            if (arr[position].check_full==0 || arr[position].id!=id2)
                printf("The student not found\n----------------- \n ");
            goto Exit_function_search;
        }
        position++;
    }
Exit_function_search:
    {}

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------Start quadric prop-------------------------------------------------------------------------------------------------------------
//function that calculate the key of that student by birthday
int hashing_by_quadric_birthday(struct  Student S1)
{
    int key_closed= ((S1.day+S1.month+S1.year)+(quadric*quadric))%L;
    return key_closed;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Function to insert by quadric .
void insert_by_quadric(struct Student arr[])
{
    int k=0;//counter for the hash size
    int position= hashing_by_quadric_birthday(S1);//call the function to get the key of student by birth
    if(full_position==L)
    {
        printf("The Hash is full so can't insert student \n--------\n");
        return;
    }
    while (arr[position].check_full==1 && k<L)//to check if the key of we need is free and didn't go more than 1 cycle
    {
        quadric++;
        position=hashing_by_quadric_birthday(S1);//check if that position is full so increment and go to next of that key
        if(position==L)
            position=0;//to return to the begin of the hash table
        k++;
    }
    if(k<L &&arr[position].check_full==0)
    {
        arr[position]=S1;
        arr[position].check_full=1;
        printf("The insert done\n------- \n");
        quadric=0;
        full_position++;
    }
    else
        printf("There is no place free in the hash of that key to be inserted!!!!!!\n--------\n");
}
//----------------------------------------------------------------------------------------------------------------------------
//Function to search by birthday and id in quadric;
void search_by_quadric(struct Student arr[],int day,int month,int year, int id2)
{
    int data;
    int k =0;//Variable to check if we moved on the all hash
    printf("enter ID of student: \n");
    scanf("%d", &data);
    id2=data;
    printf("enter Day of student: \n");
    scanf("%d", &data);
    day=data;
    printf("enter month of student: \n");
    scanf("%d", &data);
    month=data;
    printf("enter year of student: \n");
    scanf("%d",&data );
    year=data;
    printf("------------------------------------------------------------------------------------------------\n");
    if (full_position==0)
    {
        printf("The Hash is Empty so no student to search on him\n-------------- \n ");
        return;
    }
    int position =((day+month+year)+(quadric*quadric))%L;//to calculate the key of the student we want to search on
    for(int count_in_hash=0; count_in_hash<L; count_in_hash++)
    {
        if(arr[position].check_full!=0)
        {
            while (arr[position].check_full!=0)
            {
                if((arr[position].id==id2)&&(((arr[position].day+arr[position].month+arr[position].year)+(quadric*quadric))%L)==(((day+month+year)+(quadric*quadric))%L))
                {
                    printf("Founded \n");
                    printf("Name:%s\n id:%d\n birthday: %d/%d/%d\n score:%d\n",arr[position].name,arr[position].id,arr[position].day,arr[position].month,arr[position].year,arr[position].score);
                    return;
                }
                else if((arr[position].id!=id2)&&(((arr[position].day+arr[position].month+arr[position].year)+(quadric*quadric))%L)==(((day+month+year)+(quadric*quadric))%L))
                {
                    quadric++;
                    position=((day+month+year)+(quadric*quadric))%L;
                }
                else
                {
                    quadric++;
                    position=((day+month+year)+(quadric*quadric))%L;
                }
                k++;
                if(k==L)
                    goto Exit_loob2;
            }
Exit_loob2:
            if (arr[position].check_full==0 || arr[position].id!=id2)
                printf("The student not found\n----------------- \n ");
            goto Exit_function_search_quadr;
        }
        quadric++;
        position=(position+(quadric*quadric))%L;
    }
    Exit_function_search_quadr:{}
    quadric=0;
}
//------------------------------------------------------------------------------------------------------------
//Function delete
void delete_by_quadric(struct Student arr[],int day,int month,int year, int id2)
{
    int k =0;
    int data;
    printf("enter ID of student: \n");
    scanf("%d", &data);
    id2=data;
    printf("enter Day of student: \n");
    scanf("%d", &data);
    day=data;
    printf("enter month of student: \n");
    scanf("%d", &data);
    month=data;
    printf("enter year of student: \n");
    scanf("%d",&data );
    year=data;
    printf("------------------------------------------------------------------------------------------------\n");
    if (full_position==0)
    {
        printf("The Hash is Empty so can't delete \n ");
        return;
    }
    int position =((day+month+year)+(quadric*quadric))%L;//to calculate the key of the student we want to delete
    for(int count_in_hash=0; count_in_hash<L; count_in_hash++)
    {
        if(arr[position].check_full!=0)
        {
            while (arr[position].check_full!=0)
            {
                if((arr[position].id==id2)&&(((arr[position].day+arr[position].month+arr[position].year)+(quadric*quadric))%L)==(((day+month+year)+(quadric*quadric))%L))
                {
                    printf("deleted \n");
                    arr[position].check_full=0;
                    full_position--;
                    return;
                }
                else if((arr[position].id!=id2)&&(((arr[position].day+arr[position].month+arr[position].year)+(quadric*quadric))%L)==(((day+month+year)+(quadric*quadric))%L))
                {
                    quadric++;
                    position=((day+month+year)+(quadric*quadric))%L;
                }
                else
                {
                    quadric++;
                    position=((day+month+year)+(quadric*quadric))%L;
                }
                k++;
                if(k==L)
                    goto Exit_loob_delete_quadric;

            }
Exit_loob_delete_quadric:
            if (arr[position].check_full==0 || arr[position].id!=id2 )
                printf("The student not found\n----------------- \n ");
            goto Exit_function_delete_quadr;
        }
        quadric++;
        position=(position+(quadric*quadric))%L;
    }

Exit_function_delete_quadr:{}
    quadric=0;
}

int main()
{
    printf("Welcome to our Hash tables project....\n--------------\n");
    printf("Please enter the data of name in string form and number as numbers to avoid error\n");
    int choice_main;
    int n;
    int k;
start_program:
    {
        while(1)
        {

            printf("Choose between \n 1- Open Hash list \n 2- Closed Hash \n 3- Exit\nAny other number will return to the main again \n----------\nEnter the number \n");
            scanf("%d",&choice_main);
            switch(choice_main)//SWITCH CASE between open and closed hash
            {
            case 1:
                printf("You know will work with open hash(chain)\n----------\n");
                while(1)
                {
                    printf("1)insert \n2)delete \n3)display \n4)Search \n5)...Main menu\n-------\n ");
                    scanf("%d",&k);
                    switch(k)//switch case between functions in open hash
                    {
                    case 1:
                        printf("You chose the insert in hash ....  \n ");
                        insert_open_hash();
                        break;
                    case 2:
                        printf("You chose the delete in hash ....\n-------  \n ");
                        delete_open_hash();
                        break;
                    case 3:
                        printf("You chose the display in hash ....\n-------  \n ");
                        display_open_hash();
                        break;
                    case 4:
                        printf("You chose the search in hash ....\n-------  \n ");
                        search_open_hash();
                        break;
                    case 5:
                        goto start_program;
                        break;
                    default :
                        printf("wrong choice \n-------\n ");
                    }
                }
                break;
            case 3 :
                printf("Exit \n----------------------\nHave a good day dr/Omar Nasr .... \n\n\n\n\n\n\\n\n\n");
                return 0;
                break;
            default :
                printf("wrong choice \n ");
                goto start_program;
                break;
            case 2:
                size_of_array();
                struct  Student arr[L];
                initialize_arr(arr);
                printf("Choose between \n 1-Linear Hash \n 2-QUADRIC Hash\n Enter the number \n");
                scanf("%d",&n);

                while(1)
                {
                    switch(n)//switch case between functions in linear or quadric prob
                    {
                    case 1:
                        printf("You know will work with linear hash\n");
                        printf("1)insert \n2)delete \n3)display \n4)Search \n5)...Main menu\n ");
                        scanf("%d",&k);
                        switch(k)
                        {
                        case 1:
                            printf("You chose the insert in hash ....\n-------\n ");
                            save_student_Data();//to save the data of student in a struc
                            insert_by_linear(arr);
                            break;
                        case 2:
                            printf("You chose the delete in hash ....\n-------\n ");
                            printf("enter a student : \n ");
                            struct Student deletion;
                            delete_by_linear(arr,deletion.day,deletion.month,deletion.year,deletion.id);
                            break;
                        case 3 :
                            printf("You chose the display in hash ....\n-------  \n ");
                            display_array(arr);
                            break;
                        case 4:
                            printf("You chose the search in hash ....\n-------  \n ");
                            printf("enter a student : \n ");
                            struct Student  searcher;
                            search_by_linear(arr,searcher.day,searcher.month,searcher.year,searcher.id);
                            break;
                        case 5:
                            goto start_program;
                            break;

                        default :
                            printf("wrong choice \n ");
                        }
                        break;
                    case 2:
                        printf("You know will work with Quadric hash\n");
                        printf("1)insert \n2)delete \n3)display \n4)Search \n5)...Main menu\n ");
                        scanf("%d",&k);
                        switch(k)
                        {
                        case 1:
                            printf("You chose the insert in hash ....  \n ");
                            save_student_Data();
                            insert_by_quadric(arr);
                            break;
                        case 2:
                            printf("enter a student : \n ");
                            struct Student deletion_byquadric;
                            delete_by_quadric(arr,deletion_byquadric.day,deletion_byquadric.month,deletion_byquadric.year,deletion_byquadric.id);
                            break;
                        case 3 :
                            printf("You chose the display in hash ....\n-------  \n ");
                            display_array(arr);
                            break;
                        case 4:
                            printf("enter a student : \n ");
                            struct Student searcher;
                            search_by_quadric(arr,searcher.day,searcher.month,searcher.year,searcher.id);
                            break;
                        case 5:
                            goto start_program;
                            break;

                        default :
                            printf("wrong choice \n ");
                        }
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
