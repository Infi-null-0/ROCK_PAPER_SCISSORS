/*
 * This is a C++ program to implement a digital rock paper scissors game.
 * developed by Sedhu Madhav B
 * in the year 2023
 */

#include <iostream>
#include <time.h>
#include <limits>

class ROCK_PAPER_SCISSOR
{
private:
    char m_uchoice;
    char m_cchoice;
    char m_continue;

public:
    int u_score = 0;
    int c_score = 0;

public:
    // fuction to init console
    void _INIT_CONSOLE()
    {
        system("cls");
        std::cout << "\tR O C K -- P A P E R -- S C I S S O R S\t";
        std::cout << "\n\t\t    FOR 1 PLAYER\n";
        std::cout << "\n\t   ================================\n";
        std::cout << "\t\t        SCORE\n\t   # Player : " << u_score << "   |  # Computer : " << c_score << "";
        std::cout << "\n\t   ================================\n";
    }

    void show_final_score()
    {
        system("cls");
        std::cout << "\tR O C K -- P A P E R -- S C I S S O R S\t";
        std::cout << "\n\t\t    FOR 1 PLAYER\n";
        std::cout << "\n\t   ================================\n";
        std::cout << "\t\t     FINAL SCORE\n\t   # Player : " << u_score << "   |  # Computer : " << c_score << "";
        std::cout << "\n\t   ================================\n";

        // result
        if (u_score > c_score)
            std::cout << "\n\t\t     PLAYER WINS!";
        else if (u_score < c_score)
            std::cout << "\n\t\t    COMPUTER WINS!";
        else
            std::cout << "\n\t\t        DRAW!";

        // press any key to exit
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\n\t   Press Enter key to exit ..! ";
        std::cin.get();
    }

    // function to get computer choice
    void getcchoice()
    {
        srand(time(0));
        int n = rand() % 3 + 1;
        (n == 1) ? (n == 2) ? m_cchoice = 'r' : m_cchoice = 'p' : m_cchoice = 's';
    }

    // function to get user choice
    void getuchoice()
    {
        std::cout << "\n\tChoose One Option\n"
                  << std::endl;
        std::cout << "\t(r) for ROCK " << std::endl
                  << "\t(p) for PAPER" << std::endl
                  << "\t(s) for SCISSORS " << std::endl
                  << "\n  Choice : ";
        std::cin >> m_uchoice;

        while (m_uchoice != 'r' && m_uchoice != 'p' && m_uchoice != 's')
        {
            std::cout << "\nPlease enter one of the following options only. " << std::endl;
            std::cout << "\n  Choice : ";
            std::cin >> m_uchoice;
        }
    }

    // fuction to show winner
    void show_winner()
    {
        if (m_uchoice == 'r' && m_cchoice == 'p')
        {
            std::cout << "\nComputer Wins! Paper wraps Rock." << std::endl;
            c_score++;
        }
        else if (m_uchoice == 'p' && m_cchoice == 's')
        {
            std::cout << "\nComputer Wins! Scissors cut Paper." << std::endl;
            c_score++;
        }
        else if (m_uchoice == 's' && m_cchoice == 'r')
        {
            std::cout << "\nComputer Wins! Rock smashes Scissors." << std::endl;
            c_score++;
        }
        else if (m_uchoice == 'r' && m_cchoice == 's')
        {
            std::cout << "\nYou Win! Rock smashes Scissors." << std::endl;
            u_score++;
        }
        else if (m_uchoice == 'p' && m_cchoice == 'r')
        {
            std::cout << "\nYou Win! Paper wraps Rock." << std::endl;
            u_score++;
        }
        else if (m_uchoice == 's' && m_cchoice == 'p')
        {
            std::cout << "\nYou Win! Scissors cut Paper." << std::endl;
            u_score++;
        }
        else
        {
            std::cout << "\nTie. Play again win the Game." << std::endl;
        }
    }

    // function to show user selection
    void show_user_selection()
    {
        std::cout << "\nYour choice is: " << std::endl;
        if (m_uchoice == 'r')
            std::cout << "Rock" << std::endl;
        if (m_uchoice == 'p')
            std::cout << "Paper" << std::endl;
        if (m_uchoice == 's')
            std::cout << "Scissors" << std::endl;
    }

    // function to show computer selection
    void show_computer_selection()
    {
        std::cout << "\nComputer's choice is: " << std::endl;
        if (m_cchoice == 'r')
            std::cout << "Rock" << std::endl;
        if (m_cchoice == 'p')
            std::cout << "Paper" << std::endl;
        if (m_cchoice == 's')
            std::cout << "Scissors" << std::endl;
    }

    // ask user if we wanna play again
    bool continue_game()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\n\t Do You Want to Play Again? (y) : ";
        std::cin >> m_continue;
        if (m_continue == 'y')
            return true;
        else
            return false;
    }

    // flow of run game;
    static void run_game()
    {
        ROCK_PAPER_SCISSOR game;
        do
        {
            game._INIT_CONSOLE();
            game.getuchoice();
            game.show_user_selection();
            game.getcchoice();
            game.show_computer_selection();
            game.show_winner();
        } while (game.continue_game());
        game.show_final_score();
    }
};

int main()
{
    ROCK_PAPER_SCISSOR::run_game();
    return 0;
}