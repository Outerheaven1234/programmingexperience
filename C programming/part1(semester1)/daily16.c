/***********************************************
  Program: daily 16
	Author: Vibishan Wigneswaran
	Date: 8/5/2020
	Time Spent: 1 hour 30 minutes
	Purpose: Create a program that uses top down approach and utilizes stub functions. Previous stub functions are implemented. Full program utilizing the previous 2 stub filled programs.
 ***********************************************/

#include <stdio.h>

//clears keyboard buffer
void clear_keyboard_buffer(void);

//Options functions
void convert_length (void);
void convert_weight (void);
void length_to_us (void);
void length_to_metric (void);
void weight_to_us (void);
void weight_to_metric (void);

//length
void US_length_in(int *m, double *cent);
void US_length_conv(int meters, double centimeters, int *ft, double *in);
void US_length_out(int ft, int meters, double in, double centimeters);

void Met_length_in(int *ft, double *in);
void Met_length_conv(int feet, double inches, int *m, double *cent);
void Met_length_out(int feet, int meters, double inches, double cent);

//weight
void US_weight_in(int *kg, double *g);
void US_weight_conv(int kilograms, double grams, int *lb, double *on);
void US_weight_out(int pounds, int kilograms, double ounces, double grams);

void Met_weight_in(int *lb, double *on);
void Met_weight_conv(int pounds, double ounces, int *kg, double *g);
void Met_weight_out(int pounds, int kilograms, double onces, double grams);

int main(int argc, char *argv[]) {
    int choice; //stores choice

    printf("1. convert lengths\n2. convert weights\n0. Exit\nPlease choose from (1, 2, 0):"); //initialprompt
    scanf("%d", &choice); //record prompt
    clear_keyboard_buffer();

while (choice != 0) {
    switch(choice) {
      case 0: break;
      //Exit
      case 1: printf("1. convert lengths \n\n"); convert_length(); printf("1. convert lengths\n2. convert weights\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice); clear_keyboard_buffer();
      case 2: printf("2. convert weights \n\n"); convert_weight(); printf("1. convert lengths\n2. convert weights\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice); clear_keyboard_buffer();
    }
}
    printf("User chose to Exit \n\n"); //prompt caused by exiting
    return 0;
}

void convert_length (void) {
  int choice;
  printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); //initialprompt
  scanf("%d", &choice); //record prompt
  clear_keyboard_buffer();

while (choice != 0) {
  switch(choice) {
    case 0: break;
    //Exit
    case 1: printf("1. convert to metric \n\n"); length_to_metric(); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice); clear_keyboard_buffer();
    case 2: printf("2. convert to us \n\n"); length_to_us(); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice); clear_keyboard_buffer();
  }
}
  printf("User chose to Exit \n\n");
  }

void convert_weight (void) {
  int choice;
  printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); //initialprompt
  scanf("%d", &choice); //record prompt
  clear_keyboard_buffer();

while (choice != 0) {
  switch(choice) {
    case 0: break;
    //Exit
    case 1: printf("1. convert to metric \n\n"); weight_to_metric(); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice); clear_keyboard_buffer();
    case 2: printf("2. convert to us \n\n"); weight_to_us(); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice); clear_keyboard_buffer();
  }
}
}

void length_to_us (void) {
  int *ft, feet = 0, *m, meters = 0;
  double *in, inches= 0, *cent, centimeters = 0;

  ft = &feet;
  in = &inches;
  m = &meters;
  cent = &centimeters;

  printf("Convert length to US.\n");
  US_length_in(m, cent);
  US_length_conv(meters, centimeters, ft, in);
  US_length_out(feet, meters, inches, centimeters);

}

void length_to_metric (void) {
  int feet = 0, meters = 0;
	double inches = 0, centimeters = 0;
	int *ft, *m;
	double *in, *cm;

	ft = &feet;
	in = &inches;
	m = &meters;
	cm = &centimeters;

  printf("Convert length to metric.\n");

	Met_length_in(ft, in);
	Met_length_conv(feet, inches, m, cm);
	Met_length_out(feet, meters, inches, centimeters);

	return;
}

