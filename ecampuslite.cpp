
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <sstream>

using namespace std;

void clear()
{
    system("cls");
}

void colourgreen()
{
    system("color 02");
}

void colourblue()
{
    system("color 03");
}

void colourorange()
{
    system("color 06");
}

void choices();

class Person
{
    protected:
        string rollno;
        string name;
        string email;
        string phone;
        string department;
        string resident;

    protected:
        string password;

    public:
        Person() {}

        Person(string rollno1,string name1,string email1,string phone1,string department1,string resident1,string password1):rollno(rollno1),name(name1),email(email1),phone(phone1),department(department1),resident(resident1),password(password1){}

        void viewDetails()
        {
            cout << "Roll Number: " << rollno << endl;
            cout << "Name: " << name << endl;
            cout << "Email: " << email << endl;
            cout << "Phone: " << phone << endl;
            cout << "Department: " << department << endl;
            cout << "Resident Status: " << resident << endl;
            cout << "Password: " << password << endl;
        }

        void changePassword(string password1)
        {
            password = password1;
        }

        bool verifyPassword(string enteredPassword)
        {
            return password == enteredPassword;
        }

        string courses(string rollno,int i)
        {
            if(rollno[3] == 'w' || rollno[3] == 'W')
            {
                string course[8] = {"23XW21 - LINEAR ALGEBRA","23XW22 - DISCRETE STRUCTURES","23XW23 - DATA STRUCTURES AND ALGORITHMS","23XW24 - OBJECT ORIENTED PROGRAMMING","23XW25 - COMPUTER ORGANIZATION","23XW26 - DATA STRUCTURES LABORATORY","23XW27 - OBJECT COMPUTING LABORATORY","23XW28 - PYTHON PROGRAMMING LABORATORY"};
                return course[i];
            }
            else if(rollno[3] == 'T' || rollno[3] == 't')
            {
                string course[8] = {"23XT21 - DISCRETE STRUCTURES","23XT22 - ABSTRACT ALGEBRA","23XT23 - DATA STRUCTURES AND ALGORITHMS","23XT24 - OBJECT ORIENTED PROGRAMMING","23XT25 - TRANSFORMS AND ITS APPLICATIONS","23XT26 - DATA STRUCTURES LABORATORY","23XT27 - OBJECT ORIENTED PROGRAMMING LABORATORY","23XT28 - PYTHON PROGRAMMING LABORATORY"};
                return course[i];
            }
            else if(rollno[3] == 'C' || rollno[3] == 'c')
            {
                string course[8] = {"23XC21 - DISCRETE STRUCTURES","23XC22 - ALGEBRA AND NUMBER THEORY","23XC23 - DATA STRUCTURES AND ALGORITHMS","23XC24 - OBJECT ORIENTED PROGRAMMING","23XC25 - COMPUTER ARCHITECTURE","23XC26 - DATA STRUCTURES LABORATORY","23XC27 - OBJECT COMPUTING LABORATORY","23XC28 - PYTHON PROGRAMMING LABORATORY"};
                return course[i];
            }
            else if(rollno[3] == 'D' || rollno[3] == 'd')
            {
                string course[8] = {"23XD21 - DISCRETE STRUCTURES","23XD22 - ABSTRACT ALGEBRA","23XD23 - DATA STRUCTURES AND ALGORITHMS","23XD24 - OBJECT ORIENTED PROGRAMMING","23XD25 - THEORY OF PROBABILITY","23XD26 - OBJECT COMPUTING LABORATORY","23XD27 - DATA STRUCTURES LABORATORY","23XD28 - PYTHON PROGRAMMING LABORATORY"};
                return course[i];
            }
            return "0";
        }
};

string rollno2;

class Student:public Person
{
    private:
        string batch;
        string programme;

        int attendance[8];
        int caMarks[8];
        int semMarks[8];

    public:
        Student(string rollno1,string name1,string email1,string phone1,string department1,string resident1,string password1,string batch1,string programme1):Person(rollno1,name1,email1,phone1,department1,resident1,password1),batch(batch1),programme(programme1)
        {
            for (int i = 0; i < 8; i++)
            {
                attendance[i] = 0;
                caMarks[i] = 0;
                semMarks[i] = 0;
            }
        }

        Student():Person()
        {
            batch = "";
            programme = "";
            for (int i = 0; i < 8; i++)
            {
                attendance[i] = 0;
                caMarks[i] = 0;
                semMarks[i] = 0;
            }
        }

        void viewDetails()
        {
            ifstream attendanceFile("students.txt");
            string line;
            int flag = 0;
            if(attendanceFile)
            {
                while (getline(attendanceFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno2)
                    {
                        istringstream istreamline(line);
                        string indAttendance;
                        string details[9];
                        for (int i = 0; i < 9; i++)
                        {
                            getline(istreamline, indAttendance, ',');
                            details[i] = indAttendance;
                        }
                        flag = 1;
                        cout << "Roll Number: " << details[0] << endl;
                        cout << "Name: " << details[1] << endl;
                        cout << "Email: " << details[2] << endl;
                        cout << "Phone: " << details[3] << endl;
                        cout << "Department: " << details[4] << endl;
                        cout << "Resident Status: " << details[5] << endl;
                        cout << "Batch: " << details[6] << endl;
                        cout << "Programme: " << details[7] << endl;
                        cout << endl;
                        cout << "\n\n<Back>";
                        getch();
                    }
                }
            }
        }

