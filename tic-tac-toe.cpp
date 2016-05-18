#include <iostream>

class TicTacToe
{
    /*
     * 0  is a free cell,
     * 1  is a cell owned by player 1
     * -1 is a cell owned by player 2
     */
    union
    {
        int         _dim1[9] = {0};
        int         _dim2[3][3];
    };

    std::string     _name[2];
//                    _name_2;

    int             _turn = 1;

public:
    TicTacToe(void)
    {
		for (std::size_t i(0) ; i < 2 ; ++i)
		{
			std::cout << "Player " << i + 1 << " name: ";
        	if (not (std::cin >> _name[i]))
            	throw std::runtime_error("End of input");
		}
    }

    void display_board(void)
    {
        for (std::size_t i(0) ; i < 3 ; ++i)
        {
            std::cout << "+---+---+---+\n";
            for (std::size_t j(0) ; j < 3 ; ++j)
            {
                switch (_dim2[i][j])
                {
                case 1:
                    std::cout << "| O ";
                    break ;
                case -1:
                    std::cout << "| X ";
                    break ;
                default:
                    std::cout << "|(" << 3 * i + j + 1 << ")";
                }
            }
            std::cout << "|\n";
        }
        std::cout << "+---+---+---+\n";
    }

    /* Return false if player input has failed (CTRL + D, for example) */
    bool player_input(void)
    {
        int         input;

        do
        {
            std::cout << _name[_turn < 0] << "'s turn ("
                    << (_turn > 0 ? 'O' : 'X') << ") : ";
            if (not (std::cin >> input))
                return false;
        } while (input < 1 or input > 9 or _dim1[input - 1]);
        _dim1[input - 1] = _turn;
        _turn = -_turn;
        return true;
    }

    bool winner(void)
    {
        /* Check horizontally and vertically */
        for (std::size_t i(0) ; i < 3 ; ++i)
        {
            if ((_dim2[0][i] + _dim2[1][i] + _dim2[2][i]) / 3 or
                    (_dim2[i][0] + _dim2[i][1] + _dim2[i][2]) / 3)
                return true;
        }
        /* Check for diagonals */
        if ((_dim2[0][0] + _dim2[1][1] + _dim2[2][2]) / 3 or
                (_dim2[2][0] + _dim2[1][1] + _dim2[0][2]) / 3)
            return true;
        /* Here, there is no winner */
        return false;
    }

    bool game_finished(void)
    {
        /* If there is a winner, the game has finished */
        if (winner())
        {
            std::cout << _name[_turn > 0] << " won\n";
            return true;
        }
        /* If there is a free cell, the game must continue */
        for (std::size_t i(0) ; i < 9 ; ++i)
            if (not _dim1[i])
                return false;
        /* There are no more free cells : this is a draw */
        std::cout << "Draw\n";
        return true;
    }

    int loop(void)
    {
        do
        {
            display_board();
            if (game_finished())
                return 0;
        } while (player_input());
        return -1;
    }
};

int                 main(void)
{
    return TicTacToe().loop();
}
