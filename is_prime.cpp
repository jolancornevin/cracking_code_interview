#include <bits/stdc++.h>
#include <cmath>

using namespace std;

map<int, int> prime_map;
map<int, int> not_prime_map;

void isPrime(const int num) {
    // Test if we know this number.
    if (num == 1 || prime_map.count(num) > 0) {
        cout << "Prime" << '\n';
        return;
    } 
    // prime_map contains all primed number between his first and last element.
    // If the num is below thann the last, then it's not prime (we'd have return otherwise).
    else if (not_prime_map.count(num) > 0) {
        cout << "Not prime" << '\n';
        return;
    }

    int numSquare = sqrt(num);
    map<int, int>::iterator primeIt;
    // Loop over our primes and find out if it's divisible or not.
    for (
        primeIt = prime_map.begin(); 
        primeIt != prime_map.end() && primeIt->first <= numSquare; 
        ++primeIt
    ) {
        bool divisibleByPrime = (num % primeIt->first == 0);
        if (divisibleByPrime) {
            cout << "Not prime" << '\n';
            not_prime_map[num] = 1;
            return;
        }
    }

    // Loop until we the num to maybe discover new prime numbers and find out if num is Prime;
    int possible_prime = (prime_map.rbegin())->first + 2;
    for (;possible_prime <= numSquare;) {
        bool isPrime = true;
        
        for (
            primeIt = prime_map.begin(); 
            primeIt != prime_map.end() && primeIt->first <= sqrt(possible_prime); 
            ++primeIt
        ) {
            bool divisibleByPrime = (possible_prime % primeIt->first == 0);
            if (divisibleByPrime) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) 
            prime_map[possible_prime] = 1;
        else
            not_prime_map[possible_prime] = 1;
        
        // Make sure that this possible prime is not a divider of our num.
        if (num != possible_prime && num % possible_prime == 0) {
            cout << "Not prime" << '\n';
            return;
        }

        possible_prime += 2;
    }
    
    if (prime_map.count(num) > 0 || possible_prime > numSquare) {
        prime_map[num] = 1;
        cout << "Prime" << '\n';
    } else {
        not_prime_map[possible_prime] = 1;
        cout << "Not prime" << '\n';
    }
}


int main()
{  
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    prime_map[2] = 1;
    prime_map[3] = 1;
    prime_map[5] = 1;
    prime_map[7] = 1;
    prime_map[11] = 1;
    prime_map[13] = 1;
    prime_map[17] = 1;
    prime_map[19] = 1;
    prime_map[23] = 1;
    prime_map[29] = 1;

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        isPrime(n);
    }

    return 0;
}
