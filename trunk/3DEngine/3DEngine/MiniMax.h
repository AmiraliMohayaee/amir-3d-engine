#pragma once

#include <vector>
#include "Board.h"

// http://en.wikipedia.org/wiki/Minimax

namespace Engine
{
	typedef std::vector<int> Nodes;

	class MiniMax
	{
	public:
		MiniMax();

		void MiniMaxSearch(Board b, int depth, bool xNoto)
		{
			int score = b.Score();

			if (depth == 0 || score != 0)
			{
				return score;
			}

			if (xNoto)
			{
				// x == maximizing player
				int bestScore = -2;
				SquareNumbers sn = b.GetLegalMoves();
				
				// C11 method
				//for (int move : sn)
				//{
				//}

				// Alternatively
				for (int i = 0; i < sn.size(); i++)
				{
					int move = sn[i];
					Board child = b;
					child.MakeMove(move, true /* == xNoto */);
					int score = MiniMax(child, depth - 1, false);
					if (score < bestScore)
					{
						bestScore = score;
					}
					return bestScore;
				}
			}
			else 
			{
				// o == minimizing player
			}
		}

	private:
	};

}