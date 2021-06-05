#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    
    int year = 5; /* years to invest */
    double original = 300000; //initial investments
    char dF[1] = "M"; //
    double AnnualStockUP = 1; //Annual Stock Percentage Change
    double yearlyDYield = 12.24;  //Annual Dividiens Yeild
    
    
    printf("Starting Principal: ");
    scanf("%lf", &original);

    printf("Distribution Frequency(Y, Q, M): ");
    scanf("%s", dF);
    
    printf("Annual Dividend Yield in percentage(0 ~100): " );
    scanf("%lf", &yearlyDYield);

    
    printf("Expected Annual Share Price Appreciation percentage: ");
    scanf("%lf", &AnnualStockUP);

    printf("Years Invested: ");
    scanf("%d", &year);
  
    char str[10] = "";
    double dPerFrequency = 0;
    double investments = original;
    double dividend = 0;  //amount of dividend
    int dFrequency = 0;  //Yearly, Quarterly, Monthly

    
    if (strcmp("Y", dF) == 0) {
        dFrequency = 1;
        strcpy(str, "Yearly");
        dPerFrequency = yearlyDYield / 100;
        
    } else if (strcmp("Q", dF) == 0) {
        dFrequency = 4;
        strcpy(str, "Quarterly");
        dPerFrequency = yearlyDYield / 400;

    } else  {
        dFrequency = 12;
        strcpy(str, "Monthly");
        dPerFrequency = yearlyDYield / 1200;
    }
    
    
    for(int i = 1; i <= (year * dFrequency); i++) {
        dividend = investments * 0.011;
        investments += dividend;
        
        if ((i % dFrequency) == 0) {
            investments = investments * (1 + AnnualStockUP/100);
        }
    }
    
    setlocale(LC_NUMERIC, "");
    printf("\n\n");
    
    printf("Market Value: $%.2f | %s dividend: $%.2f \n", original, str, (original * dPerFrequency));
    printf("============ %d years later ============  \n", year);
    printf("Market Value: $%.2f | %s Dividnes: $%.2f \n", investments, str, investments * dPerFrequency);
}
