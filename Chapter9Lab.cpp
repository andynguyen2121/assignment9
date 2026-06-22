//
// Name: Andy Nguyen
// Date: 6/21/26
// Course: COSC 1437 C++ Programming Fundamentals II
// Desc: Chapter 9 Lab - Student Grade Report System using Records (structs)
//
 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
 
using namespace std;
 
// Struct definition
struct studentType 
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};
 
// Function prototypes
void readStudentsData(ifstream& inFile, studentType roster[], int size);
void assignGrades(studentType roster[], int size);
int findHighestScore(const studentType roster[], int size);
void printHighestScorers(ostream& out, const studentType roster[], int size, int highestScore);
void printGradeReport(ostream& out, const studentType roster[], int size);
 
int main() 
{
    const int CLASS_SIZE = 20;
    studentType studentRoster[CLASS_SIZE];
    
    // File stream declarations
    ifstream inFile;
    ofstream outFile;
    string inFileName, outFileName;
    
    // TODO: Prompt for input file, check for success.
    cout << "Enter input file name: ";
    cin >> inFileName;

    inFile.open(inFileName);
    if (!inFile) {
        cout << "Could not open input file" << endl;
        return 1;
    }

    // TODO: Prompt for output file, check for success.
    cout << "Enter output file name: ";
    cin >> outFileName;
    
    outFile.open(outFileName);
    if (!outFile) {
        cout << "Could not open output file" << endl;
        return 1;
    }
    
    // TODO: Call structural processing functions.
    readStudentsData(inFile, studentRoster, CLASS_SIZE);
    assignGrades(studentRoster, CLASS_SIZE);
    
    int highest = findHighestScore(studentRoster, CLASS_SIZE);
    
    printGradeReport(outFile, studentRoster, CLASS_SIZE);
    printHighestScorers(outFile, studentRoster, CLASS_SIZE, highest);

    // TODO: Close files.
    inFile.close();
    outFile.close();

    cout << "Report has been made" << endl;

    return 0;
}
 
// TODO: Implement readStudentsData
void readStudentsData(ifstream& inFile, studentType roster[], int size) {
    for (int i = 0; i < size; i++) {
        inFile >> roster[i].studentFName >> roster[i].studentLName >> roster[i].testScore;
    }
}

// TODO: Implement assignGrades
void assignGrades(studentType roster[], int size) {
    for (int i = 0; i < size; i++) {
        int score = roster[i].testScore;

        if (score >= 90) {
            roster[i].grade = 'A';
        }
        else if (score >= 80) {
            roster[i].grade = 'B';
        }
        else if (score >= 70) {
            roster[i].grade = 'C';
        }
        else if (score >= 60) {
            roster[i].grade = 'D';
        }
        else {
            roster[i].grade = 'F';
        }
    }
}

// TODO: Implement findHighestScore
int findHighestScore(const studentType roster[], int size) {
    int highest = roster[0].testScore;

    for (int i = 1; i < size; i++) {
        if (roster[i].testScore > highest) {
            highest = roster[i].testScore;
        }
    }

    return highest;
}

// TODO: Implement printHighestScorers
void printHighestScorers(ostream& out, const studentType roster[], int size, int highestScore) {
    out << "Highest test score: " << highestScore << endl << endl;
    out << "Students with the highest score: " << endl;

    for (int i = 0; i < size; i++) {
        if (roster[i].testScore == highestScore) {
            out << " - " << roster[i].studentLName << ", " << roster[i].studentFName << endl;
        }
    }
}

// TODO: Implement printGradeReport
void printGradeReport(ostream& out, const studentType roster[], int size) {
    out << "--------------------------------------------------" << endl;
    out << "ANNUAL CLASS GRADE REPORT" << endl;
    out << "--------------------------------------------------" << endl;
    out << left << setw(15) << "Student Name" << setw(10) << "Test Score " << right << setw(10) << "Grade" << endl;
    out << "--------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        string fullName = roster[i].studentLName + ", " + roster[i].studentFName;

        out << left << setw(15) << fullName
             << right << setw(10) << roster[i].testScore
             << setw(15) << roster[i].grade << endl;
    }

    out << "--------------------------------------------------" << endl;

    /* Running the program
    
    @andynguyen2121 ➜ /workspaces/assignment9 (main) $ g++ -std=c++17 -Wall -o grades Chapter9Lab.cpp 
    @andynguyen2121 ➜ /workspaces/assignment9 (main) $ ./grades 
    Enter input file name: students.txt
    Enter output file name: report.txt
    Report has been made
    @andynguyen2121 ➜ /workspaces/assignment9 (main) $ 

    */

    /* students.txt

    Maria Garza 88
    Jake Thomas 72
    Aaliyah Brown 95
    John Smith 61
    David Nguyen 90
    Emily Davis 100
    Michael Chang 84
    Sarah Connor 78
    Robert Miller 55
    Sophia Wilson 95
    James Anderson 82
    Linda Taylor 90
    William Thomas 74
    Elizabeth Jackson 100
    Richard White 68
    Jessica Harris 89
    Charles Martin 70
    Karen Thompson 83
    Matthew Garcia 91
    Nancy Martinez 60
    
    */

    /* report.txt output 
    
    --------------------------------------------------
    ANNUAL CLASS GRADE REPORT
    --------------------------------------------------
    Student Name   Test Score      Grade
    --------------------------------------------------
    Garza, Maria           88              B
    Thomas, Jake           72              C
    Brown, Aaliyah         95              A
    Smith, John            61              D
    Nguyen, David          90              A
    Davis, Emily          100              A
    Chang, Michael         84              B
    Connor, Sarah          78              C
    Miller, Robert         55              F
    Wilson, Sophia         95              A
    Anderson, James        82              B
    Taylor, Linda          90              A
    Thomas, William        74              C
    Jackson, Elizabeth       100              A
    White, Richard         68              D
    Harris, Jessica        89              B
    Martin, Charles        70              C
    Thompson, Karen        83              B
    Garcia, Matthew        91              A
    Martinez, Nancy        60              D
    --------------------------------------------------
    Highest test score: 100

    Students with the highest score: 
    - Davis, Emily
    - Jackson, Elizabeth

    */
}