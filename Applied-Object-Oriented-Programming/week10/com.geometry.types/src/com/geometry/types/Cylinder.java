package com.geometry.types;

public class Cylinder extends Circle {

    private int height;

    public Cylinder() {
        this(0, 0, 1, 1);
    }
    public Cylinder(int x, int y, int radius, int height) {
        super(x, y, radius);
        setHeight(height);
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = (height > 0) ? height : 1;
    }

    @Override
    public String toString() {
        return String.format("Cylinder with base %s, height %d", super.toString(), height);
    }

    @Override
    public int compareTo(Object o) {
        if (o == null) return 1;

        if (!(o instanceof Cylinder)) return 1;

        Cylinder cylinder = (Cylinder) o;

        int larger = super.compareTo((Circle) cylinder);

        if (larger == 0) return this.height - cylinder.height;

        return larger;
    }
}
