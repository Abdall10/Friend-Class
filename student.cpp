#include <iostream>
using namespace std;

//Friend Class

// Class Student1 definition
class Student1
{
    private:
      int mark1=0;
      string name="unknown";
      public:
      // Constructor to initialize name and mark1
       Student1(string n, int m)
       {
        name=n;
        mark1=m;
       }
     // Member function to print student details
       void print()
       {
        cout<<"Hello "<<name<<endl;
        cout<<"Your Mark is: "<<mark1<<endl;
       }
       // Declare Student2 and Student3 as friend classes
       friend class Student2;  // Allow Student2 to access private members of Student1
       friend class Student3;
};

// Class Student2 definition
class Student2
{
    private:
    int mark2=0;
    string name="unknown";
    public:
    Student2(string n)
    {
        name=n;
    }
    void print()
    {
        cout<<"Hello "<<name<<endl;
        cout<<"Your mark is :"<<mark2<<endl;
    }
     // Member function to set mark2 based on mark1 of a Student1 object
    void setMark(Student1 ob)
    {
      mark2=ob.mark1; // Set mark2 to the value of mark1 of the provided Student1 object
    }
};

// Class Student3 definition
class Student3
{
    private:
    int mark3=0;
    string name="unknown";
    public:
    Student3(string n)
    {
        name=n;
    }
    void print()
    {
        cout<<"Hello "<<name<<endl;
        cout<<"Your mark is :"<<mark3<<endl;
    }
    void setMark(Student1 ob)
    {
        mark3=ob.mark1;
    }
};
int main()
{
    Student1 ob1("Jack", 98); // Create a Student1 object with name "Jack" and mark 98
    Student2 ob2("john");        // Create a Student2 object with name "john"
    Student3 ob3("jordan");

    ob2.setMark(ob1);    // Set mark2 of ob2 to mark1 of ob1
    ob2.print();        // The Outputs is  Hello john , Your mark is :98

    ob3.setMark(ob1);
    ob3.print();       // The Outputs is  Hello jordan, Your mark is :98

    return 0;
}