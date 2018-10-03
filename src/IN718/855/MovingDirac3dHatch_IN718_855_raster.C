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

#include "MovingDirac3dHatch_IN718_855_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_IN718_855_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_IN718_855_raster::MovingDirac3dHatch_IN718_855_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_IN718_855_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.001019283) //scan 1
  {
  float locationX = 0.2 + _t  * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.746 - _t * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.001019283 && _t <= 0.002038565) //scan 2
  {
  float locationX = 1.195 - (_t - 0.001019283) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.054 + (_t - 0.001019283) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002038565 && _t <= 0.003057848) //scan 3
  {
  float locationX = 0.806 + (_t - 0.002038565) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.746 - (_t - 0.002038565) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003057848 && _t <= 0.004077131) //scan 4
  {
  float locationX = 1.801 - (_t - 0.003057848) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.054 + (_t - 0.003057848) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.004077131 && _t <= 0.005096413) //scan 5
  {
  float locationX = 1.412 + (_t - 0.004077131) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.746 - (_t - 0.004077131) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.005096413 && _t <= 0.006115696) //scan 6
  {
  float locationX = 2.407 - (_t - 0.005096413) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.054 + (_t - 0.005096413) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_IN718_855_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
