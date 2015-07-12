#include "../main/stdafx.h"
#include "RandomNumber.h"

RandomNumber::RandomNumber()
{
    m_Seed = 1;
    index = 0;
    generateNumbers();
}

RandomNumber::RandomNumber(unsigned int seed)
{
    m_Seed = seed;
    index = 0;
    generateNumbers();
}

unsigned int RandomNumber::generateRandomNumber()
{
    return generateRandomNumber(UINT_MAX);
}

unsigned int RandomNumber::generateRandomNumber(unsigned int range)
{
    if (range == 0)
        return 0;

    unsigned int y = MT[index];
    y ^= y >> 11;
    y ^= (y << 7 & 0x9d2c5680);
    y ^= (y << 15 & 0xefc60000);
    y ^= y >> 18;

    index = (index + 1) % 624;
    return y % range;
}

void RandomNumber::setSeed(unsigned int seed)
{
    m_Seed = seed;
    generateNumbers();
}

unsigned int RandomNumber::getSeed()
{
    return m_Seed;
}

void RandomNumber::randomizeSeed()
{
    setSeed((unsigned int)time(NULL));
    generateNumbers();
}

void RandomNumber::generateNumbers()
{
    MT[0] = m_Seed;
    index = 0;

    //Intialize the generator from a seed
    for (int i = 1; i < 623; i++)
    {
        MT[i] = (0xffffffffff & 0x6c078965 * (MT[i-1] ^ (MT[i-1] >> 30)) + i);
    }
}