void weight_to_us (void) {
  int kilograms = 0, pounds = 0;
	double grams = 0, ounces = 0;
	int *kg, *lb;
	double *g, *on;

	kg = &kilograms;
	lb = &pounds;
	g = &grams;
	on = &ounces;

  printf("Converts weight to US\n");

  US_weight_in(kg, g);
  US_weight_conv(kilograms, grams, lb, on);
  US_weight_out(pounds, kilograms, ounces, grams);
  return;
}

void weight_to_metric (void) {
  int kilograms = 0, pounds = 0;
	double grams = 0, ounces = 0;
	int *kg, *lb;
	double *g, *on;

	kg = &kilograms;
	lb = &pounds;
	g = &grams;
	on = &ounces;

  printf("Converts weight to metric\n");

  Met_weight_in(lb, on);
  Met_weight_conv(pounds, ounces, kg, g);
  Met_weight_out(pounds, kilograms, ounces, grams);
  return;
}

void US_length_in(int *m, double *cent){
  printf("Enter meters and centimeters(separated by a space) to convert to feet/inches:\n");
  scanf("%d %lf", m, cent);
  clear_keyboard_buffer();
  return;
}

void US_length_conv(int meters, double centimeters, int *ft, double *in){
  double totInches = 0, totCm = 0;

	totCm = ((double)meters * 100) + centimeters;
	totInches = ((totCm / 100) / .3048) * 12;

	while(totInches > 12)
	{
		*ft = *ft + 1;
		totInches = totInches - 12;
	}
	*in = totInches;

	return;
}

void US_length_out(int ft, int meters, double in, double centimeters){
  printf("\n%d Meters %.2lf centimeters = %d feet %.2lf inches. \n", meters, centimeters, ft, in);
  return;
}

void Met_length_in(int *ft, double *in){
  printf("Enter feet and inches(separated by a space) to convert to meters/centimeters.\n");
  scanf("%d %lf", ft, in);
  clear_keyboard_buffer();
}

void Met_length_conv(int feet, double inches, int *m, double *cent){
  double totInches = 0, totCm = 0;

  	totInches = ((double)feet * 12) + inches;
  	totCm = (totInches / 12) * .3048 * 100;

  	while(totCm > 100)
  	{
  		*m = *m + 1;
  		totCm = totCm - 100;
  	}
  	*cent = totCm;
  	return;
}

void Met_length_out(int feet, int meters, double inches, double cent){
  printf("\n%d Meters %.2lf centimeters = %d feet %.2lf inches. \n", meters, cent, feet, inches);
	return;
}

void US_weight_in(int *kg, double *g){
  printf("Enter kilograms and grams(separated by a space) to convert to pounds/ounces.\n");
  scanf("%d %lf", kg, g);
  clear_keyboard_buffer();
}

void US_weight_conv(int kilograms, double grams, int *lb, double *on){
  double totOunces = 0, totGrams = 0;

  	totGrams = ((double)kilograms * 1000) + grams;
  	totOunces = ((totGrams / 1000) * 2.2046) * 16;


  	while(totOunces > 16)
  	{
  		*lb = *lb + 1;
  		totOunces = totOunces - 16;
  	}

  	*on = totOunces;

  	return;
}

void US_weight_out(int pounds, int kilograms, double ounces, double grams){
  printf("\n%d Kilograms %.2lf grams = %d pounds %.2lf ounces. \n", kilograms, grams, pounds, ounces);
  return;
}

void Met_weight_in(int *lb, double *on){
  printf("Enter pounds and ounces(separated by a space) to convert to kilograms/grams.\n");
  scanf("%d %lf", lb, on);
  clear_keyboard_buffer();
}

void Met_weight_conv(int pounds, double ounces, int *kg, double *g){
    double totOunces = 0, totGrams = 0;

  	totOunces = ((double)pounds * 16) + ounces;
  	totGrams = ((totOunces / 16) / 2.2046) * 1000;

  	while(totGrams > 1000)
  	{
  		*kg = *kg + 1;
  		totGrams = totGrams - 1000;
  	}

  	*g = totGrams;

  	return;
}

void Met_weight_out(int pounds, int kilograms, double ounces, double grams){
  printf("\n%d Pounds %.2lf ounces = %d kilograms %.2lf grams. \n", pounds, ounces, kilograms, grams);
  return;
}

void clear_keyboard_buffer(void) {
  char ch;
  scanf("%c", &ch);
  while (ch != '\n') {
      scanf("%c", &ch);
  }
}
