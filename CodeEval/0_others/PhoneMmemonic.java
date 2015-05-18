import java.io.*;
import java.util.*;
public class PhoneMmemonic {
    private static Map<Character, List<Character>> numberToCharacters = new HashMap<Character, List<Character>>();
    static {
        numberToCharacters.put('0', new ArrayList<Character>(Arrays.asList(' ')));
        numberToCharacters.put('1', new ArrayList<Character>(Arrays.asList('1')));
        numberToCharacters.put('2', new ArrayList<Character>(Arrays.asList('A', 'B', 'C')));
        numberToCharacters.put('3', new ArrayList<Character>(Arrays.asList('D', 'E', 'F')));
        numberToCharacters.put('4', new ArrayList<Character>(Arrays.asList('G', 'H', 'I')));
        numberToCharacters.put('5', new ArrayList<Character>(Arrays.asList('J', 'K', 'L')));
        numberToCharacters.put('6', new ArrayList<Character>(Arrays.asList('M', 'N', 'O')));
        numberToCharacters.put('7', new ArrayList<Character>(Arrays.asList('P', 'Q', 'R', 'S')));
        numberToCharacters.put('8', new ArrayList<Character>(Arrays.asList('T', 'U', 'V')));
        numberToCharacters.put('9', new ArrayList<Character>(Arrays.asList('W', 'X', 'Y', 'Z')));
    }

    public static void main(String[] args) {
        permutations(234);
    }

    public static void permutations(int phoneNum) {
        StringBuilder buffer = new StringBuilder();
        permutationGenerator(Integer.toString(phoneNum), buffer);
    }

    public static void permutationGenerator(String partialPhoneNum, StringBuilder partialMmemonic) {
        if (partialPhoneNum.length() == 0) {
            System.out.println(partialMmemonic.toString());
            return;
        }

        int curPartialLength = partialMmemonic.length();
        char firstNumber = partialPhoneNum.charAt(0);
        String remainingNumbers = partialPhoneNum.substring(1);
        for (Character singleChar : numberToCharacters.get(firstNumber)) {
            partialMmemonic.setLength(curPartialLength);
            permutationGenerator(remainingNumbers, partialMmemonic.append(singleChar));
        }
    }
}

/*
 phone2string
 1 => " "
 2 =>ABC
 3 =DEF
 4 = GHI
 5 =>JKL
 6 =MNO
 7 =>PQRS
 8 =>TUV
 9 =>WXYZ
 0 => " "

 234 => ADG, ADH, ADI, etc.

 public void permutation(int num) {
     Map<Integer, String> phone2String = new HashMap<Integer, String>();
         String numStr = Integer.toString(num);
             int len = numStr.size();
                 permHelper(numStr, "", len);
 }

 public void permHelper(String num, String result, int len) {
     if (result.size() == num.size()) {
             System.out.println(result);
                     return;
                         }
                             
                             for (int i = 0; i < len; ++i) {
                                     result += phone2String.get(num[i]);
                                             permHelper(num, result, len-1);
                                                 }
 }

 (234, "", 3)
 result = A
 (234, "A", 2)
 */
