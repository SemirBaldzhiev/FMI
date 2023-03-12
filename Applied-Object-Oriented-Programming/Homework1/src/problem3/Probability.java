package problem3;

public class Probability {
    public static void main(String[] args) {

        int countDivisibleBy12 = 0;
        int countOfAllNums = 0;
        double probability;
        String formatResult;

        for (int firstDig = 1; firstDig <= 6; firstDig++) {
            for (int secondDig = 4; secondDig <= 8; secondDig++) {
                for (int thirdDig = 3; thirdDig <= 7; thirdDig++) {
                    for (int fourthDig = 1; fourthDig <= 9; fourthDig++) {
                        for (int fifthDig = 1; fifthDig <= 8; fifthDig++) {

                            int currNum = firstDig * 10000 + secondDig * 1000 + thirdDig * 100 + secondDig * 10 + fifthDig;
                            countOfAllNums++;
                            if (currNum % 12 == 0) {
                                countDivisibleBy12++;
                            }
                        }
                    }
                }
            }
        }

        probability = (double)countDivisibleBy12 / countOfAllNums;
        formatResult = String.format(
                "Probability %.2f%nCount of numbers with the above properties: %d%nCount of numbers dividable by 12: %d%n",
                probability, countOfAllNums, countDivisibleBy12);

        System.out.println(formatResult);
    }
}