        void viewTimetable()
        {
            if(rollno2[3] == 'w' || rollno2[3] == 'W')
            {
                cout << "TIME TABLE (SOFTWARE SYSTEMS)\n\n";
                cout << left << setw(10) << "MON" << "" << setw(10) << "23XW21" << setw(10) << "23XW24" << setw(10) << "23XW26" << setw(10) << "23XW26" << setw(10) << "23XW25" << setw(10) << "23XW22" << setw(10) << "23XW23" << "\n";
                cout << left << setw(10) << "TUE" << "" << setw(10) << "23XW23" << setw(10) << "23XW22" << setw(10) << "23XW21" << setw(10) << "SMR" << setw(10) << "23XW24" << setw(10) << "23XW25" << "\n";
                cout << left << setw(10) << "WED" << "" << setw(10) << "23XW23" << setw(10) << "23XW27" << setw(10) << "23XW27" << setw(10) << "23XW28" << setw(10) << "23XW28" << setw(10) << "23XW26" << "\n";
                cout << left << setw(10) << "THU" << "" << setw(10) << "23XW25" << setw(10) << "23XW22" << setw(10) << "23XW21" << setw(10) << "23XW24" << setw(10) << "23XW23" << setw(10) << "23XW21" << "\n";
                cout << left << setw(10) << "FRI" << "" << setw(10) << "23XW27" << setw(10) << "23XW27" << setw(10) << "23XW21" << setw(10) << "23XW24" << setw(10) << "23XW25" << setw(10) << "23XW28" << setw(10) << "23XW28" << "\n";
                cout << endl << "23XW21 - LINEAR ALGEBRA\n23XW22 - DISCRETE STRUCTURES\n23XW23 - DATA STRUCTURES AND ALGORITHMS\n23XW24 - OBJECT ORIENTED PROGRAMMING\n23XW25 - COMPUTER ORGANIZATION\n23XW26 - DATA STRUCTURES LABORATORY\n23XW27 - OBJECT COMPUTING LABORATORY\n23XW28 - PYTHON PROGRAMMING LABORATORY\n\n";
            }
            else if(rollno2[3] == 'T' || rollno2[3] == 't')
            {
                cout << "TIME TABLE (THEORETICAL COMPUTER SCIENCE)\n\n";
                cout << left << setw(10) << "MON" << "" << setw(10) << "23XT21" << setw(10) << "23XT24" << setw(10) << "23XT26" << setw(10) << "23XT26" << setw(10) << "23XT25" << setw(10) << "23XT22" << setw(10) << "23XT23" << "\n";
                cout << left << setw(10) << "TUE" << "" << setw(10) << "23XT23" << setw(10) << "23XT22" << setw(10) << "23XT21" << setw(10) << "SMR" << setw(10) << "23XT24" << setw(10) << "23XT25" << "\n";
                cout << left << setw(10) << "WED" << "" << setw(10) << "23XT23" << setw(10) << "23XT27" << setw(10) << "23XT27" << setw(10) << "23XT28" << setw(10) << "23XT28" << setw(10) << "23XT26" << "\n";
                cout << left << setw(10) << "THU" << "" << setw(10) << "23XT25" << setw(10) << "23XT22" << setw(10) << "23XT21" << setw(10) << "23XT24" << setw(10) << "23XT23" << setw(10) << "23XT21" << "\n";
                cout << left << setw(10) << "FRI" << "" << setw(10) << "23XT27" << setw(10) << "23XT27" << setw(10) << "23XT21" << setw(10) << "23XT24" << setw(10) << "23XT25" << setw(10) << "23XT28" << setw(10) << "23XT28" << "\n";
                cout << endl << "23XT21 - DISCRETE STRUCTURES\n23XT22 - ABSTRACT ALGEBRA\n23XT23 - DATA STRUCTURES AND ALGORITHMS\n23XT24 - OBJECT ORIENTED PROGRAMMING\n23XT25 - TRANSFORMS AND ITS APPLICATIONS\n23XT26 - DATA STRUCTURES LABORATORY\n23XT27 - OBJECT COMPUTING LABORATORY\n23XT28 - PYTHON PROGRAMMING LABORATORY\n\n";
            }
            else if(rollno2[3] == 'C' || rollno2[3] == 'c')
            {
                cout << "TIME TABLE (CYBER SECURITY)\n\n";
                cout << left << setw(10) << "MON" << "" << setw(10) << "23XC21" << setw(10) << "23XC24" << setw(10) << "23XC26" << setw(10) << "23XC26" << setw(10) << "23XC25" << setw(10) << "23XC22" << setw(10) << "23XC23" << "\n";
                cout << left << setw(10) << "TUE" << "" << setw(10) << "23XC23" << setw(10) << "23XC22" << setw(10) << "23XC21" << setw(10) << "SMR" << setw(10) << "23XC24" << setw(10) << "23XC25" << "\n";
                cout << left << setw(10) << "WED" << "" << setw(10) << "23XC23" << setw(10) << "23XC27" << setw(10) << "23XC27" << setw(10) << "23XC28" << setw(10) << "23XC28" << setw(10) << "23XC26" << "\n";
                cout << left << setw(10) << "THU" << "" << setw(10) << "23XC25" << setw(10) << "23XC22" << setw(10) << "23XC21" << setw(10) << "23XC24" << setw(10) << "23XC23" << setw(10) << "23XC21" << "\n";
                cout << left << setw(10) << "FRI" << "" << setw(10) << "23XC27" << setw(10) << "23XC27" << setw(10) << "23XC21" << setw(10) << "23XC24" << setw(10) << "23XC25" << setw(10) << "23XC28" << setw(10) << "23XC28" << "\n";
                cout << endl << "23XC21 - DISCRETE STRUCTURES\n23XC22 - ALGEBRA AND NUMBER THEORY\n23XC23 - DATA STRUCTURES AND ALGORITHMS\n23XC24 - OBJECT ORIENTED PROGRAMMING\n23XC25 - COMPUTER ARCHITECTURE\n23XC26 - DATA STRUCTURES LABORATORY\n23XC27 - OBJECT COMPUTING LABORATORY\n23XC28 - PYTHON PROGRAMMING LABORATORY\n\n";
            }
            else if(rollno2[3] == 'D' || rollno2[3] == 'd')
            {
                cout << "TIME TABLE (DATA  SCIENCE)\n\n";
                cout << left << setw(10) << "MON" << "" << setw(10) << "23XD21" << setw(10) << "23XD24" << setw(10) << "23XD26" << setw(10) << "23XD26" << setw(10) << "23XD25" << setw(10) << "23XD22" << setw(10) << "23XD23" << "\n";
                cout << left << setw(10) << "TUE" << "" << setw(10) << "23XD23" << setw(10) << "23XD22" << setw(10) << "23XD21" << setw(10) << "SMR" << setw(10) << "23XD24" << setw(10) << "23XD25" << "\n";
                cout << left << setw(10) << "WED" << "" << setw(10) << "23XD23" << setw(10) << "23XD27" << setw(10) << "23XD27" << setw(10) << "23XD28" << setw(10) << "23XD28" << setw(10) << "23XD26" << "\n";
                cout << left << setw(10) << "THU" << "" << setw(10) << "23XD25" << setw(10) << "23XD22" << setw(10) << "23XD21" << setw(10) << "23XD24" << setw(10) << "23XD23" << setw(10) << "23XD21" << "\n";
                cout << left << setw(10) << "FRI" << "" << setw(10) << "23XD27" << setw(10) << "23XD27" << setw(10) << "23XD21" << setw(10) << "23XD24" << setw(10) << "23XD25" << setw(10) << "23XD28" << setw(10) << "23XD28" << "\n";
                cout << endl << "23XD21 - DISCRETE STRUCTURES\n23XD22 - ABSTRACT ALGEBRA\n23XD23 - DATA STRUCTURES AND ALGORITHMS\n23XD24 - OBJECT ORIENTED PROGRAMMING\n23XD25 - THEORY OF PROBABILITY\n23XD26 - OBJECT COMPUTING LABORATORY\n23XD27 - DATA STRUCTURES LABORATORY\n23XD28 - PYTHON PROGRAMMING LABORATORY\n\n";
            }
            cout << "\n\n<Back>";
            getch();
        }

