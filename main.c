#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void delsp(char*s,char*r)
{
    int dot=0,i=0;
    while(s[i++]!='\0')if(s[i]=='.')dot=1;
    char*word=strtok(s," .");
    while(word!=NULL)
    {
        while(*word!='\0')
        {
            if(*word=='.') return;
            *r++=*word;
            word++;
        }
        word=strtok(NULL," .");
        if(word!=NULL)
        *r++=' ';
    }
    if(dot)*r++='.';
    *r++='\0';
}

void prep(char*s,char*r)
{
    int i=0;
    r[0]=' ';
    r[1]=' ';
    strcat(r,s);
    while(r[i]!='\0')i++;
    if(r[i-1]=='.')
    {
        r[i-1]=' ';
        r[i]='.';
        r[i+1]='\0';
    }
    else
    {
        r[i]=' ';
        r[i+1]='\0';
    }
}

char findLw(char*lw,char*s)
{
    int bw,ew,i=0,len;
    while(s[i]!='\0')i++;
    if(s[i-1]=='.')ew=i-2;
    else ew=i-1;
    i=ew;
    while((int)s[i]!=(int)' ')
    {
        bw=i;
        i--;
    }
    len=ew-bw+2;
    //len=ew-bw+1;
    //lw=(char*)malloc(len*sizeof(char));
    for(i=0;i<len-1;i++)lw[i]=s[bw+i];
    //lw[0]=s[bw];
    //lw[1]=s[bw+1];
    lw[len-1]='\0';
}

void dellw(char*s,char*r,char*lw)
{
    char*word=strtok(s,lw);
    r[0]='\0';
    strcat(r,word);
    do
    {
        word=strtok('\0',lw);
        if(word)
        {

            strcat(r,word);
        }
    }while(word);
}

int main()
{
    SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);
    char str[256],str2[256],str3[256],word[256],prepw[256],*s,*s2,*s3,*lw,*pw;
    s=str;
    s2=str2;
    s3=str3;
    lw=word;
    pw=prepw;
    printf("Task 10\n");
    gets(s);
    printf("Без лишних пробелов(1A):\n");
    delsp(s,s2);
    puts(s2);

    printf("Без последнего слова(2):\n");
    strcpy(s,s2);
    findLw(lw,s2);
    prep(s,s3);
    strcpy(s,s3);
    pw[0]=' ';
    pw[1]='\0';
    strcat(pw,lw);
    strcat(pw," ");
    dellw(s,s3,pw);
    puts(s3);
    delsp(s3,s);
    strcpy(s3,s);
    puts(s3);

    printf("Файловый ввод-вывод\n");
    printf("Строка из задания А1 запишется в файл, а затем выведется\n");
    FILE *f=fopen("MyFile.txt","w");
    fputs(s2,f);
    fputs("\n",f);
    fputs(s3,f);
    fputs("\0",f);
    fclose(f);
    f=fopen("MyFile.txt","r");
    fgets(s,255,f);
    puts(s);
    fgets(s,255,f);
    puts(s);
    fclose(f);
    return 0;
}
