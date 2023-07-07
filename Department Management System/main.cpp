#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <regex>


using namespace std;
struct User {
    string username;
    string password;
};

bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

bool Passcheck(string password)
{
    const regex pattern("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@#$%^&+=])(?=\\S+$).{8,}");
    return regex_match(password, pattern);
}

bool Coursecheck(string course)
{
    const regex pattern("^[A-Za-z][A-Za-z_]{3,29}$");
    return regex_match(course, pattern);
}
bool studentcheck(string name)
{
    const regex pattern("^[A-Za-z][A-Za-z_]{3,29}$");
    return regex_match(name, pattern);
}
// Function to check if a username already exists
bool isUsernameExists(const string& username) {
    ifstream file("users.txt"); //input mode in file
    string line;
    while (getline(file, line)) {
        if (line == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Function to create a new user account
void signUp() {
    User newUser;
    email:
     cout << "Enter E~mail ID: ";
    getline(cin, newUser.username);
    if (Emailcheck(newUser.username))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;
        goto email;
    }

    password:
    cout << "Enter password: ";
    getline(cin, newUser.password);
    if (Passcheck(newUser.password))
    {
        cout << "\t\t\t Your Password  is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Password is InValid \n\t\t\t please enter minimum 8 letters with atleast one Capital letter,small letter, interger, symbols  :)  " << endl;
        goto password;
    }

    if (isUsernameExists(newUser.username)) {
        cout << "Username already exists. Please try again with a different username.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << newUser.username << "\n";
    file << newUser.password << "\n";
    file.close();
    cout << "Account created successfully!\n";
}

// Function to validate login credentials
bool signIn() {


    User user;
    cout << "Enter registered E~mail ID: ";
    getline(cin, user.username);
    cout << "Enter password: ";
    getline(cin, user.password);

    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        if (line == user.username) {
            getline(file, line);
            if (line == user.password) {
                file.close();
                return true;
            }
            break;
        }
    }
    file.close();
    return false;
}




class dept
{
private:
    string course_name,name,course_code, roll_no, course, address, email_id,company,package,date;
    long long int contact_no;


public:

    void menu();
    void home_menu();
    void course_menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    void ctpg();
    void highlights();
    void lab();
    void lib();
    void log();
    void faculty();
    void jamunadevi();
    void maragatham();
    void placement();
    void add_plc();
    void display_plc();
    void delete_plc();
};
void dept::log()
{
    system("cls");
    cout << "\t\t\t ------------------------------------------" << endl;
    cout << "\t\t\t|        KONGU ENGINEERING COLLEGE         |" << endl;
    cout << "\t\t\t|              (AUTONOMOUS)                |" << endl;
    cout << "\t\t\t| Department of Computer Technology - PG   |" << endl;
    cout << "\t\t\t ------------------------------------------" << endl;
int choice;
    bool loggedIn = false;

    do {
        cout << "\n\n\n\n1. Sign Up\n";
        cout << "2. Sign In\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                loggedIn = signIn();
                if (loggedIn){
                    cout << "Login successful!\n";
                    menu();}
                else
                    cout << "Invalid credentials. Please try again.\n";
                break;
            case 3:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 3);
}
void dept::menu()
{
menustart:
    int choice;
    system("cls");
    cout << "\t\t\t ------------------------------------------" << endl;
    cout << "\t\t\t|        KONGU ENGINEERING COLLEGE         |" << endl;
    cout << "\t\t\t|              (AUTONOMOUS)                |" << endl;
    cout << "\t\t\t| Department of Computer Technology - PG   |" << endl;
    cout << "\t\t\t ------------------------------------------" << endl;
    cout << "\t\t\t 1. Home" << endl;
    cout << "\t\t\t 2. Course " << endl;
    cout << "\t\t\t 3. Faculty" << endl;
    cout << "\t\t\t 4. Placement Details" << endl;
    //cout << "\t\t\t 5. About" << endl;
    cout << "\t\t\t 5. Log Out\n"
         << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        home_menu();
        break;
    case 2:
        course_menu();
        break;
    case 3:
        faculty();
        break;
    case 4:
       placement();
        break;
    //case 5:
       // deleted();
     //   break;
    case 5:
        cout << "\n\t\t\t Program Is Exit";
        log();

           default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
}


void dept::home_menu()
{
menustart:
    int choice;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| Department Of Computer Technology - PG |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. CT PG" << endl;
    cout << "\t\t\t 2. Highlights " << endl;
    cout << "\t\t\t 3. Laboratories" << endl;
    cout << "\t\t\t 4. Department Library" << endl;
    cout << "\t\t\t 5. Back\n"
         << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
       ctpg();
        break;
    case 2:
        highlights();
        break;
    case 3:
        lab();
        break;
    case 4:
        lib();
        break;
    case 5:
        menu();
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
}
void dept::course_menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| Course Details |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Back \n"
         << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t Add Another Course Record (Y, N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        menu();
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
    }

    //DETAILS
void dept::ctpg() // Add CTPG details
{
    system("cls");
        cout << "\n\n<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COMPUTER TECHNOLOGY - PG ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << endl;
    cout << "\n\n\n Head Of The Department: " << endl;
    cout << "\n Dr.E.Gothai (wef. 04.05.2022) \n\n";
    cout << "\n\n Programmes Offered\n\n";
    cout << " Programme                             Intake\n";
    cout << " M.Sc Software Systems(5 years)          60";
    cout <<"\n\n\n\n Version\n   To become a technically competent centre in the domain of Computer Science to meet the changing needs of nation and beyond.";
    cout <<"\n\n\n\n Mission\n    Department of Computer Technology - PG is committed to:\n\n    M1:  Inculcate conceptual knowledge with profound practical and real time industry exposure to the students.";
    cout<<"\n    M2:  Nourish a learning ambience to enhance innovations, problem solving skills, leadership qualities, team-spirit and ethical responsibilities.\n    M3:  Vitalize the students to acquire entrepreneurial skills to become global leaders.";
    cout <<"\n\n\n\n Programme Educational Objectives\n    Graduate of Software Systems will:\n\n    PEO1:  Work productively as high competent software professionals with strong domain knowledge to develop smart solutions for the upliftment of society.";
    cout<<"\n    PEO2:  Emerge successful entrepreneurs with the strong business managerial skills.\n    PEO3:  Exhibit eternal improvement to enhance knowledge and skills through life-long learning appreciating human values and ethics.";
    cout <<"\n\n\n\n Programme Educational Objectives\n    Graduate of Software Systems will:\n";
    cout<<"\n\n    PO1    Computational knowledge:  Apply knowledge of mathematics and computing to the abstraction and conceptualization of computing models from defined problems and requirements.";
    cout<<"\n\n    PO2    Problem analysis: Identify, formulate and solve complex computing problems reaching substantiated conclusions using fundamental principles of mathematics and computer science.";
    cout<<"\n\n    PO3    Design/development of solutions: Design solutions for well defined computing problems and design systems components or processes that meet the specified needs with appropriate\n           consideration for public health and safety, cultural, societal and environmental considerations.";
    cout<<"\n\n    PO4    Conduct investigations of complex computing problems: Use research-based knowledge and research methods including design of experiments, analysis and interpretation of data and\n           synthesis of the information to provide valid conclusions.";
    cout<<"\n\n    PO5    Modern tool usage: Create, select and apply appropriate techniques, resources, and computing technologies necessary for computing practices.";
    cout<<"\n\n    PO6    Professional Ethics: Understand and practice professional ethics in multidisciplinary environments";
    cout<<"\n\n    PO7    Life-long learning: Recognize the need for and have the preparation and ability to engage in independent and life-long learning in the broadest context of technological change.";
    cout<<"\n\n    PO8    Project management and finance: Demonstrate knowledge and understanding of the computing and management principles and apply these to one’s own work, as a member and leader in\n           a team, to manage projects in multidisciplinary environments.";
    cout<<"\n\n    PO9    Communication Efficacy: Communicate effectively on broadly defined computing community and with society by being able to comprehend and write effective reports, design documentation\n           and make effective presentations.";
    cout<<"\n\n    PO10   Societal and Environmental Concern: Understand and assess societal, environmental, health, safety, legal and cultural issues within local and global contexts and the consequential\n           responsibilities relevant to professional computing practice.";
    cout<<"\n\n    PO11   Individual and team work: Function effectively as an individual and as a member or leader in diverse technical teams.";
    cout<<"\n\n    PO12   Innovation and Entrepreneurship: Identify a timely opportunity and using innovation to pursue that opportunity to create value and wealth to succeed as an employee or an entrepreneur.";
}


void dept::highlights() // Highlights details
{
    system("cls");
cout << "\n\n<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Highlights ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << endl;
cout << "\n\n\n Highlights " << endl;
cout<<"\n\n     1)   Papers published in SCI and Scopus Journals.\n\n     2)   Actively involved in consultancy activities with various industries and generated Rs.5,02,022.\n\n     3)   Six faculty members completed PhD and 9 faculty members are pursuing PhD.";
cout<<"\n\n     4)   Two approved supervisors with 11 scholars pursuing and 35 scholars completed Ph.D.\n\n     5)   Completed tworesearch projects sponsored by AICTE and UGC.\n\n     6)   Eleven books published.";
cout<<"\n\n     7)   Organized Seminar / workshops/Short Term Training Programmes (STTP)/Faculty Development Programmes (FDP) sponsored by various funding agencies like AICTE, DST, ICMR, DRDO, CSIR, NBHM,\n          DIT, INSA, MoEF, MNRE.";
cout<<"\n\n     8)   Internship opportunities for students with stipend in 7 th and 10 th standard.\n\n     9)   MOU Signed with\n             +   Aalam Info Solutions\n             +   Government Arts and Science College, Kangeyam\n             +   BTS Infotech\n             +   Geniuscrate Edutainment Pvt Ltd\n             +   Exalca Technologies Private Limited\n             +   SW Elegance\n             +   Nitroware Technologies\n             +   LITZ Tech India Private Limited\n             +   Teal Orca web agency\n";
}

void dept::lab() // Laboratories  details
{
    system("cls");
cout << "\n\n<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Laboratories ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << endl;
cout << "\n\n\n LABORATORY FACILITIES " << endl;
cout<<"\n\n     1)   Computer laboratory is furnished with 125 Computer Systems and one Server worth INR. 49, 70,535 to cater the needs of the students.\n\n     2)   The FTP Server is installed with UBUNTU.\n\n     3)   Students can develop simple software using C, C++, Java and Microsoft Visual Studio.";
cout<<"\n\n     4)   Oracle 10G Client is installed for Relational Database Management Laboratory ­to create and interact with database.\n\n     5)   Students can design and develop software using Rational Rose and other software development tools.\n\n     6)   Students can design and develop interactive web page using HTML, CSS, Java Script, J2EE and .Net Framework Technologies.";
cout<<"\n\n     7)   Provide practical exposure on Linux platform by creating and executing applications using gcc compiler.\n\n     8)   Cloud Computing Techniques are imparted to the students using Free and Open source software like Virtual Box.\n\n     9)   Students can analyze and simulate testing methodologies using testing frameworks such as Selenium, JUnit.\n\n     10)  The Free and Open source software is downloaded and customized to meet the requirements of the software design methodologies.";
}


void dept::lib() // Department Library  details
{
    system("cls");
cout << "\n\n<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Department Library ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << endl;
cout << "\n\n\n COMPUTER TECHNOLOGY PG " << endl;
cout<<"\n\n       The Computer Technology PG department has a separate library to cater to the specific needs of the Computer Application students. The following is the consolidated data related to the\n       department library.\n\n";
cout<<"\n\n\n       No. Of Titles Of the Books          	           	275\n\n       No. of International Journals          	           	 10\n\n       No. of National Journals          	           	  5";
}

void dept::insert() // Add Course details
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Course Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Course Name: ";
    cin >> course_name;
    cout << "\t\t\tEnter Course Code: ";
    cin >> course_code;

    course:
    cout << "\t\t\tEnter Faculity Name(OnlY Letters): ";
    cin >> course;
    if (Coursecheck(course))
    {
        cout << "\t\t\t Your Faculity name is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Faculity name is InValid" << endl;
        goto course;
    }
email:
    cout << "\t\t\tEnter Faculity Email Id(pravin@gmail.com): ";
    cin >> email_id;
    if (Emailcheck(email_id))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;
        goto email;
    }
contact:
    cout << "\t\t\tEnter Contact No(9360xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    cout << "\t\t\tEnter Course Details: ";
    cin >> address;
    file.open("CourseRecord.txt", ios::app | ios::out);// ios input output screen,  app:append
    file << " " << course_name << " " << course_code << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}
