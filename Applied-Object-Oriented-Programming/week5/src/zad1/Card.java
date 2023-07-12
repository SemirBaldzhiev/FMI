package zad1;// Fig. 7.9: Card.java
// Card class represents a playing card.

public class Card 
{
   private String face; // face of card ("Ace", "Deuce", ...)
   private String suit; // suit of card ("Hearts", "Diamonds", ...)

   // two-argument constructor initializes card's face and suit
   public Card( String cardFace, String cardSuit )
   {
      setFace(cardFace); // initialize face of card
      setSuit(cardSuit); // initialize suit of card
   } // end two-argument Card constructor

   public void setFace(String face) {
      this.face = face;
   }

   public String getFace() {
      return this.face;
   }

   public void setSuit(String suit) {
      this.suit = suit;
   }

   public String getSuit() {
      return this.suit;
   }
   // return String representation of Card
   public String toString() 
   { 
      return face + " of " + suit;
   } // end method toString

} // end class Card

