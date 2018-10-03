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

#include "MovingDirac3dHatch_AlSi10Mg_500_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_500_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_500_raster::MovingDirac3dHatch_AlSi10Mg_500_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_500_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.00015143) //scan 1
  {
  float locationX = 0.2 + _t  * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.4696 - _t * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.00015143  && _t <= 0.00030286) //scan 2
  {
  float locationX = 0.5262 - (_t - 0.00015143) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.3304 + (_t - 0.00015143) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00030286  && _t <= 0.00045429) //scan 3
  {
  float locationX = 0.574 + (_t - 0.00030286) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.4696 - (_t - 0.00030286) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00045429  && _t <= 0.00060572) //scan 4
  {
  float locationX = 0.9 - (_t - 0.00045429) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.3304 + (_t - 0.00045429) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00060572  && _t <= 0.00075715) //scan 5
  {
  float locationX = 0.948 + (_t - 0.00060572) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.4696 - (_t - 0.00060572) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00075715  && _t <= 0.00090858) //scan 6
  {
  float locationX = 1.27 - (_t - 0.00075715) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.3304 + (_t - 0.00075715) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00090858  && _t <= 0.00106001) //scan 7
  {
  float locationX = 1.32 + (_t - 0.00090858) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.4696 - (_t - 0.00090858) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00106001  && _t <= 0.00121144) //scan 8
  {
  float locationX = 1.648 - (_t - 0.00106001) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.3304 + (_t - 0.00106001) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_500_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
