#include "rummikub.h"

using namespace std;

bool RummiKub::validCheck(vector<Tile> toBeChecked, type Typing) {
	int _size = static_cast<int>(toBeChecked.size());

	if (Typing == type::Group) {

		if (_size < 3 || _size > 4)
			return false;

		set<Color> sameCheck;

		for (int i = 0; i < _size; i++) {
			if (toBeChecked[0].denomination != toBeChecked[i].denomination)
				return false;
			sameCheck.insert(toBeChecked[i].color);
		}

		if (static_cast<int>(sameCheck.size()) != _size)
			return false;

		return true;
	}
	else {

		if (_size < 3)
			return false;

		for (int i = 0; i < _size; i++) {

			if (toBeChecked[0].color != toBeChecked[i].color)
			{
				return false;
			}

			if (i != _size - 1 && toBeChecked[i].denomination + 1 != toBeChecked[i + 1].denomination)
			{
				return false;
			}
		}

		return true;
	}
}

int RummiKub::Recursion(int index) {

	if (index == static_cast<int>(hand.size())) {

		for (const vector<Tile>& runs : runs) {
			if (!validCheck(runs, type::Run))
				return 0;
		}

		for (const vector<Tile>& group : groups) {
			if (!validCheck(group, type::Group))
				return 0;
		}

		return 1;
	}

	Tile temp = hand[index];

	// Add it to a existing run
	for (int i = 0; i < (int)runs.size(); i++) {

		runs[i].push_back(temp);

		if (Recursion(index + 1))
			return 1;

		runs[i].pop_back();

	}

	// Add it to a existing group
	for (int i = 0; i < (int)groups.size(); i++) {

		groups[i].push_back(temp);
		
		if (Recursion(index + 1))
			return 1;
		
		groups[i].pop_back();
	
	}

	// Make new run
	{
		runs.push_back({ temp });

		if (Recursion(index + 1))
			return 1;

		runs.pop_back();
	}

	// Make new group
	{
		groups.push_back({ temp });

		if (Recursion(index + 1))
			return 1;
		
		groups.pop_back();
	}

	// Failed
	return 0;
}

void RummiKub::Solve() {

	sort(hand.begin(), hand.end());
	Recursion(0);
}