void dept::display() // Display data in courses
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Course Record Table --------------------------------------------" << endl;
    file.open("CourseRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
        while (!file.eof())// end of file
        {
            cout << "\n\n\t\t\tCourse No.: " << total++ << endl;
            cout << "\t\t\tCourse Name: " << course_name << "\n";
            cout << "\t\t\tCourse Code.: " << course_code << "\n";
            cout << "\t\t\tFaculity Name: " << course << "\n";
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            cout << "\t\t\tCourse Details: " << address << "\n";
            file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void dept::modify() // Modify details of course
{
    system("cls");
    fstream file, file1;
    string courses_code;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Course Modify Details ------------------------------------------" << endl;
    file.open("CourseRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter of Course Code which you want to Modify: ";
        cin >> courses_code;
        file1.open("record.txt", ios::app | ios::out);
        file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (courses_code != course_code)
                file1 << " " << course_name << " " << course_code << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Course Name: ";
                cin >> course_name;
                cout << "\t\t\tEnter Course Code: ";
                cin >> course_code;
                cout << "\t\t\tEnter Faculity Name: ";
                cin >> course;
            email:
                cout << "\t\t\tEnter Email Id(pravin@gmail.com): ";
                cin >> email_id;
                if (Emailcheck(email_id))
                {
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }
                else
                {
                    cout << "\t\t\t Your Email-Id is InValid" << endl;
                    goto email;
                }
            contact:
                cout << "\t\t\tEnter Contact No(9360xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999)
                {
                    cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }
                cout << "\t\t\tCourse Details: ";
                cin >> address;
                file1 << " " << course_name << " " << course_code << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Course Code. Not Found....";
        }
        file1.close();
        file.close();
        remove("CourseRecord.txt");
        rename("record.txt", "CourseRecord.txt");
    }
}

void dept::search() // search data of courses
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("CourseRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Course Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string courses_code;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Course Search Table --------------------------------------------" << endl;
        cout << "\nEnter Course code of Course which you want to search: ";
        cin >> courses_code;
        file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (courses_code == course_code)
            {
                cout << "\n\n\t\t\tCourse Name: " << course_name << "\n";
                cout << "\t\t\tCourse Code: " << course_code << "\n";
                cout << "\t\t\tFaculity Name: " << course << "\n";
                cout << "\t\t\t Faculity Email Id: " << email_id << "\n";
                cout << "\t\t\t Contact No.: " << contact_no << "\n";
                cout << "\t\t\tCourse Details: " << address << "\n";
                found++;
            }
            file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\t\t\t Course Code. Not Found....";
            }
        }
        file.close();
    }
}
void dept::deleted() // ddeleted data of course
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string course1_code;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Course Details ------------------------------------------" << endl;
    file.open("CourseRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Course Code of the Course which you want Delete Data: ";
        cin >> course1_code;
        file1.open("record.txt", ios::app | ios::out);
        file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (course1_code != course_code)
            {
                file1 << " " << course_name << " " << course_code << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> course_name >> course_code >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Course Code. Not Found....";
        }
        file1.close();
        file.close();
        remove("CourseRecord.txt");
        rename("record.txt", "CourseRecord.txt");
    }
}

