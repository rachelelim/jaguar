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

#include "MovingDirac3dHatch_IN718_500_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_IN718_500_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_IN718_500_raster::MovingDirac3dHatch_IN718_500_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_IN718_500_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.0004982) //scan 1
  {
  float locationX = 0.2 + _t  * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.569 - _t * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.0004982  && _t <= 0.000996402) //scan 2
  {
  float locationX = 0.841 - (_t - 0.0004982) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.231 + (_t - 0.0004982) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000996402  && _t <= 0.001494603) //scan 3
  {
  float locationX = 0.806 + (_t - 0.000996402) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.569 - (_t - 0.000996402) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001494603  && _t <= 0.001992804) //scan 4
  {
  float locationX = 1.447 - (_t - 0.001494603) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.231 + (_t - 0.001494603) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001992804  && _t <= 0.002491005) //scan 5
  {
  float locationX = 1.412 + (_t - 0.001992804) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.569 - (_t - 0.001992804) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002491005  && _t <= 0.002989206) //scan 6
  {
  float locationX = 2.053 - (_t - 0.002491005) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.231 + (_t - 0.002491005) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002989206  && _t <= 0.003487406) //scan 7
  {
  float locationX = 2.018 + (_t - 0.002989206) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.569 - (_t - 0.002989206) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003487406  && _t <= 0.003985607) //scan 8
  {
  float locationX = 2.659 - (_t - 0.003487406) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.231 + (_t - 0.003487406) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_IN718_500_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
