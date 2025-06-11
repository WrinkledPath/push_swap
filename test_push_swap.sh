#!/bin/bash

# Ensure push_swap and checker_OS are in the current directory
PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

# Test function
run_test() {
    local count=$1
    echo "Testing with $count numbers..."

    # Generate shuffled list of $count numbers
    ARG=$(shuf -i 0-4999 -n $count | tr '\n' ' ')
    
    # Get operation count
    OP_COUNT=$($PUSH_SWAP $ARG | tee ops.txt | wc -l)

    # Check with checker_OS
    RESULT=$(cat ops.txt | $CHECKER $ARG)

    echo "Instructions: $OP_COUNT"
    echo "Checker: $RESULT"

    # Check performance limits
    if [ "$count" -eq 100 ]; then
        [ "$OP_COUNT" -le 700 ] && echo "✅ Pass (≤ 700 moves)" || echo "❌ Fail (> 700 moves)"
    elif [ "$count" -eq 500 ]; then
        [ "$OP_COUNT" -le 5500 ] && echo "✅ Pass (≤ 5500 moves)" || echo "❌ Fail (> 5500 moves)"
    fi

    echo "---------------------------------------"
}

# Run test for 100 elements
run_test 100

# Run test for 500 elements
run_test 500

# Optional: test smaller random sets
for size in 5 10 50 150; do
    run_test $size
done

