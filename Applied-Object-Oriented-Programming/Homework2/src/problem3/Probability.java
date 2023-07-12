package problem3;

import java.text.NumberFormat;
import java.util.Random;

public class Probability {

    public static void main(String[] args) {
        probabilityTest(10000);
        probabilityTest(60000);
    }
    public static int drawRandomNumber()
    {
        Random randNum = new Random();
        int result;
        int number = randNum.nextInt(101);

        if (number <= 20)
        {
            result = 1;
        }
        else if (number <= 50)
        {
            result = 2;
        }
        else
        {
            result = 3;
        }
        return result;
    }

    public static double calcProbability(int frequency, int timesDrawn)
    {
        return (double)frequency / (double)timesDrawn;
    }

    public static void probabilityTest(int drawCount) {

        NumberFormat percentFormat = NumberFormat.getPercentInstance();
        percentFormat.setMinimumFractionDigits(1);

        int freqOne = 0;
        int freqTwo = 0;
        int freqThree = 0;

        for (int i = 0; i < drawCount; i++)
        {
            int number = drawRandomNumber();
            switch (number)
            {
                case 1: freqOne++; break;
                case 2: freqTwo++; break;
                case 3: freqThree++; break;
                default: break;
            }
        }

        double oneProb = calcProbability(freqOne, drawCount);
        double twoProb = calcProbability(freqTwo, drawCount);
        double threeProb = calcProbability(freqThree, drawCount);

        System.out.printf("Results of generating %d times:\n" +
                        "Number 2 has been drawn %d times with probability: %.3f - %s\n" +
                        "Number 1 has been drawn %d times with probability: %.3f - %s\n" +
                        "Number 3 has been drawn %d times with probability: %.3f - %s\n", drawCount,
                freqOne, oneProb, percentFormat.format(oneProb),
                freqTwo, twoProb, percentFormat.format(twoProb),
                freqThree, threeProb, percentFormat.format(threeProb));
    }
}
