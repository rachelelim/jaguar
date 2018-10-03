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

#include "MovingDirac3dHatch_IN718_665_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_IN718_665_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_IN718_665_raster::MovingDirac3dHatch_IN718_665_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_IN718_665_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000740394) //scan 1
  {
  float locationX = 0.2 + _t  * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.651 - _t * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.000740394  && _t <= 0.001480788) //scan 2
  {
  float locationX = 1.006 - (_t - 0.000740394) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.149 + (_t - 0.000740394) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001480788  && _t <= 0.002221181) //scan 3
  {
  float locationX = 0.806 + (_t - 0.001480788) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.651 - (_t - 0.001480788) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002221181  && _t <= 0.002961575) //scan 4
  {
  float locationX = 1.612 - (_t - 0.002221181) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.149 + (_t - 0.002221181) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002961575  && _t <= 0.003701969) //scan 5
  {
  float locationX = 1.412 + (_t - 0.002961575) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.651 - (_t - 0.002961575) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003701969  && _t <= 0.004442363) //scan 6
  {
  float locationX = 2.218 - (_t - 0.003701969) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.149 + (_t - 0.003701969) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_IN718_665_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
