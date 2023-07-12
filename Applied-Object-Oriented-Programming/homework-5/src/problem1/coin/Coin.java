package problem1.coin;

import java.util.Random;

public abstract class Coin {
    private Random rand;
    private Face face;

    public Coin(Face face){
        this.rand = new Random();
        this.face = face;
    }

    public Face getFace(){
        return Face.valueOf(this.face.toString());
    }

    public void setFace(Face face){
        if(face != null){
            this.face = face;
        }
        else {
            face = Face.HEADS;
        }
    }

    public void flip(){
        int newFace = rand.nextInt(2) + 1;
        if (newFace == 1){
            setFace(Face.HEADS);
        }
        else {
            setFace(Face.TAILS);
        }
    }

    public boolean isHeads(){
        return this.face.toString().equals("HEAD");
    }

    @Override
    public String toString() {
        return String.format("Coin: %s", face.toString());
    }
}