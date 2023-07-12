package problem1;

import com.sun.source.tree.CompilationUnitTree;

public class RouteCipher {
    private int key;

    public RouteCipher(int key) {
        setKey(key);
    }

    public void setKey(int key) {
        if (key != 0) {
            this.key = key;
        } else {
            this.key = 1;
        }
    }

    public int getKey() {
        return key;
    }

    public String decrypt(String ciphertext) {
        int rows = calcRows(ciphertext);
        int cols = Math.abs(key);
        char[][] result;
        if (key > 0) {
            result = decryptTopLeftSpiralMatrix(rows, cols, ciphertext);
        } else {
            result = decryptBottomRightSpiralMatrix(rows, cols, ciphertext);
        }

        StringBuilder plaintext = new StringBuilder();
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (result[row][col] != 'X') {
                    plaintext.append(result[row][col]);
                }
            }
        }

        return plaintext.toString();
    }

    public String encrypt(String cipherText) {
        int cols = Math.abs(key);
        int rows = calcRows(cipherText);
        char[] plainText = cipherText.toCharArray();
        int plainTextIndex = 0;
        char[][] matrix = new char[rows][cols];

        // fill matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(plainTextIndex == plainText.length){
                    matrix[i][j] = 'X';
                }
                else{
                    matrix[i][j] = plainText[plainTextIndex];
                    plainTextIndex++;
                }
            }
        }
        // encrypting
        String encryptedText ="";
        if (this.key > 0){
            encryptedText = topLeftIterateSpiralMatrix(rows,cols, matrix);
        }
        else {
            encryptedText = bottomRightIterateSpiralMatrix(rows,cols,matrix);
        }
        return encryptedText;
    }

    private String topLeftIterateSpiralMatrix(int rows, int cols, char matrix[][]) {
        String result = "";
        int startRowIndex = 0;
        int startColIndex = 0;
        int count = 0;
        int total = rows * cols;

        while (startRowIndex < rows && startColIndex < cols) {
            if (count == total) {
                break;
            }

            for (int i = startRowIndex; i < rows; i++) {
                result += matrix[i][startColIndex];
                count++;
            }
            startColIndex++;

            if (count == total) {
                break;
            }

            for (int i = startColIndex; i < cols; i++) {
                result += matrix[rows - 1][i];
                count++;
            }
            rows--;

            if (count == total) {
                break;
            }

            if (startRowIndex < rows) {
                for (int i = rows - 1; i >= startRowIndex; i--) {
                    result += matrix[i][cols - 1];
                    count++;
                }
                cols--;
            }

            if (count == total) {
                break;
            }

            if (startColIndex < cols) {
                for (int i = cols - 1; i >= startColIndex; i--) {
                    result += matrix[startRowIndex][i];
                    count++;
                }
                startRowIndex++;
            }
        }
        return result;
    }

    private String bottomRightIterateSpiralMatrix(int rows, int cols, char matrix[][]) {
        String result = "";
        int startRowIndex = rows-1;
        int startColIndex = cols - 1;
        int remainingRows = 0;
        int remainingCols = 0;
        int count = 0;
        int total = rows * cols;

        while (startRowIndex >= remainingRows && startColIndex >= remainingCols) {
            if (count == total) {
                break;
            }

            // append the last column from the remaining columns
            for (int i = startRowIndex; i >= remainingRows; --i) {
                result += matrix[i][startColIndex];
                count++;
            }
            startColIndex--;

            if (count == total) {
                break;
            }

            // append the first row from the remaining rows
            for (int i = startColIndex; i >= remainingCols; --i) {
                result += matrix[remainingRows][i];
                count++;
            }
            remainingRows++;

            if (count == total)
                break;

            // append the first column from the remaining columns
            if (startRowIndex > remainingRows) {
                for (int i = remainingRows; i <= startRowIndex; ++i) {
                    result += matrix[i][remainingCols];
                    count++;
                }
                remainingCols++;
            }

            if (count == total) {
                break;
            }
            // append the last row from the remaining rows
            if (startColIndex > remainingCols) {
                for (int i = remainingCols; i <= startColIndex; ++i) {
                    result += matrix[startRowIndex][i];
                    count++;
                }
                startRowIndex--;
            }
        }
        return result;
    }

    private char[][] decryptBottomRightSpiralMatrix(int rows, int cols, String cipherText) {
        int startRowIndex = rows-1;
        int startColIndex = cols - 1;
        int remainingRows = 0;
        int remainingCols = 0;
        int count = 0;
        int total = rows * cols;

        char[][] matrix = new char[rows][cols];

        char[] cipherTextAsArr = cipherText.toCharArray();

        while (startRowIndex >= remainingRows && startColIndex >= remainingCols) {
            if (count == total) {
                break;
            }

            // append the last column from the remaining columns
            for (int i = startRowIndex; i >= remainingRows; --i) {
                matrix[i][startColIndex] = cipherTextAsArr[count];
                count++;
            }
            startColIndex--;

            if (count == total) {
                break;
            }

            // append the first row from the remaining rows
            for (int i = startColIndex; i >= remainingCols; --i) {
                matrix[remainingRows][i] = cipherTextAsArr[count];
                count++;
            }
            remainingRows++;

            if (count == total)
                break;

            // append the first column from the remaining columns
            if (startRowIndex > remainingRows) {
                for (int i = remainingRows; i <= startRowIndex; ++i) {
                    matrix[i][remainingCols] = cipherTextAsArr[count];
                    count++;
                }
                remainingCols++;
            }

            if (count == total) {
                break;
            }
            // append the last row from the remaining rows
            if (startColIndex > remainingCols) {
                for (int i = remainingCols; i <= startColIndex; ++i) {
                    matrix[startRowIndex][i] = cipherTextAsArr[count];
                    count++;
                }
                startRowIndex--;
            }
        }

        return matrix;
    }

    private char[][] decryptTopLeftSpiralMatrix(int rows, int cols, String cipherText) {
        int startRowIndex = 0;
        int startColIndex = 0;
        int count = 0;
        int total = rows * cols;

        char[] cipherTextAsArr = cipherText.toCharArray();

        char[][] matrix = new char[rows][cols];

        while (startRowIndex < rows && startColIndex < cols) {
            if (count == total) {
                break;
            }

            for (int i = startRowIndex; i < rows; i++) {
                matrix[i][startColIndex] = cipherTextAsArr[count];
                count++;
            }
            startColIndex++;

            if (count == total) {
                break;
            }

            for (int i = startColIndex; i < cols; i++) {
                matrix[rows - 1][i] = cipherTextAsArr[count];
                count++;
            }
            rows--;

            if (count == total) {
                break;
            }

            if (startRowIndex < rows) {
                for (int i = rows - 1; i >= startRowIndex; i--) {
                    matrix[i][cols - 1] = cipherTextAsArr[count];
                    count++;
                }
                cols--;
            }

            if (count == total) {
                break;
            }

            if (startColIndex < cols) {
                for (int i = cols - 1; i >= startColIndex; i--) {
                    matrix[startRowIndex][i] = cipherTextAsArr[count];
                    count++;
                }
                startRowIndex++;
            }
        }

        return matrix;
    }

    private int calcRows(String plainText){
        double rows = (double)plainText.length() / (double)Math.abs(key);
        return (int)Math.ceil(rows);
    }
}