#include <iostream>
using namespace std;
//This Test class will be the abstract class containing the pure virtual functions as mentioned below
class Test
{
public:
    virtual void preWork() = 0;
    virtual void launch() = 0;
    virtual void test() = 0;
    virtual void closure() = 0;
    virtual void report() = 0;
    virtual void startExecution()=0;
};

//This class will have the method having the parameter of type Test,
//so that it can have the address of any class which extends this Test class
class RunTestCases
{
    public:
    void startTesting(Test *t,string fileHeader)
    {
        if(fileHeader=="MSWORD_FILE") cout<<"MSWord File Test Processing"<<endl;
        else if(fileHeader=="MSEXCEL_FILE") cout<<"MSExcel File Test Processing"<<endl;
        else return;
    }
};

//If we want the MSWordFile to go on the Testing then this MSWordFile class needs to extend the Test class
class MSWordTestCases : public Test
{
    public:
    //we can have the constructors and assignment operators as per requirement
    void preWork()
    {
        cout<<"Download the test data for the MSWord File"<<endl;
        cout<<"-- Logging --"<<endl;
    }
    void launch()
    {
        cout<<"Some Launching related to the MSWordFile"<<endl;
    }
    void test()
    {
        RunTestCases *rtc=new RunTestCases();
        rtc->startTesting(this,"MSWORD_FILE");
    }
    void closure()
    {
        cout<<"Delete the MSWord test data"<<endl;
        cout<<"-- Closing --"<<endl;
    }
    void report()
    {
        cout<<"Report Generated for the MSWord File"<<endl;
    }
    void startExecution()
    {
    preWork();
    launch();
    test();
    closure();
    report();
    }
    
};

//If we want the MSExcelFile to go on the Testing then this MSWordFile class needs to extend the Test class
class MSExcelTestCases : public Test
{
    public:
    void preWork()
    {
        cout<<"Download the test data for the MSExcel File"<<endl;
        cout<<"-- Logging --"<<endl;
    }
    void launch()
    {
        cout<<"Some Launching related to the MSExcelFile"<<endl;
    }
    void test()
    {
        RunTestCases *rtc=new RunTestCases();
        rtc->startTesting(this,"MSEXCEL_FILE");        
    }
    void closure()
    {
        cout<<"Delete the MSExcel test data"<<endl;
        cout<<"-- Closing --"<<endl;
    }
    void report()
    {
        cout<<"Report Generated for the MSExcel File"<<endl;
    }
    void startExecution()
    {
    preWork();
    launch();
    test();
    closure();
    report();
    }
};

int main()
{
    Test *test; //this pointer can contain the address of any class whichever had extended this one
    test=new MSWordTestCases();
    test->startExecution();
    cout<<"***********************************************"<<endl;
    test=new MSExcelTestCases();
    test->startExecution();
    delete test;
    return 0;
}