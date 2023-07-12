package lab14problem4;

import java.util.Arrays;
import java.util.Random;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Roll {
    public static void main(String[] args) {
        Random random = new Random();
        System.out.printf("%-6s%-10s%n", "Face", "Frequency");

        IntStream.rangeClosed(1, 6_000_000)
                .mapToObj(n -> random.nextInt(1,7))
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()))
                .forEach((face, freq) ->  System.out.printf("%-6s%-10s%n", face, freq));

    }
}
