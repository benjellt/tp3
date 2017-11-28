// vim: set sw=4 ts=4 sts=4:
#include <iostream>
#include <cmath>
#include "MonteCarlo.hpp"

MonteCarlo::MonteCarlo(BSCall &product, size_t samples)
    : m_product(product), m_samples(samples)
{}



void MonteCarlo::mc(double &prix, double &stddev, PnlRng *rng)
{
    double sum = 0.;
    double var = 0.;
    for (size_t i = 0; i < m_samples; i++) {
        double g = pnl_rng_normal(rng);
        double flow = m_product.payoff(g);
        sum += flow;
        var += flow * flow;
    }
    prix = sum / m_samples;
    var = var / m_samples - prix * prix;
    stddev = std::sqrt(var / m_samples);
}
