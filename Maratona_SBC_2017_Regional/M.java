import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
 
    public static void main(String[] args) throws IOException {
 
        Scanner s = new Scanner(System.in);

        int[] numbers = new int[3];
        int a, b, c;
        
        a = s.nextInt();
        b = s.nextInt();
        c = s.nextInt();
        
        numbers[0] = a * 4 + b * 2;
        numbers[1] = a * 2 + c * 2;
        numbers[2] = b * 2 + c * 4;
        
        Arrays.sort(numbers);

        System.out.println(numbers[0]);
 
    }
 
}