void dept::faculty()  // faculity details
{
menustart:
    int choice;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| Faculty Details |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1.  Dr.P.Ananthi" << endl;
    cout << "\t\t\t 2.  S.Deepa" << endl;
    cout << "\t\t\t 3.  C.Jamunadevi" << endl;
    cout << "\t\t\t 4.  M.Arumugam" << endl;
    cout << "\t\t\t 5.  S.Aruna" << endl;
    cout << "\t\t\t 6.  S.Hamsanandhini" << endl;
    cout << "\t\t\t 7.  P.Yuvarani" << endl;
    cout << "\t\t\t 8.  Dr.T.Maragatham" << endl;
    cout << "\t\t\t 9.  K.Karthika" << endl;
    cout << "\t\t\t 10. T.E.Ramya" << endl;
    cout << "\t\t\t 11. P.Shanmughapriya" << endl;
    cout << "\t\t\t 12. Dr.P.Ananthi" << endl;
    cout << "\t\t\t 13. C.Rukumani Khandhan" << endl;
    cout << "\t\t\t 14. Back \n"<< endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7/8/9/10/11/12/13/14]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:
        jamunadevi();
        break;
    case 4:

        break;
    case 5:

        break;
        case 6:

        break;
    case 7:

        break;
        case 8:
          maragatham();
        break;
    case 9:

        break;
        case 10:

        break;
    case 11:

        break;
        case 12:

        break;
    case 13:

        break;
    case 14:
        menu();
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
    }

    void dept::jamunadevi() // Highlights details
{
    system("cls");
cout << "\n\n<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C.Jamunadevi   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << endl;
cout << "\n\n\n KEC Faculty Profile " << endl;
cout<<"\n\n     Name                                            C.Jamunadevi\n\n     Department                                      Computer Technology-PG\n\n     Qualification                                   MSc., MPhil\n\n     Area of Specialization                          Big Data Analytics\n\n     Date of Joining KEC                             13-06-2008\n\n     Experience in (Years)                           18\n\n     Number of Papers Published                      9\n\n     Number of Papers Presented                      27\n\n                                           Teching:                 14\n\n                                           Industry:                --\n\n                                           Others:                  --\n\n\n\n\n                                           International Journals:                 9\n\n                                           National Conferences:                   6\n\n                                           International Conferences:              22\n\n\n\n     Number of Consultancy Projects                          30";
cout<<"\n\n     Contact Details\n\n            ============================================\n            |                                          |\n            |   Email:        	cjamuna@kongu.ac.in    |\n            |                                          |\n            |   Mobile:        	9952650001             |\n            |                                          |\n            |   Office:        	04294-226582           |\n            |                                          |\n            |   Intercom:       586                    |\n            ============================================";
}
void dept::maragatham() // Highlights details
{
    system("cls");
cout << "\n\n<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Dr.T.Maragatham ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>" << endl;
cout << "\n\n\n KEC Faculty Profile " << endl;
cout<<"\n\n     Name                                            Dr.T.Maragatham\n\n     Department                                      Computer Technology-PG\n\n     Qualification                                   MSc., MPhil\n\n     Area of Specialization                          Data Structures, Operating System, Database Management Systems\n\n     Date of Joining KEC                             05-06-2017\n\n     Experience in (Years)                           7\n\n     Number of Papers Published                      --\n\n     Number of Papers Presented                      --\n\n                                           Teching:                 12\n\n                                           Industry:                --\n\n                                           Others:                  --\n\n\n\n\n                                           International Journals:                 6\n\n                                           National Conferences:                   8\n\n                                           International Conferences:              4\n\n\n\n     Number of Consultancy Projects                          5";
cout<<"\n\n     Contact Details\n\n            =====================================================\n            |                                                   |\n            |   Email:        	tmaragatham.ctpg@kongu.ac.in    |\n            |                                                   |\n            |   Mobile:        	9942697597                      |\n            |                                                   |\n            |   Office:        	04294-226582                    |\n            |                                                   |\n            |   Intercom:       582                             |\n            =====================================================";
}

