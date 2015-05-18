import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while((line = buffer.readLine()) != null) {
            if (line.isEmpty()) continue;
            String[] words = line.split(" ");
            for (int i = words.length-1; i >= 0; --i) {
                System.out.print(words[i]);
                if (i > 0) System.out.print(" ");
            }
            System.out.println();
        }
    }
}
