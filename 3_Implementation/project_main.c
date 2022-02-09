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
        while( fgets ( dataToBeRead, 50, filePointer ) != NULL )
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
       printf("username and password matches");
       //to-do -add accounts and display accounts
       //to-do -customer login and transaction
   }

   
   
}
        
    
         
        // Closing the file using fclose()
        fclose(filePointer) ;

    }
    return 0;
}


