// FileHandling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
//#include <filesystem>
//#include <sys/stat.h>
//struct stat results;

// The size of the file in bytes is in
// results.st_size
using namespace std;

int main() {
	ofstream myfile;
	string filePath = "myData.txt";
	myfile.open(filePath);
	myfile << "1234\n";
	myfile << "1234\n";
	myfile << "1234\n";
	cout << "Data has been written into txt file" << endl;

	/*
	if (stat("myData.txt", &results) == 0) {
		cout << "Size : " << results.st_size;
	}
	
	ifstream file(filePath, ios::binary | ios::ate);
	cout<< file.tellg();


	ifstream in_file(filePath, ios::binary);
	in_file.seekg(0, ios::end);
	int file_size = in_file.tellg();
	cout << "Size of the file is" << " " << file_size << " " << "bytes";


	cout << "size of file '" << filePath << "' = " <<
			file_size(filePath) << endl;
	*/
	myfile.close();

	ofstream wf("myDataBinary.txt", ios::out | ios::binary);
	if (!wf) {
		cout << "Cannot open file!" << endl;
		return 1;
	}
	int data = 1234;
	for (int i = 0; i < 3; i++)
	{
		wf.write((char*)&data, sizeof(int));

	}
	cout << "Data has been written into binary file" << endl;

	wf.close();
	return EXIT_SUCCESS;
}


/*
ostream& write(const char*, int);
The write member function writes a given number of bytes on the given stream,
starting at the position of the "put" pointer.
If the put pointer is current at the end of the file, the file is extended.
If the put pointer points into the middle of the file,
characters in the file are overwritten with the new data. 
The bytes that are written and not interpreted,
no carriage return is added after the data,
and the write method does not assume there is a null terminator at the end of the bytes that are being written.
If an error occurs while writing
(for example, if you run out of disk space), 
the stream is placed in an error state. 
Such errors are not as common as read errors, and are often not checked.

*/