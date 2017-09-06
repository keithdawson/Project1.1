#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

	/*if (argc != 2) {
		cout << "Proper usage ./project1 sample.txt" << endl;
		return 0;
	}*/
	bool found = false;
	int fromLocation, toLocation;
	int i, j, matchRow, nextRow=0, speed;
	int dataArray[1000][5];
	for (int m=0;m<1000;m++){
		for (int n=0;n<5;n++)
			dataArray[m][n]=0;
	}

	string strArray[1000];
	//Opens file to read from
	ifstream inFile(argv[1]);
	string word;
	while (inFile >> word){
		//This is the case for the first word it hits, it puts this in the array
		char c;
		int k;
		for(int i = 0; i < word.length(); i++) {
			word[i] = toupper(word[i]);
		}
		for(i=0;i<1000;i++){
			if (word == strArray[i]){
				matchRow = i;
				dataArray[i][1]+= 1;
				found = true;
				fromLocation = i;
			}
		}
		if (!found){
			strArray[nextRow] = word;
			dataArray[nextRow][1]=1;
			fromLocation = nextRow;
			nextRow++;
		}
		found = false;

		//This is the case for the second word

		inFile >> word;

		k=0;
		for(int i = 0; i < word.length(); i++) {
			word[i] = toupper(word[i]);
		}
		for(i=0;i<=1000;i++){
			if (word == strArray[i]){
				matchRow = i;
				dataArray[i][2]+= 1;
				found = true;
				toLocation = i;
			}
		}
		if (!found){
			strArray[nextRow] = word;
			dataArray[nextRow][2]=1;
			toLocation = nextRow;
			nextRow++;
		}
		found = false;

		//This is the case for the third word/the speed in numbers

		inFile >> speed;
		dataArray[fromLocation][3] += speed;
		dataArray[toLocation][4] += speed;
	}
	// Now for going through and printing
	double d = 0.0, e, f;
	for (int u=0;strArray[u]!="";u++) {
		cout << strArray[u] << endl;
	}
	cout << endl;
	for (int u=0;strArray[u]!="";u++){
		if (dataArray[u][1] != 0 && dataArray[u][2] != 0){
			cout << strArray[u] << ' ' << dataArray[u][4] << ' ' << dataArray[u][3] << ' ';
			e=dataArray[u][4];
			f=dataArray[u][3];
			d=e/f;
			cout << fixed;
			cout << setprecision(2) << d << endl;
		}

	}

}