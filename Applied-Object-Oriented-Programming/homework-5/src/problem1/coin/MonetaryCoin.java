package problem1.coin;

public class MonetaryCoin extends Coin {
    public MonetaryCoin(Face face){
        super(face);
    }

    public int getValue() {
        return getFace().getValue();
    }
}
