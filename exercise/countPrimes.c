
/*
 * Count the number of prime numbers less than a non-negative number, n.
 * http://danielzs.com/2015/05/22/c%E8%AF%AD%E8%A8%80%E8%AE%A1%E7%AE%97%E6%AF%94n%E5%B0%8F%E7%9A%84%E7%B4%A0%E6%95%B0%E4%B8%AA%E6%95%B0/
 */
int countPrimes(int n) {
    bool *isPrime = (bool*)malloc(n*sizeof(bool));
    int i = 0, j = 0;
    for ( i = 2; i < n; i++) {
        isPrime[i] = 1;
    }
    // Loop¡¯s ending condition is i * i < n instead of i < sqrt(n)
    // to avoid repeatedly calling an expensive function sqrt().
    // Time complex: sqrt(n)*sqrt(n) = O(n)
    for ( i = 2; i*i < n; i++) {
        if (!isPrime[i]) continue;
        for ( j = i*i; j < n; j += i) {
            isPrime[j] = 0;
        }
    }
    int count = 0;
    for ( i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }
    free(isPrime);
    return count;
}