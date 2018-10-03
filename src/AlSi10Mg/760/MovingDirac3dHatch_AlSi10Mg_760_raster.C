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

#include "MovingDirac3dHatch_AlSi10Mg_760_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_760_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_760_raster::MovingDirac3dHatch_AlSi10Mg_760_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_760_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000436592) //scan 1
  {
  float locationX = 0.2 + _t  * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6007 - _t * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.000436592  && _t <= 0.000873) //scan 2
  {
  float locationX = 0.788 - (_t - 0.000436592) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1993 + (_t - 0.000436592) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000873  && _t <= 0.001310) //scan 3
  {
  float locationX = 0.574 + (_t - 0.000873) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6007 - (_t - 0.000873) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001310  && _t <= 0.001746) //scan 4
  {
  float locationX = 1.162 - (_t - 0.001310) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1993 + (_t - 0.001310) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001746  && _t <= 0.002183) //scan 5
  {
  float locationX = 0.948 + (_t - 0.001746) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6007 - (_t - 0.001746) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002183  && _t <= 0.002620) //scan 6
  {
  float locationX = 1.536 - (_t - 0.002183) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1993 + (_t - 0.002183) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002620  && _t <= 0.003056) //scan 7
  {
  float locationX = 1.322 + (_t - 0.002620) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6007 - (_t - 0.002620) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003056  && _t <= 0.003493) //scan 8
  {
  float locationX = 1.910 - (_t - 0.003056) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1993 + (_t - 0.003056) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_760_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
