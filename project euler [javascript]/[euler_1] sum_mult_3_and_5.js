// Find the sum of all the multiples of 3 or 5 below 1000.

const max_three = 333; // 333 multiples of '3' below 1000
const max_five = 199; // 199 multiples of '5' below 1000
const max_fifteen = 66; // 66 multiples of '15' below 1000

// the sum of the first 'n' digits is given by: n(n+1)/2, multiplying by 'k' will give the sum of first 'n' multiples of 'k'

// k = 3
sum_three = 3*(max_three*(max_three+1)/2);

// k = 5
sum_five = 5*(max_five*(max_five+1)/2);

// k = 15
sum_fifteen = 15*(max_fifteen*(max_fifteen+1)/2);

// subtract sum of multiples of 15 since they were added twice
ans = sum_three + sum_five - sum_fifteen;

console.log(ans);