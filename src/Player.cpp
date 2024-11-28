/**
 * @file Player.cpp
 * @author Raymond Pridgen
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024 Ray Gun Technologies
 *
 */
#pragma once

#include <vector>
#include <string>
#include <stdexcept>
#include "../inc/Card.h"
#include "../inc/Deck.h"
#include "../inc/Player.h"


using namespace std;
namespace chants
{
    Player::Player(string name, int threshold, bool isUser, bool isDealer)
    {
        if(isUser && isDealer)
        {
            throw runtime_error("User cannot be dealer.");
        }
        _name = name;
        _winThreshold = threshold;
        _isUser = isUser;
        _isDealer = isDealer;
        isBusted = false;
    }

    int Player::calculateScore()
    {
        int score = 0;
        for(Card card : _hand)
        {
            score = score + card.GetValue();
        }
        return score;
    }



    /**
     * @brief Get the Threshold object
     *
     * @return int
     */
    int Player::GetThreshold()
    {
        return _winThreshold;
    }

    /**
     * @brief Get the Name object
     *
     * @return string
     */
    string Player::GetName()
    {
        return _name;
    }

    /**
     * 
     */
    bool Player::GetisUser()
    {
        return _isUser;
    }

    bool Player::GetisDealer()
    {
        return _isDealer;
    }

    /**
     * @brief
     *
     * @param card
     */
    void Player::AddCard(Card card)
    {
        _hand.push_back(card);
    }

    /**
     * @brief
     *
     * @return string
     */
    string Player::ShowHand()
    {
        string handString = "";
        for(Card card : _hand)
        {
            card.isFaceUp = true;
            handString = handString + card.ToString() + '\n';
        }
        return handString + "Score: " + to_string(this->calculateScore())  + '\n';
    }

    /**
     * @brief
     *
     */
    void Player::EmptyHand()
    {
        _hand.clear();
    }

    /**
     * @brief
     *
     * @return int
     */
    int Player::CountCards()
    {
        int counter = 0;
        for(Card card : _hand)
        {
            counter++;
        }
        return counter;
        
    }

    /**
     * @brief
     *
     * @return int
     */
    int Player::Score()
    {
        return this->calculateScore();
    }

    /**
     * @brief
     *
     */
    void Player::FlipCard(int cardToFlip)
    {
        _hand[cardToFlip].isFaceUp = true;
        return;
    }

    /**
     * @brief
     *
     * @param faceUp
     */
    void Player::FlipAllCards(bool faceUp)
    {
        for(Card card : _hand)
        {
            card.isFaceUp = faceUp;
        }
    }
};