// The Board class is a data tree that tries to simulate a 
// tictactoe board. The board would use the Minimax function
// to determine the moves based on the value returned by the
// data tree

#pragma once

#include <vector>


namespace Engine
{
	typedef std::vector<int> SquareNumbers;

	class Board
	{
	private:
		int m_square[9];
		//const int EMPTY;
		//const int O;
		//const int X;

		// Or create an enum
		enum { EMPTY = 2, O = -1, X = 1 };

		// Checking for 3 as in a row or 3 elements
		int Score2(int a) const
		{
			// Looping through the 3x3 grid
			if (m_square[0] == a && m_square[1] == a && m_square[2] == a)
			{
				for (int i = 0; i < 3; i++)
				{
				
				// Checking for horizontal loops
					if (m_square[i * 3] == a && 
						m_square[i * 3 + 1] == a && 
						m_square[i * 3 + 2] == a)
					{
						return true;
					}
					
				// Checking for vertical loops
					if (m_square[i] == a && 
						m_square[i + 3] == a && 
						m_square[i + 6] == a)
					{
						return true;
					}
				}
			}

			// Major Diagonals check
			if (m_square[0] == a && m_square[4] == a && m_square[8] == a)
			{
				return true;
			}
			if (m_square[2] == a && m_square[4] == a && m_square[6] == a)
			{
				return true;
			}
			return false;
		}

	public:
		// Setting all values to zero on startup
		Board();

		// 
		void MakeMove(int square, bool xNoto);
		SquareNumbers GetLegalMoves() const;
	
		void Print() const;
		int Score() const;
	};
}