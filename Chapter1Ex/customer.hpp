#ifndef __CUSTOMER_GUARD__
#define __CUSTOMER_GUARD__

#include <vector>
#include <sstream>
#include "rentals.hpp"
#include "movies.hpp"

class Customer
{
    private:
        std::string _name;
        std::vector<Rental> _rentals;

    public:
        Customer(std::string name)
        {
            _name = name;
        }

        void addRental(Rental rental)
        {
            _rentals.push_back(rental);
        }

        std::string getName()
        {
            return _name;
        }

        std::string statement()
        {
            double totalAmount = 0;
            int frequentRenterPoints = 0;
            std::string result = "Rental Record for " + getName() + "\n";
            Movie types;

            for(int i = 0; i < _rentals.size(); ++i)
            {
                double thisAmount = 0;
                Rental each = _rentals.at(i);

                switch (each.getMovie().getPriceCode())
                {
                    case types.REGULAR:
                    {
                        thisAmount += 2;
                        if (each.getDaysRented() > 2)
                        {
                            thisAmount += (each.getDaysRented() - 2) * 1.5;
                        }
                        break;
                    }
                    case types.NEW_RELEASE:
                    {
                        thisAmount += each.getDaysRented() * 3;
                        break;
                    }
                    case types.CHILDRENS:
                    {
                        thisAmount += 1.5;
                        if (each.getDaysRented() > 3)
                        {
                            thisAmount += (each.getDaysRented() - 3) * 1.5;
                        }
                        break;
                    }
                }

                ++frequentRenterPoints;

                if ((each.getMovie().getPriceCode() == types.NEW_RELEASE) && each.getDaysRented() > 1)
                {
                    ++frequentRenterPoints;
                }
                std::ostringstream toString;

                toString << thisAmount;

                std::string thisAmountStr = toString.str();
                result += "\t" + each.getMovie().getTitle() + "\t" + thisAmountStr + "\n";
                totalAmount += thisAmount;
            }
            
            std::ostringstream toString;

            toString << totalAmount;

            std::string totalAmountStr = toString.str();

            result += "Amount owed is " + totalAmountStr;

            std::ostringstream toString;

            toString << frequentRenterPoints;

            std::string frequentPointsStr = toString.str();

            result += "You earned " +  frequentPointsStr + " frequent renter points";

            return result; 
        }
};

#endif