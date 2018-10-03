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

#include "MovingDirac3dHatch_AlSi10Mg_500_contour1.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_500_contour1>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_500_contour1::MovingDirac3dHatch_AlSi10Mg_500_contour1(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_500_contour1::addPoints()
{
  if (_t <= 0.00121144) //Before contour1 scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00121144  && _t <= 0.001321662) //contour1 scan 1 offset: 0.02 mm
  {
  float locationX = 0.22;
  float locationY = 0.4496 - (_t - 0.00121144) * 900;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001321662  && _t <= 0.002886107) //contour1 scan 2 offset: 0.02 mm
  {
  float locationX = 0.22 + (_t - 0.001321662) * 900;
  float locationY = 0.3504;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002886107  && _t <= 0.002996329) //contour1 scan 3 offset: 0.02 mm
  {
  float locationX = 1.628;
  float locationY = 0.3504 + (_t - 0.002886107) * 900;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002996329  && _t <= 0.004560773) //contour1 scan 4 offset: 0.02 mm
  {
  float locationX = 1.628 - (_t - 0.002996329) * 900;
  float locationY = 0.4496;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_500_contour1::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
