#include <stdio.h>
int Xor(int num1, int num2) 
{
   int result;
   if (num1 == num2)
    result = 0;
   else
    result = 1;
   return result; 
}
int main()
{
    int NumberOfDataBits;
    printf("enter number of data bits :\n");        //take number of data bits from user
    scanf("%d", &NumberOfDataBits);
    int DataBit[NumberOfDataBits];
    int i;  
    printf("enter values of data bits :\n");  
    for(i=0; i<NumberOfDataBits; i++)  
    {  
	    printf("bit (%d) : ",i);        //consist array of data bits
        scanf("%d", &DataBit[i]);  
    }  
    int NumberOfDivisorBits;
    printf("enter number of divisor bits :\n");     //take number of divisor bits from user
    scanf("%d", &NumberOfDivisorBits);
    int DivisorBit[NumberOfDivisorBits];
    int j;  
    printf("enter values of divisor bits :\n");  
    for(j=0; j<NumberOfDivisorBits; j++)  
    {  
	    printf("bit (%d) : ",j);        //consist array of divisor bits
        scanf("%d", &DivisorBit[j]);  
    }  
    
                                                  /*Sender side*/
    int k;
    int DivisionDataSize;
    DivisionDataSize=NumberOfDataBits+(NumberOfDivisorBits-1);      //size of data will do long div for it
    int DivisionData[DivisionDataSize];     //data will do long div for it
    for(k=0; k<DivisionDataSize; k++)  
    {  
        if (k < NumberOfDataBits)
        {
	    DivisionData[k]=DataBit[k];     //consisting of division data add zeros after input data
        }
        else DivisionData[k]=0;
    }  
    int startPoint;                              
    for(int L=0; L<DivisionDataSize; L++)
    {
        for(int m=0; m<DivisionDataSize; m++)
        {
            if (DivisionData[m]==1)
            {
                startPoint=m;                //knowing the starting point which represent place of one in the Division
                m=DivisionDataSize;         //before the first long division and after every time we did it
            }
        }
        if (DivisionDataSize-(startPoint) >= NumberOfDivisorBits)
        {
            for(int n=0; n<NumberOfDivisorBits; n++)
            {
            DivisionData[startPoint+n]=Xor(DivisionData[startPoint+n],DivisorBit[n]);
            }
        }
        if (DivisionDataSize-(startPoint) == NumberOfDivisorBits)   //for no repeated start point and more division happens        
        {                                                           //gurante for no more division after last one
            L=DivisionDataSize;
        }
    }
    int reminderSize=NumberOfDivisorBits-1;
    int reminder[reminderSize];
    for(int p=0; p<NumberOfDivisorBits-1; p++)                      //calculating of the remining part
    {
        reminder[reminderSize-1-p]=DivisionData[DivisionDataSize-1-p];
    }
    /*Configure sended Data*///same as first code for long division
    int SendedData[DivisionDataSize];
    for(int loop = 0; loop < NumberOfDataBits; loop++)
    {
        SendedData[loop]=DataBit[loop];
    }
    int ii=0;
    for(int loop = NumberOfDataBits; loop < DivisionDataSize; loop++)
    {
        SendedData[loop]=reminder[ii];
        ii++;
    }

                                                    /*Reciever side*/
    for(int L=0; L<DivisionDataSize; L++)
    {
        for(int m=0; m<DivisionDataSize; m++)
        {
            if (SendedData[m]==1)
            {
                startPoint=m;
                m=DivisionDataSize;
            }
        }
        if (DivisionDataSize-(startPoint) >= NumberOfDivisorBits)
        {
            for(int n=0; n<NumberOfDivisorBits; n++)
            {
            SendedData[startPoint+n]=Xor(SendedData[startPoint+n],DivisorBit[n]);
            }
        }
        if (DivisionDataSize-(startPoint) == NumberOfDivisorBits)
        {                                                                 //for no repeated start point and more division happens
            L=DivisionDataSize;                                          //gurante for no more division after last one
        }
    }
    for(int p=0; p<NumberOfDivisorBits-1; p++)
    {
        reminder[reminderSize-1-p]=SendedData[DivisionDataSize-1-p];
    }
    int ERROR=0;
    for(int kk = 0; kk < NumberOfDivisorBits-1; kk++)       //ERROR detection
    {
        if(reminder[kk]==1)
        {
        ERROR=1;
        }
    }
    if(ERROR==0)
    {
        printf("\n NO ERRORS");
    }
    else printf("\n ERROR exist");
    return 0;
}