import java.io.*;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) throws IOException {
        PrimeSieve primeSieve = new PrimeSieve(1000000);
        long sum = 0;
        int i = 2;
        int counter = 0;
        while(counter < 1000) {
            if (primeSieve.isPrime(i)) {
               sum += i; 
               ++counter;
            }
            ++i;
        }
        System.out.println(sum);
    }

    public static class PrimeSieve {
        boolean[] primes;
        public PrimeSieve(int N) {
            primes = new boolean[N];
            Arrays.fill(primes, true);
            primes[0] = false;
            primes[1] = false;
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
