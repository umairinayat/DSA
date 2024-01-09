#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string codelist[5], namelist[5];
int crdhrlist[5], semesterlist[5];
int total = 0;
bool isvalidCourseCode(string coursecode)
{

    if (coursecode[0] >= 'A' && coursecode[0] <= 'Z' &&
        coursecode[1] >= 'A' && coursecode[1] <= 'Z' &&
        coursecode[2] >= '0' && coursecode[2] <= '9' &&
        coursecode[3] >= '0' && coursecode[3] <= '9' &&
        coursecode[4] >= '0' && coursecode[4] <= '9')
    {

        return true;
    }
    else
    {

        return false;
    }
}
bool isvalidCourseName(string coursename)
{

    bool valid = true;

    for (int i = 0; i < coursename.length(); i++)
    {
        if (islower(coursename[i]) || isupper(coursename[i]) || coursename[i] == ' ')
        {
            continue;
        }
        else
        {
            valid = false;
            break;
        }
    }
    return valid;
}
bool isvalidCreditHours(int crdhr)
{
    if (crdhr >= 1 && crdhr <= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isvalidSemester(int semester)
{
    if (semester >= 1 && semester <= 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Addcourse(string coursecode, string coursename, int crdhr, int semester)
{
    if (isvalidCourseCode(coursecode) && isvalidCourseName(coursename) &&
        isvalidCreditHours(crdhr) && isvalidSemester(semester))
    {
        codelist[total] = coursecode;
        namelist[total] = coursename;
        crdhrlist[total] = crdhr;
        semesterlist[total] = semester;

        total++;
        cout << "Course has been added successfully" << endl;
    }
    else
    {
        cout << "Invalid Course" << endl;
    }
}

void Updatecourse(string coursecode, string ncode, string nname, int ncrdhr, int nsem)
{
    bool found = false;

    if (isvalidCourseCode(coursecode))
    {
        for (int i = 0; i < total; i++)
        {
            if (codelist[i] == coursecode)
            {
                codelist[i] = ncode;
                namelist[i] = nname;
                crdhrlist[i] = ncrdhr;
                semesterlist[i] = nsem;
                found = true;
                cout << "Coure has been updated successfully ";
                break;
            }
        }
        if (!found)
        {
            cout << "Code not found";
        }
    }
    else
    {
        cout << "Invalid Code";
    }
}

void Dletecourse(string coursecode)
{
    bool found = false;

    if (isvalidCourseCode(coursecode))
    {
        for (int i = 0; i < total; i++)
        {
            if (codelist[i] == coursecode)
            {
                found = true;
                for (int j = i; j < total - 1; j++)

                {
                    codelist[j] = codelist[j + 1];
                    namelist[j] = namelist[j + 1];
                    crdhrlist[j] = crdhrlist[j + 1];
                    semesterlist[j] = semesterlist[j + 1];

                    cout << "Course has been deleted successfully ";
                    total--;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "Code not found";
        }
    }
    else
    {
        cout << "Invalid Code";
    }
}
void Viewcourse()
{
    for (int i = 0; i < total; i++)
    {
        cout << codelist[i] << "\t" << namelist[i] << "\t\t" << crdhrlist[i] << "\t" << semesterlist[i] << endl;
    }
}
void ViewSemesterCourses(int semester)
{
    bool found = false;
    if (isvalidSemester(semester))
    {
        for (int i = 0; i < total; i++)
        {

            if (semesterlist[i] == semester)
            {

                found = true;
                cout << "Course code\tName\t\tCredit Hours" << endl;
                cout << codelist[i] << "\t" << namelist[i] << "\t" << crdhrlist[i] << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Semester not found";
        }
    }
    else
    {
        cout << "Invalid Semester";
    }
}

int main()
{
    string coursecode, coursename;
    string ncode, nname;
    int nsem, ncrdhr;
    int semester, crdhr;
    int crdhrlist;
    int semlist;
    int option;
    bool login = true;
    while (login)
    {
        cout << " ************** Welcome to University Learning Management System ************** " << endl;
        cout << " Choose the following option" << endl;
        cout << " 1 Add Course " << endl;
        cout << " 2 Update Course " << endl;
        cout << " 3 Delete course " << endl;
        cout << " 4 View All Courses " << endl;
        cout << " 5 View Courses of Semester" << endl;
        cout << " 6 Exit Program" << endl;
        cout << "Choose the option: ";
        cin >> option;
        cout << "You Choose the option " << option << endl;

        switch (option)
        {
        case 1:
        {
            cout << "Enter the Detail of Course (code credithour semester name): " << endl;
            cin >> coursecode >> crdhr >> semester;
            // getline(cin.ignore(), coursename);
            cin >> coursename;
            Addcourse(coursecode, coursename, semester, crdhr);

            break;
        }
        case 2:
        {

            cout << "Enter the coursecode" << endl;
            cin >> coursecode;

            cout << "Enter the new detail of Course (code credithour semester name): ";
            cin >> ncode >> ncrdhr >> nsem;
            cin >> nname;

            Updatecourse(coursecode, ncode, nname, nsem, ncrdhr);
            break;
        }
        case 3:
        {
            cout << "Enter the Course code" << endl;
            cin >> coursecode;

            Dletecourse(coursecode);
            break;
        }
        case 4:
        {
            cout << "Course code\tName\t\tCredit Hours\tSemester" << endl;

            Viewcourse();
            break;
        }
        case 5:
        {
            // int semester;
            cout << "Enter the Semester: ";
            cin >> semester;

            ViewSemesterCourses(semester);
            break;
        }
        case 6:
        {
            cout << "Exiting the Program";
            login = false;
            break;
        }
        }
    }
    return 0;
}