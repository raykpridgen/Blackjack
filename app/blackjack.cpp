/**
 * @file blackjack.cpp
 * @author Raymond Pridgen rkpridgen@coastal.edu
 * @brief This is the game file for blackjack
 * @version 0.1
 * @date 2024-10-17
 *
 * @copyright Copyright (c) 2024 Ray Gun Technologies
 *
 */
//#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include "../inc/Card.h"
#include "../inc/Player.h"
#include "../inc/Deck.h"
using namespace std;
using namespace chants;

vector<Player> EnterPlayers(int players, int threshold);
vector<Player> SortPlayers(vector<Player> players);
void DetermineOutcomeOfGame(vector<Player>& players);
void PlayBlackjack(vector<Player>& players, Deck deck);


int main(int argc, char **argv)
{
    srand(time(nullptr));
    int playerNum;
    int threshold;
    cout << "---------- Game Setup ----------\n";
    cout << "Enter number of players: ";
    cin >> playerNum;
    cout << "Enter threshold for players: ";
    cin >> threshold;
    vector<Player> players;
    Deck deck(false);
    players = EnterPlayers(playerNum, threshold);
    PlayBlackjack(players, deck);
    SortPlayers(players);
    DetermineOutcomeOfGame(players);

}

vector<Player> EnterPlayers(int players, int threshold)
{
    cin.ignore();
    vector<Player> playerList;
    string playerName; 
    for(int i=0; i<players-2; i++)
    { 
        cout << "Enter computer player name: ";
        getline(cin, playerName);
        Player newPlayer(playerName, threshold, false, false);
        playerList.push_back(newPlayer);
    }
    cout << "Enter your name: ";
    getline(cin, playerName);
    Player user(playerName, threshold, true, false);
    Player dealer("Dealer", threshold, false, true);
    playerList.push_back(user);
    playerList.push_back(dealer);
    return playerList;
}

vector<Player> SortPlayers(vector<Player> players)
{
    vector<string> nameList;
    vector<Player> sortedPlayers;
    // Take in a list of all players names
    for(Player player : players)
    {
        nameList.push_back(player.GetName());
    }
    // sort the list of names
    sort(nameList.begin(), nameList.end());
    // for each player
    for(Player player : players)
    {
        // if their name mathces that in the first position
        if(player.GetName() == nameList[0])
        {
            // add player to sorted list
            sortedPlayers.push_back(player);
            // remove name from the list
            nameList.erase(nameList.begin());
        }   
    }
    return sortedPlayers;
}

void DetermineOutcomeOfGame(vector<Player>& players)
{
    int highestScore = 0;
    // Find the highest score out of the players
    for(Player& player : players)
    {
        if (!player.isBusted && player.Score() > highestScore)
        {
            highestScore = player.Score();
        }
    }

    // Name each player with this highest score as the winner
    string winners;
    int winNum = 0;
    for (Player player : players)
    {
        if (player.Score() == highestScore)
        {
            player.isWinner = true;
            winners = winners + player.GetName() + " ";
            winNum++;
        }
    }
    if (winNum == 1)
    {
        cout << "The player: " << winners << "\nhas won the game with a score of " << highestScore << "\n";
    }
    else
    {
        cout << "The players:\n" << winners << "\n have won the game with a score of " << highestScore << "\n";
    }
    

}

