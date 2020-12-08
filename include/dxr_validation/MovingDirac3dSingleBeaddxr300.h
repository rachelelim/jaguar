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

#ifndef MOVINGDIRAC3DSINGLEBEADDXR300_H
#define MOVINGDIRAC3DSINGLEBEADDXR300_H

// Moose Includes
#include "DiracKernel.h"

// Forward Declarations
class MovingDirac3dSingleBeaddxr300;

template <>
InputParameters validParams<MovingDirac3dSingleBeaddxr300>();

class MovingDirac3dSingleBeaddxr300 : public DiracKernel
{
public:
  MovingDirac3dSingleBeaddxr300(const InputParameters & parameters);

  virtual void addPoints() override;
  virtual Real computeQpResidual() override;

protected:
  Real _value;
  Point _point;
};

#endif // MOVINGDIRAC3DSINGLEBEADDXR300_H
