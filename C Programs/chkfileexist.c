#include <stdio.h>
#include <unistd.h>
int fileExists(char *filename);
int main(){
if( fileExists("existingFile.txt") == 0 ){
printf("\nThe file 'existingFile.txt' exists!");
} else {
printf("\nThe file 'existingFile.txt' doesn't exist.");
}
 
if( fileExists("nonExistingFile.txt") == 0){
printf("\nThe file 'nonExistingFile.txt' exists!");
} else {
printf("\nThe file 'nonExistingFile.txt' doesn't exist.");
}
printf("\n");
return 0;
}
int fileExists(char *filename){ // Returns 0 for exists and -1 for doesn't exist.
if(access(filename, F_OK) != -1) return 0; else; return -1;
}