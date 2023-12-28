//Test_Framework version-3

#include <iostream>
using namespace std;

//This is the abstract Base class
class Test
{
public:
    virtual void startExecution() = 0;
};

// This class will have the method having the parameter of type Test*, 
// so that it can have the address of any class object which extends this above Test class
class RunTestCases
{
public:
    void startTesting(Test *t, string fileHeader)
    {
        if (fileHeader == "MSWORD_FILE")
            cout << "MSWord File Test Processing" << endl;
        else if (fileHeader == "MSEXCEL_FILE")
            cout << "MSExcel File Test Processing" << endl;
        else
            return;
    }
};

// If we want the MSWordFile to go on the Testing then this MSWordTestCases class needs to extend the Test class
// and provide the implementation of the startExecution() method
class MSWordTestCases : public Test
{
public:
    // we can have the constructors and assignment operators as per requirement
    
    //I have defined the steps in the form of lambda function under here, so that the end user can only access
    //the startExecution() method and rest the ordering is defined properly
    void startExecution()
    {
        auto preWork=[](){
            cout << "Download the test data for the MSWord File" << endl;
            cout << "-- Logging --" << endl;
        };
        auto launch=[](){
            cout << "Some Launching related to the MSWordFile" << endl;
        };
        auto test=[this](){
            RunTestCases *rtc = new RunTestCases();
            rtc->startTesting(this, "MSWORD_FILE");
        };
        auto closure=[](){
            cout << "Delete the MSWord test data" << endl;
            cout << "-- Closing --" << endl;
        };
        auto report=[](){
            cout << "Report Generated for the MSWord File" << endl;
        };
        preWork();
        launch();
        test();
        closure();
        report();
    }
};


// If we want the MSExcelFile to go on the Testing then this MSExcelTestCases class needs to extend the Test class
// and provide the implementation of the startExecution() method
class MSExcelTestCases : public Test
{
public:
    // we can have the constructors and assignment operators as per requirement
    
    //I have defined the steps in the form of lambda function under here, so that the end user can only access
    //the startExecution() method and rest the ordering is defined properly
    void startExecution()
    {
        auto preWork=[](){
            cout << "Download the test data for the MSExcel File" << endl;
            cout << "-- Logging --" << endl;
        };
        auto launch=[](){
            cout << "Some Launching related to the MSExcel File" << endl;
        };
        auto test=[this](){
            RunTestCases *rtc = new RunTestCases();
            rtc->startTesting(this, "MSEXCEL_FILE");
        };
        auto closure=[](){
            cout << "Delete the MSExcel test data" << endl;
            cout << "-- Closing --" << endl;
        };
        auto report=[](){
            cout << "Report Generated for the MSExcel File" << endl;
        };
        preWork();
        launch();
        test();
        closure();
        report();
    }
};

int main()
{
    Test *test; // this pointer can contain the address of any class whichever had extended this one
    test = new MSWordTestCases();
    test->startExecution();
    cout<<"***********************************************"<<endl;
    test=new MSExcelTestCases();
    test->startExecution();
    delete test;
    return 0;
}