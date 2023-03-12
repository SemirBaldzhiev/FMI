package lab1;

import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number;
        int originalNumber;
        String resultString;

        System.out.print("Enter a five digit number: ");
        number = input.nextInt();
        originalNumber = number;

        if (number > 9_999 && number < 100_000) {
            int d1, d2, d4, d5;
            d5 = number % 10;
            number /= 10;
            d4 = number % 10;
            number /= 100;
            d2 = number % 10;
            d1 = number / 10;

            if (d1 == d5 && d2 == d4) {
                resultString = String.format("%d is a palindrome", originalNumber);
            } else {
                resultString = String.format("%d is NOT a palindrome", originalNumber);
            }

            System.out.println(resultString);
        } else {
            System.out.println("Not a five digit number!");
        }
    }
}
