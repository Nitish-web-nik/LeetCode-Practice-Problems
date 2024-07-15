class Solution {
public:
    int countPrimes(int N) {
            if (N < 2) return 0; // There are no primes less than 2

    vector<bool> is_prime(N + 1, true); // Assume all numbers are prime
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Count the number of prime numbers
    int count = 0;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            count++;
        }
    }

    return count;
    }
};