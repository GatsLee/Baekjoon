#include <iostream>
#include <string>
using namespace std;

pair <char, int>rock_pos;
pair <char, int>king_pos;

void	pos_init(string &pos, pair <char, int> &pos_input)
{
	pos_input.first = pos[0];
	pos_input.second = pos[1];
	return ;
}

void	mv_init(string &move)
{
	if (move == "R")
	{
		if (king_pos.second + 1 > 0)
		if (dup_check() == true)

	}
	else if (move == "L")

	else if (move == "B")

	else if (move == "T")

	else if (move == "RT")

	else if (move == "LT")

	else if (move = "RB")

	else

}

int main(void)
{
	string rock_pos, king_pos, move;
	int	mv_cnt;

	cin>>king_pos>>rock_pos;
	cin>>mv_cnt;
	pos_init(king_pos);
	pos_init(rock_pos);
	while (mv_cnt--)
	{
		cin>>move;
		mv_init(move);
	}
}
