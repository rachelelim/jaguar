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

#include "MovingDirac3dHatch_Ti64_665_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_Ti64_665_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_Ti64_665_raster::MovingDirac3dHatch_Ti64_665_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_Ti64_665_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000436) //scan 1
  {
  float locationX = 0.2 + _t  * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.585 - _t * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000436  && _t <= 0.000872) //scan 2
  {
  float locationX = 0.858 - (_t - 0.000436) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.215 + (_t - 0.000436) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000872 && _t <= 0.001308) //scan 3
  {
  float locationX = 0.776 + (_t - 0.000872) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.585 - (_t - 0.000872) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001308 && _t <= 0.001745) //scan 4
  {
  float locationX = 1.434 - (_t - 0.001308) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.215 + (_t - 0.001308) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001745 && _t <= 0.002181) //scan 5
  {
  float locationX = 1.352 + (_t - 0.001745) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.585 - (_t - 0.001745) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002181 && _t <= 0.002617) //scan 6
  {
  float locationX = 2.01 - (_t - 0.002181) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.215 + (_t - 0.002181) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002617  && _t <= 0.003053) //scan 7
  {
  float locationX = 1.928 + (_t - 0.002617) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.585 - (_t - 0.002617) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003053  && _t <= 0.003489) //scan 8
  {
  float locationX = 2.586 - (_t - 0.003053) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.215 + (_t - 0.003053) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_Ti64_665_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
