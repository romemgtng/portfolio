// find the smallest positive number evenly divisible by all numbers from 1-20

// prime_factors = [2, 3, 5, 7, 11, 13, 17, 19], the sum of these is '9,699,690'

i = 4
product = 9699690

while (i < 20) {
    // if 'i' is already a factor, move to next value of 'i'
    if (product%i === 0) {
        i += 1
    }

    else {
        var j = i - 1
        
        // find 'j', the largest factor of 'i'
        while (i%j !== 0) {
            j -= 1
        }

        // multiply 'j' to current product, move to next value of 'i'
        product = product*j
        i += 1
    }
}

console.log(product)