/*
Vibishan Wigneswaran
8/11/2020
purpose: copy contents of 2 txt files and organize them into another file
time spent: 20 minutes
*/

#include <stdio.h>
#include <stdlib.h>

void merge(FILE *fp_input, FILE *fp2_input, FILE *fp_output);

int main(int argc, char *argv[])
{
FILE *fp_input, *fp2_input, *fp_output;

merge(fp_input, fp2_input, fp_output);

return 0;
}

//function copies in.txt & in2.txt and organizes em into out.txt
void merge(FILE *fp_input, FILE *fp2_input, FILE *fp_output)
{

int num;
int n = 0;
int buffer[100];

//open files
fp_input=fopen("numbers1.txt","r");
fp2_input=fopen("numbers2.txt","r");
fp_output=fopen("output.txt","w");
if (fp_input==NULL || fp2_input==NULL)
{
	printf("Couldn't open file");
	exit(1);
}

//file 1 into array
while(num=fscanf(fp_input, "%d", &buffer[n])!=EOF){
	++n;
}

//file 2 into array
while(num=fscanf(fp2_input, "%d", &buffer[n])!=EOF){
	++n;
}


//organize and output (write)
for(int i = 0; i<n; i++){
	for(int j=i+1; j<n; j++){
		if(buffer[i]>buffer[j]){
			int temp = buffer[i];
			buffer[i] = buffer[j];
			buffer[j] = temp;
		}
	}
	fprintf(fp_output, "%d ", buffer[i]);
}

//close files
fclose(fp_input);
fclose(fp2_input);
fclose(fp_output);
}
