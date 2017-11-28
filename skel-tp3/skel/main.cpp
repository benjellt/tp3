// vim: set sw=4 ts=4 sts=4:

#include <iostream>
#include <ctime>
#include "MonteCarlo.hpp"
#include "BSCall.hpp"

int main()
{
    double prix, stddev;
    BSCall product(2., 0.2, 0.03, 100., 120.);
    MonteCarlo pricer(product, 50000);
    PnlRng *rng = pnl_rng_create(PNL_RNG_MERSENNE);
    pnl_rng_sseed(rng, std::time(NULL));
    pricer.mc(prix, stddev, rng);
    std::cout << "prix : " << prix << " (IC = " << stddev * 1.96 << ")\n";
    pnl_rng_free(&rng);
    exit(0);
}
