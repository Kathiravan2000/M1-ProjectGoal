 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

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
        printf( "account.dat file failed to open.\n" ) ;
        return -1;
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
            const char s[7] = "|";
            char *token;
            /* get the first token */
            token = strtok(dataToBeRead, s);
            /* walk through other tokens */
            int i=0,uflag=0,pflag=0;
            while( token != NULL ) 
            {
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
                printf("username and password matches\n");
                printf("\n1.Account create \n2.Account deposit \n3.Account Withdrawal\n");
                scanf("%d",&userinput);
                switch (userinput) 
                {
                    case 1:
                        printf("Account creation:\n");
                        int customerid=0, accountnumber=0,availablebalance=0;
                        long int mobilenumber=0;
                        char customername[50],password[50],address[50];
                        printf("Customer id:");
                        scanf("%d",&customerid);
                        printf("Account Number:");
                        scanf("%d",&accountnumber);
                        printf("Mobile Number:");
                        scanf("%ld",&mobilenumber);
                        printf("Available Balance:");
                        scanf("%d",&availablebalance);
                        printf("Customer Name:");
                        scanf("%s",customername);
                        printf("Password:");
                        scanf("%s",password);
                        printf("Address:");
                        scanf("%s",address);
                        char account[200];
                        sprintf(account,"%d|%s|%s|%d|%s|%ld|%d|",customerid,password,customername,accountnumber,address,mobilenumber,availablebalance);
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
                        printf("\nEnter customer id\n");
                        scanf("%s",cid);
                        FILE *filePointer1 ;
                        filePointer1 = fopen("account.dat", "r+") ;
                        const char s[7] = "|";
                        char *token;
                        char* lastletter;
                        while( fgets (readline, 300,filePointer1 ) )
                        {
                            int line_length = sizeof(readline);
                            /* get the first token */
                            token = strtok(readline, s);
                            if(strcmp(token,cid)==0)
                            {
                                char* output[200];
                                char* update_data;
                                update_data =  cid;
                                for(int y=0;y<=6;y++)
                                {
                                    token=strtok(NULL,s);               
                                    if(y==5)
                                    {
                                        printf("\n Available Balance - Rs.%s/- \n",token);
                                        int accountnumber;
                                        printf("Enter the amount you would like to deposit:\n Rs." );
                                        scanf("%d",&accountnumber);
                                        int balance;
                                        sscanf(token, "%d", &balance);
                                        printf("\n Account Balance= Rs.%d/- \n",accountnumber+balance);
                                        char str[10];
                                        sprintf(str,"%d",accountnumber+balance);
                                        token=(char*)str;
                                    } 
                                    strcat(update_data,s);
                                    strcat(update_data,token);
                                }
                                fseek(filePointer1, -44, SEEK_CUR );
                                fputs(update_data, filePointer1);
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
                    case 3:
                        printf("\nAccount Withdrawal");
                        char  cid1[50];
                        char readline1[300];
                        printf("\nEnter customer id\n");
                        scanf("%s",cid1);
                        FILE *filePointer11 ;
                        filePointer11 = fopen("account.dat", "r+") ;
                        const char ss[7] = "|";
                        char *token1;
                        while( fgets (readline1, 300,filePointer11 ) )
                        {
                            int line_length = sizeof(readline1)/sizeof(char);
                            for(i = 0; i < line_length; i++)
                            {  
                                if(readline1[i] == ' ')
                                {  
                                    for(int j=i;j<line_length;j++)  
                                    {  
                                        readline1[j]=readline1[j+1];  
                                    }  
                                    line_length--;  
                                }  
                            }
                            /* get the first token */
                            token1 = strtok(readline1, ss);
                            if(strcmp(token1,cid1)==0)
                            {
                                char* output[200];
                                char* update_data;
                                update_data =  cid1;
                               //strcat(update_data,cid);
                                for(int y=0;y<=6;y++)
                                {
                                    token1=strtok(NULL,ss);               
                                    if(y==5)
                                    {
                                        printf("\n Available Balance - Rs.%s/- \n",token1);
                                        int accountnumber;
                                        printf("Enter the amount you would like to Withdraw:\n Rs." );
                                        scanf("%d",&accountnumber);
                                        int balance;
                                        sscanf(token1, "%d", &balance);
                                        printf("\n Account Balance= Rs.%d/- \n",balance-accountnumber);
                                        char str[10];
                                        sprintf(str,"%d",balance-accountnumber);
                                        token1=(char*)str;
                                    } n;
                                    strcat(update_data,ss);
                                    strcat(update_data,token1);
                                }
                                fseek(filePointer11, -44, SEEK_CUR );   
                                fputs(update_data, filePointer11);
                                break;
                            }
                            else
                            {
                                token1=strtok(NULL,ss);
                                continue;
                            }
                        }
                        fclose(filePointer11) ;
                        break;
                    default:
                        printf("/nChoice other than 1, 2 and 3");
                        break;
                }
            }  
        }     
        // Closing the file using fclose()
        fclose(filePointer) ;
    }
    return 0;
}
