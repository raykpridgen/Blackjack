# BlackJack Project
Raymond Pridgen, in CS207-02 with Professor David Blair 
## Function to make a deck of cards: CreateDeckOfCard()
This part was relatively easy, I just had to look over the class of a card, and then use the vector functionality for a list. So, I made a loop and another nested one to iterate through each suit and value, to then place each card object in the vector. 
## Function to shuffle a deck of cards: Shuffle()
This function took a little more mental gymnastics, but I figured it out. To start, I needed a random number. I used the random number generator rand(), which is seeded with the comptuer clock. I also used the mod % operator to make the random number fall within the range of the deck of cards. Then, I used the vector functions .push_back() and .erase() to find a random card in the list, remove it, and place it at the back. Finally I iterate that process 200 times to make sure the deck is thoroughly shuffled. This fucntion also takes a reference, so it actually shuffles the original deck, instead of makign a copy and returning a whole new deck. 
## Function to print a deck of cards to the console: ToString()
This function was about as simple as the first one. All I did was use the .ToString() function from the Card.cpp file. First, I iterated through the vector of Cards, then used the ToString function to print each one out. 
## Quick main code to deal four cards from a shuffled deck
Finally, I used all these functions to show that each part works, and then I dealt four cards by printing four from the back of the list to the console. I also used .pop_back() and .push_back() to remove the dealt cards from the deck, and added them to a list to mark cards already dealt. 