#include <cstdlib>
#include <time.h>

class RandomNumber
{
    private:
        unsigned int m_Seed;
        int MT[623];
        int index;
    public: 
        RandomNumber();
        RandomNumber(unsigned int);

        unsigned int generateRandomNumber();
        unsigned int generateRandomNumber(unsigned int range);

        unsigned int getSeed();
        void setSeed(unsigned int seed);
        void randomizeSeed();
        void generateNumbers();
};