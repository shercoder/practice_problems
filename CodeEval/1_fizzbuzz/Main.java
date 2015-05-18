import java.io.*;
public class Main {
    public static void main (String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            String[] numbers = line.split(" ");
            int x = Integer.parseInt(numbers[0]);
            int y = Integer.parseInt(numbers[1]);
            int N = Integer.parseInt(numbers[2]);
            for (int i = 1; i <= N; ++i) {
                if (i%x == 0 && i%y == 0) System.out.print("FB");
                else if (i%x == 0) System.out.print("F");
                else if (i%y == 0) System.out.print("B");
                else System.out.print(i);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}
