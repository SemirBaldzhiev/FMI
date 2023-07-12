package problem2;

import java.util.Arrays;
import java.util.StringJoiner;

public class SquareMatrix {
    private int[][] dataArray;

    public SquareMatrix(int[][] dataArray) {
        setDataArray(dataArray);
    }

    public SquareMatrix() {
        this(new int[0][0]);
    }

    public SquareMatrix(SquareMatrix other) {
        setDataArray(other.dataArray);
    }

    public int[][] getDataArray() {
        return dataArray;
    }

    public void setDataArray(int[][] dataArray) {
        if (dataArray != null) {
            this.dataArray = dataArray;
        }
        else {
            this.dataArray = new int[0][0];
        }
    }

    @Override
    public String toString() {

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < dataArray.length; i++) {
            for (int j = 0; j < dataArray[i].length; j++){
                sb.append(dataArray[i][j]);
                sb.append(" ");
            }

            sb.append("\n");
        }

        return sb.toString();
    }

    public int findMaxSum() {
        int maxSum = 0;
        int currSum = Integer.MIN_VALUE;

        for (int i = 0; i < dataArray.length - 1; i++) {
            for (int j = 0; j < dataArray[i].length - 1; j++) {
                currSum = sum2x2Matrix(i, j);
                if (currSum > maxSum) {
                    maxSum = currSum;
                }
            }
        }

        return maxSum;
    }

    public void printAll() {
        int maxSum = findMaxSum();
        System.out.printf("Maximum sum: %d%n", maxSum);
        System.out.println("Submatrices with Maximum sum:");
        printCoordOfSubMatrices(maxSum);
    }

    private int sum2x2Matrix(int startIndexRow, int startIndexCol) {
        int sum = 0;
        for (int i = startIndexRow; i < startIndexRow + 2; i++) {
            for (int j = startIndexCol; j < startIndexCol + 2; j++) {
                sum += dataArray[i][j];
            }
        }

        return sum;
    }

    private void printCoordOfSubMatrices(int maxSum) {

        for (int i = 0; i < dataArray.length - 1; i++) {
            for (int j = 0; j < dataArray[i].length - 1; j++) {
                if (sum2x2Matrix(i, j) == maxSum) {
                    System.out.printf("[%d, %d]%n", i, j);
                }
            }
        }
    }

}

