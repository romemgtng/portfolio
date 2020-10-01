// find the difference betweem the [square of them sum] and the [sum of the squares] of the first 100 numbers

n = 100

// sum of first n digits: 
sum = n*(n+1)/2

// sum of squares of first n digits:
square_sum = n*(n+1)*(2*n+1)/6

ans = (sum ** 2) - square_sum

console.log(ans)