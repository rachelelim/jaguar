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

#include "MovingDirac3dHatch_AlSi10Mg_855_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_855_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_855_raster::MovingDirac3dHatch_AlSi10Mg_855_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_855_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000540785) //scan 1
  {
  float locationX = 0.2 + _t  * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6486 - _t * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.000540785  && _t <= 0.001082) //scan 2
  {
  float locationX = 0.884 - (_t - 0.000540785) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1514 + (_t - 0.000540785) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001082  && _t <= 0.001622) //scan 3
  {
  float locationX = 0.574 + (_t - 0.001082) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6486 - (_t - 0.001082) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001622  && _t <= 0.002163) //scan 4
  {
  float locationX = 1.258 - (_t - 0.001622) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1514 + (_t - 0.001622) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002163  && _t <= 0.002704) //scan 5
  {
  float locationX = 0.948 + (_t - 0.002163) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6486 - (_t - 0.002163) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002704  && _t <= 0.003245) //scan 6
  {
  float locationX = 1.632 - (_t - 0.002704) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1514 + (_t - 0.002704) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003245  && _t <= 0.003785) //scan 7
  {
  float locationX = 1.32 + (_t - 0.003245) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6486 - (_t - 0.003245) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003785  && _t <= 0.004326) //scan 8
  {
  float locationX = 2.006 - (_t - 0.003785) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1514 + (_t - 0.003785) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_855_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