        void viewAttendance()
        {
            ifstream attendanceFile("attendance.txt");
            string line;
            int flag = 0;
            if(attendanceFile)
            {
                while (getline(attendanceFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        flag = 1;
                        istringstream istreamline(line);
                        string indAttendance;
                        getline(istreamline, indAttendance, ',');
                        for (int i = 0; i < 8; i++)
                        {
                            getline(istreamline, indAttendance, ',');
                            attendance[i] = stoi(indAttendance);
                        }
                        cout << "Attendance: " << endl;
                        for (int i = 0; i < 8; i++)
                        {
                            cout << courses(rollno,i) << " - " << attendance[i] << "\n";
                        }
                        cout << endl;
                        break;
                    }
                }
                attendanceFile.close();
            }
            cout << "\n\n<Back>";
            getch();
        }

        void viewCAMarks()
        {
            ifstream attendanceFile("camarks.txt");
            string line;
            int flag = 0;
            if(attendanceFile)
                {
                while (getline(attendanceFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        flag = 1;
                        istringstream istreamline(line);
                        string indAttendance;
                        getline(istreamline, indAttendance, ',');
                        for (int i = 0; i < 8; i++)
                        {
                            getline(istreamline, indAttendance, ',');
                            attendance[i] = stoi(indAttendance);
                        }
                        cout << "CA Marks: " << endl;
                        for (int i = 0; i < 8; i++)
                        {
                            cout << courses(rollno,i) << " - " << attendance[i] << "\n";
                        }
                        cout << endl;
                        break;
                    }
                }
                attendanceFile.close();
            }
            cout << "\n\n<Back>";
            getch();
        }

