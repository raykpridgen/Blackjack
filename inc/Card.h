/**
 * @file Card.cpp
 * @author Raymond Pridgen rkpridgen@coastal.edu
 * @brief This is the include (header) file for a playing Card.
 * @version 0.1
 * @date 2024-10-15
 *
 * @copyright Copyright (c) 2024 Ray Gun Technologies
 *
 */
#pragma once
#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

namespace chants
{
    class Card
    {
    private:
        /// @brief _value is an integer from 1 to 13 represent values Ace - King
        ///         where values for Ace is 11, Jack is 10, Queen is 10, and King is 10
        ///         The value is set in the parameterized constructor
        int _value;

        /// @brief _strValue is the text representation for values 1 - 13
        ///         where 1 is Ace, 11 is Jack, 12 is Queen, and 13 is King
        string _strValue;

        /// @brief _suit will be an integer between 1 and 4
        ///         where 1 = Clubs, 2 = Diamonds, 3 = Hearts, and 4 is Spades
        int _suit;

        /// @brief _strSuit will be the text Clubs, Diamonds, Hearts, or Spades
        string _strSuit;

        /**
         * @brief converts the card integer to a string representation,
         *          example: 1 = Ace, 11 = Jack, 12 = Queen, 13 = King.
         *          It is a private method called in the parameterized constructor
         *
         * @param val - number 1 - 13
         */
        void convertValueToString(int val);

        /**
         * @brief converts the suit integer to a string representation,
         *          example: 1 = Clubs, 2 = Diamonds, 3 = Hearts, 4 = Spades.
         *          It is a private method called in the parameterized constructor
         *
         * @param val - number 1 - 4
         */
        void convertSuitToString(int suit);

    public:
        /// @brief When isFaceUp is true, the ToString function will display the card _strValue and _strSuit
        ///     When isFaceUp is false, the ToString function will display "Face-down"
        bool isFaceUp;

        /**
         * @brief Parameterized Construct a new Card
         *
         * @param value - is a number between 1 and 13, Ace (11), 2 - 10, Jack (10), Queen (10), King (10)
         * @param suit - is a number between 1 and 4, Clubs, Diamonds, Hearts, Spades
         * @param isFaceUp - true or false
         */

        // If it has parameters then it is a parameterized constructor
        // Default constructor has no parameters like Card();
        // Copy constructor Card(Card);
        Card(int value, int suit, bool isFaceUp);

        /**
         * @brief Get the integer value of the card, 2 - 11
         *      where Ace is 11, Jack is 10, Queen is 10, King is 10
         *
         * @return int
         */
        int GetValue();

        /**
         * @brief Simple string output that represents this playing card face up or face down
         *
         * @return string - card representation
         */
        string ToString();
    };
}

#endif