void dept::placement()
{
menustart:
    char x;
    int choice;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| Student Placement Details |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Add Details" << endl;
    cout << "\t\t\t 2. Display Details" << endl;
    cout << "\t\t\t 3. Delete Details" << endl;
    cout << "\t\t\t 4. Back \n"
         << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            add_plc();
            cout << "\n\n\t\t\t Add Another Course Record (Y, N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display_plc();
        break;
    case 3:
         delete_plc();
        break;
    case 4:
        menu();
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
    }

void dept::add_plc() // Add placement details
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Placed Student Details ---------------------------------------------" << endl;
     name:
      cout << "\t\t\tEnter Student Name: ";
    cin >> name;
    if (studentcheck(name))
    {
        cout << "\t\t\t Your Student name is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Student name is InValid" << endl;
        goto name;
    }

    cout << "\t\t\tEnter Student Roll Number: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Company Name: ";
    cin >> company ;

   contact:
    cout << "\t\t\tEnter Contact No(9360xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    cout << "\t\t\tEnter Package (eg:5LPA) ";
    cin >> package;
    int day,month,year;

  cout<<"Enter the date (Day Month Year) : \n";

  cin>>day>>month>>year;

  if(1000 <= year <= 3000)
       {
         if((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12) && day>0 && day<=31)
         cout<<"It is valid";
         else
     if(month==4 || month==6 || month==9|| month==11 && day>0 && day<=30)
            cout<<"It is Valid";
         else
            if(month==2)
               {
               if((year%400==0 || (year%100!=0 && year%4==0)) && day>0 && day<=29)
                 cout<<"It is Valide";
               else if(day>0 && day<=28)
                  cout<<"It is Valid";
               else
                  cout<<"It is Invalid";
               }
         else
               cout<<"It is Invalid";
      }
    else
        cout<<"It is Invalid";

     cout << "\t\t\tEnter Date of Placed (29.06.2023) :";
     cin>>date;