        void viewSemesterMarks()
        {
            ifstream attendanceFile("semmarks.txt");
            string line;
            int flag = 0;
            if(attendanceFile)
            {
                while (getline(attendanceFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        flag = 1;
                        istringstream istreamline(line);
                        string indAttendance;
                        getline(istreamline, indAttendance, ',');
                        for (int i = 0; i < 8; i++)
                        {
                            getline(istreamline, indAttendance, ',');
                            attendance[i] = stoi(indAttendance);
                        }
                        cout << "Semester Marks: " << endl;
                        for (int i = 0; i < 8; i++)
                        {
                            cout << courses(rollno,i) << " - " << attendance[i] << "\n";
                        }
                        cout << endl;
                        break;
                    }
                }
                attendanceFile.close();
            }
            cout << "\n\n<Back>";
            getch();
        }

        void leaveEntry()
        {
            string startDate,endDate,reason;
            cout << "Enter start date of leave (DD/MM/YYYY): ";
            cin >> startDate;
            cout << "Enter end date of leave (DD/MM/YYYY): ";
            cin >> endDate;
            cout << "Enter reason for leave: ";
            cin.ignore();
            getline(cin, reason);

            ofstream leaveFile("leaves.txt", ios::app);
            if(leaveFile)
            {
                leaveFile << rollno << ',' << name << ',' << startDate << ',' << endDate << ',' << reason << endl;
                leaveFile.close();
                cout << "Leave entry saved successfully." << endl;
            }

            cout << "\n\n<Back>";
            getch();
        }

        void changePassword1()
        {
            cout << "Enter new password: ";
            string password1;
            char ch;
            while (1)
            {
                ch = getch();
                if(ch == 13)
                    break;
                else
                {
                    cout << "*";
                    password1 = password1 + ch;
                }
                ifstream studentFile("students.txt");
            ofstream tempFile("temp.txt");

            int flag = 0;
            string line;

            if(studentFile && tempFile)
            {
                while (getline(studentFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno2)
                    {
                        istringstream istreamline(line);
                        string indAttendance;
                        string details[9];
                        for (int i = 0; i < 9; i++)
                        {
                            getline(istreamline, indAttendance, ',');
                            details[i] = indAttendance;
                        }

                        tempFile << details[0] << ',' << details[1] << ',' << details[2] << ',' << details[3] << ',' << details[4] << ',' << details[5] << ',' << details[6] << ',' << details[7] << ',' << password1 << endl;
                    }
                    else
                    {
                        tempFile << line << endl;
                    }

            }

                studentFile.close();
                tempFile.close();

                remove("students.txt");
                rename("temp.txt", "students.txt");

                if(flag)
                {
                    cout << "Student details modified successfully." << endl;
                }
            }
            }
            password = password1 + '\0';
            cout << "\n\n<Back>";
            getch();
        }

