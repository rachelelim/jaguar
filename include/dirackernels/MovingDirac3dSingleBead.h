/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef MOVINGDIRAC3DSINGLEBEAD_H
#define MOVINGDIRAC3DSINGLEBEAD_H

// Moose Includes
#include "DiracKernel.h"

// Forward Declarations
class MovingDirac3dSingleBead;

template <>
InputParameters validParams<MovingDirac3dSingleBead>();

class MovingDirac3dSingleBead : public DiracKernel
{
public:
  MovingDirac3dSingleBead(const InputParameters & parameters);

  virtual void addPoints() override;
  virtual Real computeQpResidual() override;

protected:
  Real _value;
  Point _point;
};

#endif // MOVINGDIRAC3DSINGLEBEAD_H
