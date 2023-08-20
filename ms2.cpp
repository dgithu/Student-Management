/*GROUP 11: -
Member 1: - Devangi Jayeshbhai Patel,  167437219, dpatel484@myseneca.ca
Member 2: - Mahi Kalpeshkumar Patel, 168283216, mpatel477@myseneca.ca
Member 3: - Aashna Kundra, 163028210, akundra5@myseneca.ca


*/

//Created by Devangi Patel, Student id:- 167437219
#include <iostream>
#include <occi.h>

using oracle::occi::Connection;
using oracle::occi::Environment;
using namespace oracle::occi;
using namespace std;

//created by Devangi patel, student id:- 167437219
struct ACADEMICRECORDS
{
    string n_ame;
    int id;
    string grades;
    string overallgpa;
    string email;
}; 

//created by Devangi patel, student id:- 167437219
   int findSTUDENT(Connection* conn, int id);
    void displaySTUDENT(Connection * conn);
    void displayAllSTUDENT(Connection * conn);

    //definition of functions
  
    //created by Devangi patel, student id:- 167437219
    int findSTUDENT(Connection* conn, int id)
    {
        Statement* stmt = conn->createStatement();
        ResultSet* rsss1 = stmt->executeQuery("SELECT name,id,grades,overallgpa,email FROM academicrecords WHERE id = " + to_string(id));

        if (rsss1->next())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    } 

    //created by Devangi patel, student id:- 167437219
     void displaySTUDENT(Connection* conn)
    {
        int ide;
        cout << "Enter Student ID" << endl;
        cin >> ide;
        cout << endl << endl << endl << endl;
        Statement* stmt = conn->createStatement();
        ResultSet* rsss2 = stmt->executeQuery("SELECT name,id,grades,overallgpa,email FROM academicrecords WHERE id = " + to_string(ide));
        cout << "----------------------------------STUDENT DETAILS------------------------------------" << endl;
      
        while (rsss2->next()) {
            
            cout << "Name: ";
            string n_ame = rsss2->getString(1);
            cout.width(20);
            cout << left << n_ame << " " << endl;
            cout << "id: ";
            int id = rsss2->getInt(2);
            cout.width(15);
            cout << left << id << " " << endl;
            cout << "grades: ";
            string grades = rsss2->getString(3);
            cout.width(15);
            cout << grades << " " << endl;
            cout << "overallgpa: ";
            string overallgpa = rsss2->getString(4);
            cout.width(15); 
            cout << overallgpa << " " << endl;
            cout << "email: ";
            string email = rsss2->getString(5);
            cout.width(30);
            cout << email << " " << endl;

        }

    }  

    //created by Devangi patel, student id:- 167437219
     void displayAllSTUDENT(Connection* conn)
    {
        Statement* stmt = conn->createStatement();
        ResultSet* rsss3 = stmt->executeQuery("SELECT name,id,grades,overallgpa,email FROM academicrecords");
        cout << "----------------------------------- All Student Details---------------------------" << endl << endl;
        
        cout << "# name                id            grades         overallgpa         email" << endl;
        while (rsss3->next()) {
            string n_ame = rsss3->getString(1);
            int id = rsss3->getInt(2);
            string grades = rsss3->getString(3);
            string overallgpa = rsss3->getString(4);
            string email = rsss3->getString(5);
            cout.width(20);
            cout << left << n_ame << " ";
            cout.width(15);
            cout << left << id << " ";
            cout.width(15);
            cout << grades << " ";
            cout.width(15);
            cout << overallgpa << " ";
            cout.width(30);
            cout << email << " " << endl;

        }
    } 
  
    //main function starts

     int main(void)
    {
       
        Environment* env = nullptr;
        Connection* conn = nullptr;
        string usr = "dbs211_223nff22"; // this is your login assigned to you
        string pass = "34602762"; // this is your password assigned to you
        string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(usr, pass, srv);

        int input = 0;
        do
        {
            cout << "\n\n\n\n STUDENT RECORDS MANAGEMENT SYSTEM APP" << endl;


            cout << "1. Find Student" << endl;
            cout << "2. Display a Student Detail" << endl;
            cout << "3. Display all Student Detail" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice ";
            cin >> input;

            if (input == 1)
            {
                cout << "Entering choice to find a student" << endl;
                int no;
                cout << "Enter Student ID" << endl;
                cin >> no;
                if (findSTUDENT(conn, no) == 1)
                {
                    cout << " Valid Student ID" << endl;
                }
                else
                {
                    cout << "There is no student details to be displayed" << endl;
                }
            }
            else if (input == 2)
            {
                cout << "Entering choice to display a Student Detail" << endl;
                
                    displaySTUDENT(conn);
            }
            else if (input == 3)
            {
                cout << "Entering choice to display All Student Details" << endl;
                displayAllSTUDENT(conn);
            }
            else if (input == 4)
            {
                exit(0);
            }
            else if (input == 0)
            {
                exit(0);
            }
        } while (input != 5);



    }  


    
 // Created By Mahi Patel, Student Id:- 168283216



 #include <iostream>
