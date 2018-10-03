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

#include "MovingDirac3dHatch_Ti64_855_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_Ti64_855_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_Ti64_855_raster::MovingDirac3dHatch_Ti64_855_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_Ti64_855_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000655) //scan 1
  {
  float locationX = 0.2 + _t  * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.678 - _t * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000655  && _t <= 0.001310) //scan 2
  {
  float locationX = 1.044 - (_t - 0.000655) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.122 + (_t - 0.000655) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001310 && _t <= 0.001965) //scan 3
  {
  float locationX = 0.776 + (_t - 0.001310) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.678 - (_t - 0.001310) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001965 && _t <= 0.002620) //scan 4
  {
  float locationX = 1.620 - (_t - 0.001965) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.122 + (_t - 0.001965) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002620 && _t <= 0.003275) //scan 5
  {
  float locationX = 1.352 + (_t - 0.002620) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.678 - (_t - 0.002620) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003275 && _t <= 0.003929) //scan 6
  {
  float locationX = 2.196 - (_t - 0.003275) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.122 + (_t - 0.003275) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003929  && _t <= 0.004584) //scan 7
  {
  float locationX = 1.928 + (_t - 0.003929) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.678 - (_t - 0.003929) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.004584  && _t <= 0.005239) //scan 8
  {
  float locationX = 2.772 - (_t - 0.004584) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.122 + (_t - 0.004584) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_Ti64_855_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
