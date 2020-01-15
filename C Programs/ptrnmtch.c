//pattern match
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    main(int x,char *j[])
    {
    int g,h,z=1;
    char ch,c[30]=" ",d[30]=" ",a[30]=" ";
    int n,i=0,line=0;
    FILE *f;
    printf("*****************FILE NAME IS:%s\n",j[1]);
    f=fopen(j[1],"r");
    if(f!=NULL)
    printf("*****************FILE OPENED****************\n");
    for(n=2;n<x;n++)
    {
    strcat(c,j[n]);
    if(n!=x-1)
    strcat(c," ");
    }
    strcpy(a,c);
    for(g=0,h=1;a[g]!='\0';g++,h++)
    a[g]=a[h];
    a[g]='\0';
    printf("******************SEARCH TEXT IS:%s\n",a);
    while((z=feof(f))==0)
    {
    fseek(f,0,1);
    while((ch=fgetc(f))!='\n')
    i++;
    i=i+2;
    line++;
    fseek(f,-i,1);
    fgets(d,i,f);
    if((strstr(d,a))!=NULL)
    {
    printf("******************LINE NO IS=>%d  :%s\n",line,d);
    }
    else
    {
    printf("*****************LINE NO IS=>%d\t***********NOT FOUND\n",line);
    }
    i=0;
    }
    }

