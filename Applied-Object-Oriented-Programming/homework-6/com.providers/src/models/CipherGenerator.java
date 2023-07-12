package models;

import interfaces.Cipherable;

public class CipherGenerator {
    public static Result countDistinct(Cipherable cipher, int seed){
        int distinctCount = 0;
        char[] secretCharsArray = cipher.getSecretChars(seed);

        for (int index = 0; index < secretCharsArray.length; index++) {
            boolean hasEqual = true;
            for (int i = 0; i < secretCharsArray.length; i++) {
                if (i == index)
                    continue;

                if (secretCharsArray[i] == secretCharsArray[index]) {
                    hasEqual = false;
                    break;
                }
            }

            if (hasEqual)
                distinctCount++;
        }
        return new Result(secretCharsArray, distinctCount);
    }
}
