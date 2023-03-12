package lab2;

public class RectangleTest {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle();

        System.out.println("Area: " + rectangle.getArea());
        rectangle.setWidth(-5);
        rectangle.setHeight(3);

        System.out.println("Perimeter: " + rectangle.getPerimeter());
        System.out.println("Rectangle color: " + Rectangle.getColor());

        Rectangle r2 = new Rectangle(7, 2);
        Rectangle.setColor("red");
        System.out.println("Perimeter: " + r2.getPerimeter());
        System.out.println("Rectangle color: " + Rectangle.getColor());
    }
}
