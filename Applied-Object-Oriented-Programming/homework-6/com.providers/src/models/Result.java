package models;

public class Result {
    private char[] chars;
    private int data;

    public Result(char[] chars, int data){
        setChars(chars);
        setData(data);
    }

    public char[] getChars() {
        // returning deep copy
        char[] charsArrayCopy = new char[chars.length];
        for (int i = 0; i < chars.length; i++) {
            charsArrayCopy[i] = chars[i];
        }
        return charsArrayCopy;
    }

    public int getData() {
        return data;
    }

    public void setChars(char[] chars) {
        this.chars = chars;

        if (chars != null) {
            this.chars = chars;
        }
        else {
            this.chars = new char[10];
        }
    }

    public void setData(int data) {
        this.data = data;
    }
}