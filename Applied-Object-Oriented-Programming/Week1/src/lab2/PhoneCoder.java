package lab2;

public class PhoneCoder {
    private int key;

    public PhoneCoder() {
    }

    public PhoneCoder(int key) {
        this.key = key;
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public String encode(String phoneNumber) {
        return null;
    }

    public String decode(String codePhoneNumber) {
        return null;
    }

    @Override
    public String toString() {
        return "PhoneCoder: " + key;
    }
}

