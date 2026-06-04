#!/bin/bash

# 1. Compile all three files
echo "Compiling files..."
g++ -O2 gen.cpp -o gen
g++ -O2 test.cpp -o test
g++ -O2 brute.cpp -o brute

echo "Compilation successful! Starting stress test..."
echo "------------------------------------------------"

# 2. Run the infinite loop
for ((i=1; ; ++i)); do
    # Generate the test case and save it to test.in
    ./gen > test.in
    
    # Pass test.in to your fast solution and save output to test.out
    ./test < test.in > test.out
    
    # Pass test.in to the brute force solution and save output to brute.out
    ./brute < test.in > brute.out
    
    # Compare the two outputs
    if diff -w test.out brute.out > /dev/null; then
        echo "Passed test: $i"
    else
        echo "------------------------------------------------"
        echo "❌ WRONG ANSWER FOUND on test $i!"
        echo "------------------------------------------------"
        echo "Test case that failed:"
        cat test.in
        echo "------------------------------------------------"
        echo "Your output (test.cpp):"
        cat test.out
        echo "------------------------------------------------"
        echo "Correct output (brute.cpp):"
        cat brute.out
        echo "------------------------------------------------"
        break
    fi
done