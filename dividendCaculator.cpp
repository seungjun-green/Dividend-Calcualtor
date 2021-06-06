#include <iostream>
#include<string.h>
using namespace std;

int main() {
    int year = 5; /* years to invest */
    double original = 300000; //initial investments
    string dF = "M"; //
    double AnnualStockUP = 1; //Annual Stock Percenatge Change
    double yearlyDYeild = 12.24;  //Annual Dividiens Yeild
    
   

    cout << "Distribution Frequency(Y, Q, M): ";
    getline (cin, dF);
    
    cout << "Annual Dividend Yield in percentage(0 ~ 100): " ;
    cin >> yearlyDYeild;
    
     cout << "Starting Principal: ";
    cin >> original;
    
    cout << "Expected Annual Share Price Appreciation: ";
    cin >> AnnualStockUP;
    
    cout << "Years Invested: ";
    cin >> year;
    
    
    string str = "M"; 
    double dPerFrequency = 0;
    double investments = original; 
    double dividens = 0;  //amount of dividens
    int dFrequency = 0;  //Yearly, Quartely, Monthly
    
    
     if (dF.compare("Y") == 0) {
        dFrequency = 1;
        str = "Yearly";
        dPerFrequency = yearlyDYeild / 100;
        
    } else if (dF.compare("Q") == 0) {
        dFrequency = 4;
        str = "Quartely";
        dPerFrequency = yearlyDYeild / 400;

    } else  {
        dFrequency = 12;
        str = "Monthly";
        dPerFrequency = yearlyDYeild / 1200;
    }
    
    
    for(int i = 1; i <= (year * dFrequency); i++) {
        dividens = investments * 0.011;
        investments += dividens;
        
        if ((i % dFrequency) == 0) {
            investments = investments * (1 + AnnualStockUP/100);
        }
    }
    
    
    cout << "Market Value: " << "$"<<original << " | " << str << "Dividens: " << "$"<<(original * dPerFrequency)<< endl;
    cout << year <<"years layter" << endl;
    cout << "Market Value: " << "$"<<investments << " | " << str << "Dividens: " << "$"<<investments * dPerFrequency << endl;

    
    
    

    return 0;
}
