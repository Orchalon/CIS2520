#include "fraction.h"
#include <stdio.h>

int getNumerator(Fraction* fraction)
{
    if(fraction)
        return fraction->numerator;
    return 0;
}

int getDenominator(Fraction * fraction)
{
    if(fraction)
        return fraction->denominator;
    return 1;
}


void setFraction( Fraction * fraction, int numerator, int denominator )
{
    setFractionNumerator(fraction, numerator);
    setFractionDenominator(fraction, denominator);
}

void setFractionNumerator( Fraction * fraction, int numerator )
{
    if(fraction)
    {
        fraction->numerator = numerator;
    }
}


void setFractionDenominator( Fraction * fraction, int denominator )
{
    if(fraction)
    {
        fraction->denominator = denominator;
    }
}

void printFraction( Fraction * fraction )
{
    if( fraction )
    {
        printf("%d / %d\n", fraction->numerator, fraction->denominator);
    }
    else
    {
        printf("Fraction is not initialized.");
    }
}