        void studentMenu()
        {
            clear();
            colourblue();
            int choice1 = 0;
            char option1;

            cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
            cout <<  left << setw(26) << "<1.View Details>" << setw(26) << " 2.View Timetable " << setw(26) << " 3.View Attendance " << setw(26) << " 4.View CA Marks " << setw(26) << " 5.View Semester Marks " << setw(26) << " 6.Leave Entry " << setw(26) << " 7.Change Password " << setw(26) << " 8.Logout " << endl;

            while(1)
            {
                option1=getch();
                if(option1==77)
                    choice1=(choice1+1)%8;
                else if(option1==75)
                    choice1=(choice1+7)%8;
                else if(option1==13)
                {
                    clear();
                    break;
                }

                switch(choice1)
                {
                    case 0:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << "<1.View Details>" << setw(26) << " 2.View Timetable " << setw(26) << " 3.View Attendance " << setw(26) << " 4.View CA Marks " << setw(26) << " 5.View Semester Marks " << setw(26) << " 6.Leave Entry " << setw(26) << " 7.Change Password " << setw(26) << " 8.Logout " << endl;
                        break;
                    case 1:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << " 1.View Details " << setw(26) << "<2.View Timetable>" << setw(26) << " 3.View Attendance " << setw(26) << " 4.View CA Marks " << setw(26) << " 5.View Semester Marks " << setw(26) << " 6.Leave Entry " << setw(26) << " 7.Change Password " << setw(26) << " 8.Logout " << endl;
                        break;
                    case 2:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << " 1.View Details " << setw(26) << " 2.View Timetable " << setw(26) << "<3.View Attendance>" << setw(26) << " 4.View CA Marks " << setw(26) << " 5.View Semester Marks " << setw(26) << " 6.Leave Entry " << setw(26) << " 7.Change Password " << setw(26) << " 8.Logout " << endl;
                        break;
                    case 3:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << " 1.View Details " << setw(26) << " 2.View Timetable " << setw(26) << " 3.View Attendance " << setw(26) << "<4.View CA Marks>" << setw(26) << " 5.View Semester Marks " << setw(26) << " 6.Leave Entry " << setw(26) << " 7.Change Password " << setw(26) << " 8.Logout " << endl;
                        break;
                    case 4:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << " 1.View Details " << setw(26) << " 2.View Timetable " << setw(26) << " 3.View Attendance " << setw(26) << " 4.View CA Marks " << setw(26) << "<5.View Semester Marks>" << setw(26) << " 6.Leave Entry " << setw(26) << " 7.Change Password " << setw(26) << " 8.Logout " << endl;
                        break;
                    case 5:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << " 1.View Details " << setw(26) << " 2.View Timetable " << setw(26) << " 3.View Attendance " << setw(26) << " 4.View CA Marks " << setw(26) << " 5.View Semester Marks " << setw(26) << "<6.Leave Entry>" << setw(26) << " 7.Change Password " << setw(26) << " 8.Logout " << endl;
                        break;
                    case 6:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << " 1.View Details " << setw(26) << " 2.View Timetable " << setw(26) << " 3.View Attendance " << setw(26) << " 4.View CA Marks " << setw(26) << " 5.View Semester Marks " << setw(26) << " 6.Leave Entry " << setw(26) << "<7.Change Password>" << setw(26) << " 8.Logout " << endl;
                        break;
                    case 7:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tSTUDENT ZONE\n" << endl;
                        cout <<  left << setw(26) << " 1.View Details " << setw(26) << " 2.View Timetable " << setw(26) << " 3.View Attendance " << setw(26) << " 4.View CA Marks " << setw(26) << " 5.View Semester Marks " << setw(26) << " 6.Leave Entry " << setw(26) << " 7.Change Password " << setw(26) << "<8.Logout>" << endl;
                        break;
                }
            }
            colourorange();
            switch (choice1)
            {
                case 0:
                    clear();
                    viewDetails();
                    studentMenu();
                    break;
                case 1:
                    clear();
                    viewTimetable();
                    studentMenu();
                    break;
                case 2:
                    clear();
                    viewAttendance();
                    studentMenu();
                    break;
                case 3:
                    clear();
                    viewCAMarks();
                    studentMenu();
                    break;
                case 4:
                    clear();
                    viewSemesterMarks();
                    studentMenu();
                    break;
                case 5:
                    clear();
                    leaveEntry();
                    studentMenu();
                    break;
                case 6:
                    clear();
                    changePassword1();
                    studentMenu();
                    break;
                case 7:
                    clear();
                    choices();
                    break;
            }

            cout << "\n\n<Back>";
            getch();
        }
        string getpass(){
            return password;
        }

    friend int checkrollpass(Student &,string,string);
};

