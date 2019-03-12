#ifndef player1_cpp
#define player1_cpp

class player {

public:
	int x;
	int y;
	int lungime;
	int latime;

	int logLungime[10];
	int logLatime[10];
	int logPozx[10];
	int logPozy[10];

	void logare(int lungime, int latime, int x, int y)
	{

		int a;

		for (a = 9; a > 0; a--)
		{
			logLungime[a] = logLungime[a - 1];
		}
		logLungime[0] = lungime;

		for (a = 9; a > 0; a--)
		{
			logLatime[a] = logLatime[a - 1];
		}
		logLatime[0] = latime;

		for (a = 9; a > 0; a--)
		{
			logPozy[a] = logPozy[a - 1];
		}
		logPozy[0] = y;

		for (a = 9; a > 0; a--)
		{
			logPozx[a] = logPozx[a - 1];
		}
		logPozx[0] = x;

	}
};


#endif