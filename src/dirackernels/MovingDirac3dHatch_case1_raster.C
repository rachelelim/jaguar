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

#include "MovingDirac3dHatch_case1_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_case1_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_case1_raster::MovingDirac3dHatch_case1_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_case1_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000249844) //scan 1
  {
  float locationX = 0.2 + _t  * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - _t * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000249844  && _t <= 0.000499684) //scan 2
  {
  float locationX = 0.7 - (_t - 0.000249844) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.000249844) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000499684  && _t <= 0.000749524) //scan 3
  {
  float locationX = 0.776 + (_t - 0.000499684) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.000499684) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000749524  && _t <= 0.000999364) //scan 4
  {
  float locationX = 1.276 - (_t - 0.000749524) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.000749524) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000999364  && _t <= 0.001249204) //scan 5
  {
  float locationX = 1.352 + (_t - 0.000999364) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.000999364) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001249204  && _t <= 0.001499044) //scan 6
  {
  float locationX = 1.852 - (_t - 0.001249204) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.001249204) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001499044  && _t <= 0.001748884) //scan 7
  {
  float locationX = 1.928 + (_t - 0.001499044) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.001499044) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001748884  && _t <= 0.001998724) //scan 8
  {
  float locationX = 2.428 - (_t - 0.001748884) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.001748884) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001998724  && _t <= 0.002248564) //scan 9
  {
  float locationX = 2.504 + (_t - 0.001998724) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.001998724) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_case1_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
