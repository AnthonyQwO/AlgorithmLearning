# Math

## Factorization
This C++ code implements two important algorithms in number theory: Pollard's Rho algorithm for factorization and the Miller-Rabin primality test.

### Pollard's Rho Algorithm
Pollard's Rho algorithm is used for integer factorization. It's particularly efficient when the factors of the number to be factored are small. The algorithm generates a sequence of numbers using a recurrence relation and detects cycles in this sequence to find non-trivial factors.

#### Function `f(x, mod)`
This function computes $x^2 + 1 \mod \text{mod}$.

#### Function `pointard_rho(n)`
This function implements Pollard's Rho algorithm to find a non-trivial factor of the given integer \(n\).

### Miller-Rabin Primality Test
Miller-Rabin is a probabilistic primality test. It tests whether a given number \(n\) is prime or composite. It's highly reliable, with the probability of error decreasing exponentially with the number of iterations performed.

#### Function `miinter_rabin(n)`
This function implements the Miller-Rabin primality test to determine whether the given integer \(n\) is a prime number.

### Other Functions
- `add(x, y, mod)`: Adds two integers \(x\) and \(y\) modulo \(mod\).
- `mul(x, y, mod)`: Multiplies two integers \(x\) and \(y\) modulo \(mod\).
- `qpow(n, k, mod)`: Computes \(n^k \mod \text{mod}\).
- `witness(a, n, u, t)`: Checks if \(a\) is a witness to the compositeness of \(n\).
- `f(n)`: Finds factors of the given integer \(n\) using Pollard's Rho algorithm.
- `main()`: Main function that takes input \(n\), finds its factors using `f(n)`, and prints the factors.

### Notes
- The Miller-Rabin test uses a set of predefined witness values (`magic`) for testing compositeness.
- The code expects the input \(n\) to be provided via standard input and prints the factors of \(n\) along with the maximum representable integer in the system (`INT64_MAX`).

Overall, this code can be used to efficiently factorize large integers and test primality with good accuracy.