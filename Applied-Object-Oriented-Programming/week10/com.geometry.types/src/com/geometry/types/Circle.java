package com.geometry.types;

public class Circle extends Point {
    private int radius;

    public Circle() {
        this(0, 0, 1);
    }

    public Circle(int x, int y, int radius) {
        super(x, y);
        setRadius(radius);
    }

    public int getRadius() {
        return radius;
    }

    public void setRadius(int radius) {
        this.radius = (radius > 0) ? radius : 1;
    }

    @Override
    public String toString() {
        return String.format("Circle with center %s and radius %d", super.toString(), radius);
    }

    @Override
    public int compareTo(Object o) {

        if (o == null) return 1;

        if (!(o instanceof Circle)) return 1;

        Circle circle = (Circle) o;

        int larger = super.compareTo((Point) circle);

        if (larger == 0) return this.radius - circle.radius;


        return larger;
    }
}
