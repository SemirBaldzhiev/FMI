package com.geometry.types;

public class Point implements Comparable {

    private int x;
    private int y;

    public Point() {
        setX(0);
        setY(0);
    }

    public Point(int x, int y) {
        setX(x);
        setY(y);
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = (x >= 0) ? x : 0;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = (y > 0) ? y : 0;
    }

    @Override
    public String toString() {
        return String.format("(%d; %d)", x, y);
    }

    @Override
    public int compareTo(Object o) {

        if (o == null) {
            return 1;
        }

        if (!(o instanceof Point)) {
            return 1;
        }

        Point point = (Point)o;

        if (this.x > point.x) return 1;
        else if (this.x == point.x) {
            return this.y - point.y;
        }

        return 0;
    }
}
