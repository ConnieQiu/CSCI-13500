#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
	string date;
	string begin_date;
	string end_date;
	double eastSt, eastEl, westSt, westEl;
	double elevation[INT_MAX];
	string dates[INT_MAX];
	int counter = 0;
	bool inInterval;
	
	cout << "Enter earlier date: ";
	cin >> begin_date;
	cout << "Enter later date: ";
	cin >> end_date;

	ifstream fin("Current_Reservoir_Levels.tsv");

	if(fin.fail()){
		cerr << "File cannot be opened for reading." << endl; //character error
		exit(1); //exit if failed to open the file //terminate the process
	}

	string junk;	//use variable to store the first line
	getline(fin, junk); //reads in the entire line vs just one thing at a time, including spaces,
			   // 1st argument where you are reading data from, second argument is the variable you store the first line in
	
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){ 
		//this loop reads the file line-by-line
		//extracting 5 values on each iteration
		if(date == begin_date){
			inInterval = true;
		}
		if(inInterval == true){
			dates[counter] = date;
			elevation[counter] = westEl;
			counter++;	//arr[counter] counter++
		}
		if(date == end_date){
			inInterval = false;
		}
		fin.ignore(INT_MAX, '\n'); //skips the end of line, ignoring the remaining columns
					   // first arg how many chars to ignore, second argument when does it stop ignoring, \n = tab

	}
	for(int i = counter - 1; 1 >= 0; i--){
                        cout << dates[i] << " " << elevation[i] << " " << "ft" << endl;
                }
	//print the array, set for loop to start at counter int i = counter - 1	
	fin.close(); //closes the connection with the file
	return 0;
}
