
let original: Double = 10000 //initial investments
let year = 2 //for how long users gonna kepp investing?
let yearlyDYield: Double = 12.24 //
var dF = "M" //Dividiens Frequency
var AnnualStockUP: Double = 1 //Annual Stock Percentage Change
//yearly dividens yeild of the stock


var retrunOfInvestment: Double = 0 //return of invesetment
retrunOfInvestment = original
var i = 0 //index for while statement
var dividensFrequency: Int = 12
var str = ""
var dPerFrequency = 0.0
var dividens: Double = 0.0 //value of dividens


func getFrequency(input: String) {
    if dF == "M" {
        dividensFrequency = 12
        str = "Monthly"
        dPerFrequency = yearlyDYield / 1200
    }else if dF == "Q"{
        dividensFrequency = 4
        str = "Quartely"
        dPerFrequency = yearlyDYield / 400
    }else if dF == "Y" {
        dividensFrequency = 1
        str = "Yearly"
        dPerFrequency = yearlyDYield / 100
    }
}

func cacualte() {
    while i < (year * (dividensFrequency)) {
        dividens = Double(retrunOfInvestment) * 0.015
        
        retrunOfInvestment += dividens
        i = i + 1
        
        
        if ((i % dividensFrequency) == 0) {
            retrunOfInvestment = retrunOfInvestment * (1 + AnnualStockUP/100)
        }
    }
    
}

func printoutResult() {
    print("Market Value: $\(original) | \(str) Dividens: $\((original * dPerFrequency)) \n")
    print("============ \(year) years later ============  \n")
    print("Market Value: $\(retrunOfInvestment) | \(str) Dividens: $\((retrunOfInvestment * dPerFrequency)) \n")
    
}



func masterFunc() {
    getFrequency(input: "M")
    cacualte()
    printoutResult()
}

masterFunc()










