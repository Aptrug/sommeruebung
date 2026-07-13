#!/bin/sh
gawk -M '
BEGIN {
    # Define the base-5 and base-13 alphabets natively
    # \x27 represents the single quote, \\ is backslash, \" is double quote
    b5_1 = "\x27\\\"?!"
    b5_2 = "mrdoc"
    b13 = "gtaio luSnemf"

    # Pull variables directly from the environment to avoid shell injection
    n1 = ENVIRON["FT_NBR1"]
    n2 = ENVIRON["FT_NBR2"]

    # Convert FT_NBR1 to decimal
    sum1 = 0
    for (i = 1; i <= length(n1); i++) {
        sum1 = sum1 * 5 + (index(b5_1, substr(n1, i, 1)) - 1)
    }

    # Convert FT_NBR2 to decimal
    sum2 = 0
    for (i = 1; i <= length(n2); i++) {
        sum2 = sum2 * 5 + (index(b5_2, substr(n2, i, 1)) - 1)
    }

    total = sum1 + sum2

    # Handle edge case of 0
    if (total == 0) {
        print substr(b13, 1, 1)
        exit
    }

    # Convert decimal total to base 13
    out = ""
    while (total > 0) {
        rem = total % 13
        out = substr(b13, rem + 1, 1) out
        total = (total - rem) / 13
    }

    print out
}'
