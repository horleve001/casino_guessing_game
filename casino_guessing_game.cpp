#include <iostream>
#include <ctime>
#include <cstdlib>
int win(int bet, int balance);
int lose(int bet, int balance);
int szamitas();
void osszehasonlitas(int szamitas1, int guess, int bet, int balance);
bool sikeres_e(int szamitas1, int guess);
int check_balance();
int main()
{
    int balance, bet, szamitas1;
    int guesss = 0;
    std::string player, play;
    std::cout << "write your name: ";
    std::cin >> player;
    std::cout << "hi " << player << " do you want to play? ";
    std::cin >> play;
    if (play == "no") {
        std::cout << "then bye" << std::endl;
    }
    else if (play == "yes") {
        std::cout << "then lets play" << std::endl;
        std::cout << "how much money do you have? ";
        std::cin >> balance;
        do {
            std::cout << "what is your bet? ";
            std::cin >> bet;
            if (balance < bet) {
                std::cout << "You dont have enough money!\n";
                std::cout << "Be realistic!\n";
            }
            else {
                std::cout << "write a number: ";
                std::cin >> guesss;
                std::cout << "the winner number is: " << szamitas() << std::endl;
                szamitas1 = szamitas();
                osszehasonlitas(szamitas1, guesss, bet, balance);
                if (sikeres_e(szamitas1, guesss) == true) {
                    balance = win(bet, balance);
                }
                else {
                    balance = lose(bet, balance);
                }
            }
            std::cout << "Your current balance is : " << balance << std::endl;
        } while (balance > 0);
        std::cout << "Well played. see you next time!";
    }
    else {
        std::cout << "write a valid choice" << std::endl;
    }
}
int szamitas() {
    int correct_number = rand() % 10 + 1;
    return correct_number;
}
void osszehasonlitas(int szamitas1, int guess, int bet, int balance) {
    if (sikeres_e(szamitas1, guess)) {
        std::cout << "You won: " << bet * 2 << std::endl;
    }
    else if (szamitas1 > guess) {
        std::cout << "You guessed too low, and you lost: " << bet << std::endl;
    }
    else {
        std::cout << "You guessed too high, and you lost: " << bet << std::endl;
    }
}
int win(int bet, int balance) {
    return balance += bet ;
}
int lose(int bet, int balance) {
    return balance -= bet;
}
bool sikeres_e(int szamitas1, int guess) {
    if (szamitas1 == guess) {
        return true;
    }
    else {
        return false;
    }
}
