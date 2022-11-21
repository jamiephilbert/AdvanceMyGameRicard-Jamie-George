#include "Scoreboard.h"

Scoreboard::Scoreboard() : Scoreboard({230,230,230})
{

}

Scoreboard::Scoreboard(SDL_Color color)
{
	mColor = color;
	Score(0);
}

Scoreboard::~Scoreboard()
{
	ClearBoard();
}

void Scoreboard::Render()
{
	for (auto digit : m_pScore) {
		digit->Render();
	}
}




void Scoreboard::ClearBoard()
{

	for (unsigned i = 0; i < m_pScore.size(); i++) {
		delete m_pScore[i];
		m_pScore[i] = nullptr;
	}

	m_pScore.clear();
}

void Scoreboard::Score(int score)
{
	ClearBoard();
	if (score == 0) {
		for (int i = 0; i < 2; i++) {
			m_pScore.push_back(new Texture("0", "emulogic.ttf", 16, mColor));
			m_pScore[i]->Parent(this);
			m_pScore[i]->Position(Vector2(-17.0f * i, 0.0f));
		}
	}
	else
	{
		std::string str = std::to_string(score);
		unsigned lastIndex = (unsigned)str.length() - 1;

		for (unsigned i = 0; i <= lastIndex; i++) {
			m_pScore.push_back(new Texture(str.substr(i, 1), "emulogic.ttf", 16, mColor));
			m_pScore[i]->Parent(this);
			m_pScore[i]->Position(Vector2(-17.0f * (lastIndex - i), 0.0f));
		}
	}
}

