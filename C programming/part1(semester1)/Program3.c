/***********************************************
   Author:	Vibishan Wigneswaran
   Course: COMP1010, Computing 1
   Date: 8/11/2020
   Description:	Reads data from file and uses it to input student grades and average into table.
  
***********************************************/
//packages
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function defintion
double findAverage(int quiz1, int quiz2, int quiz3, int quiz4, int quiz5, int quiz6, int quiz7, int quiz8, int quiz9, int quiz10);

//main statment
int main(int argc, char *argv[])
{
    int quiz1 = 0, quiz2 = 0, quiz3 = 0, quiz4 = 0, quiz5 = 0, quiz6 = 0, quiz7 = 0, quiz8 = 0, quiz9 = 0, quiz10 = 0;
    //FIle pointers
    FILE *fp_input;
    FILE *fp_output;
    //arrays for names
    char firstName[20];
    char lastName[20];

//file presence check
if ((fp_input = fopen("quiz.txt","r")) == NULL)
    {
    printf("Couldnt open\n");
    }
else if ((fp_output=fopen("average.txt","w")) == NULL)
    {
    printf("Couldnt open\n");
    }

fprintf(fp_output,"Name            Quiz:   1   2   3   4   5   6   7   8   9  10  Average\n");
fprintf(fp_output,"______________________________________________________________________\n");

//scans files for names and quiz grades

while(fscanf(fp_input,"%s %s %d %d %d %d %d %d %d %d %d %d", firstName, lastName, &quiz1,&quiz2,&quiz3,&quiz4,&quiz5,&quiz6,&quiz7,&quiz8,&quiz9,&quiz10) != EOF)
    {
      double average = findAverage(quiz1, quiz2, quiz3, quiz4, quiz5, quiz6, quiz7, quiz8, quiz9, quiz10);
      fprintf(fp_output, "%s, %s          %-3d %-3d %-3d %-3d %-3d %-3d %-3d %-3d %-3d %-3d %-3f\n", lastName, firstName, quiz1, quiz2, quiz3, quiz4, quiz5, quiz6, quiz7, quiz8, quiz9, quiz10, average);
      quiz1 = 0, quiz2 = 0, quiz3 = 0, quiz4 = 0, quiz5 = 0, quiz6 = 0, quiz7 = 0, quiz8 = 0, quiz9 = 0, quiz10 = 0;
      }
      fclose(fp_input);
      fclose(fp_output);
      return 0;
    }

//finds quiz grade average
double findAverage(int quiz1, int quiz2, int quiz3, int quiz4, int quiz5, int quiz6, int quiz7, int quiz8, int quiz9, int quiz10)
{
  double average = ((double)(quiz1 + quiz2 + quiz3 + quiz4 + quiz5 + quiz6 + quiz7 + quiz8 + quiz9 + quiz10))/10;
  return average;
}
