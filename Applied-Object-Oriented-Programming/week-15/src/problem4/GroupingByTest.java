package problem4;

import java.util.List;
import java.util.stream.Collectors;

public class GroupingByTest {

    public static void main(String[] args) {
        List<String> strings = List.of("b", "a", "cc", "bb", "ddd");

        strings.stream().collect(Collectors.groupingBy(String::length))
                .forEach((length, list) -> System.out.printf("Length %d: %s%n", length, list));

        strings.stream().collect(Collectors.groupingBy(String::length, Collectors.counting()))
                .forEach((length, count) -> System.out.printf("Length %d have %d strings%n", length, count));
    }


}
