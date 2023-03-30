#include <iostream>
#include <string>
using namespace std;

pair <char, char>rock_pos;
pair <char, char>king_pos;

void	pos_init(string cur_king, string cur_rock) {
	king_pos.first = cur_king[0];
	king_pos.second = cur_king[1];
	rock_pos.first = cur_rock[0];
	rock_pos.second = cur_rock[1];
	return ;
}

int moveable(string &move, int i) {
	pair <char, char>tmp;
	
	if (i == 1)
		tmp = king_pos;
	else
		tmp = rock_pos;
	if (move == "R")
		tmp.first++;
	else if (move == "L")
		tmp.first--;
	else if (move == "B")
		tmp.second--;
	else if (move == "T")
		tmp.second++;
	else if (move == "RT") {
		tmp.first++;
		tmp.second++;
	}
	else if (move == "LT") {
		tmp.first--;
		tmp.second++;
	}
	else if (move == "RB") {
		tmp.first++;
		tmp.second--;
	}
	else {
		tmp.first--;
		tmp.second--;
	}
	if ((tmp.first >= 'A' && tmp.first <= 'H')
				&& (tmp.second >= '1' && tmp.second <= '8'))
		return (1);
	return (0);
}



int	move_act(string &move, int i) {
		pair <char, char>tmp;
		
		if (i == 1)
			tmp = king_pos;
		else
			tmp = rock_pos;
		if (move == "R")
			tmp.first++;
		else if (move == "L")
			tmp.first--;
		else if (move == "B")
			tmp.second--;
		else if (move == "T")
			tmp.second++;
		else if (move == "RT") {
			tmp.first++;
			tmp.second++;
		}
		else if (move == "LT") {
			tmp.first--;
			tmp.second++;
		}
		else if (move == "RB") {
			tmp.first++;
			tmp.second--;
		}
		else {
			tmp.first--;
			tmp.second--;
		}
		if (i == 1) {
			if ((tmp.first >= 'A' && tmp.first <= 'H')
				&& (tmp.second >= '1' && tmp.second <= '8')) {
					if (tmp == rock_pos) {
						if (moveable(move, 0) == 1)
							king_pos = tmp;
					}
					else
						king_pos = tmp;
				}
			}
		else {
			
			if ((tmp.first >= 'A' && tmp.first <= 'H')
				&& (tmp.second >= '1' && tmp.second <= '8')) 
			{
				rock_pos = tmp;
				return (1);
			}
		}
	return (0);
}


void	mv_init(string &move, int i)
{
	pair <char, char>tmp;

	if (i == 1)
		move_act(move, 1);
	else {
		if (king_pos == rock_pos)
			move_act(move, 0);
	}
}

int main(void)
{
	string cur_rock, cur_king, move;
	int	mv_cnt;

	cin>>cur_king>>cur_rock;
	cin>>mv_cnt;
	pos_init(cur_king, cur_rock);
	while (mv_cnt--)
	{
		cin>>move;
		mv_init(move, 1);
		mv_init(move, 0);
	}
	cout<<king_pos.first<<king_pos.second<<'\n';
	cout<<rock_pos.first<<rock_pos.second<<'\n';
}
