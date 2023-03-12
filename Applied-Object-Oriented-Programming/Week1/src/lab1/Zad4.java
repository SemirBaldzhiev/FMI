package lab1;

import java.util.Scanner;
public class Zad4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number;
        int remainder;

        System.out.println("Enter a four digit number: ");
        number = input.nextInt();

        if (number >= 1000 && number <= 9999) {
            String result = "";

            do {
                remainder = number % 4;

                if (remainder == 0) {
                    result = "A" + result;
                } else if (remainder == 1) {
                    result = "C" + result;
                } else if (remainder == 2) {
                    result = "G" + result;
                } else {
                    result = "T" + result;
                }

                number /= 4;
            } while(number != 0);
            System.out.println(result);
        } else {
            System.out.println("Not a four digit number.");
        }
    }
}
