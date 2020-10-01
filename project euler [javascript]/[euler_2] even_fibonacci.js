// Find the sum of even-valued Fibonacci numbers below 4,000,000

var fibonacci = [1, 2, 3, 5, 8, 13, 21];
var fib = [];

// let n1 = first number
// let n2 = second number
// let next = next number

n1 = 1
n2 = 2
sum = 0

while (n1 < 4000000) {
    if (n1 % 2 == 0) {
        sum += n1
    }

    next = n1 + n2
    n1 = n2
    n2 = next
}

console.log(sum)