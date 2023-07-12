package lab13bproblem2;

import java.util.Arrays;
import java.util.function.*;

public class LambdaTest {

    public static void main(String[] args) {
        // 1st option
        Function<Integer, String> function = (number) -> {
            return "Number is " + number;
        };
        // 2nd option
        Function<Integer, String> function2 = (number) -> "Number is " + number;

        System.out.println("Function test: " + function.apply(13));
        System.out.println("Function test2: " + function2.apply(11));

        BiPredicate<Double, Double> predicat = (d1, d2) -> d1.compareTo(d2) > 0;
        System.out.println("BiPredicate test: " + predicat.test(13.0, 15.0));


        BiConsumer<String, String> consumer = (s1, s2) -> System.out.println(s1 + s2);
        consumer.accept("BiConsumer test: ", "a b");

        Supplier<int[]> supplier = () ->  {
            int[] arr = new int[10];
            Arrays.fill(arr, 3);
            return arr;
        };
        System.out.println("Supplier test: " + Arrays.toString(supplier.get()));

        IntFunction<double[]> intFunction = (c) -> {
            double[] arr = new double[c];
            Arrays.fill(arr, 5);
            return arr;
        };

        System.out.println("IntFunction test: " + Arrays.toString(intFunction.apply(4)));

        Runnable task = System.out::println;
        task.run();

        Function<Double, Double> func = Math::cos;
        System.out.println("Method reference test: " + func.apply(0.));

    }
}
