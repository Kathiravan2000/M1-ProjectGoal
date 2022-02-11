#include <stdio.h>
#include <string.h>
 #include <stdlib.h>

#define STR(num) #num


int main()
{
    // Declare the file pointer
    FILE *filePointer ;
     
    // Declare the variable for the data to be read from file
    char dataToBeRead[50];
 
    // Open the existing account.dat using fopen()
    // in read mode using "r" attribute
    filePointer = fopen("account.dat", "r") ;
     
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "account.dat file failed to open." ) ;
    }
    else
    {
         
        printf("The file is now opened.\n") ;
        char username[50];
        char password[50];
    printf("Enter the username: ");
    scanf("%s", username);
     printf("Enter the password: ");
    scanf("%s", password);
    
         
        // Read the dataToBeRead from the file
        // using fgets() method
        if( fgets ( dataToBeRead, 50, filePointer ) != NULL )
        {
         
            // Print the dataToBeRead
           // printf( "%s" , dataToBeRead ) ;
            
            const char s[7] = "|";
            char *token;
   
   /* get the first token */
   token = strtok(dataToBeRead, s);
   
   /* walk through other tokens */
   int i=0,uflag=0,pflag=0;

   while( token != NULL ) {
     // printf( " %s\n", token );
      if(i==0 && !strcmp( token,username) )
      {
          i++;
          uflag=1;
      }
      if(i==1 && !strcmp(token,password))
      {
          i++;
          pflag=1;
      }
      token = strtok(NULL, s);
   }
   if(uflag==1 && pflag==1)
   {
       int userinput=0;
       printf("username and password matches");
       printf("\n1.Account create,\n2.Account deposit");
       
       scanf("%d",&userinput);
        switch (userinput) {
    case 1:
        printf("Account create");
        int customerid=0, accountnumber=0,mobilenumber=0,availablebalance=0;
        char customername[50],password[50],address[50];
        printf("customer id");
        scanf("%d",&customerid);
        printf("accountnumber");
        scanf("%d",&accountnumber);
        printf("mobilenumber");
        scanf("%d",&mobilenumber);
        printf("availablebalance");
        scanf("%d",&availablebalance);
        printf("customername");
        scanf("%s",customername);
        printf("password");
        scanf("%s",password);
        printf("address");
        scanf("%s",address);
       // printf("%d"customerid,"%d" accountnumber,"%d"mobilenumber,"%d"availablebalance,"%d"customername,password, address);
        printf("%d|%s|%s|%d|%s|%d|%d|",customerid,password,customername,accountnumber,address,mobilenumber,availablebalance);
        char account[200];
        sprintf(account,"%d|%s|%s|%d|%s|%d|%d|",customerid,password,customername,accountnumber,address,mobilenumber,availablebalance);
        printf("test print %s/n",account);
         FILE *filePointer ;
     
    // Get the data to be written in file
    
 
    // Open the existing file GfgTest.c using fopen()
    // in write mode using "w" attribute
    filePointer = fopen("account.dat", "a") ;
          fputs(account, filePointer) ;
            fputs("\n", filePointer) ;
            fclose(filePointer) ;

        break;
    case 2:
     printf("\nAccount deposit");
        char  cid[50];
         char readline[300];
       
        printf("\nenter customer id\n");
        scanf("%s",cid);
         FILE *filePointer1 ;
         filePointer1 = fopen("account.dat", "r") ;
         const char s[7] = "|";
            char *token;
            char* lastletter;
        while( fgets (readline, 300,filePointer1 ) )
        {
   /* get the first token */
   token = strtok(readline, s);
   //printf("\n %s-%s \n",token,cid);
         if(strcmp(token,cid)==0)
         {
         // printf("account matches");
           //lastletter =(char*)token[5];
           char* output[200];
           for(int y=0;y<=6;y++)
           {
               token=strtok(NULL,s);
              // if(token!=NULL)
//output=strcat(output,token);
               if(y==5)
               {
                    printf("\n %s-balance \n",token);
                  
                  
                      int accountnumber;
                      printf("enter the account number you would like to deposit\n" );
                      scanf("%d",&accountnumber);
                      
               int balance;
               sscanf(token, "%d", &balance);
               printf("\n accountbalance=%d\n",accountnumber+balance);
               char str[10];
              // s=itoa(accountnumber+balance,str,10);
              sprintf(str,"%d",accountnumber+balance);
              token=(char*)str;
               } 

           }
           //printf("%s - output",output);
          break;
         }
         else
         {
             token=strtok(NULL,s);
             continue;
         }
        }
         fclose(filePointer1) ;
        break;
    //case 3:
        //printf("/nAccount withdrawl");

        break;
    default:
        printf("/nChoice other than 1, 2 and 3");
        break;
    }
       //to-do -add accounts and display accounts
       //to-do -customer login and transaction
   }

   
   
}
        
    
         
        // Closing the file using fclose()
        fclose(filePointer) ;

    }
    return 0;
}


   

