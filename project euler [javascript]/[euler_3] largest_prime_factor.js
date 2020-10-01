var x = 600851475143

// logic: prime factorization, the last factor in this loop is the largest prime factor
for (i = 2; i < x; i++) {
    // if 'i' is a prime number, divide 'x' by 'i'
    while (x%i === 0) {
        x /= i
    }
}

console.log(i)