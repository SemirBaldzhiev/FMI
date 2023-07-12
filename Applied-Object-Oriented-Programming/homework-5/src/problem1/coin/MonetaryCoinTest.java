package problem1.coin;

public class MonetaryCoinTest {
    public static void main(String[] args) {
        MonetaryCoin coin1 = new MonetaryCoin(Face.HEADS);
        MonetaryCoin coin2 = new MonetaryCoin(Face.HEADS);
        MonetaryCoin coin3 = new MonetaryCoin(Face.TAILS);

        System.out.println(coin1);
        System.out.println(coin2);
        System.out.println(coin3);

        System.out.println("Flipping coins, 1/2 chance of heads/tails!");
        coin1.flip();
        coin2.flip();
        coin3.flip();

        System.out.println(coin1);
        System.out.println(coin2);
        System.out.println(coin3);

        System.out.println(String.format("Coin 1 is heads: %b", coin1.isHeads()));
        System.out.println(String.format("Coin 1 value : %d", coin1.getValue()));
    }
}
