/**
 * @file Deck.cpp
 * @author Raymond Pridgen rkpridgen@coastal.edu
 * @brief This is the definition file for a deck of cards
 * @version 0.1
 * @date 2024-10-17
 *
 * @copyright Copyright (c) 2024 Ray Gun Technologies
 *
 */
#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "../inc/Card.h"
#include "../inc/Deck.h"

namespace chants
{

    Deck::Deck(bool faceUpCards)
    {
        _cardsFaceUp = faceUpCards;
        buildDeck();
    }
        
    /**
     * @brief Deals a card in the game
     */
    Card Deck::Deal()
    {
        if(!_deckOfCards.empty())
        {
            Card returnCard = _deckOfCards.back();
            _deckOfCards.pop_back();
            return returnCard;
        }
        else
        {
            throw runtime_error("Cannot deal from an empty deck");
        }
    }

    /**
     * @brief Returns the amount of cards left in the deck
     */
    int Deck::CardsInDeck()
    {
        int counter;
        for (Card card : _deckOfCards)
        {
            counter++;
        }
        return counter;
    }

    /**
     * @brief Shuffle the deck of cards
     *        This function shuffles the same object, does not make a new one
     *
     * @return nothing
     */
    void Deck::ShuffleDeck()
    {
        for(int i=0; i<200; i++)
        {
            int randomVal = rand() % 52;
            Card randomCard = _deckOfCards[randomVal];
            _deckOfCards.push_back(randomCard);
            _deckOfCards.erase(_deckOfCards.begin() + randomVal);
        }
    }
    /**
     * @brief Returns a string of the deck of cards
     */
    string Deck::ToString()
    {
        string newString;
        for (Card card : _deckOfCards)
        {
            newString = newString + card.ToString() + "\n";
        }
        return newString;
    }
    void Deck::buildDeck()
    {
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 13; j++)
            {
                Card card(j, i, false);
                _deckOfCards.push_back(card);
            }
        }
    }

};








