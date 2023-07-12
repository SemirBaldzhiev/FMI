package zad1;// Fig. 7.11: DeckOfCardsTest.java
// Card shuffling and dealing application.

import java.util.Arrays;

public class DeckOfCardsTest
{
   // execute application
   public static void main( String args[] )
   {


      DeckOfCards myDeckOfCards = new DeckOfCards();
      myDeckOfCards.shuffle(); // place Cards in random order
      
      // print all 52 Cards in the order in which they are dealt
//      for ( int i = 0; i < 13; i++ )
//      {
//         // deal and print 4 Cards
////         System.out.printf( "%-20s%-20s%-20s%-20s\n",
////            myDeckOfCards.dealCard(), myDeckOfCards.dealCard(),
////            myDeckOfCards.dealCard(), myDeckOfCards.dealCard() );
//
//
//
//      } // end for

      Card[]  player1Hand = myDeckOfCards.dealHand();
      Card[]  player2Hand = myDeckOfCards.dealHand();

      System.out.println(Arrays.toString(player1Hand));
      System.out.println(Arrays.toString(player2Hand));

      System.out.printf("%-20s%-20s%n", "Left hand:", "Right hand:");
      for (int i = 0; i < player1Hand.length; i++) {
         System.out.printf("%-20s%-20s%n", player1Hand[i], player2Hand[i]);
      }

      System.out.println("\nHand values: ");


      result(myDeckOfCards, player1Hand);
      result(myDeckOfCards, player2Hand);
   } // end main

   public static void result(DeckOfCards myDeckOfCards, Card[] player1Hand) {

      if (myDeckOfCards.hasPair(player1Hand)) {
         System.out.printf("%-20s","One Pair");
         return;
      }
      if (myDeckOfCards.hasThreeOfAKind(player1Hand)) {
         System.out.printf("%-20s", "Three");
         return;
      }
      if (myDeckOfCards.hasFourOfAKind(player1Hand)) {
         System.out.printf("%-20s", "Four");
         return;
      }
      if (myDeckOfCards.hasFullHouse(player1Hand)) {
         System.out.printf("%-20s", "Full house");
         return;
      }
      if (myDeckOfCards.hasTwoPair(player1Hand)) {
         System.out.printf("%-20s", "Two Pair");
         return;
      }
      if (myDeckOfCards.hasFlush(player1Hand)) {
         System.out.printf("%-20s", "Flush");
         return;
      }
      if (myDeckOfCards.hasStraight(player1Hand)) {
         System.out.printf("%-20s", "Straight");
         return;
      }
      System.out.printf("%-20s", "none");
   }
} // end class DeckOfCardsTest

