#include<stdio.h>
#include<string.h>

int getIntLength(long num);
int noOfOccurence(long,long,int,int *arr,int *arr2);
void checkSelfDescribe(int length,int *arr,int *arr2);


int main()
{
    int numTestCase;//This stores the number of test cases

    FILE *file;//declaring the file
    file = fopen("self.in","r");
    if (file== NULL)
    {
        printf("Error accessing the file");
    }
    
    fscanf(file,"%d",&numTestCase);
    for(int k = 0;k<numTestCase;k++)//loop to perform self describing operation if k is less than number of test
    {
            long num,remainder;
            int count2 = 0,length;
            fscanf(file,"%li",&num);

            length = getIntLength(num);
            int arrNum[10],arrNum2[10];// The first variable will store the number of 0s,1s etc up to the length of the number while the second variable will store each number from index 0 to the length of the number
            
            arrNum[10],arrNum2[10] = noOfOccurence(remainder,num,length,arrNum,arrNum2);//the returned array is stored in both variable

            checkSelfDescribe(length,arrNum,arrNum2);//The self described function is called
    }  

    fclose(file);
    return 0;
}



int getIntLength(long num){//This function get the number of length stored in num variable
        long tempNum;//Temporary num variable is created to get the length of the num
        int count = 0;//The count variable will keep incrementing by one if the value of the temp is equal than zero
        tempNum = num;
        while(tempNum>0){
            tempNum = tempNum/10;
            count++;
        }

        return count;
        printf("\n");

}

int noOfOccurence(long remainder,long num,int length,int *arr,int *arr2){//This function checks the number of 0s,1s etc up to the length of the number 
    for(int count2 = 0;count2< length;count2++){
            int j = length;//This variable stores the length of the number to avoid it being over written when looping through each digit
            int reverse = length-1;//This reverse variable will get/loop through each integer from the back using the modulus method
            int remain;

            remainder = num;
            int pick= 0;
            for(int i = 0;i < j;i++)
            {
                
            remain = remainder%10;
            arr2[reverse] = remain;
            remainder = remainder/10;
            if(remain == count2){
                pick+= 1;//This variable get the number of occurence of 0s,1s up till the length of the number
            }
            reverse--;
            
            }
            arr[count2] = pick;//The value from the pick is store in this variable
            
        }
        return arr[10],arr2[10];
}

void checkSelfDescribe(int length,int *arr,int *arr2){//This function checks if the number is self describing
        for(int i =0;i < length;i++){
            if(arr[i]==arr2[i] && i==length-1){//if the index of each variable is the same with the other throughout the entire array,then display it as a self describing number
                printf("Self-describing\n");
            }
            else if(arr[i] !=arr2[i] ){
                printf("Not self-describing\n");//if each index are not the same when compared, then it is not self decribing
                break;
                
            }
    }
}

