#include <stdio.h>
#include <string.h>

/* 
 * Name : <Insert name>
 * Program to experiment with character arrays
 */

#define MaxWord 20
 
int main ()
{
    char c;
    char str[MaxWord+1];
    int len = 0;
    int num_blank = 0;
    int num_word = 0;
    double sum = 0;
    int count = 0;
    int longest_num = 0;
    int longest_flag = 0;
    char longest_str[20] = { 0 };

  
    puts ("Enter text. Include a dot ('.') to end a sentence to exit:");
    do 
    {
        c=getchar();
        if (c == ' ')
            num_blank++;

        if (num_blank == 2)
        {
            num_blank = 0;
            continue;
        }

        if(c != ' ' && c != '.')
        {
            /* This is a character of a word */
            //str[len] = c;
            //len++;
            /* Only save it if we have space */
            num_blank = 0;
            if(len < MaxWord)
            {
                str[len] = c;
                len++;
            }
        }
        else
        {
            /* The word is done */
            count++;

            str[len] = 0;
            num_word = strlen(str);
            //longest_num = longest_num>num_word?longest_num:num_word;
            //longest_flag = longest_num>num_word?longest_flag:count;
            //longest_str = longest_num>num_word?longest_str:str;
            if (longest_num > num_word)
            {
                longest_num = longest_num;
                longest_flag = longest_flag;
            }
            else
            {
                longest_num = num_word;
                longest_flag = count;
                strcpy(longest_str, str);
            }
            sum = sum + num_word;

            printf("%-10s\t%d\n", str, num_word);
            len = 0;

            
        }
        

    } while (c != '.');

    printf("The Average word length is: %.f / %d = %.2f\n", sum, count, sum/count);
    printf("The longest word is '%s' at %d and has %d letters.\n",
         longest_str, longest_flag, longest_num);
    //str[len] = 0;
    //printf("%s\n", str);
  
}