int checkrollpass(Student &student,string rollno1,string password1)
{
    if(rollno1 == student.rollno && password1 == student.getpass())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Admin : public Person
{
    public:
        Admin():Person(" ","Admin1","admn@gmail.com","0","Applied Mathematics and Computational Sciences","N/A", " ")
        {
            rollno = "ADMN1";
            password = "10";
        }

        void viewDetails()
        {
            Person::viewDetails();
            cout << "Admin ID: " << rollno << endl;
            cout << "Password: " << password << endl;
            cout << "\n\n<Back>";
            getch();
        }

        void addStudent()
        {
            string rollno, name, email, phone, department, resident, batch, programme, password;
            cout << "Enter roll number: ";
            cin >> rollno;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter phone: ";
            cin >> phone;
            cin.ignore();
            cout << "Enter department: ";
            getline(cin,department);
            cout << "Enter resident status: ";
            cin.ignore();
            getline(cin,resident);
            cout << "Enter batch: ";
            cin >> batch;
            cout << "Enter programme: ";
            cin.ignore();
            getline(cin,programme);
            cout << "Enter password: ";
            cin >> password;

            Student newStudent(rollno, name, email, phone, department, resident, password, batch, programme);

            ofstream studentFile("students.txt", ios::app);
            if(studentFile)
            {
                studentFile << rollno << ',' << name << ',' << email << ',' << phone << ',' << department << ',' << resident << ',' << batch << ',' << programme << ',' << password << endl;
                studentFile.close();
                cout << "Student added successfully." << endl;
            }

            ofstream attendanceFile("attendance.txt",ios::app);
            ofstream caFile("camarks.txt",ios::app);
            ofstream semFile("semmarks.txt",ios::app);

            attendanceFile << rollno;
            caFile << rollno;
            semFile << rollno;

            int newAttendance[8] = {0,0,0,0,0,0,0,0};
            for (int i = 0; i < 8; i++)
            {
                attendanceFile << "," << newAttendance[i];
                caFile << "," << newAttendance[i];
                semFile << "," << newAttendance[i];
            }
            attendanceFile << endl;
            cout << "\n\n<Back>";
            getch();
        }

        void updateAttendance()
        {
            string rollno;
            cout << "Enter roll number of student to update attendance: ";
            cin >> rollno;

            ifstream attendanceFile("attendance.txt");
            ofstream tempFile("temp.txt");

            int flag = 0;
            string line;

            if(attendanceFile && tempFile)
            {
                while (getline(attendanceFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        line = line.substr(line.find(',') + 1);
                        flag = 1;
                        cout << "Current attendance: " << line << endl;

                        cout << "Enter new attendance: " << endl;
                        float newAttendance[8];
                        for (int i = 0; i < 8; i++)
                        {
                            cout << courses(rollno,i) << " - ";
                            cin >> newAttendance[i];
                        }

                        tempFile << rollno;
                        for (int i = 0; i < 8; i++)
                        {
                            tempFile << "," << newAttendance[i];
                        }
                        tempFile << endl;
                    }
                    else
                    {
                        tempFile << line << endl;
                    }
                }

                attendanceFile.close();
                tempFile.close();

                remove("attendance.txt");
                rename("temp.txt", "attendance.txt");

                if(flag)
                {
                    cout << "Attendance updated successfully." << endl;
                }

                cout << "\n\n<Back>";
                getch();
            }
        }

        void updateCAMarks()
        {
            string rollno;
            cout << "Enter roll number of student to update attendance: ";
            cin >> rollno;

            ifstream caFile("camarks.txt");
            ofstream tempFile("temp.txt");

            int flag = 0;
            string line;

            if(caFile && tempFile)
            {
                while (getline(caFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        flag = 1;
                        cout << "Enter CA marks: " << endl;
                        float newCAMarks[8];
                        for (int i = 0; i < 8; i++)
                        {
                            cout << courses(rollno,i) << " - ";
                            cin >> newCAMarks[i];
                        }

                        tempFile << rollno;
                        for (int i = 0; i < 8; i++)
                        {
                            tempFile << "," << newCAMarks[i];
                        }
                        tempFile << endl;
                    }
                    else
                    {
                        tempFile << line << endl;
                    }
                }

                caFile.close();
                tempFile.close();

                remove("camarks.txt");
                rename("temp.txt", "camarks.txt");

                if(flag)
                {
                    cout << "CA Marks updated successfully." << endl;
                }
            }

            cout << "\n\n<Back>";
            getch();
        }

        void updateSemesterMarks()
        {
            string rollno;
            cout << "Enter roll number of student to update Semester Marks: ";
            cin >> rollno;

            ifstream semFile("semmarks.txt");
            ofstream tempFile("temp.txt");

            int flag = 0;
            string line;

            if(semFile && tempFile)
            {
                while (getline(semFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        flag = 1;
                        cout << "Enter Semester Marks: " << endl;
                        float newAttendance[8];
                        for (int i = 0; i < 8; i++)
                        {
                            cout << courses(rollno,i) << " - ";
                            cin >> newAttendance[i];
                        }

                        tempFile << rollno;
                        for (int i = 0; i < 8; i++)
                        {
                            tempFile << "," << newAttendance[i];
                        }
                        tempFile << endl;
                    }
                    else
                    {
                        tempFile << line << endl;
                    }
                }

                semFile.close();
                tempFile.close();

                remove("semmarks.txt");
                rename("temp.txt", "semmarks.txt");

                if(flag)
                {
                    cout << "Semester Marks updated successfully." << endl;
                }

                cout << "\n\n<Back>";
                getch();
            }
        }

        void deleteStudent()
        {
            string rollno;
            cout << "Enter roll number: ";
            cin >> rollno;

            ifstream studentFile("students.txt");
            ofstream tempFile("temp.txt");

            int flag = 0;
            string line;

            if(studentFile && tempFile)
            {
                while (getline(studentFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        flag = 1;
                        continue;
                    }
                    tempFile << line << endl;
                }

                studentFile.close();
                tempFile.close();

                remove("students.txt");
                rename("temp.txt", "students.txt");

            }

            cout << "\n\n<Back>";
            getch();
        }

        void modifyStudent()
        {
            string rollno;
            cout << "Enter roll number: ";
            cin >> rollno;

            ifstream studentFile("students.txt");
            ofstream tempFile("temp.txt");

            int flag = 0;
            string line;

            if(studentFile && tempFile)
            {
                while (getline(studentFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        istringstream istreamline(line);
                        string indAttendance;
                        string details[9];
                        for (int i = 0; i < 9; i++)
                        {
                            getline(istreamline, indAttendance, ',');
                            details[i] = indAttendance;
                        }
                        flag = 1;
                        cout << "Current details: " << endl;
                        cout << "Roll Number: " << details[0] << endl;
                        cout << "Name: " << details[1] << endl;
                        cout << "Email: " << details[2] << endl;
                        cout << "Phone: " << details[3] << endl;
                        cout << "Department: " << details[4] << endl;
                        cout << "Resident Status: " << details[5] << endl;
                        cout << "Batch: " << details[6] << endl;
                        cout << "Programme: " << details[7] << endl;

                        cout << endl << "New details: " << endl;
                        string name, email, phone, department, resident, batch, programme, password;
                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter new email: ";
                        cin >> email;
                        cout << "Enter new phone: ";
                        cin >> phone;
                        cout << "Enter new department: ";
                        cin.ignore();
                        getline(cin,department);
                        cout << "Enter new resident status: ";
                        cin.ignore();
                        getline(cin,resident);
                        cout << "Enter new batch: ";
                        cin >> batch;
                        cout << "Enter new programme: ";
                        cin.ignore();
                        getline(cin,programme);

                        tempFile << rollno << ',' << name << ',' << email << ',' << phone << ',' << department << ',' << resident << ',' << batch << ',' << programme << ',' << details[8]<< endl;
                    }
                    else
                    {
                        tempFile << line << endl;
                    }
                }

                studentFile.close();
                tempFile.close();

                remove("students.txt");
                rename("temp.txt", "students.txt");

                if(flag)
                {
                    cout << "Student details modified successfully." << endl;
                }
            }

            cout << "\n\n<Back>";
            getch();
        }


        void viewAllStudents()
        {
            ifstream studentFile("students.txt");

            if(studentFile)
            {
                cout << "Students:" << endl;
                string line;

                while (getline(studentFile, line))
                {
                    string name = line.substr(line.find(',') + 1);
                    name = name.substr(0, name.find(','));
                    cout << name << endl;
                }

                studentFile.close();
            }

            cout << "\n\n<Back>";
            getch();
        }

        void searchStudent()
        {
            string rollno;
            cout << "Enter roll number: ";
            cin >> rollno;

            ifstream studentFile("students.txt");

            if(studentFile)
            {
                int flag = 0;
                string line;

                while (getline(studentFile, line))
                {
                    if(line.substr(0, line.find(',')) == rollno)
                    {
                        flag = 1;
                        cout << "Student details: " << line << endl;
                        break;
                    }
                }

                studentFile.close();

            cout << "\n\n<Back>";
            getch();
            }
        }

        void viewStudentsInClass()
        {
            string programme,programme1;
            cout << "Enter programme: ";
            getline(cin,programme);

            ifstream studentFile("students.txt");

            if(studentFile)
            {
                cout << "Students in " << programme << ":" << endl;
                string line;

                if(programme == "tcs")
                {
                    programme1 = "t";
                }
                else if(programme == "ss")
                {
                    programme1 = "w";
                }
                else if(programme == "cs")
                {
                    programme1 = "c";
                }
                else if(programme == "ds")
                {
                    programme1 = "d";
                }

                while (getline(studentFile, line))
                {
                    if(line.find("p"+programme1) != string::npos)
                    {
                        string name = line.substr(line.find(',') + 1);
                        name = name.substr(0, name.find(','));
                        cout << name << endl;
                    }
                }

                studentFile.close();
            }

            cout << "\n\n<Back>";
            getch();
        }
        void viewAllLeaves()
        {
            ifstream leaveFile("leaves.txt");

            if(leaveFile)
            {
                cout << "All leave entries:" << endl;
                string line;

                while (getline(leaveFile, line))
                {
                    cout << line << endl;
                }

                leaveFile.close();
            }

            cout << "\n\n<Back>";
            getch();
        }
        void changePassword()
        {
            cout << "Enter new password: ";
            string password1;
            char ch;
            while (1)
                {
                ch = getch();
                if(ch == 13)
                    break;
                else
                {
                    cout << "*";
                    password1 = password1 + ch;
                }
            }
            password = password1;

            cout << "\n\n<Back>";
            getch();

        }

        void adminMenu()
        {
            clear();
            colourblue();
            int choice1 = 0;
            char option1;

            cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
            cout << left << setw(26) <<"<1.Add Student>" << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;

            while(1)
            {
                option1=getch();
                if(option1==77)
                    choice1=(choice1+1)%12;
                else if(option1==75)
                    choice1=(choice1+11)%12;
                else if(option1==13)
                    break;
                switch(choice1)
                {
                    case 0:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << "<1.Add Student>" << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 1:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << "<2.Delete Student>" << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 2:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << "<3.Modify Student>" << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 3:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << "<4.Update Attendance>" << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 4:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << "<5.View All Students>" << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 5:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << "<3.Modify Student>" << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << "<6.Search a Student>" << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 6:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << "<4.Update Attendance>" << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << "<7.View Class Students>" << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 7:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << "<8.View All Leaves>" << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 8:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << "<9.Update CA Marks>" << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;
                    case 9:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << "<10.Update Semester Marks>" << setw(26) << " 11.Change Password " << setw(26) << " 12.Logout " << endl;
                        break;

                    case 10:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << "<11.Change Password>" << setw(26) << " 12.Logout " << endl;
                        break;

                    case 11:
                        clear();
                        cout << "\t\t\t\t\t\t\t\t\tADMIN ZONE\n" << endl;
                        cout << left << setw(26) << " 1.Add Student " << setw(26) << " 2.Delete Student " << setw(26) << " 3.Modify Student " << setw(26) << " 4.Update Attendance " << setw(26) << " 5.View All Students " << setw(26) << " 6.Search a Student " << setw(26) << " 7.View Class Students " << setw(26) << " 8.View All Leaves " << setw(26) << " 9.Update CA Marks " << setw(26) << " 10.Update Semester Marks " << setw(26) << " 11.Change Password " << setw(26) << "<12.Logout>" << endl;
                        break;
                }
            }
                colourorange();
                switch (choice1)
                {
                    case 0:
                        clear();
                        addStudent();
                        adminMenu();
                        break;
                    case 1:
                        clear();
                        deleteStudent();
                        adminMenu();
                        break;
                    case 2:
                        clear();
                        modifyStudent();
                        adminMenu();
                        break;
                    case 3:
                        clear();
                        updateAttendance();
                        adminMenu();
                        break;
                    case 4:
                        clear();
                        viewAllStudents();
                        adminMenu();
                        break;
                    case 5:
                        clear();
                        searchStudent();
                        adminMenu();
                        break;
                    case 6:
                        clear();
                        viewStudentsInClass();
                        adminMenu();
                        break;
                    case 7:
                        clear();
                        viewAllLeaves();
                        adminMenu();
                        break;
                    case 8:
                        clear();
                        updateCAMarks();
                        adminMenu();
                        break;
                    case 9:
                        clear();
                        updateSemesterMarks();
                        adminMenu();
                        break;
                    case 10:
                        clear();
                        changePassword();
                        adminMenu();
                        break;
                    case 11:
                        clear();
                        choices();
                        break;
                }
                cout << "\n\n<Back>";
                getch();
        }
};

void choices()
{
    clear();
    int choice = 0;
    char option;
    colourblue();
    cout<<"\t\t\t\t\t\t\t\tPSG COLLEGE OF TECHNOLOGY eCAMPUS LITE\n\n";
    cout<<"\t\t\t\t\t\t <1.Student Zone>  \t\t\t\t   2.Admin Zone\n";
    while(1)
    {
        option=getch();
        if(option==77||option==75)
        {
            choice=(choice+1)%2;
            clear();
            cout<<"\t\t\t\t\t\t\t\tPSG COLLEGE OF TECHNOLOGY eCAMPUS LITE\n\n";
            choice == 0 ? (cout<< "\t\t\t\t\t\t <1.Student Zone>  \t\t\t\t   2.Admin Zone\n") : (cout<< "\t\t\t\t\t\t  1.Student Zone   \t\t\t\t  <2.Admin Zone>\n");
        }
        else if(option==8)
        {
            choice=10;
            clear();
            break;
        }
        else if(option==13)
        {
            break;
        }
    }
    colourgreen();
    if(choice == 1)
    {
        clear();
        Admin admin;
        cout << "Enter admin password: ";
        string password1;
        char ch;
        while (1)
        {
            ch = getch();
            if(ch == 13)
                break;
            else
            {
                cout << "*";
                password1 = password1 + ch;
            }
        }
        //password1 = password1 + '\0';
        if(admin.verifyPassword(password1))
        {
            cout << "\n\n<Next>";
            getch();
            admin.adminMenu();
        }
        else
        {
            cout << "Invalid password!" << endl;
        }
    }
    else if(choice == 0)
    {
        clear();
        cout << "Enter roll number: ";
        string rollno;
        cin >> rollno;
        rollno2 = rollno;
        cout << "Enter password: ";
        string password;
        //cin >> password;
        char ch;
        while (1)
        {
            ch = getch();
            if(ch == 13)
                break;
            else
            {
                cout << "*";
                password = password + ch;
            }
        }
        //password = password + '\0';

        Student student;
        ifstream studentFile("students.txt");
        if(studentFile)
        {
            string line;
            while (getline(studentFile, line))
            {
                stringstream ss(line);
                string r, n, e, p, d, rs, b, prog, pw;
                getline(ss, r, ',');
                getline(ss, n, ',');
                getline(ss, e, ',');
                getline(ss, p, ',');
                getline(ss, d, ',');
                getline(ss, rs, ',');
                getline(ss, b, ',');
                getline(ss, prog, ',');
                getline(ss, pw, ',');
                student = Student(r, n, e, p, d, rs, pw, b, prog);
                if(checkrollpass(student,rollno,password))
                {
                    student = Student(r, n, e, p, d, rs, pw, b, prog);
                    cout << "\n\n<Next>";
                    getch();
                    student.studentMenu();

                }
                else
                {
                    clear();

                }
            }
            cout << endl << "Invalid roll number or password!" << endl;
        }
        else if(choice == 10)
        {
            clear();
            cout << "\t\t\t\t\t\t\t\tTHANK YOU VISIT AGAIN" << endl;
        }
        studentFile.close();
    }
}

int main()
{
    choices();
    return 0;
}
