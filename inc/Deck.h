/**
 * @file Deck.cpp
 * @author Raymond Pridgen rkpridgen@coastal.edu
 * @brief This is the include (header) file for a Deck of playing Cards.
 * @version 0.1
 * @date 2024-10-15
 *
 * @copyright Copyright (c) 2024 Ray Gun Technologies
 *
 */
#pragma once
#ifndef DECK_H
#define DECK_H
#include <string>
#include <vector>
#include <stdexcept>
#include "Card.h"
using namespace std;

namespace chants
{
    class Deck
    {
    private:
        /// @brief deckofCards is a vector list of Cards that is the main part of the
        ///        deck class. This is private.
        vector<Card>_deckOfCards;
        
        bool _cardsFaceUp;
        /**
         * @brief Builds the deck of cards, adds 52 card objects to the deck list
         */
        void buildDeck();
    public:
        /**
         * @brief Default contstruction of a new deck of cards
         *
         */

        Deck(bool faceUpCards);

        /**
         * @brief Boolean for something... not sure yet
         */

        /**
         * @brief Deals a card in the game
         */
        Card Deal();

        /**
         * @brief Returns the amount of cards left in the deck
         */
        int CardsInDeck();

        /**
         * @brief Shuffle the deck of cards
         *        This function shuffles the same object, does not make a new one
         *
         * @return nothing
         */
        void ShuffleDeck();

        /**
         * @brief Returns a string of the deck of cards
         */
        string ToString();
    };
}
#endif