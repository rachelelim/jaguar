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

#ifndef MOVINGDIRAC3DSINGLEBEADDXR500_H
#define MOVINGDIRAC3DSINGLEBEADDXR500_H

// Moose Includes
#include "DiracKernel.h"

// Forward Declarations
class MovingDirac3dSingleBeaddxr500;

template <>
InputParameters validParams<MovingDirac3dSingleBeaddxr500>();

class MovingDirac3dSingleBeaddxr500 : public DiracKernel
{
public:
  MovingDirac3dSingleBeaddxr500(const InputParameters & parameters);

  virtual void addPoints() override;
  virtual Real computeQpResidual() override;

protected:
  Real _value;
  Point _point;
};

#endif // MOVINGDIRAC3DSINGLEBEADDXR500_H
