package lab2;

public class Rectangle {
    private double width;
    private double height;

    private static String color;

    public Rectangle() {
        this(1, 1);
    }

    public Rectangle(double width, double height) {
        setWidth(width);
        setHeight(height);
        setColor("yellow");
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }

    public static String getColor() {
        return color;
    }

    public void setWidth(double width) {
        if (width > 0) {
            this.width = width;
        } else {
            this.width = 1;
        }
    }

    public void setHeight(double height) {
        if (height > 0) {
            this.height = height;
        } else {
            this.height = 1;
        }
    }

    public static void setColor(String color) {
        if (color != null) {
            Rectangle.color = color;
        } else {
            Rectangle.color = "yellow";
        }
    }

    public double getArea(){
        return width * height;
    }

    public double getPerimeter() {
        return 2 * (width + height);
    }
}
