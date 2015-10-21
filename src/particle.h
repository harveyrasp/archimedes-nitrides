/* particle.h -- This file is part of Archimedes release 1.2.0.
   Archimedes is a simulator for Submicron 2D III-V semiconductor
   Devices. It implements the Monte Carlo method
   for the simulation of the semiclassical Boltzmann equation for both
   electrons and holes. It includes some quantum effects by means
   of effective potential method. It is also able to simulate applied
   magnetic fields along with self consistent Faraday equation.

   Copyright (C) 2004-2011 Jean Michel Sellier
   <jeanmichel.sellier@gmail.com>
   <jsellier@purdue.edu>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


// ######################################################
// Created on 20 oct.2015, J. Marini
// Last modif. : 20 oct.2015, J. Marini
// ######################################################

#ifndef ARCHIMEDES_PARTICLE_H
#define ARCHIMEDES_PARTICLE_H

typedef struct {
    int valley;  // number id of the valley the particle is in
    real kx;     // momentum coordinates
    real ky;
    real kz;
    real t;      // time
    real x;      // real coordinates
    real y;
} particle_t;


inline int mc_does_particle_exist(particle_t *particle) {
    return particle->valley != 9;
}


inline void mc_remove_particle(particle_t *particle) {
    particle->valley = 9;
}


inline real mc_particle_ksquared(particle_t *particle) {
    return (particle->kx * particle->kx +
            particle->ky * particle->ky +
            particle->kz * particle->kz);
}

#endif
