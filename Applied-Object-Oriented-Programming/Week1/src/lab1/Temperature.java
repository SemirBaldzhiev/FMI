package lab1;
import java.util.Scanner;
public class Temperature {
    public static void main(String[] args) {
        double fahrenheit;
        double celsius;
        Scanner input = new Scanner(System.in);

        //a)
        /*System.out.println("Enter temperature in fahrenheit: ");
        fahrenheit = input.nextDouble();
        celsius = 5.0 / 9.0 * (fahrenheit - 32);
        System.out.println("Temperature in celsius: " + celsius);

        //b)
        System.out.println("Enter temperature in celsius: ");
        celsius = input.nextDouble();
        fahrenheit = 9.0 / 5.0 * celsius + 32;
        System.out.printf("%s %.1f", "Temperature in fahrenheit: " , fahrenheit);*/

        //c)
        System.out.println("Enter 1 for F to C or 2 for C to F: ");
        int choice = input.nextInt();
        if (choice == 1) {
            System.out.println("Enter temperature in fahrenheit: ");
            fahrenheit = input.nextDouble();
            celsius = 5.0 / 9.0 * (fahrenheit - 32);
            System.out.println("Temperature in celsius: " + celsius);
        } else if (choice == 2) {
            System.out.println("Enter temperature in celsius: ");
            celsius = input.nextDouble();
            fahrenheit = 9.0 / 5.0 * celsius + 32;
            System.out.printf("%s %.1f", "Temperature in fahrenheit: " , fahrenheit);
        } else {
            System.out.println("Invalid user choice!");
        }

    }
}
