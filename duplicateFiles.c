#include<stdio.h>
#include<string.h>
#define MAXLEN 100//maximum size in the struct variables
struct File{//The struct datatype stores the file name and the id and matches up in the same index
    char fileName[MAXLEN][MAXLEN];
    int id[MAXLEN];
};

struct File ascendingOrder(struct File file1,int numFiles);
struct File removeDuplicate(struct File file1,int numFiles);
 

int main()
{
    int numTestCase;//This is the number of test cases to be performed
    FILE *file;
    file = fopen("files.in","r");
    fscanf(file,"%d",&numTestCase);//The fscanf method reads the Test Case amd stores it in the numTestCase variable

    for (int count = 0; count < numTestCase; count++)
    {//This loop includes methods such as fscanf which stores the number of files in numFile in order to read the number of files in each case.
        struct File file1;
        int numFiles;
        fscanf(file,"%d",&numFiles);

        for (int i = 0; i < numFiles; i++)
    {
        fscanf(file,"%s",file1.fileName[i]);
        fscanf(file,"%d",&file1.id[i]);

    }
    file1 = ascendingOrder(file1,numFiles);//file1 store the numfiles and id in ascending oder.
    file1 = removeDuplicate(file1,numFiles);//file1 store the original file after the duplicate has been removed.
    }  
    
    fclose(file);
    return 0;
}



struct File ascendingOrder(struct File file1,int numFiles){//This function switch the fileName and id in ascending order
    // SORTING
        char temp[100];
        int temp2;
        int len = numFiles - 1;
        for (int i = 0; i < len; i++)
        {
        for (int j = i+1; j < numFiles; j++)
        {
            int compare = strcmp(file1.fileName[i],file1.fileName[j]);

            if(compare == 0){
                temp2 = file1.id[i];
                file1.id[i] = file1.id[j];
                file1.id[j] = temp2;


            }
            if (compare > 0)
            {
                strcpy(temp,file1.fileName[i]);
                strcpy(file1.fileName[i],file1.fileName[j]);
                strcpy(file1.fileName[j],temp);

                temp2 = file1.id[i];
                file1.id[i] = file1.id[j];
                file1.id[j] = temp2;
            }
            
        
        }
    }
    printf("\n");

    return file1;

}

struct File removeDuplicate(struct File file1,int numFiles){//This function removes the duplicate in the fileName
        for (int i = 0; i < numFiles; i++)
        {
            for (int j = i+1; j < numFiles;)
            {
                if(strcmp(file1.fileName[i],file1.fileName[j])==0)
                {//compare if the two files are equal and remove the new file
                    for (int k = j; k < numFiles; k++)
                    {
                        file1.id[k] = file1.id[k+1];
                    strcpy(file1.fileName[k],file1.fileName[k+1]);
                    }
                    numFiles--;              
                }
                else{
                    j++;
                }
            }
        }
        for (int i = 0; i < numFiles; i++)
        {
            printf("%d ",file1.id[i]);
        }
        printf("\n");
        return file1;
}


    



















