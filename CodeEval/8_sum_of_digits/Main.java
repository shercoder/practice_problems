import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.lang.Character;

public class Main {
    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        int sum = 0;
        while ((line = buffer.readLine()) != null) {
            sum = 0;
            for (int i = 0; i < line.length(); ++i) {
                sum += Character.getNumericValue(line.charAt(i));
            }
            System.out.println(sum);
        }
    }
}
