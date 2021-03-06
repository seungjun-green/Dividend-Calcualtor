# importing the required module
import matplotlib.pyplot as plt

original = float(input("Starting Principal: "))

dF = input("Distribution Frequency(Y, Q, M): ")

yearlyDYield = float(input("Annual Dividend Yield in percentage(0 ~100): "))

AnnualStockUP = float(input("Expected Annual Share Price Appreciation percentage: "))

year = int(input("Years Invested: "))

str = ""
dPerFrequency = 0
investments = original
dividend = 0 #amount of dividend
dFrequency = 0  #Yearly, Quarterly, Monthly

if 'Y' == dF:
    dFrequency = 1
    str = "Yearly"
    dPerFrequency = yearlyDYield / 100
elif 'Q' == dF:
    dFrequency = 4
    str = "Quarterly"
    dPerFrequency = yearlyDYield / 400
else:
    dFrequency = 12
    str = "Monthly"
    dPerFrequency = yearlyDYield / 1200

# x axis values
time = []
# corresponding y axis values
usd = [] #market value
usd2 = []



for x in range(1, year * dFrequency + 1):
    dividend = investments * dPerFrequency
    investments += dividend
    usd.append(investments)
    usd2.append(dividend)
    time.append(x * (12/dFrequency))


    if ((x % dFrequency) == 0):
        investments = investments * (1 + AnnualStockUP / 100)


print("Market Value: $%.2f | %s dividend: $%.2f " %(original, str, (original * dPerFrequency)))
print("============ %d years later ============  " %year)
print("Market Value: $%.2f | %s Dividnes: $%.2f " %(investments, str, investments * dPerFrequency))



# plotting the points
plt.plot(time, usd, label = "Marktet Value")
plt.plot(time, usd2, label = "dividend")



# naming the x axis
plt.xlabel('Time(Month)')
# naming the y axis
plt.ylabel('Market Value($USD)')

# giving a title to my graph
plt.title('Expected Growth')

# function to show the plot
plt.show()


