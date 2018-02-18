#ifndef __MOVIES_GUARD__
#define __MOVIES_GUARD__

#include <string>

class Movie
{
    private:
        std::string _title;
        int _priceCode;

    public:
        static const int CHILDRENS = 2;
        static const int REGULAR = 0;
        static const int NEW_RELEASE = 1;

        Movie() {}

        Movie(std::string title, int priceCode)
        {
            _title = title;
            _priceCode = priceCode;
        }

        std::string getTitle()
        {
            return _title;
        }

        int getPriceCode()
        {
            return _priceCode;
        }

        void setPriceCode(int priceCode)
        {
            _priceCode = priceCode;
        }
        
};

#endif