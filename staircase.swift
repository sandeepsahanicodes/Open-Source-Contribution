import UIKit

func staircase(n: Int) -> Void {
    
    for i in 1...n {
        var rowString = ""
        for j in 1...n {
            rowString += n - j < i ? "#" : " "
        }
        print(rowString)
    }
}

staircase(n: 4)
