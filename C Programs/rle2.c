 #include <stdio.h>

extern compression_function(char arr[1000])

{
   char current_char;
   int count, i,j=0,t=0,G=0,H=0, char_size=0;
   int original_length=0,com_number_length=0,compressed_length=0;
   int index=0;

    FILE* outputfile;
    FILE* processing;

   outputfile= fopen("C:\\Users\\Desktop\\output.txt","w");
   processing= fopen("C:\\Users\\Desktop\\processing.txt","w");

   if(outputfile == '\0' )
{ 
                printf("Cannot Write To File!\n");

                }        


current_char = arr[0]; 
count = 1; 
i = 0; 

printf("\n\nOUTPUT: ");
//USING A WHILE LOOP
while (arr[i] != '\0') 
{ 
//'i' WILL BE INCREMENTED TO CHECK ALL THE CHAR IN THE ARRAY      

i++;

// CHECK IF THE CURENT CHAR IS THE SAME AS THE LAST ONE        
if( arr[i] == current_char )
{
count++; 
}

//ELSE IF NO MORE CHAR IS SIMILAR, IT WILL PRINT THE COUNT RESULT RIGHT AWAY    
else
{
if(count==1)
{ 
//sprintf(output_array,"%c", current_char);             
printf("%c", current_char);
fprintf(outputfile,"%c", current_char);
fprintf(processing,"%c", current_char);

G++;
}

if(count>=2)
{        
       printf("%c%d", current_char, count);
       fprintf(outputfile,"%c%d", current_char,count);
       fprintf(processing,"%c", current_char );
       }

if (count>9)
{
           j++;
           }
           if (count>99)
{
           t++;
           }

//REST ALL COUNT FOR THE SECOND DIFFRENT CHAR IN ARRAY

   current_char = arr[i]; 
   count = 1;
   char_size++;


//BREAK THE LOOP WHEN CHAR IN ARRAY IS NULL       
   if( current_char == '\0' )
   {

           break;

           }   
    } 
    }

 original_length = strlen(arr);
 com_number_length=(char_size+j+t-G);
 compressed_length=(char_size+char_size+j+t-G);

 fclose(outputfile);
 fclose(processing);

 //CALLING FUNCTION-SIZE-CALCULATOR
size_calculator(original_length,char_size,com_number_length,compressed_length);


           }