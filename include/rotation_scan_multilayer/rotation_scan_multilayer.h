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

#ifndef ROTATION_SCAN_MULTILAYER_H
#define ROTATION_SCAN_MULTILAYER_H

// Moose Includes
#include "DiracKernel.h"

// Forward Declarations
class rotation_scan_multilayer;

template <>
InputParameters validParams<rotation_scan_multilayer>();

class rotation_scan_multilayer : public DiracKernel
{
public:
  rotation_scan_multilayer(const InputParameters & parameters);

  virtual void addPoints() override;
  virtual Real computeQpResidual() override;

protected:
  Real _value;
  Point _point;
};

#endif // ROTATION_SCAN_MULTILAYER_H
