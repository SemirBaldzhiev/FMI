package com.geometry.utils;

public class SelectionSort {
    public static void sortArray(Comparable[] arr) {
        int index;

        for (int i = 0; i < arr.length - 1; i++) {
            index = i;

            for (int j = i + 1; j < arr.length; j++) {
                if (arr[index].compareTo(arr[j]) > 0) {
                    index = j;
                }
            }

            if (i != index) {
                Comparable temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
        }
    }
}