//date=(day>>"/">>month>>"/">>year);
    cout << "\n\t\t\tEnter Company Location: ";
    cin >> address;
    file.open("PlacementRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << company << " " << contact_no << " "<< package<<" " <<date<<" "<< address << "\n";
    file.close();
}

void dept::display_plc() // Display data of student
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Placed Student Details --------------------------------------------" << endl;
    file.open("PlacementRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> company >>  contact_no >> package>> date >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tS.no: " << total++ << endl;
            cout << "\t\t\tStudent Name : " << name << "\n";
            cout << "\t\t\tStudent Roll Num : " << roll_no << "\n";
            cout << "\t\t\tCompany Name : " << company << "\n";
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            cout <<"\t\t\tPackage : "<<package<<"\n";
            cout<<"\t\t\tDate of Placed : "<<date<<"\n";
            cout << "\t\t\tLocation : " << address << "\n";
            file >> name >> roll_no >> company >> contact_no >>package>>date>> address;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void dept::delete_plc() // deleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Placed Details ------------------------------------------" << endl;
    file.open("PlacementRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll Number of the Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record1.txt", ios::app | ios::out);
        file >> name >> roll_no >> company >> contact_no >> package >>date>> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << company << " " << contact_no<<" "<<package<<" " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> company >> contact_no >> package >> date>>address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Roll Number . Not Found....";
        }
        file1.close();
        file.close();
        remove("PlacementRecord.txt");
        rename("record1.txt", "PlacementRecord.txt");
    }
}
int main()
{
    dept project;

    // object
      //object calling
    project.log();
    project.home_menu();
    project.course_menu();
    project.faculty();
    project.placement();

    return 0;
}
