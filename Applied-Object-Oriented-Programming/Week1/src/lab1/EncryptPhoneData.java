package lab1;

import java.util.Scanner;

public class EncryptPhoneData {
    public static void main(String[] args) {
        int number;
        Scanner input = new Scanner(System.in);

        System.out.print("Enter four digit number: ");
        number = input.nextInt();
        if (number > 999 && number < 10_000) {

            int fourDigit = number % 10;
            number /= 10;
            int thirdDigit = number % 10;
            number /= 10;
            int secondDigit = number % 10;
            int firstDigit = number / 10;

            fourDigit  = (fourDigit + 7) % 10;
            thirdDigit  = (thirdDigit + 7) % 10;
            secondDigit  = (secondDigit + 7) % 10;
            firstDigit  = (firstDigit + 7) % 10;

            int encryptedNum = 1000 * secondDigit + 100 * fourDigit + 10 * firstDigit + thirdDigit;

            System.out.println("Encrypted number is: " + encryptedNum);

        } else {
            System.out.println("Not a four digit integer!");
        }


    }
}
