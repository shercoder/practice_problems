import java.io.*;
public class Main {
    public static void main (String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while((line = buffer.readLine()) != null) {
            String[] numbers = line.split(",");
            int n = Integer.parseInt(numbers[0]);
            int p1 = Integer.parseInt(numbers[1]);
            int p2 = Integer.parseInt(numbers[2]);
/*            int i1 = (n & (1 << p1)) >> p1;
            int i2 = (n & (1 << p2)) >> p2;
            System.out.println("i1=" + i1 + " i2=" + i2);
            if (i1 == i2) System.out.println("true");
            */
           // boolean i1 = ((0x1 << p1) ^ n) == 0;
            //boolean i2 = ((0x1 << p2) ^ n) == 0;
            //boolean i = ((n >> p1) ^ (n >> p2)) == 0; 
            boolean i = (((n >> p1) & 1) == ((n >> p2) & 1));
            System.out.println("i=" + i);

          //  else System.out.println("false");
        }
    }
}
