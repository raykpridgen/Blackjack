/**
 * @file Player.h
 * @author Raymond Pridgen (rkpridgen@coastal.edu)
 * @brief
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024 Ray Gun Technologies
 *
 */
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <Card.h>
#include <Deck.h>

using namespace std;
namespace chants
{

    /**
     * @brief
     *
     */
    class Player
    {
    private:
        /// @brief
        string _name;
        /// @brief
        vector<Card> _hand;
        /// @brief
        int _winThreshold;

        bool _isUser;

        bool _isDealer;

        /**
         * @brief
         *
         * @return int
         */
        int calculateScore();

    public:
        /// @brief
        bool isBusted;

        /// @brief
        bool isWinner;

        /**
         * @brief Construct a new Player object
         *
         * @param name
         * @param threshold
         */
        Player(string name, int threshold, bool isUser, bool isDealer);

        /**
         * @brief Get the Threshold object
         *
         * @return int
         */
        int GetThreshold();

        /**
         * @brief Get the Name object
         *
         * @return string
         */
        string GetName();

        bool GetisUser();

        bool GetisDealer();

        /**
         * @brief
         *
         * @param card
         */
        void AddCard(Card card);

        /**
         * @brief
         *
         * @return string
         */
        string ShowHand();

        /**
         * @brief
         *
         */
        void EmptyHand();

        /**
         * @brief
         *
         * @return int
         */
        int CountCards();

        /**
         * @brief
         *
         * @return int
         */
        int Score();

        /**
         * @brief
         *
         */
        void FlipCard(int cardToFlip);

        /**
         * @brief
         *
         * @param faceUp
         */
        void FlipAllCards(bool faceUp);
    };
}


#endif