#include <stdio.h>
#include <string.h>

int main()
{
    char alpha[101];
    int count = 0;

    scanf("%s", alpha);

    int len = strlen(alpha);

    for(int i = 0; i < len; i++)
    {
        if(alpha[i] == 'c')
        {
            if(alpha[i+1] == '-' || alpha[i+1] == '=')
            {
                count++;
                i+=1;
            }
            else{
                count++;
            }
        }
        else if(alpha[i] == 'd')
        {
            if(alpha[i+1] == 'z' && alpha[i+2] == '=')
            {
                count++;
                i+=2;
            }
            else if(alpha[i+1] == '-')
            {
                count++;
                i+=1;
            }
            else{
                count++;
            }
        }
        else if(alpha[i] == 'l')
        {
            if(alpha[i+1] == 'j')
            {
                count++;
                i+=1;
            }
            else{
                count++;
            }
        }
        else if(alpha[i] == 'n')
        {
            if(alpha[i+1] == 'j')
            {
                count++;
                i+=1;
            }
            else{
                count++;
            }
        }
        else if(alpha[i] == 's')
        {
            if(alpha[i+1] == '=')
            {
                count++;
                i+=1;
            }
            else
            {
                count++;
            }
        }
        else if(alpha[i] == 'z')
        {
            if(alpha[i+1] == '=')
            {
                count++;
                i+=1;
            }
            else
            {
                count++;
            }
        }
        else if(alpha[i] != '-' && alpha[i] != '='){
            count++;
        }
    }



    printf("%d", count);


    return 0;
}