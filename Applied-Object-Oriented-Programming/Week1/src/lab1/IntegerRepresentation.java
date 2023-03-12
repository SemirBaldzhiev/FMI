package lab1;

import java.util.Scanner;

public class IntegerRepresentation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter symbol: ");
        char symbol = input.next().charAt(0);

        System.out.printf("Integer representation of '%c' is %d", symbol, (int)symbol);
    }
}
