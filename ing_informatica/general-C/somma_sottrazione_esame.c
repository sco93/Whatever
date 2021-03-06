#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define GETNUM(a) (a-'0')
#define NEXT_IS_NUM(a) (a+1<='9' && a+1>='0')
#define IS_NUM(a) (a<='9' && a>='0')
#define IS_OPERATOR(pos) (pos=='+' || pos=='-')
#define IS_MULTDIV(pos) (pos=='*' || pos=='/')

char* is_operators(char*s)
{
    int i=0;
    int flag=0;
    for (i=0;s[i+1]!='\0';i++)
    {
        if (IS_OPERATOR(s[i]))
            flag=1;
    }
    printf("flag=%i\n",flag);
    if(flag==1)
        for (i=0;s[i+1]!='\0';i++)
        {
            if (IS_MULTDIV(s[i]))
            {
                printf("%c\n",s[i]);
                i--;
                while(IS_NUM(s[i]))
                {
                    if(i!=0)
                        i--;
                    else return s;
                }
                return s+i+1;
            }
        }
    return NULL;
}

int eval(char* expr)
{
    int prev=0,i=0, cifra=0,len;
    char*c =NULL;
    char* temp=calloc(100,sizeof(char));
    char* temp_due=calloc(100,sizeof(char));
    char* totale=calloc(100,sizeof(char));
    while(c=is_operators(expr),c!=NULL)
    {
        i=0;
        prev=0;
        temp=calloc(100,sizeof(char));
        temp[0]='\0';
        temp_due=calloc(100,sizeof(char));
        temp_due[0]='\0';
        while (IS_NUM(c[i]) || IS_MULTDIV(c[i]))
            i++;
        printf("%s\n",c);
        strncat(temp,c,i);
        printf("temp=%s\n",temp);
        prev=eval(temp);
        printf("prev=%i\n",prev);
        sprintf(temp_due,"%i",prev);
        printf("ciao\n");
        strncat(totale,expr,c-expr); 
        strcat(totale,temp_due);
        strcat(totale,c+i);
        expr=totale;
        printf("%s\n",expr);
    }
    for (i=0;expr[i]!='\0';i++)
    {
        cifra=0;
        len=1;
        while(IS_NUM(expr[i]))
        {
            cifra=cifra*10+GETNUM(expr[i]);
            i++;
            len++;
        }
        switch (expr[i-len]){
            case '+':
                printf("somma\n");
                prev+=cifra;
                break;
            case '-':
                printf("differenza\n");
                prev-=cifra;
                break;
            case '*':
                printf("moltiplicazione\n");
                prev*=cifra;
                break; 
            case '/':
                printf("divisione\n");
                prev/=cifra;
                break;
            default:
                printf("prima cifra\n");
                prev=cifra;
                break;
        }
        if(expr[i+1]=='\0')
            break;
    }
    return prev;

}
int main(int argc, char** argv)
{
    printf("%i\n", eval("2/2+10/10+90"));
}

