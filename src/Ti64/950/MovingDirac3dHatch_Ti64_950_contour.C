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

#include "MovingDirac3dHatch_Ti64_950_contour.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_Ti64_950_contour>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_Ti64_950_contour::MovingDirac3dHatch_Ti64_950_contour(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_Ti64_950_contour::addPoints()
{
  if (_t <= 0.006114) //Before contour scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006114  && _t <= 0.006601223) //contour scan 1 offset: 0.02 mm
  {
  float locationX = 0.22;
  float locationY = 0.704 - (_t - 0.006114) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006601223 && _t <= 0.008701223) //contour scan 2 offset: 0.02 mm
  {
  float locationX = 0.22 + (_t - 0.006601223) * 1250;
  float locationY = 0.096;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008701223 && _t <= 0.009188047) //contour scan 3 offset: 0.02 mm
  {
  float locationX = 2.845;
  float locationY = 0.096 + (_t - 0.008701223) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.009188047 && _t <= 0.011288047) //contour scan 4 offset: 0.02 mm
  {
  float locationX = 2.845 - (_t - 0.009188047) * 1250;
  float locationY = 0.704;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.011288047 && _t <= 0.011806871) //contour scan 1 offset: 0.0 mm
  {
  float locationX = 0.2;
  float locationY = 0.724 - (_t - 0.011288047) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.011806871 && _t <= 0.013938871) //contour scan 2 offset: 0.0 mm
  {
  float locationX = 0.2 + (_t - 0.011806871) * 1250;
  float locationY = 0.076;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.013938871 && _t <= 0.014457695) //contour scan 3 offset: 0.0 mm
  {
  float locationX = 2.865;
  float locationY = 0.076 + (_t - 0.013938871) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.014457695 && _t <= 0.016589695) //contour scan 4 offset: 0.0 mm
  {
  float locationX = 2.865 - (_t - 0.014457695) * 1250;
  float locationY = 0.724;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_Ti64_950_contour::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
