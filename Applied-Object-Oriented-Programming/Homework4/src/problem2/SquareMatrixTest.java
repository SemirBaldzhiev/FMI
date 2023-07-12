package problem2;

import java.util.Random;

public class SquareMatrixTest {
    public static void main(String[] args) {

        Random random = new Random();

        int row = random.nextInt(2, 13);
        int col = random.nextInt(2, 13);

        int[][] matrix = new int[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = random.nextInt(0, 9);
            }
        }

        SquareMatrix sm = new SquareMatrix(matrix);
        sm.printAll();
    }
}
