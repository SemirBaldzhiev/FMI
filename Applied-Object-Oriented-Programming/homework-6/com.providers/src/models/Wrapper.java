package models;

import interfaces.Cipherable;

import java.util.Random;

public class Wrapper {
    private int size;

    public Wrapper(int size){
        this.size = size;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        if(size > 0){
            this.size = size;
        }
        else {
            this.size = 10;
        }
    }

    public Cipherable makeFixedSelection(){
        return new FixedRandom(this.size);
    }

    public Cipherable makeFixedRandom(){
        return new FixedSelection(this.size);
    }

    private class FixedRandom implements Cipherable{
        private int size;

        public FixedRandom(int size){
            this.size = size;
        }

        public int getSize() {
            return size;
        }

        @Override
        public char[] getSecretChars(int seed) {
            Random generator = new Random(seed);
            char[] toReturn = new char[this.size];

            for (int index = 0; index < toReturn.length; index++){
                toReturn[index] = (char)(generator.nextInt(26) + 'A');
            }

            return toReturn;
        }
    }

    private class FixedSelection implements Cipherable{
        private int size;

        public FixedSelection(int size){
            this.size = size;
        }

        public int getSize() {
            return size;
        }

        @Override
        public char[] getSecretChars(int seed) {
            Random generator = new Random();
            char[] toReturn = new char[this.size];
            char[] seedArray = new char[seed];

            for (int i = 0; i < seedArray.length; i++){
                seedArray[i] = (char)(generator.nextInt(26) + 'A');
            }

            for (int index = 0; index < toReturn.length; index++){
                toReturn[index] = seedArray[generator.nextInt(seedArray.length - 1)];
            }

            return toReturn;
        }
    }
}