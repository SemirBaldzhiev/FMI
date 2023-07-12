package functions;

import services.Computable;

import java.util.Scanner;

public class Tabulate {
    private Computable callback;

    public Tabulate(Computable callback) {
        setCallback(callback);
    }

    public Computable getCallback() {
        return callback;
    }

    public void setCallback(Computable callback) {

        if (callback == null) {
            this.callback = new Computable() {
                @Override
                public double function(double x) {
                    return Math.cos(x); // in Radians
                }
            };
        }
        else {
            this.callback = callback;
        }

//        this.callback = new Functions().getSinFunction();
    }

    public void tabulate(double a,double b, int steps) {
        tabulateFunction(a, b, steps, callback);
    }

    public static void tabulateFunction(double a, double b, int steps, Computable computable) {
        if (a >= b) {
            System.out.println("Please enter a valid interval");
            return;
        }

        if (steps <= 0) {
            System.out.println("Please enter a valid steps value");
            return;
        }
        Scanner scanner = new Scanner(System.in);
        double x;
        System.out.printf("%-10s%-10s%n", "X", "F(X)");
        int size = (int) (b - a) / steps;
        for (int i = 0; i < size; i++) {
            x = a + i * size;
            System.out.printf("%-10.3f%-10.3f%n", x, computable.function(x));

            if (i != 0 && i % 20 == 0) {
                System.out.println("Pres Return to continue...");
                scanner.nextLine();
            }
        }



    }
}
