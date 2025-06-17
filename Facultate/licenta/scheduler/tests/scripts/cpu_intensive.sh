#!/bin/bash

echo "Starting CPU intensive task at $(date)"
# Calculate prime numbers up to 1000000
for ((i=2; i<=1000000; i++)); do
    is_prime=1
    for ((j=2; j*j<=i; j++)); do
        if ((i % j == 0)); then
            is_prime=0
            break
        fi
    done
    if ((is_prime == 1)); then
        echo $i >> /home/kgbeast/Bogdan/Programming/Facultate/licenta/scheduler/tests/primes.txt
    fi
done
echo "Finished CPU intensive task at $(date)" 