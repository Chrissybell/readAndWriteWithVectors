/* As a demo, Dr. Li used various strange data structures. Hopefully it enriches and
*expand your knowledge. But you don’t have to follow Dr Li's strange defs to finish this
*project
Project by Christobel Nweke
* Xuechao Li
* Project3 practice
Took ideas and little bit of code from these webpages :
    * https://stackoverflow.com/questions/20052010/writing-content-of-vector-to-file-c/20052118
    * https://stackoverflow.com/questions/4324441/testing-stream-good-or-stream-eof-reads-last-line-twice
    * https://stackoverflow.com/questions/2287121/how-to-read-groups-of-integers-from-a-file-line-by-line-in-c
*/

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/* declare your user-defined functions */
bool check_file(string);


/* do not forget to describe each function */
vector<int> read_file(string);


void write_file(string, vector<int>);


vector<int> merge(vector<int>, vector<int>);
/*


* Display the values of a given vector.
*
* Param: file Name of file to display. (string)
* Param: v Vector containing values to display. (vector<int>)
*/
void to_string(string, vector<int>);

void to_string_merge(string, vector<int>);

/*
* Merge the numbers in two specified files and write all the numbers
* to a specified third file sorted in ascending order.
*
* Return: 1 Program completed successfully. (int)
*/
int main() {
    /* declare your variables */
    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> numbers3;
    string file1;
    string file2;
    string file3;

    /* Get name of file one. */
    do {
        cout << "*** Welcome to Chris's sorting program *** \n";

        cout << "Enter the first input file name:\n";
        cin >> file1;
        /* user friendly interfaces */
    } while (cin.fail() || !check_file(file1));
    /* Get and display numbers from file one. */
    numbers1 = read_file(file1);
    to_string(file1,numbers1);
    /* Get name of file two. */
    do {
        cout << "Enter the second input file name:\n";
        cin >> file2;
    /* user friendly interfaces */
    } while (cin.fail() || !check_file(file2));
    /* Get and display numbers from file two. */
    numbers2 = read_file(file2);
    to_string(file2,numbers2);
    /* Combine vectors and display the sorted result. */
    numbers3 = merge(numbers1, numbers2);
    to_string_merge(file3,numbers3);
    /* Get name of output file. */
    do {
        cout << "Enter the output file name:\n";
        cin >> file3;
    /* user friendly interfaces */
    } while (cin.fail() || !check_file(file3));
    /* Write combined vector to output file. */
    write_file(file3, numbers3);
    cout << " *** Please check the new file ***\n" ;
    cout << " *** Goodbye. ***\n";
    return 0;
}

bool check_file(string file) {
    /* Input file stream. (ifstream) */
    ifstream stream;
    /* Check whether file exists. */
    stream.open(file.c_str());
    /* if file does not exist return false */
    if (stream.fail()) {
        return false;
    }
    stream.close();
    // if the file exists return true;
    return true;
}

vector<int> read_file(string file) {
    /* Input file stream. (ifstream) */
    ifstream stream;
    /* Vector containing numbers from file. (vector<int>) */
    vector<int> v;
    /* Integer read from file. (int) */
    int i;
    /*
    string line;
    if (stream) {
        double value;

        while (stream >> value) {
            v.push_back(value);
        }
    }
    stream.close();
    return v;
    */
    /* Add each number in the file to a vector. */
    stream.open(file);
    while (stream.good()) {

      stream >> i;
      v.push_back(i);
    }
    v.pop_back();
    stream.close();
        /*
        for (int line = 0; line < file.size(); line++) {

            v.push_back(line);
        }
        */
    return v;

}

void write_file(string file, vector<int> v) {
    /* Output file stream. (ofstream) */
    ofstream outputfile(file);

    for( int i = 0; i < v.size(); i++) {
        outputfile<<v[i]<<"\n";
    }

}

vector<int> merge(vector<int> v1, vector<int> v2) {

    int temp;
    vector<int> v3;
    vector<int> v;
    /* Compare both vectors. */
    while ((v1.size() > 0)  &&(v2.size() > 0)) {
        if (v1.at(0)  > v2.at(0)) {
                v3.push_back(v2.at(0));
                v2.erase(v2.begin());
        }else {
                  v3.push_back(v1.at(0));
                  v1.erase(v1.begin());
        }
      }
// g++ -o project3_Nweke_Csn0012 project3_Nweke_Csn0012.cpp
    /* Add any remaining numbers from vector one. */

    if (v1.size() > 0) {
        for( int i = 0; i < v1.size(); i++) {
                v3.push_back(v1.at(0));
                v1.erase(v1.begin());
        }
    }

    if (v2.size() > 0) {
        for( int i = 0; i < v2.size(); i++) {
                v3.push_back(v2[i]);
                v2.erase(v2.begin());
        }
    }


        return v3;
    }

        /* Add any remaining numbers from vector one. */
/*
    while (v1.size() > 0) {
        for( int i = 0; i < v1.size(); i++) {
            int current_value = i;
            for( int j = i + 1; j , v1.size(); j++) {
                if ( current_value == j) {

                }
                else {
                    v3.push_back(v1[current_value]);
                    v1.erase(v1.begin());
                }
            }
        }
    }
*/

/*
    while (v2.size() > 0) {
        for( int i = 0; i < v1.size(); i++) {
            int current_value = i;
            for( int j = i + 1; j , v1.size(); j++) {
                if ( current_value == j) {

                }
                else {
                    v3.push_back(v2[current_value]);
                    v2.erase(v2.begin());
                }
            }
        }
    }
*/
    /* Add any remaining numbers from vector two. */


    // 
    // if ( ((v1.size() == 0) && (v2.size() ==0)) ) {
    //
    //     int miniPos;
    //     for(int i = 0; i < v3.size(); i++) {
    //         miniPos = i;
    //         for ( int j = i +1; j < v3.size(); j++) {
    //             if (v3[j] < v3[i])  {
    //                 miniPos = j;
    //             }
    //
    //         }
    //         temp = v3[miniPos];
    //         v3[miniPos] = v3[i];
    //         v3[i] = temp;
    //         v3.push_back(temp);
    //
    //         //v3.erase(v3.begin());
    //
    //     }
    //
    // }

void to_string(string file, vector<int> v) {
    /* Vector interator number. (unsigned short) */
    cout << "The list of " << v.size() << " numbers in file " << file << " is:\n";
    /* Display the numbers contained in a vector. */
    for(int i: v) {

        cout << i << " " << "\n";
    }
}
void to_string_merge(string file, vector<int> v) {
    /* Vector interator number. (unsigned short) */
    cout << "The Sorted list of " << v.size() << " numbers in file " << file << " is:\n";
    /* Display the numbers contained in a vector. */
    for(int i: v) {
        cout << i << " " << "\n";
    }
}
