package lab14problem1;

import java.util.Arrays;
import java.util.Comparator;

public class ProcessInvoices {
    public static void main(String[] args) {
        Invoice[] invoices = {
                new Invoice(83, "Electric sander", 7, 57.98),
                new Invoice(24, "Power saw", 18, 99.99),
                new Invoice(7, "Sledge hammer", 11, 21.50),
                new Invoice(77, "Hammer", 76, 11.99),
                new Invoice(39, "Lawn mower", 3, 79.50),
                new Invoice(68, "Screwdriver", 106, 6.99),
                new Invoice(56, "Jig saw", 21, 11.00),
                new Invoice(3, "Wrench", 34, 7.50)
        };

        System.out.println("Invoices sorted by part description:");
        Arrays.stream(invoices)
                        .sorted(Comparator.comparing(Invoice::getPartDescription))
                        .forEach(System.out::println);
        System.out.printf("%nnInvoices sorted by price:%n");
        Arrays.stream(invoices)
                .sorted(Comparator.comparing(Invoice::getPrice))
                .forEach(System.out::println);


        System.out.printf("%nInvoices mapped to description and quantity:%n");
        Arrays.stream(invoices)
                .map((inv -> String.format("%s\t%d", inv.getPartDescription(), inv.getQuantity())))
                .forEach(System.out::println);

        System.out.printf("%nInvoices mapped to description and invoice amount:%n");



        System.out.printf("%nInvoices mapped to description and invoice amount for invoices in the range 200-500:%n");
        
    }
}