void PlayBlackjack(vector<Player>& players, Deck deck)
{
    Card currentDealtCard(1, 1, true);
    cout << "The game has started, and the bets have been placed. Get ready.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    deck.ShuffleDeck();

    // First, give each player two cards. Dealer has one face down.
    for (int i=0; i<2; i++) // Two iterations for two cards
    {
        // For each player
        for (Player& player : players)
        {
            // Deal a face down card to the dealer as their first card
            if (player.GetisDealer() && player.CountCards() == 0)
            {
                // Deal a card
                currentDealtCard = deck.Deal();
                // Add card to dealer's hand
                player.AddCard(currentDealtCard);
                // Give output to user
                cout << player.GetName() << " was dealt the " << currentDealtCard.ToString() << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                // Continue to the next iteration
                continue;
            }
            // If the player has less than 2 cards
            if (player.CountCards() < 2)
            {
                // Deal a face up card to the player
                currentDealtCard = deck.Deal();
                // Make card face up
                currentDealtCard.isFaceUp = true;
                // Add card to player's hand
                player.AddCard(currentDealtCard);
                // Show output to user
                cout << player.GetName() << " was dealt the " << currentDealtCard.ToString() << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));

            } 
        }
    }

    // Next, allow each player to play. Dealer goes last. 
    for (Player& player : players)
    {   
        // If player is not the dealer
        if (!player.GetisDealer())
        {
            // Print inital score from two cards alreadt dealt
            cout << player.GetName() <<  " has a score of " << player.Score() << "\n"; 
            std::this_thread::sleep_for(std::chrono::seconds(2));
            // IF player is not the user, run automation for all computer players
            if (!player.GetisUser())
            {
                // While the score is less than the threshold
                while (player.Score() < player.GetThreshold())
                {
                    // Deal a card to the player until they are over the threshold
                    currentDealtCard = deck.Deal();
                    currentDealtCard.isFaceUp = true;
                    player.AddCard(currentDealtCard);
                    cout << player.GetName() << " was dealt the " << currentDealtCard.ToString() << " and now has a score of " << player.Score() << "\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    // Update if bust occurs
                    if (player.Score() > 21)
                    {
                        player.isBusted = true;
                        cout << player.GetName() << " busted!" << "\n";
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    }
                }
                if(!player.isBusted)
                {
                    cout << player.GetName() << " is standing at " << player.Score() << "\n";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }
            }
            // If the player is the user
            else
            {
                while (player.Score() < 21)
                {
                    // Alert user of threshold
                    if (player.Score() == player.GetThreshold())
                    {
                        cout << "Warning! Your score is at your threshold, " << player.GetThreshold() << "\n";
                    }
                    string userInput;
                    cout << "You have a score of " << player.Score() << ". Are you going to hit (h) or stand (s)?\n Enter: ";
                    getline(cin, userInput);
                    if (userInput == "h")
                    {
                        // Deal a card to the player until they are over the threshold
                        currentDealtCard = deck.Deal();
                        currentDealtCard.isFaceUp = true;
                        player.AddCard(currentDealtCard);
                        cout << player.GetName() << " was dealt the " << currentDealtCard.ToString() << " and now has a score of " << player.Score() << "\n";
                        // Update if bust occurs
                        if (player.Score() > 21)
                        {
                            player.isBusted = true;
                            cout << "You busted!" << "\n";
                            std::this_thread::sleep_for(std::chrono::seconds(3));
                        }
                    }
                    else if (userInput == "s")
                    {
                        cout << "You are choosing to stand at " << player.Score() << ". Next player will play now.\n";
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        break;
                    }
                    else
                    {
                        cout << "Invalid entry.\n";
                    }
                }
            }
        }
    }
    int highestScore = 0;
    // Get highest score so far to see where the dealer needs to stand
    for (Player player : players)
    {
        if (!player.GetisDealer() && player.Score() > highestScore && player.Score() <= 21)
        {
            highestScore = player.Score();
        }
    }

    if (highestScore == 0)
    {
        highestScore = 21;
    }

    // Dealer plays after all other players have
    // There is probably a better way to handle this logically but I can't think of anything
    for (Player& player : players)
    {
        if (player.GetisDealer())
        {
            // Flip dealer cards
            player.FlipAllCards(true);
            // While dealer is below their threshold or the highest score
            while (player.Score() < highestScore || player.Score() < player.GetThreshold())
            {
                // Deal a card to the player until they are over the threshold
                currentDealtCard = deck.Deal();
                currentDealtCard.isFaceUp = true;
                player.AddCard(currentDealtCard);
                cout << player.GetName() << " was dealt the " << currentDealtCard.ToString() << " and now has a score of " << player.Score() << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                // Update if bust occurs
                if (player.Score() > 21)
                {
                    player.isBusted = true;
                    cout << player.GetName() << " busted!" << "\n";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }
            }
        }
    }
    return;
}