#include <occi.h>

    using oracle::occi::Connection;
    using oracle::occi::Environment;
    using namespace oracle::occi;
    using namespace std;

    struct PROGRAMS
    {
        string programcode;
        int student_id;
        string programname;
        string department;
        string duration;
        string availability;
    };


    int findSTUDENTPG(Connection* conn, int student_id);
    void displaySTUDENTPG(Connection* conn);
    void displayAllSTUDENTPG(Connection* conn);

    //definition of functions

    int findSTUDENTPG(Connection* conn, int student_id)
    {
        Statement* stmt = conn->createStatement();
        ResultSet* rsss1 = stmt->executeQuery("SELECT programcode,student_id, programname, department, duration, availability from programs WHERE student_id = " + to_string(student_id));

        if (rsss1->next())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void displaySTUDENTPG(Connection* conn)
    {
        int ide;
        cout << "Enter the id  ";
        cin >> ide;
        cout << endl << endl << endl << endl;
        Statement* stmt = conn->createStatement();
        ResultSet* rsss2 = stmt->executeQuery("SELECT programcode,student_id, programname, department, duration, availability from programs WHERE student_id = " + to_string(ide));
        cout << "----------------------------------STUDENT DETAILS------------------------------------" << endl;

        while (rsss2->next()) {

            cout << "Programcode: ";
            string programcode = rsss2->getString(1);
            cout.width(20);
            cout << left << programcode << " " << endl;
            cout << "Student_Id: ";
            int student_id = rsss2->getInt(2);
            cout.width(15);
            cout << left << student_id << " " << endl;
            cout << "Programname: ";
            string programname = rsss2->getString(3);
            cout.width(50);
            cout << programname << " " << endl;
            cout << "Department: ";
            string department = rsss2->getString(4);
            cout.width(50);
            cout << department << " " << endl;
            cout << "Duration: ";
            string duration = rsss2->getString(5);
            cout.width(30);
            cout << duration << " " << endl;
            cout << "Availability: ";
            string availability = rsss2->getString(6);
            cout.width(30);
            cout << availability << " " << endl;

        }

    }
    void displayAllSTUDENTPG(Connection* conn)
    {
        Statement* stmt = conn->createStatement();
        ResultSet* rsss3 = stmt->executeQuery("SELECT programcode,student_id, programname, department, duration, availability from programs");
        cout << "----------------------------------- All Student Details---------------------------" << endl << endl;

        cout << " code" << endl;
        while (rsss3->next()) {
            string programcode = rsss3->getString(1);
            int student_id = rsss3->getInt(2);
            string programname = rsss3->getString(3);
            string department = rsss3->getString(4);
            string duration = rsss3->getString(5);
            string availability = rsss3->getString(6);

            cout.width(5);
            cout << left << programcode;
            cout.width(10);
            cout << left << student_id << " ";
            cout.width(45);
            cout << left << programname << " ";
            cout.width(45);
            cout << left << department << " ";
            cout.width(10);
            cout << left << duration << " ";
            cout.width(15);
            cout << left << availability << " " << endl;

        }
    }

    //main function starts

    int main(void)
    {
        Environment* env = nullptr;
        Connection* conn = nullptr;
        string usr = "dbs211_223nff25"; // this is your login assigned to you
        string pass = "48712199"; // this is your password assigned to you
        string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(usr, pass, srv);

        int input = 0;
        do
        {
            cout << "\n\n\n\n STUDENT RECORDS MANAGEMENT SYSTEM APP" << endl;


            cout << "1. Find Student" << endl;
            cout << "2. Display a Student Detail" << endl;
            cout << "3. Display all Student Detail" << endl;
            cout << "4. Find Student" << endl;
            cout << "5. Display a Student Detail" << endl;
            cout << "6. Display all Student Detail" << endl;
            cout << "7. Find Student" << endl;
            cout << "8. Display a Student Detail" << endl;
            cout << "9. Display all Student Detail" << endl;
            cout << "10. EXit " << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice ";
            cin >> input;

            if (input == 1)
            {
                cout << "Entering choice to find a student" << endl;
                int no;
                cout << "Enter Student ID" << endl;
                cin >> no;
                if (findSTUDENTPG(conn, no) == 1)
                {
                    cout << " Valid Student ID" << endl;
                }
                else
                {
                    cout << "There is no student details to be displayed" << endl;
                }
            }
            else if (input == 2)
            {
                cout << "Entering choice to display a Student Detail" << endl;
                displaySTUDENTPG(conn);
            }
            else if (input == 3)
            {
                cout << "Entering choice to display All Student Details" << endl;
                displayAllSTUDENTPG(conn);
            }
            else if (input == 4)
            {
                cout << "Entering choice to find a student" << endl;
                int numb;
                cout << "Enter Student ID:";
                cin >> numb;
                if (findSTUDENTMR(conn, numb) == 1)
                {
                    cout << " Valid Student ID" << endl;
                }
                else
                {
                    cout << "There is no student details to be displayed" << endl;
                }
            }
            else if (input == 5)
            {
                cout << "Entering choice to display a Student Detail" << endl;
                displaySTUDENTMR(conn);
            }
            else if (input == 6)
            {
                cout << "Entering choice to display All Student Details" << endl;
                displayAllSTUDENTMR(conn);
            }
            else if (input == 7)
            {
                cout << "Entering choice to find a student" << endl;
                int no;
                cout << "Enter Student ID" << endl;
                cin >> no;
                if (findSTUDENT(conn, no) == 1)
                {
                    cout << " Valid Student ID" << endl;
                }
                else
                {
                    cout << "There is no student details to be displayed" << endl;
                }
            }
            else if (input == 8)
            {
                cout << "Entering choice to display a Student Detail" << endl;

                displaySTUDENT(conn);
            }
            else if (input == 9)
            {
                cout << "Entering choice to display All Student Details" << endl;
                displayAllSTUDENT(conn);
            }
            else if (input == 10)
            {
                exit(0);
            }
            else if (input == 0)
            {
                exit(0);
            }
        } while (input != 11);


       



    }  
    



// Created By Aashna Kundra, Student Id:- 163028210




 
int findSTUDENTMR(Connection* conn, int stdid);
void displaySTUDENTMR(Connection* conn);
void displayAllSTUDENTMR(Connection* conn);

//definition of functions

int findSTUDENTMR(Connection* conn, int stdid)
{
    Statement* stmt = conn->createStatement();
    ResultSet* rsss1 = stmt->executeQuery("SELECT certificateno,stdid,age,height,weight,disability FROM medicalrecords WHERE stdid = " + to_string(stdid));

    if (rsss1->next())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void displaySTUDENTMR(Connection* conn)
{
    int i_de;
    cout << "Enter student id:";
    cin >> i_de;
    Statement* stmt = conn->createStatement();
    ResultSet* rsss2 = stmt->executeQuery("SELECT certificateno,stdid,age,height,weight,disability FROM medicalrecords WHERE stdid = " + to_string(i_de));
    cout << "--------------Student Details------------------" << endl;
    while (rsss2->next()) {
        cout << "Certificateno:";
        int  certificateno = rsss2->getInt(1);
        cout.width(20);
        cout << left << certificateno << " " <<endl;
        cout << "stdid:";
        int stdid = rsss2->getInt(2);
        cout.width(15);
        cout << left << stdid << " " <<endl;
        cout << "age:";
        string age = rsss2->getString(3);
        cout.width(15);
        cout << age << " " <<endl;
        cout << "height:";
        string height = rsss2->getString(4);
        cout.width(15);
        cout << height << " "<<endl;
        cout << "weight:";
        string weight = rsss2->getString(5);
        cout.width(30);
        cout << weight << " " <<endl;
        cout << "disability:";
        string disability = rsss2->getString(6);
        cout.width(30);
        cout << disability << " " << endl;

    }

}
void displayAllSTUDENTMR(Connection* conn)
{
    Statement* stmt = conn->createStatement();
    ResultSet* rsss3 = stmt->executeQuery("SELECT certificateno,stdid,age,height,weight,disability FROM medicalrecords");
    cout << "# certificateno stdid age height weight disability" << endl;
    while (rsss3->next()) {
        int certificateno = rsss3->getInt(1);
        int stdid = rsss3->getInt(2);
        string age = rsss3->getString(3);
        string height = rsss3->getString(4);
        string weight = rsss3->getString(5);
        string disability = rsss3->getString(6);
        cout.width(20);
        cout << left << certificateno << " ";
        cout.width(15);
        cout << left << stdid << " ";
        cout.width(15);
        cout << age << " ";
        cout.width(15);
        cout << height << " ";
        cout.width(30);
        cout << weight << " ";
        cout.width(30);
        cout << disability << " " << endl;

    }
}

//main function starts

int main(void)
{
    Environment* env = nullptr;
    Connection* conn = nullptr;
    string usr = "dbs211_223nff15"; // this is your login assigned to you
    string pass = "54851694"; // this is your password assigned to you
    string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
    env = Environment::createEnvironment(Environment::DEFAULT);
    conn = env->createConnection(usr, pass, srv);

    int input = 0;
    do
    {
        cout << "\n STUDENT RECORDS MANAGEMENT SYSTEM APP" << endl;


        cout << "1. Find Student" << endl;
        cout << "2. Display a Student Detail" << endl;
        cout << "3. Display all Student Detail" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice";
        cin >> input;

        if (input == 1)
        {
            cout << "Entering choice to find a student" << endl;
            int numb;
            cout << "Enter Student ID:";
            cin >> numb;
            if (findSTUDENTMR(conn, numb) == 1)
            {
                cout << " Valid Student ID" << endl;
            }
            else
            {
                cout << "There is no student details to be displayed" << endl;
            }
        }
        else if (input == 2)
        {
            cout << "Entering choice to display a Student Detail" << endl;
            displaySTUDENTMR(conn);
        }
        else if (input == 3)
        {
            cout << "Entering choice to display All Student Details" << endl;
            displayAllSTUDENTMR(conn);
        }
        else if (input == 4)
        {
            exit(0);
        }
        else if (input == 0)
        {
            exit(0);
        }
    } while (input != 5);

} 