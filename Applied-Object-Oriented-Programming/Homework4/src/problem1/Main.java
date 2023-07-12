package problem1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        byte num1 = scanner.nextByte();
        byte num2 = scanner.nextByte();

        byte xor = (byte)(num1 ^ num2);

        int count = countSetBits(xor);
        System.out.printf("Number1: %d - %s%n", num1, Integer.toBinaryString(num1));
        System.out.printf("Number2: %d - %s%n", num2, Integer.toBinaryString(num2));
        System.out.printf("Hamming distance: %d%n", count);

    }

    public static int countSetBits(byte n) {

        int count = 0;
        while(n > 0) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
}