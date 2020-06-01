//include header files from these libraries
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////

//Assignment: zelda

//Task: transfer the contents of link.jpg to link2.jpg.

//Steps:
//create a buffer 512 bytes large
//create files to represent original and copy of photo
//check command line for a proper cmd line input. Return error otherwise.
//open link.jpg in read mode
//open link2.jpg in write mode
//read the data from the link.jpg file
//write that data to link2.jpg
//close link.jpg
//close link2.jpg

//////////////////////////////////////////////////////////////////////////

//variables

//create a char called buffer to represent 512 blocks
char buffer[512];

//file to represent original link
FILE *link;

//file to represent copy link
FILE *link2;

/////////////////////////////////////////////////////

//main body of code

int main(int argc, char *argv[])
{
    //command line check
    if (argc != 2)
    {
        printf("Command line is incorrect\n");

        //return an error
        return 1;
    }

/////////////////////////////////////////////////

    //fopen link.jpg in read mode
    link = fopen(argv[1], "r");

    //fopen link2.jpg in write mode
    link2 = fopen("link2.jpg", "w");

/////////////////////////////////////////////////

//fread link.jpg while data is bigger than zero
while (fread(buffer, 512, 1, link) > 0)
{

//write to link2.jpg
fwrite(buffer, 512, 1, link2);
}

/////////////////////////////////////////////////

//close link.jpg
fclose (link);

//close link2.jpg
fclose (link2);
}
