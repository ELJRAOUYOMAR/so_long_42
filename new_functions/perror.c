#include <stdio.h>
#include <errno.h>
#include <string.h>

/*
 * perror: print error message
 * man perror to know more 
 * 
 * strerror(): Get Error Message as a String 
 * man strerror
*/
int main()
{
    FILE *file = fopen("fshdf.txt", "r");
    // use perror
    // if (!file)
        // perror("error opening file: ");
    // using strerrorr
    if (!file)
        printf("Erorr opening file: %s \n", strerror(errno));
}