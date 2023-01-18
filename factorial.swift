// Fatih Durmaz
func factorial(_ num: Int) -> Int {  
    if num == 1 || num == 0 {  
        return 1  
    } else {  
        return num * factorial(num - 1)  
    }  
}  
let val = 5
let result = factorial(val)  
print("Factorial \(val) is \(result)")   