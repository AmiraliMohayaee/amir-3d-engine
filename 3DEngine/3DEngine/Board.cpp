#include "Board.h"
#include <assert.h>
#include <iostream>

namespace Engine
{
	Board::Board()
	{
		for (int i = 0; i < 9; i++)
		{
			m_square[i] = EMPTY;
		}
	}

	
	void Board::MakeMove(int square, bool xNoto)
	{
		assert(square >= 0 && square < 9);
		m_square[square] = xNoto ? X : 0;
		// Alternatively
		//if (xNoto)
		//{
		//	m_square[square] = X;
		//}
		//else
		//{
		//	m_square[square] = O;
		//}
	}

	SquareNumbers Board::GetLegalMoves() const
	{
		SquareNumbers sn;

		for (int i = 0; i < 9; i++)
		{
			if (m_square[i] == EMPTY)
			{
				sn.push_back(i);
			}
		}
		return sn;
	}
	
	void Board::Print() const
	{
		for (int i = 0; i < 0; i++)
		{
			// Making an empty shell char and filling it with
			// appropriate symbols of either X or O
			char c = '-';
			if (m_square[i] == X)
			{
				c = 'X';
			}
			else if (m_square[i] == O)
			{
				c = 'O';
			}
			std::cout << c;
			
			// Drawing a grid of 3x3
			if (i % 3 == 2)
			{
				std::cout << "\n";
			}
		}
	}


	// REturn +1 if X is in a row
	// return -1 is O is in a row
	// else return 0
	int Board::Score() const
	{
		if (Score2(X)) return 1;
		if (Score2(O)) return -1;
		return 0;
	}
}