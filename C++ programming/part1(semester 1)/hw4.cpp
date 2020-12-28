/***********************************************
Author: Vibishan Wigneswaran
Date: 9/27/2019
 Purpose: create a program that converts barcodes to zipcodes and vice versa. Also have it error check valid barcodes.
 Time Spent: a lot
 ***********************************************/
#include <iostream>
#include <string>

using namespace std;

class ZipCode{
public:
  //constructers
  ZipCode(int zipNum);
  ZipCode(string barNum);

  //member functions
  int getZipCode();
  string getBarCode();

private:
  //variables(private)
  int zipCode;

  //private member functions
  string findBar(int zipCode);
  int findZip(string barCode);
};

int main(int argc, char * argv[]) {
    ZipCode zip(99504),
    zip2("100101010011100001100110001"),
    zip3(12345),
    zip4(67890);

    cout << zip.getZipCode() << "'s bar code is '"
    << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
    << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
    << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
    << zip4.getBarCode() << "'" << endl;

    cout << endl;

    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);

        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);

        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
        << z1_barcode << "'";

        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }

        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;

    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }

    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}

//overloaded functions
ZipCode::ZipCode(int zipNum){
  zipCode=zipNum;
}

ZipCode::ZipCode(string barNum){
  zipCode=findZip(barNum);
}

//private member functions
string ZipCode::findBar(int zipCode){
int d1,d2,d3,d4,d5;
//sets digits to variables
d1=zipCode%10;
zipCode/=10;
d2=zipCode%10;
zipCode/=10;
d3=zipCode%10;
zipCode/=10;
d4=zipCode%10;
zipCode/=10;
d5=zipCode%10;
zipCode/=10;

int arr[5]={d1,d2,d3,d4,d5};
string barcode;
int count = 0;
while(count!=5){
switch(arr[count]){
case 0:
  barcode= "11000"+barcode;
  break;
case 1:
  barcode= "00011"+barcode;
  break;
case 2:
  barcode= "00101"+barcode;
  break;
case 3:
  barcode= "00110"+barcode;
  break;
case 4:
  barcode= "01001"+barcode;
  break;
case 5:
  barcode= "01010"+barcode;
  break;
case 6:
  barcode= "01100"+barcode;
  break;
case 7:
  barcode= "10001"+barcode;
  break;
case 8:
  barcode= "10010"+barcode;
  break;
case 9:
  barcode= "10100"+barcode;
  break;
}
count++;
}
barcode="1"+barcode+"1";
return barcode;
}

int ZipCode::findZip(string barCode){
  //error checks for 1s at the beginning and end of barcode
  if(barCode.substr(0,1)!="1"||barCode.substr(26,1)!="1"){
    cout << "invalid barcode: 1 is not in the first or last digit of the barcode"<<endl;
  }
//check for invalid digits
  for(int i=0; i<27; i++){
    if(barCode.substr(i,1)=="1"||barCode.substr(i,1)=="0"){
    }
    else{
      cout << "invalid digit in barcode"<< endl;
    }
  }
  string arr[5]={barCode.substr(1,5),
    barCode.substr(6,5),
    barCode.substr(11,5),
    barCode.substr(16,5),
    barCode.substr(21,5)};

  int zarr[5]={0,0,0,0,0};

  int count = 0;
  while(count<5){
  if(arr[count] == "11000"){
    zarr[count]= 0;
  }
  if(arr[count] == "00011"){
    zarr[count]= 1;
  }
  else if(arr[count] == "00101"){
    zarr[count]= 2;
  }
  else if(arr[count] == "00110"){
    zarr[count]= 3;
  }
  else if(arr[count] == "01001"){
    zarr[count]= 4;
  }
  else if(arr[count] == "01010"){
    zarr[count]= 5;
  }
  else if(arr[count] == "01100"){
    zarr[count]= 6;
  }
  else if(arr[count] == "10001"){
    zarr[count]= 7;
  }
  else if(arr[count] == "10010"){
    zarr[count]= 8;
  }
  else if(arr[count] == "10100"){
    zarr[count]= 9;
  }
  else{
    cout << endl;
  }

  count++;
  }

  int s1, s2, s3, s4, s5;

  s1=zarr[0]*10000;
  s2=zarr[1]*1000;
  s3=zarr[2]*100;
  s4=zarr[3]*10;
  s5=zarr[4]*1;

  int zipCode=s1+s2+s3+s4+s5;

  return zipCode;
}

//member functions
int ZipCode::getZipCode(){
  return zipCode;
}

string ZipCode::getBarCode(){
  return findBar(zipCode);
}
/* Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation.  This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.  Violations will be dealt with as outlined therein.

All programming assignments in this class are to be done by the student alone.  No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date:9/27/2019
Name: Vibishan Wigneswaran
*/
