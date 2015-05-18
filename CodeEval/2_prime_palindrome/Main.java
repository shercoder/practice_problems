import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        PrimeSieve primeSieve = new PrimeSieve(1000);
        int maxPalindrome = 0;
        for (int i = 2; i < 1000; ++i) {
            if (primeSieve.isPrime(i) && isPalindrome(String.valueOf(i))) {
                maxPalindrome = i;
            }
        }
        System.out.println(maxPalindrome);
    }

    public static boolean isPalindrome(final String str) {
        int len = str.length();
        int midpoint = len/2;
        for (int i = 0; i < midpoint; ++i) {
            if (str.charAt(i) != str.charAt(len - i -1)) return false;
        }
        return true;
    }

    public static class PrimeSieve {
        boolean[] primes;
        public PrimeSieve(int N) {
            primes = new boolean[N];
            primes[0] = false;
            primes[1] = false;
            for (int i = 2; i < N; ++i) {
                primes[i] = true;
            }
            markNonPrimes(N);
        }

        private void markNonPrimes(int N) {
            int m = (int)Math.sqrt((double)N);
            for (int i = 2; i <= m; ++i) {
                if (primes[i]) {
                    for (int j = i*i; j < N; j+=i) {
                        primes[j] = false;
                    }
                }
            }
        }

        public boolean isPrime(int index) {
            return primes[index];
        }
    }
}
