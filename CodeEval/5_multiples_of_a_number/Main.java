import java.io.*;
public class Main {
    public static void main (String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while((line = buffer.readLine()) != null) {
            line = line.trim();
            String[] numbers = line.split(",");
            int x = Integer.parseInt(numbers[0]);
            int n = Integer.parseInt(numbers[1]);
            int multiple = n;
            while (multiple < x) {
                multiple += n;
//                System.out.println("multiple=" + multiple);
            }
            System.out.println(multiple);
        }
    }
}
