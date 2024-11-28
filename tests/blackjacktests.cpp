/**
 * @file Player.cpp
 * @author Dave Blair (dblair@seafoamtechnologies.com)
 * @brief This is a Unit Test Fixture to the Card class
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024 Seafoam Technologies
 *
 */
#include <gtest/gtest.h>
#include <vector>
#include "../inc/Card.h"
#include "../inc/Player.h"
#include "../inc/Deck.h"

using namespace chants;
// https://google.github.io/googletest/reference/assertions.html

/**
 * @brief Test parameterized constructor that creates a valid Card object.
 *      In this case, a card is created at the lowest valid suit integer
 *      and the highest valid value integer. Suit 1, Value 1
 */
TEST(CardTest, ValidLowCard)
{
    Card card(1, 1, true);
    EXPECT_EQ(card.GetValue(), 11);
    EXPECT_EQ(card.ToString(), "ACE CLUBS");
}

/**
 * @brief Test parameterized constructor that creates a valid Card object.
 *      In this case, a card is created at the highest valid suit integer
 *      and the highest valid value integer. Suit 4, Value 13
 */
TEST(CardTest, ValidHighCard)
{
    Card card(13, 4, true);
    EXPECT_EQ(card.GetValue(), 10);
    EXPECT_EQ(card.ToString(), "KING SPADES");
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 0 for suit. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, SuitLow)
{
    try
    {
        Card card(1, 0, true);
        FAIL();
    }
    catch (const std::exception)
    {
        SUCCEED();
    }
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 5 for suit. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, SuitHigh)
{
    try
    {
        Card card(1, 5, true);
        FAIL();
    }
    catch (const std::exception)
    {
        SUCCEED();
    }
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 0 for value. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, ValueLow)
{
    try
    {
        Card card(0, 1, true);
        FAIL();
    }
    catch (const std::exception)
    {
        SUCCEED();
    }
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 14 for value. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, ValueHigh)
{
    try
    {
        Card card(14, 1, true);
        FAIL();
    }
    catch (const std::exception)
    {
        SUCCEED();
    }
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(DeckTest, DeckCardsInDeck)
{
    Deck deck(true);
    int numCards = deck.CardsInDeck();
      EXPECT_EQ(numCards, 52);
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(DeckTest, DeckCardInOrder)
{
    Deck deck(false);
    Card card = deck.Deal();
    EXPECT_EQ(card.GetValue(), 11);
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(DeckTest, DeckDealFaceDown)
{
    Deck deck(false);
    Card card = deck.Deal();
    EXPECT_EQ(card.isFaceUp, false);
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(PlayeerTest, PlayerCreationValid)
{
    Player player("TestName", 15, false, false);
    EXPECT_EQ(player.GetName(), "TestName");
    EXPECT_EQ(player.GetThreshold(), 15);
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(PlayerTest, PlayerCreationInValid)
{
    try
    {
        Player player("TestName", 5, true, true);
        FAIL();
    }
    catch (const std::exception)
    {
        SUCCEED();
    }
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(PlayerTest, PlayerValidScore)
{
    Player player("TestName", 17, false, false);

    player.AddCard(Card(1, 1, true));
    player.AddCard(Card(1, 1, true));
    player.AddCard(Card(10, 1, true));
    player.AddCard(Card(9, 1, true));

    int val = player.Score();
    EXPECT_EQ(val, 21);
}

/**
 * @brief Construct a new TEST object
 *
 */
TEST(PlayerTest, PlayerInValidScore)
{
    Player player("TestName", 17, false, false);

    player.AddCard(Card(1, 1, true));
    player.AddCard(Card(1, 1, true));
    player.AddCard(Card(1, 1, true));
    player.AddCard(Card(10, 1, true));
    player.AddCard(Card(9, 1, true));

    int val = player.Score();

    EXPECT_EQ(val, 22);
}