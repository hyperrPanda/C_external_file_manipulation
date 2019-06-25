#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "terminal_user_input.h"

typedef struct Track{
char trackname[100];
char tracklocation[100];
}Track;


typedef struct Album{

char albumname[100];
char artistname[100];
char genretype[100];
struct Track array_Tracks[15];

} Album;
struct Album array_Albums[100];
int sizeFlag;

struct Track ReadTrack(FILE *file_ptr){
struct Track tmpTrack;
 char tmpString[100],tmpString2[100];
fscanf(file_ptr, "%s",&tmpString);
strcpy(tmpTrack.trackname,tmpString);
//tmpTrack.trackname = tmpString;
  //printf("\ntrackname found %s",tmpTrack.trackname);
fscanf(file_ptr, "%s",&tmpString2);
strcpy(tmpTrack.tracklocation,tmpString2);
//tmpTrack.tracklocation = tmpString;
 //printf("\ntrackname locTON found %s",tmpTrack.trackname);
return tmpTrack;


}

struct Album ReadAlbum(FILE *file_ptr){
      int size,i =0;
       char tmpString[100],tmpString2[100],tmpString3[100],tmpString4[100];

    struct Album tmpalbum;

    fscanf(file_ptr, "%s",&tmpString);
      //tmpalbum.albumname.str = tmpString.str;
      strcpy(tmpalbum.albumname,tmpString);
       printf("\nalbum found %s",tmpalbum.albumname);

     fscanf(file_ptr, "%s",&tmpString2);
     //tmpalbum.artistname = tmpString2;
     strcpy(tmpalbum.artistname,tmpString2);
     //printf("\nartist found %s",tmpalbum.artistname);
     //printf("\nalbum found %s",tmpalbum.albumname);
     fscanf(file_ptr, "%s",&tmpString3);
     strcpy(tmpalbum.genretype,tmpString3);
    //tmpalbum.genretype = tmpString3;
    //printf("\ngenere found %s",tmpalbum.genretype);
    //printf("\nalbum found %s",tmpalbum.albumname);
     fscanf(file_ptr, "%d",&size);
     //printf("\ntracks found %d",size);
     //printf("\nalbum found %s",tmpalbum.albumname);
    for (i = 0; i<size; i++)
    {

       // printf("\nalbum counter %d",i);
        tmpalbum.array_Tracks[i] = ReadTrack(file_ptr);
    }
      // printf("\nFFFFinal album found %s",tmpalbum.albumname);
    return tmpalbum;



}

void ReadAlbums(FILE *file_ptr)
{

    int size,i =0;

    int lineindex =0;
    fscanf(file_ptr, "%d", &size);
    printf("\nfile-%d",size);
    sizeFlag = size;

    for (i = 0; i<3; i++)

    {
        array_Albums[i] = ReadAlbum(file_ptr);
        //printf("\n>>>>>>>>Album name %d is %s",i,array_Albums[i].albumname);
    }
    fclose(file_ptr);


}

void DisplayAllAlbums(){
int i,t=0;
   for (i = 0; i<sizeFlag; i++)
    {
        printf("\n------Album name %d is %s--------",i+1,array_Albums[i].albumname);

    }

}

DisplayAlbumByGenre(char genrename[100])
{
  int i=0;
 for (i = 0; i<sizeFlag; i++)
    {
      if(!strcmp(genrename,array_Albums[i].genretype) )
      {
        printf("\n%d Album Name is %s",i+1,array_Albums[i].albumname);
      }
    }


}

void DisplayByGenre(){
int i;
i = read_integer_range("\nSelect Genre 1.Pop\n 2.Rock\n ",1,2);
if(i==1)
{
  DisplayAlbumByGenre("Pop");
}
else
{
  DisplayAlbumByGenre("Rock");
}

}



void DisplayAlbums()
{
    int i = 0;

    i = read_integer_range("\nSelect 1.To Display All Album 2.To Display By Genre",1,2);
if(i==1)
{
  DisplayAllAlbums();
}
else if(i==2)
{
  DisplayByGenre();
}


}
void DisplayAlbumDetails(int num)
{
  int r=0;
  int d=0;
printf("Album Name %s",array_Albums[num-1].albumname);
do{

  printf("\n%d Track Name %s",r+1,array_Albums[num-1].array_Tracks[r].trackname);
  r++;
}while(strcmp(array_Albums[num-1].array_Tracks[r].trackname,""));

d = read_integer_range("\nSelect Track Number To Play",1,r);
printf(">>>>>>>>Playin track %s<<<<<<<<<",array_Albums[num-1].array_Tracks[d-1].trackname);
}

void PlayAlbum(){
int i;

i = read_integer_range("\nSelect Album Number To Play",1,sizeFlag);

DisplayAlbumDetails(i);
}


void ChangeAlbumDetails(int num)
{
printf("Album Name %s",array_Albums[num-1].albumname);
printf("Album Genre %s",array_Albums[num-1].genretype);
int p;
p = read_integer_range("\nSelect 1.To cahnge title \n 2.To change Genre \n",1,2);

char tmpString[100];

if(p==1)
{
printf("\nenter new title");
scanf("%s",&tmpString);
strcpy(array_Albums[num-1].albumname,tmpString);
}
else
{
printf("\nenter new genere");
scanf("%s",&tmpString);
strcpy(array_Albums[num-1].genretype,tmpString);
}
printf("\nNew Details are");
printf("\nAlbum Name %s",array_Albums[num-1].albumname);
printf("\nAlbum Genre %s",array_Albums[num-1].genretype);
}

void UpdateAlbum(){
int i;

i = read_integer_range("\nSelect Album Number To Update",1,sizeFlag);

ChangeAlbumDetails(i);

}

void write_lines(FILE *file_ptr) {

  fprintf(file_ptr, "%d", 10);

// probably you want to change this to write multiple lines

  fprintf(file_ptr, "%s", "this is my test file");
}

void read_lines_to_terminal(FILE *file_ptr) {

 }

void playit()
{

 FILE *file_ptr;
  int exitSelection = 0;
  my_string filename;
int menuoption;

while(exitSelection==0)
{
  menuoption = 0;
  menuoption = read_integer_range("\n\nWelcome!\n Press\n 1.Read Album File\n 2.Display Album\n 3.Select Album to play\n 4.Update Album\n 5.Exit Apllication\n",1,5);
if(menuoption==1)
{
if ((file_ptr = fopen("maalbums.txt", "r")) == NULL)
    {printf("File could not be opened");}
  else
    {//read_lines_to_terminal(file_ptr);
    printf("Bingo");
    ReadAlbums(file_ptr);
    //exitSelection=1;
    }

// file_ptr = fopen("maalbums.txt", "r");
// ReadAlbums(file_ptr);
}
else if(menuoption==2)
{ DisplayAlbums();}
else if(menuoption==3)
{  PlayAlbum();
//printf("playalbum");
}
else if(menuoption==4)
{ UpdateAlbum();}
else if(menuoption==5)
{exitSelection=1;}
else
{}

}


}

void main()
{
  playit();

}
