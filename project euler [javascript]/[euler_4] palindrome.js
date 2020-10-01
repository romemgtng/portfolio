function is_palindrome(num) {
    // convert number to string
    num_string = num.toString()

    len = num_string.length/2

    for (var i = 0; i < len; i++) {
        // check if opposite characters are equal
        if (num_string[i] !== num_string[num_string.length - i - 1]) {
            return false
        }
    }
return true
}


largest_palindrome = 0

 for (var i = 100; i <= 999; i++) {
    for (var j = 100; j <= 999; j++) {
        product = i*j
        // check if product is a palindrome
        if (is_palindrome(product) && product > largest_palindrome) {
            largest_palindrome = product
        }
    }
 }

 console.log(largest_palindrome)