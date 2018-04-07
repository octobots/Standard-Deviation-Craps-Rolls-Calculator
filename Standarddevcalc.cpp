#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float sum = 0;
    float mean1 = 0;
    float deviation = 0;
    float number_read;
    float sum2 = 0;
    int dice1 = 0;
    int dice2 = 0;
    double dont_pass = 0;
    double pass = 0;
    double point = 0;
    int i = 0;
    
    ifstream infile("data");
    if(infile.is_open())
    {
        cout << "***Standard deviation calculation***" << endl;
        
        while(infile >> number_read) /* Reads float values in a file and prints them out, assigns them a value,
                                        then calculates the mean of all the numbers */
        {
            i++;
            cout << "Value #" << i << ": " << number_read << endl;
            sum = sum + number_read;
            mean1 = sum / i;
        }
        
        infile.clear();
        infile.seekg(0);
        
        while(infile >> number_read) //Read numbers again, subtracts the mean and squares the result
        {
            sum2 = sum2 + pow((number_read - mean1), 2);
        }
        
        deviation = sqrt(sum2/(i - 1));
        cout << "Sample standard deviation: " << deviation << endl; // prints standard deviation
        
        /*
         This part of the program finds the odds of pass, don't pass, and point rolls in craps
         and prints them to the terminal as odds out of 1000000 trials, along with percentages of each roll.
         */
        
        const int TRIAL = 1000000;
        srand(time(NULL));
        
        for (int test = 0; test < TRIAL; test++) //sets number of trials
        {
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            
            
            if ((dice1 == 1 && dice2 == 1) || //checks for "don't pass" rolls
                (dice1 == 1 && dice2 == 2) ||
                (dice1 == 2 && dice2 == 1) ||
                (dice1 == 6 && dice2 == 6))
                
                dont_pass++;
            
            else if ((dice1 == 4 && dice2 == 3) || //checks for "pass" rolls
                     (dice1 == 3 && dice2 == 4) ||
                     (dice1 == 5 && dice2 == 2) ||
                     (dice1 == 2 && dice2 == 5) ||
                     (dice1 == 1 && dice2 == 6) ||
                     (dice1 == 6 && dice2 == 1) ||
                     (dice1 == 5 && dice2 == 6) ||
                     (dice1 == 6 && dice2 == 5))
                
                pass++;
            
            else    //adds a point if it is not a pass or don't pass roll
                
                point++;
        }
        setprecision(4);
        
        cout << "***Craps simulation***" << endl;
        
        cout << TRIAL << " trials conducted" << endl;
        
        cout << "Pass: " << pass << "/" << TRIAL << " " <<               //Prints odds of rolling "pass"
        pass / 10000 << "%" << endl;
        
        cout << "Don't pass: " <<  dont_pass << "/" << TRIAL << " " <<   //Prints odds of rolling "don't pass"
        dont_pass / 10000 << "%" << endl;
        
        cout << "Point established: " << point << "/" << TRIAL << " " << //Prints odds of rolling "point"
        point / 10000 << "%" << endl;
    }
    infile.close();
    
    return 0;
}


