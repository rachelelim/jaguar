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

#include "MovingDirac3d_multilayers.h"

template <>
InputParameters
validParams<MovingDirac3d_multilayers>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3d_multilayers::MovingDirac3d_multilayers(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3d_multilayers::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.003) //layer 1
  {
  float locationX = _t * 1000 + 0.0;
  float locationY = 0.2;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t >= 0.050  && _t <= 0.053) //layer 2
  {
  float locationX = (_t - 0.050) * 1000;
  float locationY = 0.2;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t >= 0.100 && _t <= 0.103) //layer 3
  {
  float locationX = (_t - 0.100) * 1000;
  float locationY = 0.2;
  Point custom_point(locationX, locationY, 0.26);
  addPoint(custom_point);
  }
  else
  if (_t >= 0.150 && _t <= 0.153) // layer 4
  {
  float locationX = (_t - 0.150) * 1000;
  float locationY = 0.2;
  Point custom_point(locationX, locationY, 0.29);
  addPoint(custom_point);
  }
  else
  if (_t >= 0.200 && _t <= 0.203) // layer 5
  {
  float locationX = (_t - 0.200) * 1000;
  float locationY = 0.2;
  Point custom_point(locationX, locationY, 0.32);
  addPoint(custom_point);
  }
  else
  if (_t >= 0.250 && _t <= 0.253) // layer 6
  {
  float locationX = (_t - 0.250) * 1000;
  float locationY = 0.2;
  Point custom_point(locationX, locationY, 0.35);
  addPoint(custom_point);
  }
}

Real
MovingDirac3d_multilayers::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
