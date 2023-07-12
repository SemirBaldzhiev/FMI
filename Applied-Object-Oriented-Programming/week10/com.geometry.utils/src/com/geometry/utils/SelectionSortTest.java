package com.geometry.utils;

import com.geometry.types.Circle;
import com.geometry.types.Cylinder;
import com.geometry.types.Point;

import java.util.Arrays;
import java.util.Random;

public class SelectionSortTest {

    private static Comparable[] arrComparable = new Comparable[9];

    public static void main(String[] args) {
        Random random = new Random();

        int x, y, r, h;

        for (int i = 0; i < 3; i++) {
            x = random.nextInt(10, 51);
            y = random.nextInt(10, 51);
            r = random.nextInt(10, 31);
            h = random.nextInt(10, 61);
            arrComparable[i] = new Point(x, y);
            arrComparable[i + 3] = new Circle(x, y, r);
            arrComparable[i + 6] = new Cylinder(x, y, r, h);
        }

        System.out.printf(Arrays.toString(arrComparable));
        SelectionSort.sortArray(arrComparable);
        System.out.printf("\n");
        System.out.printf(Arrays.toString(arrComparable));
    }
}
